#include "gba.h"
#include <string.h>

#include "BG_Externs.h"

int main()
{

	register_vblank_isr();
	//set GBA rendering context to MODE 0 Tile Rendering and enable 1D sprites enable backgrounds 0 & 1
	REG_DISPCNT = VIDEOMODE_0 | ENABLE_OBJECTS | MAPPING_MODE_1D | BGMODE_0 | BGMODE_1;
	//copy sprite palette into sprite palette memory
	memcpy( PAL_BG_MEM, bgPalette, bgPaletteSize);
	//There is enough memory to copy all tiles into memory for this exercise
	u16* tileblock = getBGTileBlock(1);
	//copy the BG tiles into tile memory
	memcpy( tileblock, bgTiles, bgTilesSize);
	//copy maps
	copy64x32MapIntoMemory( bgMapLayer0, 16);
	//copy64x32MapIntoMemory( bgMapLayer1, 18);

	//set up Background controllers for each layer
	REG_BGCNT[0] = setBGControlRegister( 1, 1, 0, 0, 16, 0, BG_REG_SIZE_64x32);
	//REG_BGCNT[1] = setBGControlRegister( 0, 0, 0, 0, 18, 0, BG_REG_SIZE_64x32);

	s32 x = 0;
	s32 y = 0;
	while (1) { //loop forever
		vblank_intr_wait();
		PollKeys();
		s32 countVal = vblank_Counter;
		//loopCounter++;
		x += getAxis(HORIZONTAL);
		y -= getAxis(VERTICAL);
		REG_BG_OFFSET[0].x = x;
		REG_BG_OFFSET[0].y = y;
		REG_BG_OFFSET[1].x = x;
		REG_BG_OFFSET[1].y = y;
	}
	return 0;
}
