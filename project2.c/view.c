#include "view.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void view_mp3(MP3Info *info)
{
    extern FILE *fp;

unsigned char frame_id[5];
unsigned char frame_size[4];
unsigned char flag[2];

 while(1)
 {
    unsigned int size;
    char *data;

    if(fread(frame_id,1,4,fp) != 4)
       break;

       frame_id[4]='\0';
    if(fread(frame_size,1,4,fp) != 4)
      break;
    if(fread(flag,1,2,fp) != 2) 
      break;  
    
     size=(frame_size[0]<<24) | (frame_size[1]<<16) | (frame_size[2]<<8) | frame_size[3];

    data=malloc(size+1);

    if(data == NULL)
    {
        perror("");
        break;
    }

    if(fread(data,1,size,fp) != size)
    {
        free(data);
        break;
    }
    data[size]='\0';

    if(strcmp(frame_id, "TIT2") == 0)
    {
        printf("Title : %s\n", data + 1);
    }
    else if(strcmp(frame_id, "TPE1") == 0)
    {
        printf("Artist : %s\n", data + 1);
    }
    else if(strcmp(frame_id, "TALB") == 0)
    {
        printf("Album : %s\n", data + 1);
    }
    else if(strcmp(frame_id, "TYER") == 0)
    {
        printf("Year  : %s\n", data + 1);
    }
    else if(strcmp(frame_id, "TCON") == 0)
    {
        printf("Genre : %s\n", data + 1);
    }
    else if(strcmp(frame_id, "COMM") == 0)
    {
        printf("Comment : %s\n", data + 1);
    }


    free(data);
 }

}