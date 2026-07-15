#ifndef AUX_H
#define AUX_H

int aux_damage();
void aux_parry();
void aux_backpack();
void aux_compt_op(int *c_op);
int aux_validate_input(int opV,int p_op);
void aux_spamm(int p_op, int *c_op, int *Ti);
void aux_combat(int p_op, int c_op, int *HpP, int *HpI, int Tp, int Ti);
int aux_kill(int HpP, int HpI);

#endif