#include "gba_map.h"

#include "BG_Externs.h"

void copy64x32MapIntoMemory( const u16* a_mapData, u16 a_mapBlockAddress )
{
	//get a pointer to the map Ed data we want to convert pages for
	HALF_ROW* src = (HALF_ROW*)a_mapData;
	//a 32x32 map occupies one address space (32x16 bits no$gba demo's this well)
	//a 64x32 map occupies two address spaces, 64x64 occupies four address spaces
	HALF_ROW* dst0 = (HALF_ROW*)getBGMapBlock(a_mapBlockAddress);
	HALF_ROW* dst1 = (HALF_ROW*)getBGMapBlock(a_mapBlockAddress+1);
	//as there are 32 tiles per page row the following loop can be used.
	//I am taking advantage of post increment here. The assignment operator happens
	//before the increment operator
	for( u32 i = 0; i < 32; ++i)
	{
		//copy row i of the left page
		*dst0++ = *src++;   *dst0++ = *src++;
		//copy row i of the right page
		*dst1++ = *src++;   *dst1++ = *src++;
	}
}