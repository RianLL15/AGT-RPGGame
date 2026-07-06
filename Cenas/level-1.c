#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "Cenas/Auxiliar_Combate/auxiliar_combate.h"
#include "Limpar_tela/limpar.h"
#include "Cenas/Desenho/desenho.h" 


void cena_de_combate() {
    srand(time(NULL)); 

    char opcao_validacao_digitada[20]; 
    int opcao_validacao_entrada, opcao_jogador, opcao_computador;               // Opções do (Player/Inimigo)
    int vidaJogador = 100, vidaComputador = 100;                           // Vida inicial (Player/Inimigo)
    int taxaJogador = 50, taxaComputador = 50;                               // Taxas de sucesso (Player/Inimigo)

    while (vidaJogador > 0 && vidaComputador > 0) {

        // --- Renderização da Interface ---
        limpar_tela();
        desenho_barra_vida(vidaJogador, vidaComputador);
        desenho_combate();
        desenho_menu_opcao();


        // --- Entrada de Dados ---
        printf("\n>> ");
        fflush(stdout);

        if (fgets(opcao_validacao_digitada, sizeof(opcao_validacao_digitada), stdin) != NULL) {
            opcao_validacao_digitada[strcspn(opcao_validacao_digitada, "\n")] = '\0';
        }

        opcao_validacao_entrada = sscanf(opcao_validacao_digitada, "%d", &opcao_jogador);
        auxiliar_opcao_computador(&opcao_computador);

        limpar_tela();
        desenho_barra_vida(vidaJogador, vidaComputador);
        desenho_combate();
        desenho_menu_opcao();

        // --- Lógica de Combate e Atualização ---
        if(auxiliar_validar_opcao(opcao_validacao_entrada, opcao_jogador) == 0){
            continue;
        }

        limpar_tela();
        desenho_barra_vida(vidaJogador, vidaComputador);
        desenho_combate();
        desenho_menu_opcao(opcao_jogador);

        auxiliar_repeticao_tecla(opcao_jogador, &opcao_computador, &taxaComputador);

        desenho_opcao_escolida(opcao_jogador, opcao_computador);
        auxiliar_combate(opcao_jogador, opcao_computador, &vidaJogador, &vidaComputador, 
                        taxaJogador, taxaComputador);
        
        // Intervalo entre turnos
        printf("\nProximo turno em 2 segundos...\n");
        sleep(60);
    }

    auxiliar_tela_final(vidaJogador, vidaComputador);
}