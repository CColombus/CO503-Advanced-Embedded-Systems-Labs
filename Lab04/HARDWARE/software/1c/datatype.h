#ifndef DATATYPE_H
#define DATATYPE_H

typedef char INT8;
typedef unsigned char UINT8;

typedef short INT16;
typedef unsigned short UINT16;

typedef int INT32;
typedef unsigned int UINT32;

typedef struct JPEG_ENCODER_STRUCTURE
{
	UINT16 mcu_width;
	UINT16 mcu_height;
	UINT16 horizontal_mcus;
	UINT16 vertical_mcus;
	UINT16 cols_in_right_mcus;
	UINT16 rows_in_bottom_mcus;

	UINT16 rows;
	UINT16 cols;

	UINT16 length_minus_mcu_width;
	UINT16 length_minus_width;
	UINT16 incr;
	UINT16 mcu_width_size;
	UINT16 offset;

	INT16 ldc1;
	INT16 ldc2;
	INT16 ldc3;

} JPEG_ENCODER_STRUCTURE;

#endif
