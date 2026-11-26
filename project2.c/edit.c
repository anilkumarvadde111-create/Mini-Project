#include "edit.h"
#include <string.h>
#include <stdio.h>

void edit_mp3(MP3Info *info)
{
    int choice;

    printf("1. Edit Title\n2. Edit Artist\n3. Edit Album\n4. Edit Year\n5. Edit Genre\n6. Edit Comment\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Editing Title.\n");
            edit_title();
            break;

        case 2:
            printf("Editing Artist.\n");
            edit_artist();
            break;

        case 3:
            printf("Editing Album.\n");
            edit_album();
            break;

        case 4:
            printf("Editing Year.\n");
            edit_year();
            break;

        case 5:
            printf("Editing Genre.\n");
            edit_genre();
            break;

        case 6:
            printf("Editing Comment.\n");
            edit_comment();
            break;

        default:
            printf("Invalid choice\n");
    }

}
extern FILE *fp;

void edit_title()
{
    char title[100];

    printf("Enter new title: ");
    scanf(" %[^\n]", title);

    edit_tag("TIT2", title);
}

void edit_artist()
{
    char artist[100];

    printf("Enter new artist: ");
    scanf(" %[^\n]", artist);

    edit_tag("TPE1", artist);
}

void edit_album()
{
    char album[100];

    printf("Enter new album: ");
    scanf(" %[^\n]", album);

    edit_tag("TALB", album);
}

void edit_year()
{
    char year[10];

    printf("Enter new year: ");
    scanf(" %[^\n]", year);

    edit_tag("TYER", year);
}

void edit_genre()
{
    char genre[50];

    printf("Enter new genre: ");
    scanf(" %[^\n]", genre);

    edit_tag("TCON", genre);
}

void edit_comment()
{
    char comment[100];

    printf("Enter new comment: ");
    scanf(" %[^\n]", comment);

    edit_tag("COMM", comment);
}

void edit_tag(char *tag, char *new_data)
{
    unsigned char frame_id[5];
    unsigned char frame_size[4];
    int size;
    long data_position;
    char data[1024];

    fseek(fp, 10, SEEK_SET);

    while(fread(frame_id, 1, 4, fp) == 4)
    {
        frame_id[4] = '\0';

        if(fread(frame_size, 1, 4, fp) != 4)
            break;

        size = (frame_size[0] << 24) |
               (frame_size[1] << 16) |
               (frame_size[2] << 8) |
                 frame_size[3];

        fseek(fp, 2, SEEK_CUR);

        data_position = ftell(fp);

        if(strcmp((char *)frame_id, tag) == 0)
        {
            fread(data,1,size,fp);

            memset(data + 1,0,size - 1);
            strncpy(data + 1,new_data,size - 1);

            fseek(fp, data_position, SEEK_SET);
            fwrite(data,1,size,fp);

            fflush(fp);

            printf("Tag updated successfully\n");
            return;
        }

        fseek(fp, data_position + size, SEEK_SET);
    }

    printf("Tag not found\n");
}

