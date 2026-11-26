#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"
#include "decode.h"




Status read_and_validate_decode_args(char*argv[],DecodeInfo*decInfo)
{
    if(strstr(argv[2],".bmp")!=NULL)
    {
        printf(".bmp is present\n");
        decInfo->stego_image_fname=argv[2];
    }
    else
    {
        printf(".bmp is not present\n");
        return e_failure;
    }

    decInfo->output_fname=argv[3];

    return e_success;
}
Status open_decode_files(DecodeInfo*decInfo)
{
    decInfo->fptr_stego_image=fopen(decInfo->stego_image_fname,"rb");

    if(decInfo->fptr_stego_image==NULL)
    {
        perror("");
        return e_failure;
    }

    decInfo->fptr_output=fopen(decInfo->output_fname,"wb");

    if(decInfo->fptr_output==NULL)
    {
        perror("");
        return e_failure;
    }
    fseek(decInfo->fptr_stego_image,54,SEEK_SET);

    return e_success;
}
Status do_decoding(DecodeInfo*decInfo)
{
    if(open_decode_files(decInfo)==e_failure)
    {
        return e_failure;
    }

    if(decode_magic_string(decInfo->magic_string,decInfo)==e_failure)
    {
        return e_failure;
    }

    if(decode_secret_file_extn(decInfo->extn_secret_file,decInfo)==e_failure)
    {
        return e_failure;
    }

    if(decode_secret_file_size(&decInfo->size_secret_file,decInfo)==e_failure)
    {
        return e_failure;
    }

    if(decode_secret_file_data(decInfo)==e_failure)
    {
        return e_failure;
    }

    return e_success;
}
Status decode_magic_string(char*magic_string,DecodeInfo*decInfo)
{
    int size=strlen(magic_string);

    if(decode_data_from_image(magic_string,size,decInfo->fptr_stego_image)==e_failure)
    {
        return e_failure;
    }

    return e_success;
}
Status decode_byte_from_lsb(char*data,char*image_buffer)
{
    char ch=0;

    for(int i=0;i<8;i++)
    {
        ch=ch|((image_buffer[i]&1)<<i);
    }

    *data=ch;

    return e_success;
}
Status decode_data_from_image(char*data,int size,FILE*fptr_stego_image)
{
    char image_buffer[8];

    for(int i=0;i<size;i++)
    {
        fread(image_buffer,8,1,fptr_stego_image);

        if(decode_byte_from_lsb(&data[i],image_buffer)==e_failure)
        {
            return e_failure;
        }
    }

    return e_success;
}
Status decode_secret_file_extn(char*file_extn,DecodeInfo*decInfo)
{
    if(decode_data_from_image(file_extn,4,decInfo->fptr_stego_image)==e_failure)
    {
        return e_failure;
    }

    file_extn[4]='\0';

    printf("Decoded extension: %s\n",file_extn);

    return e_success;
}
Status decode_secret_file_size(long*file_size,DecodeInfo*decInfo)
{
    if(decode_data_from_image((char*)file_size,sizeof(long),decInfo->fptr_stego_image)==e_failure)
    {
        return e_failure;
    }

    printf("Decoded file size: %ld\n",*file_size);

    return e_success;
}
Status decode_secret_file_data(DecodeInfo*decInfo)
{
    char ch;

    for(long i=0;i<decInfo->size_secret_file;i++)
    {
        if(decode_data_from_image(&ch,1,decInfo->fptr_stego_image)==e_failure)
        {
            return e_failure;
        }

        fwrite(&ch,1,1,decInfo->fptr_output);
    }

    return e_success;
}
