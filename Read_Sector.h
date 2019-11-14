/* Names: Tyler Andrews, Brennan Campbell, and Tyler Tetens
 * Title: Experiment #4 - Fat File System
 */

#ifndef READ_SECTOR_H
#define READ_SECTOR_H

#include "Main.h"

/*
 *
 *
 *
*/
uint8_t Read_Sector(uint32_t sector_number, uint16_t sector_size, uint8_t * array_for_data);

#endif

