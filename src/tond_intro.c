#include "global.h"
#include "main.h"
#include "palette.h"
#include "scanline_effect.h"
#include "task.h"
#include "title_screen.h"
#include "libgcnmultiboot.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "link.h"
#include "multiboot_pokemon_colosseum.h"
#include "load_save.h"
#include "save.h"
#include "new_game.h"
#include "m4a.h"
#include "random.h"
#include "decompress.h"
#include "constants/songs.h"
#include "intro_credits_graphics.h"
#include "trig.h"
#include "intro.h"
#include "graphics.h"
#include "sound.h"
#include "constants/species.h"
#include "util.h"
#include "title_screen.h"
#include "constants/rgb.h"
#include "constants/battle_anim.h"

#define TOND_SPRITE_TAG(sector) (1500 + sector - 1)
#define TOND_PAL_TAG(sector) (1500 + sector - 1)
#define TOND_OFFSET_X 94
#define TOND_OFFSET_Y 128
#define TOND_Y_ELEVATION 68
#define TOND_SECTOR_SEPARATION 48
#define CLOUDS_START_OFFSET 0x72
#define CLOUDS_END_OFFSET 0x32

#define TOND_FRAME_DELAY_1 (9)
#define TOND_FRAME_DELAY_2 (9)
#define TOND_FRAME_DELAY_3 (9)
#define TOND_FRAME_DELAY_4 (9)
#define TOND_FRAME_DELAY_5 (9)

#define LOGO_DELAY 101

#define LOGO_SCREENBASE 0
#define LOGO_CHARBASE 1

#define TOND_BG_SCREENBASE 16
#define TOND_BG_CHARBASE 1

#define LEFT_CLOUD_SCREENBASE 24
#define RIGHT_CLOUD_SCREENBASE 29
#define CLOUD_CHARBASE 0 

// external
extern u32 gIntroFrameCounter;

void Task_EndIntroMovie(u8);
void intro_reset_and_hide_bgs(void);

extern const struct SpriteTemplate gIntroRayquazaHyperbeamSprite;
extern const struct CompressedSpriteSheet gIntroRayquazaGlowSpriteSheet[];
extern const struct SpritePalette gIntroRayquazaGlowPalette[];

// this file's functions
void Task_LoadLogoScreenGraphics(u8);
static void Task_LogoScreenFadeIn(u8);
static void Task_LogoScreenFadeOut(u8);
void Task_LoadTondIntroGraphics(u8);
static void Task_TondIntroFadeIn(u8);
static void Task_TondIntroFadeOut(u8);
static void Task_IntroCloudSlideIn(u8);
static void Task_SpawnFlyingTond(u8);
static void sIntroFlyingTond_SpriteCallback(struct Sprite *sprite);
static void Task_End(u8);

//.rodata
const u16 sIntroLogo_Pal[] = INCBIN_U16("graphics/intro/intro_logo.gbapal");
const u32 sIntroLogo_Gfx[] = INCBIN_U32("graphics/intro/intro_logo.4bpp.lz");
const u32 sIntroLogo_Tilemap[] = INCBIN_U32("graphics/intro/intro_logo.bin.lz");
const u16 sTondIntroBG_Pal[] = INCBIN_U16("graphics/intro/tond_intro_bg.gbapal");
const u32 sTondIntroBG_Gfx[] = INCBIN_U32("graphics/intro/tond_intro_bg.4bpp.lz");
const u32 sTondIntroBG_Tilemap[] = INCBIN_U32("graphics/intro/tond_intro_bg.bin.lz");
const u32 sBars_Tilemap[] = INCBIN_U32("graphics/intro/bars.bin.lz");

