#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encode.h"
#include "types.h"



Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo)
{
    if(strstr(argv[2],".bmp")!=NULL)
    {
        printf(".bmp is present\n");
        encInfo->src_image_fname=argv[2];
    }
    else
    {
        printf(".bmp is not present\n");
        return e_failure;
    }
    if(strstr(argv[3],".txt")!=NULL)
    {
        printf(".txt is present\n");
        encInfo->secret_fname=argv[3];

        char*ptr=strrchr(argv[3],'.');

      if(ptr!=NULL)
      {
      strcpy(encInfo->extn_secret_file,ptr);
      }
      else
      {
        printf("ERROR: File extension not found\n");
        return e_failure;
      }

    }
    else
    {
        printf(".txt is not present\n");
        return e_failure;
    }
    if(strstr(argv[4],".bmp")!=NULL)
    {
        printf(".bmp is present\n");
        encInfo->stego_image_fname=argv[4];
    }
    else
    {
        printf(".bmp is not present\n");
        return e_failure;
    }
   
    return e_success;
}

Status do_encoding(EncodeInfo *encInfo)
{
    
    if (open_files(encInfo) == e_failure)
    {
        return e_failure;
    }

    if (check_capacity(encInfo) == e_failure)
    {
        return e_failure;
    }
    if(copy_bmp_header(encInfo->fptr_src_image,encInfo->fptr_stego_image)==e_failure)
    {
    return e_failure;
    }
    if(encode_magic_string(encInfo->magic_string,encInfo)==e_failure)
    {
        return e_failure;
    }
   
    if(encode_secret_file_extn(encInfo->extn_secret_file,encInfo)==e_failure)
    {
        return e_failure;
    }

    if(encode_secret_file_size(encInfo->size_secret_file,encInfo)==e_failure)
    {
        return e_failure;
    }

    if(encode_secret_file_data(encInfo)==e_failure)
    {
        return e_failure;
    }

    if(copy_remaining_img_data(encInfo->fptr_src_image,encInfo->fptr_stego_image)==e_failure)
    {
        return e_failure;
    }


    return e_success;
}
Status open_files(EncodeInfo *encInfo)
{
    encInfo->fptr_src_image=fopen(encInfo->src_image_fname, "rb");
    if(encInfo->fptr_src_image==NULL)
    {
        perror("");

        return e_failure;
    }
    encInfo->fptr_secret=fopen(encInfo->secret_fname, "rb");
    if(encInfo->fptr_secret==NULL)
    {
        perror("");
        return e_failure;
    }
    encInfo->fptr_stego_image=fopen(encInfo->stego_image_fname, "wb");
    if(encInfo->fptr_stego_image==NULL)
    {
        perror("");
        return e_failure;
    }
    return e_success;
}

Status check_capacity(EncodeInfo*encInfo)
{
    encInfo->image_capacity=get_image_size_for_bmp(encInfo->fptr_src_image);

    encInfo->size_secret_file=get_file_size(encInfo->fptr_secret);

    uint required_size;

    required_size=(strlen(encInfo->magic_string)
                  +strlen(encInfo->extn_secret_file)
                  +sizeof(long)
                  +encInfo->size_secret_file)*8;

    if(encInfo->image_capacity>=required_size)
    {
        return e_success;
    }
    else
    {
        printf("ERROR: Insufficient image capacity\n");
        return e_failure;
    }
}
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;

    fseek(fptr_image, 18, SEEK_SET);

    fread(&width, sizeof(int), 1, fptr_image);
    printf("width = %u\n", width);

    fread(&height, sizeof(int), 1, fptr_image);
    printf("height = %u\n", height);

    return width*height*3;
}
uint get_file_size(FILE*fptr)
{
    long int size;

    fseek(fptr,0,SEEK_END);
    size=ftell(fptr);
    fseek(fptr,0,SEEK_SET);

    return size;
}
Status copy_bmp_header(FILE*fptr_src_image,FILE*fptr_dest_image)
{
    char header[54];

    fseek(fptr_src_image,0,SEEK_SET);

    fread(header,54,1,fptr_src_image);
    fwrite(header,54,1,fptr_dest_image);

    return e_success;
}
Status encode_magic_string(const char*magic_string,EncodeInfo*encInfo)
{
    int size=strlen(magic_string);

    if(encode_data_to_image((char*)magic_string,size,encInfo->fptr_src_image,encInfo->fptr_stego_image)==e_failure)
    {
        return e_failure;
    }

    return e_success;
}
Status encode_secret_file_extn(const char*file_extn,EncodeInfo*encInfo)
{
    int size=strlen(file_extn);

    if(encode_data_to_image((char*)file_extn,size,encInfo->fptr_src_image,encInfo->fptr_stego_image)==e_failure)
    {
        return e_failure;
    }
   
    return e_success;
}
Status encode_secret_file_size(long file_size,EncodeInfo*encInfo)
{
    if(encode_data_to_image((char*)&file_size,sizeof(file_size),encInfo->fptr_src_image,encInfo->fptr_stego_image)==e_failure)
    {
        return e_failure;
    }

    return e_success;
}
Status encode_secret_file_data(EncodeInfo*encInfo)
{
    int ch;

    fseek(encInfo->fptr_secret,0,SEEK_SET);

    while((ch=fgetc(encInfo->fptr_secret))!=EOF)
    {
        char data=(char)ch;

        if(encode_data_to_image(&data,1,encInfo->fptr_src_image,encInfo->fptr_stego_image)==e_failure)
        {
            return e_failure;
        }
    }

    return e_success;
}
Status encode_data_to_image(char*data,int size,FILE*fptr_src_image,FILE*fptr_stego_image)
{
    char image_buffer[8];

    for(int i=0;i<size;i++)
    {
        fread(image_buffer,8,1,fptr_src_image);

        if(encode_byte_to_lsb(data[i],image_buffer)==e_failure)
        {
            return e_failure;
        }

        fwrite(image_buffer,8,1,fptr_stego_image);
    }

    return e_success;
}
Status encode_byte_to_lsb(char data,char*image_buffer)
{
    for(int i=0;i<8;i++)
    {
        image_buffer[i]=(image_buffer[i]&0xFE)|((data>>i)&1);
    }

    return e_success;
}
Status copy_remaining_img_data(FILE*fptr_src,FILE*fptr_dest)
{
    char ch;

    while(fread(&ch,1,1,fptr_src)>0)
    {
        fwrite(&ch,1,1,fptr_dest);
    }

    return e_success;
}

