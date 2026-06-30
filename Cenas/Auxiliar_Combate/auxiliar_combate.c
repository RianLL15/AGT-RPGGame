#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../Desenho/desenho.h"
#include "../../Limpar_tela/limpar.h" 

int auxiliar_dano(){
    int dano = (rand() % 31) + 10; //-> 10 até 30
    return dano;
}

void auxiliar_combate(int opcao_jogador, int opcao_computador, int *vidaJogador, int *vidaComputador, int taxaJogador, int taxaComputador) {
    int dano_critico, dano_reduzido, revide; 
    
    int dano_jogador = auxiliar_dano(); //Randomiza o dano que o Player vai causar
    int dano_computador = auxiliar_dano(); //Randomia o dano que o Inimigo vai causar

    //Caso ambos escolherem a opção 2 terá um contra-ataque
    if (opcao_jogador == 2 && opcao_computador == 2) {
    }

    // Lógica quando o Player ataca (opção 2) e o Inimigo tenta defender (opção 1)
    else if (opcao_jogador == 2) {
        if (opcao_computador == 1) {
            if ((rand() % 100) < taxaComputador) { // Sucesso da defesa
                revide = dano_computador / 2;
                printf("Inimigo bloqueou e revidou! -%d HP para voce.\n", revide);
                *vidaJogador -= revide;
            } else {
                printf("Ataque limpo! Voce causou %d de dano.\n", dano_jogador);
                *vidaComputador -= dano_jogador;
            }
        }
    }

    // Lógica quando o Inimigo ataca(opção 2) e o Player tenta defender (opção 1)
    else if (opcao_computador == 2) {
        if (opcao_jogador == 1) { 
            if ((rand() % 100) < taxaJogador) { // Chance de sucesso
                revide = dano_jogador / 2;
                printf("DEFESA PERFEITA! Voce revidou -%d HP no inimigo.\n", revide);
                *vidaComputador -= revide;
            } else {
                printf("O inimigo te acertou em cheio! -%d HP.\n", dano_computador);
                *vidaJogador -= dano_computador;
            }
        }
    }

    // Caso algum dos lutadores escolha acessar a mochila/itens (opção 3)
    else if(opcao_jogador == 3 || opcao_computador == 3){
    }

    // Caso ocorra uma combinação de ações que não resulte em dano direto
    else {
        printf("Turno de estudo. Ninguem se moveu para atacar.\n");
    }
}

int auxiliar_validar_opcao(int opcao_validacao_entrada,int opcao_jogador) {
    if (opcao_validacao_entrada != 1 || opcao_jogador < 1 || opcao_jogador > 3) {
        printf("\n[!] Entrada invalida! [!]\n");
        sleep(1);
        return 0; 
    }
    return 1;
}

void auxiliar_repeticao_tecla(int opcao_jogador, int *opcao_computador, int *taxaComputador) {
    static int ultima_opcao = 0; 
    static int contador_reticao = 0;

    if (opcao_jogador == ultima_opcao) {
        contador_reticao++;
    } else {
        contador_reticao = 1;
        *taxaComputador = 50;
    }

    ultima_opcao = opcao_jogador;

    if (contador_reticao >= 4) {
        if (opcao_jogador == 2) { 
            printf("\n[!] O inimigo previu seu padrão de ATAQUE! [!]\n");
            *taxaComputador = 100;   
            *opcao_computador = 1;  
        } 
        else if (opcao_jogador  == 1) { 
            printf("\n[!] O inimigo percebeu sua covardia e vai QUEBRAR sua guarda! [!]\n");
            *taxaComputador = 100;
            *opcao_computador = 2;   
            
        }
    }
}

void auxiliar_opcao_computador(int *opcao_computador){
    int chance = rand() % 101;

    if(chance < 55){
        *opcao_computador = 2;
    } else if(chance < 90){
        *opcao_computador = 1;
    } else{
       *opcao_computador = 3;
    }
}

int auxiliar_tela_final(int vidaJogador, int vidaComputador){
    if(vidaJogador <= 0){
        // --- Renderização da Interface para a Derrota---
        limpar_tela();
        desenho_barra_vida(0,vidaComputador);
        desenho_combate();
        desenha_menu_opcao();

        printf("\n--- VOCE MORREU ---\n");

    } else {
        // --- Renderização da Interface para a Vitoria---
        limpar_tela();
        desenho_barra_vida(vidaJogador,0);
        desenho_combate();
        desenha_menu_opcao();
        printf("\n--- VITORIA! ---\n");
    }

    return 0;
}