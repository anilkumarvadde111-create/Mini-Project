#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "titles.h"
#include "view.h"
#include "edit.h"


FILE *fp;
int main(int argc, char *argv[])
{
    MP3Info info;
    
    unsigned char header[10];

    if(argc<2)
    {
        printf("ERROR: Insufficient argument count!\n");
        return 0;
    }

    if (strcmp(argv[1], "-v") == 0)
    {
    printf("View operation selected\n");
    }
    else if (strcmp(argv[1], "-e") == 0)
    {
    printf("Edit operation selected\n");
    } 
    else if(strcmp(argv[1],"-h")==0)
    {
        printf("Display help\n");
    }
     else
    {
    printf("ERROR: Invalid option\n");
    printf("Use -v for View or -e for Edit\n");
    return 1;
    } 

    
     if(argc<3)
    {
      printf("ERROR: Please pass the MP3 file\n");
      printf("Usage: ./a.out -v <file.mp3>\n");
      printf("Usage: ./a.out -e <file.mp3>\n");           //chek if file is passed or not as cmdline args 
      return 1;
    }

    fp=fopen(argv[2],"rb+");
    if(fp==NULL)
    {
        perror("");
        return 0;
    }
    
    if(fread(header,1,10,fp) !=10)        //if header size is not 10bytes then not able to read the file
    {
        printf("Not able to read ID3 header !\n");
        fclose(fp);
        return 1;
    }
    if(header[0] != 'I'|| header[1] != 'D'||header[2] !='3')
    {
        printf("ID3 tag not found !\n");
        return 1;
    }
    printf("ID3 tag found\n");

    printf("ID3 version 2.%d.%d\n",header[3],header[4]);
    printf("Flag : 0x%02X\n",header[5]);


    if (strcmp(argv[1], "-v") == 0)
    {
        view_mp3(&info);
    }
    else if (strcmp(argv[1], "-e") == 0)
    {
        edit_mp3(&info);
    }
    fclose(fp);

    return 0;
}