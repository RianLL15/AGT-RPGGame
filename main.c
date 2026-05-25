#include <stdio.h>
#include <string.h>
#include "Scenes/level-1.h"
#include "Scenes/Draw/draw.h"
#include "Clear_Screen/clear.h"

int main(){
    // //draw_menu_game();
    combat_scenes();
}

// rm jogo; gcc main.c Scenes/level-1.c Clear_Screen/clear.c Scenes/Draw/draw.c Scenes/Aux/aux.c -I . -o jogo && ./jogo 