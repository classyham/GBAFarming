#ifndef GBA_MAP_H
#define GBA_MAP_H

#include "gba_macros.h"
#include "gba_types.h"
#include "gba_bios.h"
#include "gba_gfx.h"
#include "gba_drawing.h"
#include "gba_mathUtil.h"
#include "gba_input.h"

typedef struct {u32 data[8]; } HALF_ROW;

extern void copy64x32MapIntoMemory( const u16* a_mapData, u16 a_mapBlockAddress );

#endif //GBA_MAP_H