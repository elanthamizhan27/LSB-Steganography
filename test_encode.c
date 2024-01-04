#include <stdio.h>
#include "encode.h"
#include "types.h"
#include "decode.h"

int main(int argc, char* argv[])
{
    EncodeInfo encInfo;
	DecodeInfo decInfo;
	if (argc < 2)
	{
		printf("./lsb_steg: Encoding: ./lsb_steg -e <.bmp_file> <.text_file> [output file]\n");
		printf("./lsb_steg: Decoding: ./lsb_steg -d <.bmp_file> [output file]");

	}
	else
	{
	if(check_operation_type(argv) == e_encode)   //validating the condition foe checking the operation type
	{
		if( argc == 4 || argc == 5 )
		{
		printf("INFO: Data encoding started\n");
		if (read_and_validate_encode_args(argv,&encInfo) == e_success) //validating the condition of read and validate
		{
			printf("INFO: read and validate is succussfull\n");
			
			if(do_encoding(&encInfo) == e_success)				//Validating the condition for encoding
			{
				printf("\n==== ENCODING DONE SUCCESSFULLY ====\n");
			}
			else
			{
				printf("ERROR: Encoding is failure\n");
			}
		}
		else
		{
			printf("ERROR: Validation is failure\n");
		}
		}
		else
			printf("./lsb_steg: Encoding: ./lsb_steg -e <.bmp_file> <.text_file> [output file]\n");
			
	}

	else if(check_operation_type(argv) == e_decode)   //validating the condition foe checking the operation type
	{
		if(argc == 4 || argc == 3 )
		{
		printf("INFO: Data decoding started\n");
		if (read_and_validate_decode_args(argv,&decInfo) == e_success)   //validating the condition read and validate
		{
			printf("INFO: read and validate is succussfull\n");
			if ( do_decoding(&decInfo) == e_success)   //validating the condition decoding
			{
				printf("\n==== DECODING DONE SUCCESSFULLY ====\n");
			}
			else
			{
				printf("ERROR: Decoding is failure\n");
			}
		}
		else
		{
			printf("ERROR: Validation is failure\n");
		}
		}
		else
			printf("./lsb_steg: Decoding: ./lsb_steg -d <.bmp_file> [output file]");

	}
	else
	{
		printf("ERROR: unsupported format\n");
	}
	

     return 0;
}
}
