#include "encoder.h"

#include "config.h"
// #include "prototype.h"
#include "datatype.h"
#include "readYUV.h"

#include "mem_info.h"

#include "queue_wrapper.h"

void initialization(JPEG_ENCODER_STRUCTURE *jpeg, UINT32 image_format, UINT32 image_width, UINT32 image_height)
{
	UINT16 mcu_width, mcu_height, bytes_per_pixel;

	jpeg->mcu_width = mcu_width = 8;
	jpeg->mcu_height = mcu_height = 8;

	jpeg->horizontal_mcus = (UINT16)((image_width + mcu_width - 1) >> 3);
	jpeg->vertical_mcus = (UINT16)((image_height + mcu_height - 1) >> 3);

	bytes_per_pixel = 3;
	// read_format = read_444_format;

	jpeg->rows_in_bottom_mcus = (UINT16)(image_height - (jpeg->vertical_mcus - 1) * mcu_height);
	jpeg->cols_in_right_mcus = (UINT16)(image_width - (jpeg->horizontal_mcus - 1) * mcu_width);

	jpeg->length_minus_mcu_width = (UINT16)((image_width - mcu_width) * bytes_per_pixel);
	jpeg->length_minus_width = (UINT16)((image_width - jpeg->cols_in_right_mcus) * bytes_per_pixel);

	jpeg->mcu_width_size = (UINT16)(mcu_width * bytes_per_pixel);

	if (image_format != FOUR_TWO_ZERO)
		jpeg->offset = (UINT16)((image_width * (mcu_height - 1) - (mcu_width - jpeg->cols_in_right_mcus)) * bytes_per_pixel);
	else
		jpeg->offset = (UINT16)((image_width * ((mcu_height >> 1) - 1) - (mcu_width - jpeg->cols_in_right_mcus)) * bytes_per_pixel);

	jpeg->ldc1 = 0;
	jpeg->ldc2 = 0;
	jpeg->ldc3 = 0;
}

UINT8 *encode_image(UINT8 *input_ptr, UINT8 *output_ptr, UINT32 quality_factor, UINT32 image_format, UINT32 image_width, UINT32 image_height)
{
	UINT16 i, j;

	JPEG_ENCODER_STRUCTURE JpegStruct;
	JPEG_ENCODER_STRUCTURE *jpeg_encoder_structure = &JpegStruct;

	if (image_format == RGB)
	{
		image_format = FOUR_FOUR_FOUR;
	}

	initialization(jpeg_encoder_structure, image_format, image_width, image_height);

	// ! Depecrecated infavor of mem_info
	// SEND4((jpeg_encoder_structure->vertical_mcus) * (jpeg_encoder_structure->horizontal_mcus));
	// SEND4(quality_factor);

	// SEND5(image_width);
	// SEND5(image_height);
	// SEND5((jpeg_encoder_structure->vertical_mcus) * (jpeg_encoder_structure->horizontal_mcus));

	setMemInfo((jpeg_encoder_structure->vertical_mcus) * (jpeg_encoder_structure->horizontal_mcus), image_width, image_height, quality_factor, image_format);

	for (i = 1; i <= jpeg_encoder_structure->vertical_mcus; i++)
	{
		if (i < jpeg_encoder_structure->vertical_mcus)
			jpeg_encoder_structure->rows = jpeg_encoder_structure->mcu_height;
		else
			jpeg_encoder_structure->rows = jpeg_encoder_structure->rows_in_bottom_mcus;

		for (j = 1; j <= jpeg_encoder_structure->horizontal_mcus; j++)
		{
			if (j < jpeg_encoder_structure->horizontal_mcus)
			{
				jpeg_encoder_structure->cols = jpeg_encoder_structure->mcu_width;
				jpeg_encoder_structure->incr = jpeg_encoder_structure->length_minus_mcu_width;
			}
			else
			{
				jpeg_encoder_structure->cols = jpeg_encoder_structure->cols_in_right_mcus;
				jpeg_encoder_structure->incr = jpeg_encoder_structure->length_minus_width;
			}

			read_444_format(jpeg_encoder_structure, input_ptr);

			input_ptr += jpeg_encoder_structure->mcu_width_size;

// #pragma flush
		}

		input_ptr += jpeg_encoder_structure->offset;
	}

	return output_ptr;
}