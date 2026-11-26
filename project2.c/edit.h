#ifndef EDIT_H
#define EDIT_H

#include "titles.h"

void edit_mp3(MP3Info *info);
void edit_title();
void edit_artist();
void edit_album();
void edit_year();
void edit_genre();
void edit_comment();
void edit_tag(char *tag,char *new_data);

#endif
