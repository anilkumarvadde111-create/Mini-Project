#ifndef DECODE_H
#define DECODE_H

#include "types.h"


#define MAX_FILE_SUFFIX 5

typedef struct _DecodeInfo
{
    char*stego_image_fname;
    FILE*fptr_stego_image;

    uint image_capacity;
    
    char*output_fname;
    FILE*fptr_output;

    char extn_secret_file[MAX_FILE_SUFFIX];
    long size_secret_file;

    char magic_string[20];

}DecodeInfo;

OperationType check_operation_type(char*argv[]);

Status read_and_validate_decode_args(char*argv[],DecodeInfo*decInfo);

Status do_decoding(DecodeInfo*decInfo);

Status open_decode_files(DecodeInfo*decInfo);

Status decode_magic_string(char*magic_string,DecodeInfo*decInfo);

Status decode_secret_file_extn(char*file_extn,DecodeInfo*decInfo);

Status decode_secret_file_size(long*file_size,DecodeInfo*decInfo);

Status decode_secret_file_data(DecodeInfo*decInfo);

Status decode_data_from_image(char*data,int size,FILE*fptr_stego_image);

Status decode_byte_from_lsb(char*data,char*image_buffer);

#endif