const u32 sIntroFlyingTond_Gfx1[] = INCBIN_U32("graphics/intro/tond_sprite_sector1.4bpp.lz");
const u32 sIntroFlyingTond_Gfx2[] = INCBIN_U32("graphics/intro/tond_sprite_sector2.4bpp.lz");
const u32 sIntroFlyingTond_Gfx3[] = INCBIN_U32("graphics/intro/tond_sprite_sector3.4bpp.lz");
const u32 sIntroFlyingTond_Gfx4[] = INCBIN_U32("graphics/intro/tond_sprite_sector4.4bpp.lz");
const u16 sIntroFlyingTond_Pal1[] = INCBIN_U16("graphics/intro/tond_sprite_sector1.gbapal");
const u16 sIntroFlyingTond_Pal2[] = INCBIN_U16("graphics/intro/tond_sprite_sector2.gbapal");
const u16 sIntroFlyingTond_Pal3[] = INCBIN_U16("graphics/intro/tond_sprite_sector3.gbapal");
const u16 sIntroFlyingTond_Pal4[] = INCBIN_U16("graphics/intro/tond_sprite_sector4.gbapal");

static const struct CompressedSpriteSheet sIntroFlyingTond_SpriteSheet[] =
{   
    {sIntroFlyingTond_Gfx1, 0x2800, TOND_SPRITE_TAG(1)},
    {sIntroFlyingTond_Gfx2, 0x1400, TOND_SPRITE_TAG(2)},
    {sIntroFlyingTond_Gfx3, 0x1400, TOND_SPRITE_TAG(3)},
    {sIntroFlyingTond_Gfx4, 0xA00, TOND_SPRITE_TAG(4)},
    {NULL},
};

static const struct SpritePalette sIntroFlyingTond_SpritePal[] =
{
    {sIntroFlyingTond_Pal1, TOND_PAL_TAG(1)},
    {sIntroFlyingTond_Pal2, TOND_PAL_TAG(2)},
    {sIntroFlyingTond_Pal3, TOND_PAL_TAG(3)},
    {sIntroFlyingTond_Pal4, TOND_PAL_TAG(4)},
    {NULL},
};

//bekar koshish 
/**
static const struct SpritePalette sBlack_Pal[] =
{
    {sBlack, TOND_PAL_TAG(1)},
    {sBlack, TOND_PAL_TAG(2)},
    {sBlack, TOND_PAL_TAG(3)},
    {sBlack, TOND_PAL_TAG(4)},
    {NULL},
};
**/

static const struct OamData sIntroFlyingTondSector_Oam[] =
{
    {
        .y = 0,
        .affineMode = 0,
        .objMode = 0,
        .mosaic = 0,
        .bpp = 0,
        .shape = SPRITE_SHAPE(64x64),
        .x = 0,
        .matrixNum = 0,
        .size = SPRITE_SIZE(64x64),
        .tileNum = 0,
        .priority = 1,
        .paletteNum = 0,
        .affineParam = 0,
    },
    {
        .y = 0,
        .affineMode = 0,
        .objMode = 0,
        .mosaic = 0,
        .bpp = 0,
        .shape = SPRITE_SHAPE(32x64),
        .x = 0,
        .matrixNum = 0,
        .size = SPRITE_SIZE(32x64),
        .tileNum = 0,
        .priority = 1,
        .paletteNum = 0,
        .affineParam = 0,
    },
    {
        .y = 0,
        .affineMode = 0,
        .objMode = 0,
        .mosaic = 0,
        .bpp = 0,
        .shape = SPRITE_SHAPE(64x32),
        .x = 0,
        .matrixNum = 0,
        .size = SPRITE_SIZE(64x32),
        .tileNum = 0,
        .priority = 1,
        .paletteNum = 0,
        .affineParam = 0,
    },
    {
        .y = 0,
        .affineMode = 0,
        .objMode = 0,
        .mosaic = 0,
        .bpp = 0,
        .shape = SPRITE_SHAPE(32x32),
        .x = 0,
        .matrixNum = 0,
        .size = SPRITE_SIZE(32x32),
        .tileNum = 0,
        .priority = 1,
        .paletteNum = 0,
        .affineParam = 0,
    },
};

static const union AnimCmd sIntroFlyingTondSector1_Anim[] =
{
    ANIMCMD_FRAME(0, TOND_FRAME_DELAY_1),
    ANIMCMD_FRAME(64, TOND_FRAME_DELAY_2),
    ANIMCMD_JUMP(0),
	ANIMCMD_JUMP(4),
    ANIMCMD_FRAME(128, TOND_FRAME_DELAY_3),
    ANIMCMD_FRAME(192, TOND_FRAME_DELAY_4),
    ANIMCMD_FRAME(256, TOND_FRAME_DELAY_5),
    ANIMCMD_END,
};

