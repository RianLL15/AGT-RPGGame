#ifndef AUX_H
#define AUX_H

int auxiliar_dano();
void auxiliar_opcao_computador(int *c_op);
int auxiliar_validar_opcao(int opV,int p_op);
void auxiliar_repeticao_tecla(int p_op, int *c_op, int *Ti);
void auxiliar_combate(int p_op, int c_op, int *HpP, int *HpI, int Tp, int Ti);
int auxiliar_tela_final(int HpP, int HpI);

#endif