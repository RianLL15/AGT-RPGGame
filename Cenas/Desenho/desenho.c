#include <stdio.h>
#include <string.h>

void barra_de_vida(int tamanhoAtual, int vida){
    int barra = (vida * tamanhoAtual)/ 100; 
    int vazia = tamanhoAtual - barra;
    
    for(int i = 0; i < barra; i++){
        printf("|"); 
    }

    for(int i = 0; i < vazia; i++){
        printf(" ");
    }
    
}

void desenho_barra_vida(int vidaJogador, int vidaComputador) {
    int tamanho = 15;

    printf("╭─────────────────────────────────────────────────────────────────────────────────╮\n");
    printf("  Player  {-"); 
    barra_de_vida(tamanho, vidaJogador); 
    printf("-} %3d%%", vidaJogador);
    printf("   VS.   ");
    printf("Opponent  {-"); 
    barra_de_vida(tamanho, vidaComputador); 
    printf("-} %3d%%", vidaComputador);
    printf("\n╰─────────────────────────────────────────────────────────────────────────────────╯\n\n");

}

void desenho_combate() {
    printf("                    O                                       [O]         \n");
    printf("                    |                                        |          \n");
    printf("                   /|\\                                      /|\\       \n");
    printf("                  / | \\                                    / | \\      \n");
    printf("                   / \\                                      / \\       \n");
    printf("                  /   \\                                    /   \\      \n\n");
}

void desenha_menu_opcao(int botao_pressionado) {

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

void desenho_opcao_escolida(int opcao_jogador, int opcao_computador){
    printf("\nVoce: %d | Inimigo: %d\n", opcao_jogador, opcao_computador);
}