static const union AnimCmd sIntroFlyingTondSector2_3_Anim[] =
{
    ANIMCMD_FRAME(0, TOND_FRAME_DELAY_1),
    ANIMCMD_FRAME(32, TOND_FRAME_DELAY_2),
    ANIMCMD_JUMP(0),
	ANIMCMD_JUMP(4),
    ANIMCMD_FRAME(64, TOND_FRAME_DELAY_3),
    ANIMCMD_FRAME(96, TOND_FRAME_DELAY_4),
    ANIMCMD_FRAME(128, TOND_FRAME_DELAY_5),
    ANIMCMD_END,
};

static const union AnimCmd sIntroFlyingTondSector4_Anim[] =
{
    ANIMCMD_FRAME(0, TOND_FRAME_DELAY_1),
    ANIMCMD_FRAME(16, TOND_FRAME_DELAY_2),
    ANIMCMD_JUMP(0),
	ANIMCMD_JUMP(4),
    ANIMCMD_FRAME(32, TOND_FRAME_DELAY_3),
    ANIMCMD_FRAME(48, TOND_FRAME_DELAY_4),
    ANIMCMD_FRAME(64, TOND_FRAME_DELAY_5),
    ANIMCMD_END,
};

static const union AnimCmd *const sIntroFlyingTondSector_Anims[][4] =
{
    {sIntroFlyingTondSector1_Anim},
    {sIntroFlyingTondSector2_3_Anim},
    {sIntroFlyingTondSector2_3_Anim},
    {sIntroFlyingTondSector4_Anim},
};

static const struct SpriteTemplate sIntroFlyingTond_Template1 =
{
    .tileTag = TOND_SPRITE_TAG(1),
    .paletteTag = TOND_PAL_TAG(1),
    .oam = &sIntroFlyingTondSector_Oam[0],
    .anims = sIntroFlyingTondSector_Anims[0],
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sIntroFlyingTond_SpriteCallback,
};

static const struct SpriteTemplate sIntroFlyingTond_Template2 =
{
    .tileTag = TOND_SPRITE_TAG(2),
    .paletteTag = TOND_PAL_TAG(2),
    .oam = &sIntroFlyingTondSector_Oam[1],
    .anims = sIntroFlyingTondSector_Anims[1],
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sIntroFlyingTond_SpriteCallback,
};

static const struct SpriteTemplate sIntroFlyingTond_Template3 =
{
    .tileTag = TOND_SPRITE_TAG(3),
    .paletteTag = TOND_PAL_TAG(3),
    .oam = &sIntroFlyingTondSector_Oam[2],
    .anims = sIntroFlyingTondSector_Anims[2],
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sIntroFlyingTond_SpriteCallback,
};
static const struct SpriteTemplate sIntroFlyingTond_Template4 =
{
    .tileTag = TOND_SPRITE_TAG(4),
    .paletteTag = TOND_PAL_TAG(4),
    .oam = &sIntroFlyingTondSector_Oam[3],
    .anims = sIntroFlyingTondSector_Anims[3],
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = sIntroFlyingTond_SpriteCallback,
};

void Task_LoadLogoScreenGraphics(u8 taskId)
{
    u8 spriteId;
    
    // Reset background registers
    intro_reset_and_hide_bgs();
    
    // Load logo graphics and palette
    LZ77UnCompVram(sIntroLogo_Gfx, (void *)BG_CHAR_ADDR(LOGO_CHARBASE));
    LZ77UnCompVram(sIntroLogo_Tilemap, (void *)BG_SCREEN_ADDR(LOGO_SCREENBASE));
    LoadPalette(sIntroLogo_Pal, 0, 0x20);
    
    // Setup background control registers
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(1) 
                | BGCNT_CHARBASE(LOGO_CHARBASE)
                | BGCNT_SCREENBASE(LOGO_SCREENBASE)
                | BGCNT_16COLOR
                | BGCNT_TXT256x256);


    gTasks[taskId].func = Task_LogoScreenFadeIn;
}


