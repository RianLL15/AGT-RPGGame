#include <stdio.h>
#include <string.h>
#include "Cenas/level-1.h"
#include "Cenas/Desenho/desenho.h"
#include "Limpar_tela/limpar.h"

int main(){
    // desenhar_menu_game();
    cena_de_combate();

    return 0;
}

// Código a abaixo é para rodar o código no terminal

// gcc main.c Cenas/level-1.c Limpar_tela/limpar.c Cenas/Desenho/desenho.c Cenas/Auxiliar_Combate/auxiliar_combate.c -I . -o jogo && ./jogo