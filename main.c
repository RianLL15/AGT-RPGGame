#include <stdio.h>
#include <string.h>
#include "Cenas/level-1.h"
#include "Cenas/Desenho/desenho.h"
#include "Limpar_tela/limpar.h"

int main(){
    // desenhar_menu_game();
    cena_de_combate();
}

// rm jogo; gcc main.c Cenas/level-1.c Limpar_tela/limpar.c Cenas/Desenho/desenho.c Cenas/Auxixiliar_combate/auxiliar_combate.c -I . -o jogo && ./jogo