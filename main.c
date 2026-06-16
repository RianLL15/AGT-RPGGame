#include <stdio.h>
#include <string.h>
#include "Cenas/level-1.h"
#include "Cenas/Desenho/desenho.h"
#include "Limpar_tela/limpar.h"

int main(){
    // desenhar_menu_game();
    cena_de_combate();
}

// rm jogo; gcc main.c Scenes/level-1.c Clear_Screen/clear.c Scenes/Draw/draw.c Scenes/Aux/aux.c -I . -o jogo && ./jogo 