static void Task_LogoScreenFadeIn(u8 taskId)
{
	//m4aSongNumStart(MUS_RG_TITLEROG);
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_OBJ_ON);
    gTasks[taskId].func = Task_LogoScreenFadeOut;
    gIntroFrameCounter = 0;
}

static void Task_LogoScreenFadeOut(u8 taskId)
{
    if (gIntroFrameCounter == 84)
		BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB(0, 0, 0));
    if (gIntroFrameCounter == 141)
	{
		gTasks[taskId].func = Task_LoadTondIntroGraphics;
	}
}

void Task_LoadTondIntroGraphics(u8 taskId)
{
    if(!gPaletteFade.active) {
        u8 spriteId;
        
        // Reset background registers
        intro_reset_and_hide_bgs();
        
        // Clear logo data
        CpuFill32(0, (void *)BG_CHAR_ADDR(LOGO_CHARBASE), BG_CHAR_SIZE);
        CpuFill32(0, (void *)BG_SCREEN_ADDR(LOGO_SCREENBASE), BG_SCREEN_SIZE);

        // Load clouds palette
        CpuCopy16(gIntro3BgPal, gPlttBufferUnfaded, sizeof(gIntro3BgPal));
        
        // Load tond background
        
        LZ77UnCompVram(sTondIntroBG_Gfx, (void *)BG_CHAR_ADDR(TOND_BG_CHARBASE));
        LZ77UnCompVram(sTondIntroBG_Tilemap, (void *)BG_SCREEN_ADDR(TOND_BG_SCREENBASE));

		// Load bars
		
		LZ77UnCompVram(sTondIntroBG_Gfx, (void *)BG_CHAR_ADDR(TOND_BG_CHARBASE));
        LZ77UnCompVram(sBars_Tilemap, (void *)BG_SCREEN_ADDR(20));
		
        // Load tond background palette
        LoadPalette(sTondIntroBG_Pal, 0, 0x20); 
        
        // Load clouds background
        LZDecompressVram(gIntro3CloudsGfx, (void *)(BG_CHAR_ADDR(CLOUD_CHARBASE)));
        LZDecompressVram(gIntro3Clouds1Tilemap, (void *)(BG_SCREEN_ADDR(LEFT_CLOUD_SCREENBASE)));
        LZDecompressVram(gIntro3Clouds2Tilemap, (void *)(BG_SCREEN_ADDR(RIGHT_CLOUD_SCREENBASE)));
        
        // Setup background control registers
        SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(2) 
                    | BGCNT_CHARBASE(TOND_BG_CHARBASE)
                    | BGCNT_SCREENBASE(TOND_BG_SCREENBASE)
                    | BGCNT_16COLOR
                    | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                                | BGCNT_CHARBASE(CLOUD_CHARBASE)
                                | BGCNT_SCREENBASE(LEFT_CLOUD_SCREENBASE)
                                | BGCNT_16COLOR
                                | BGCNT_TXT512x256);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(1)
                                | BGCNT_CHARBASE(CLOUD_CHARBASE)
                                | BGCNT_SCREENBASE(RIGHT_CLOUD_SCREENBASE)
                                | BGCNT_16COLOR
                                | BGCNT_TXT512x256);    
        SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(0)
                                | BGCNT_CHARBASE(TOND_BG_CHARBASE)
                                | BGCNT_SCREENBASE(20)
                                | BGCNT_16COLOR
                                | BGCNT_TXT256x256);   								
								
        SetGpuReg(REG_OFFSET_BG1HOFS, CLOUDS_START_OFFSET);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, -CLOUDS_START_OFFSET);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);

        // Load flying tond sprite sectors
        for (spriteId = 0; spriteId < 4; spriteId++)
        {
            LoadCompressedSpriteSheet(&sIntroFlyingTond_SpriteSheet[spriteId]);
        }

        // Load tond sprite sector palettes
        LoadSpritePalettes(sIntroFlyingTond_SpritePal);

        LoadCompressedSpriteSheet(gIntroRayquazaGlowSpriteSheet);
        LoadSpritePalettes(gIntroRayquazaGlowPalette);
        
        gTasks[taskId].func = Task_TondIntroFadeIn;
    }
}


