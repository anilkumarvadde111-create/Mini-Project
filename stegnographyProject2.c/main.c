#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encode.h"
#include "decode.h"
#include "types.h"


int main(int argc, char *argv[])
{
    EncodeInfo encInfo;
    DecodeInfo decInfo;

if(check_operation_type(argv)==e_encode)
  {
    if(argc<5)
    {
        printf("Insufficient arguments\n");
        return e_failure;
    }

    printf("You chose the encoding option\n");

    if(read_and_validate_encode_args(argv,&encInfo)==e_success)
    {
        printf("Read and validation successful\n");

        printf("Enter magic string: ");
        scanf("%19s",encInfo.magic_string);

        if(do_encoding(&encInfo)==e_success)
        {
            printf("Encoding successful\n");
        }
        else
        {
            printf("Encoding failed\n");
            return e_failure;
        }
    }
    else
    {
        printf("Read and validation failed\n");
        return e_failure;
    }
  }
  else if(check_operation_type(argv)==e_decode)
  {
    if(argc<4)
    {
        printf("Insufficient arguments\n");
        return e_failure;
    }

    printf("You chose the decoding option\n");

    if(read_and_validate_decode_args(argv,&decInfo)==e_success)
    {
        printf("Read and validation successful\n");

        printf("Enter magic string: ");
        scanf("%19s",decInfo.magic_string);

        if(do_decoding(&decInfo)==e_success)
        {
            printf("Decoding successful\n");
        }
        else
        {
            printf("Decoding failed\n");
            return e_failure;
        }
    }
    else
    {
        printf("Read and validation failed\n");
        return e_failure;
    }
   
  }
  else
  {
    printf("Invalid input\n");
    printf("./a.out -e beautiful.bmp secret.txt stego.bmp\n");
    printf("./a.out -d stego.bmp output.txt\n");
    return e_failure;
  }

  return 0;
}

OperationType check_operation_type(char *argv[])
{
    if (strcmp(argv[1], "-e") == 0)
    {
        return e_encode;
    }
    else if (strcmp(argv[1], "-d") == 0)
    {
        return e_decode;
    }
    else
    {
        return e_unsupported;
    }
}

