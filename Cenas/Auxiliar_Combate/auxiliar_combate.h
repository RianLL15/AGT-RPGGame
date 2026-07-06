#ifndef AUX_H
#define AUX_H

void auxiliar_opcao_computador(int *opcao_computador);
int auxiliar_validar_opcao(int opcao_validacao_entrada,int opcao_jogador);
void auxiliar_repeticao_tecla(int opcao_jogador, int *opcao_computador, int *taxaComputador);
void auxiliar_combate(int opcao_jogador, int opcao_computador, int *vidaJogador, int *vidaComputador, int taxaJogador, int taxaComputador);
int auxiliar_tela_final(int vidaJogador, int vidaComputador);

#endif