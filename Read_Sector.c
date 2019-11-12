#include "Read_Sector.h"
#include "SPI.h"
#include "SDCard.h"
#include <stdio.h>

#define No_Disk_Error 0x00
#define Disk_Error 0x01

uint8_t Read_Sector(uint32_t sector_number,uint16_t sector_size, uint8_t * array_for_data)
{
	uint8_t SDtype,error_flag=No_Disk_Error;

	SDtype=Return_SD_Card_Type(); // HC=0, no change to sector number
// SC=9, multiplies sector number by 512 to convert to byte addr.
	SPI_Select_Clear(SD_Card_Select);
	error_flag=SEND_COMMAND(17,(sector_number<<SDtype));
	if(error_flag==no_errors) 
	{
		error_flag=read_block(sector_size, array_for_data);
	}
	SPI_Select_Set(SD_Card_Select);
	if(error_flag!=no_errors)
	{
		error_flag=Disk_Error;
	}
	return error_flag;
}