static void Task_TondIntroFadeIn(u8 taskId)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP |
                     DISPCNT_BG0_ON | DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON);
	m4aSongNumStart(MUS_DRAGONITE);
    gTasks[taskId].func = Task_SpawnFlyingTond;
    gIntroFrameCounter = 0;
}

static void Task_SpawnFlyingTond(u8 taskId)
{
    u8 sprCounter;
    s16 *data = gTasks[taskId].data;

    data[0] = CreateSprite(&sIntroFlyingTond_Template1, TOND_OFFSET_X, TOND_OFFSET_Y, 0);
    data[1] = CreateSprite(&sIntroFlyingTond_Template2, TOND_OFFSET_X + TOND_SECTOR_SEPARATION, TOND_OFFSET_Y, 0);
    data[2] = CreateSprite(&sIntroFlyingTond_Template3, TOND_OFFSET_X, TOND_OFFSET_Y + TOND_SECTOR_SEPARATION, 0);
    data[3] = CreateSprite(&sIntroFlyingTond_Template4, TOND_OFFSET_X + TOND_SECTOR_SEPARATION, TOND_OFFSET_Y + TOND_SECTOR_SEPARATION, 0);
    for(sprCounter = 0; sprCounter < 4; sprCounter++) {
        gSprites[data[sprCounter]].data[0] = 0;
        gSprites[data[sprCounter]].data[1] = FALSE;
        gSprites[data[sprCounter]].data[3] = -1;
    }
    
    gSprites[data[0]].data[3] = taskId;
    
    gTasks[taskId].func = Task_IntroCloudSlideIn;
    data[6] = CLOUDS_START_OFFSET + 20;
}

static void Task_IntroCloudSlideIn(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    SetGpuReg(REG_OFFSET_BG1HOFS, (data[6] / 2));
    SetGpuReg(REG_OFFSET_BG2HOFS, -(data[6] / 2));
    if (--data[6] == CLOUDS_END_OFFSET + 20)
    {   
        gIntroFrameCounter = 0;
        gTasks[taskId].func = Task_TondIntroFadeOut;
    }
}

static void Task_TondIntroFadeOut(u8 taskId)
{
    if (gIntroFrameCounter == 95)
	{ 
		SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP |
        DISPCNT_BG0_ON | DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_ON);
	    FillPalette(RGB_WHITE, 1, 0x1F); 
		BeginNormalPaletteFade(0xFFFFFFE, 3, 0, 16, RGB(0, 0, 0));
	}
	
	if ((gIntroFrameCounter >= 214) && !gPaletteFade.active)
	{
        FillPalette(RGB_BLACK, 0x10, PLTT_SIZE - 0x20);
		BeginNormalPaletteFade(0xFFFFFFFF, 4, 0, 16, RGB_WHITE); 
		gIntroFrameCounter = 0;
		gTasks[taskId].func = Task_End;
	}
}

static void Task_End(u8 taskId)
{
	if (gIntroFrameCounter >= 80)
		gTasks[taskId].func = Task_EndIntroMovie;		
}

static void sIntroFlyingTond_SpriteCallback(struct Sprite *sprite) {

    if(++sprite->data[0] <= TOND_Y_ELEVATION) {
		if(sprite->pos1.y % 23 == 0 && sprite->data[3] != -1)
		{
			PlaySE(SE_BAN);
		}
		--sprite->pos1.y;
    }
    else {
        if(!sprite->data[1]) {
            sprite->data[1] = TRUE; 
            sprite->animCmdIndex=3;
        }
        if(sprite->data[3] != -1 && !sprite->data[6] && sprite->animCmdIndex==6) {
			PlayCryInternal(SPECIES_DRAGONITE, 0, 120, 10, 0);
            sprite->data[6] = CreateSprite(&gIntroRayquazaHyperbeamSprite, 110, 82, 25);
			PlaySE(SE_OP_BASYU);
        }
    }
}