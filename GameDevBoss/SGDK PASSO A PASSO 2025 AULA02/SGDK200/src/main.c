#include <genesis.h>

#include "gfx.h"
#include "dma.h"


//DECLARACAO DE VARIAVEIS
u8 gRoom; //sala atual
u32 gFrames; //frames atuais
u16 gInd_tileset; //indice do tileset para carregar background


// Esta função carrega o tileset de um recurso Image para a VRAM.
// Ela recebe um ponteiro para a Image e um ponteiro para o índice de tile da VRAM.
// O índice de tile da VRAM é atualizado para apontar para depois dos tiles carregados.
//VDP_loadTileSet(const TileSet *tileset, u16 index, TransferMethod tm)
void setTileSetB(Image image, u16 index, TransferMethod tm)
{
    VDP_loadTileSet(gfx_logo.tileset, gInd_tileset, DMA);
    VDP_setTileMapEx(BG_A, gfx_logo.tilemap, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, gInd_tileset), 0, 0, 0, 0, 40, 28, DMA_QUEUE);
    PAL_setPalette(PAL1, gfx_logo.palette->data, DMA);
    gInd_tileset += gfx_logo.tileset->numTile;
}

int main(bool hard)
{
    gRoom = 1; //inicializa a sala
    gFrames = 0;
    gInd_tileset = 0; //inicializa o indice do tileset

    
    while(TRUE)
    {
        gFrames++;

        if(gRoom == 1)
    {
        if(gFrames == 1)
        {
            setTileSet(gfx_logo, gInd_tileset, DMA);
        }
       
    }

        //DEBUG
        char str[64];
        sprintf(str, "Tiles Total: %d", gInd_tileset);
        VDP_drawText(str, 1, 1);
        sprintf(str, "Frame Atual: %ld", gFrames);
        VDP_drawText(str, 1, 2);
        SYS_doVBlankProcess();
    }

    return 0;
}



