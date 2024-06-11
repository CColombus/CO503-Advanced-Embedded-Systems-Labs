#ifndef ENCODER_H
#define ENCODER_H

#include "datatype.h"
#include "config.h"

extern UINT8 Lqt[BLOCK_SIZE];
extern UINT8 Cqt[BLOCK_SIZE];
extern UINT16 ILqt[BLOCK_SIZE];
extern UINT16 ICqt[BLOCK_SIZE];

extern INT16 Y1[BLOCK_SIZE];
extern INT16 Y2[BLOCK_SIZE];
extern INT16 Y3[BLOCK_SIZE];
extern INT16 Y4[BLOCK_SIZE];
extern INT16 CB[BLOCK_SIZE];
extern INT16 CR[BLOCK_SIZE];
extern INT16 Temp[BLOCK_SIZE];
extern UINT32 lcode;
extern UINT16 bitindex;

extern void (*read_format)(JPEG_ENCODER_STRUCTURE *jpeg_encoder_structure, UINT8 *input_ptr);

void initialization(JPEG_ENCODER_STRUCTURE *jpeg, UINT32 image_format, UINT32 image_width, UINT32 image_height);
UINT8 *encode_image(UINT8 *input_ptr, UINT8 *output_ptr, UINT32 quality_factor, UINT32 image_format, UINT32 image_width, UINT32 image_height);
UINT8 *encodeMCU(JPEG_ENCODER_STRUCTURE *jpeg_encoder_structure, UINT32 image_format, UINT8 *output_ptr);

#endif /* ENCODER_H */