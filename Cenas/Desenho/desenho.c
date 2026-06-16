#include <stdio.h>
#include <string.h>

void bar_life(int tamanhoA, int Hp){
    int barra = (Hp * tamanhoA)/ 100; 
    int vazia = tamanhoA - barra;
    
    for(int i = 0; i < barra; i++){
        printf("|"); 
    }

    for(int i = 0; i < vazia; i++){
        printf(" ");
    }
    
}

void draw_HpB(int HpP, int HpI) {
    int tamanho = 15;

    printf("╭─────────────────────────────────────────────────────────────────────────────────╮\n");
    printf("  Player  {-"); 
    bar_life(tamanho, HpP); 
    printf("-} %3d%%", HpP);
    printf("   VS.   ");
    printf("Opponent  {-"); 
    bar_life(tamanho, HpI); 
    printf("-} %3d%%", HpI);
    printf("\n╰─────────────────────────────────────────────────────────────────────────────────╯\n\n");

}

void draw_combate() {
    printf("                    O                                       [O]         \n");
    printf("                    |                                        |          \n");
    printf("                   /|\\                                      /|\\       \n");
    printf("                  / | \\                                    / | \\      \n");
    printf("                   / \\                                      / \\       \n");
    printf("                  /   \\                                    /   \\      \n\n");
}

void draw_menu_op(int botao_pressionado) {

    printf("\n Escolha sua ação: \n");

    //Linha 1
    if(botao_pressionado == 1) printf("             "); else printf(" ____________");
    if(botao_pressionado == 2) printf("                 "); else printf("     ____________");
    if(botao_pressionado == 3) printf("                 \n"); else printf("     ____________\n");

    //Linha 2
    if(botao_pressionado == 1) printf(" ____________    "); else printf("||1  Block  ||   ");
    if(botao_pressionado == 2) printf(" ____________    "); else printf("||2  Attack ||   ");
    if(botao_pressionado == 3) printf(" ____________\n"); else printf("||3  Items  ||   \n");

    //Linha 3
    if(botao_pressionado == 1) printf("||1  Block  ||   "); else printf("||__________||   ");
    if(botao_pressionado == 2) printf("||2  Attack ||   "); else printf("||__________||   ");
    if(botao_pressionado == 3) printf("||3  Items  ||   \n"); else printf("||__________||   \n");

    //Linha 4
    printf("|/__________\\|   |/__________\\|   |/__________\\|        \n");
    
}

void draw_option_select(int p_op, int c_op){
    printf("\nVoce: %d | Inimigo: %d\n", p_op, c_op);
}

int draw_backpack(){

}

void draw_menu_game() {
    printf("                   __  __                                           \n");
    printf(" /'\\_/`\\          /\\ \\/\\ \\                                    \n");
    printf("/\\      \\         \\ \\  `\\ \\                                   \n");
    printf("\\ \\ \\__\\ \\         \\ \\ , ` \\                                \n");
    printf(" \\ \\ \\_/\\ \\   ____  \\ \\ \\`\\ \\   __  __                    \n");
    printf("  \\ \\_\\\\ \\_\\ /\\  _   \\ \\_\\ \\_\\ /\\ \\/\\ \\             \n");
    printf("   \\/_/ \\/_/ \\ \\ \\L\\_ \\/_/\\/_/ \\ \\ \\ \\ \\               \n");
    printf("              \\ \\  _\\L          \\ \\ \\ \\ \\                   \n");
    printf("               \\ \\ \\L\\           \\ \\ \\_\\ \\                 \n");
    printf("                \\ \\____/          \\ \\_____\\                    \n");
    printf("                 \\/___/            \\/_____/                       \n");
}