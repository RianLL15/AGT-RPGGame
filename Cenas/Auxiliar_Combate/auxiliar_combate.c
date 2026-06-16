#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../Desenho/desenho.h"
#include "../../Limpar_tela/limpar.h" 

int aux_damage(){
    int dano = (rand() % 31) + 10; //-> 10 até 30
    return dano;
}

void aux_parry(){

}

int aux_backpack(){

}

void aux_combat(int p_op, int c_op, int *HpP, int *HpI, int Tp, int Ti) {
    int dano_critico, dano_reduzido, revide; 
    
    int dano_P = aux_damage(); //Randomiza o dano que o Player vai causar
    int dano_I = aux_damage(); //Randomia o dano que o Inimigo vai causar

    //Caso ambos escolherem a opção 2 terá um contra-ataque
    if (p_op == 2 && c_op == 2) {
        aux_parry();
    }

    // Lógica quando o Player ataca (opção 2) e o Inimigo tenta defender (opção 1)
    else if (p_op == 2) {
        if (c_op == 1) {
            if ((rand() % 100) < Ti) { // Sucesso da defesa
                revide = dano_I / 2;
                printf("Inimigo bloqueou e revidou! -%d HP para voce.\n", revide);
                *HpP -= revide;
            } else {
                printf("Ataque limpo! Voce causou %d de dano.\n", dano_P);
                *HpI -= dano_P;
            }
        }
    }

    // Lógica quando o Inimigo ataca(opção 2) e o Player tenta defender (opção 1)
    else if (c_op == 2) {
        if (p_op == 1) { 
            if ((rand() % 100) < Tp) { // Chance de sucesso
                revide = dano_P / 2;
                printf("DEFESA PERFEITA! Voce revidou -%d HP no inimigo.\n", revide);
                *HpI -= revide;
            } else {
                printf("O inimigo te acertou em cheio! -%d HP.\n", dano_I);
                *HpP -= dano_I;
            }
        }
    }

    // Caso algum dos lutadores escolha acessar a mochila/itens (opção 3)
    else if(p_op == 3 || c_op == 3){
        aux_backpack();
    }

    // Caso ocorra uma combinação de ações que não resulte em dano direto
    else {
        printf("Turno de estudo. Ninguem se moveu para atacar.\n");
    }
}

int aux_validate_input(int opV,int p_op) {
    if (opV != 1 || p_op < 1 || p_op > 3) {
        printf("\n[!] Entrada invalida! [!]\n");
        sleep(1);
        return 0; 
    }
    return 1;
}

void aux_spamm(int p_op, int *c_op, int *Ti) {
    static int ultima_op = 0; 
    static int spam_count = 0;

    if (p_op == ultima_op) {
        spam_count++;
    } else {
        spam_count = 1;
        *Ti = 70;
    }

    ultima_op = p_op;

    if (spam_count >= 4) {
        if (p_op == 2) { 
            printf("\n[!] O inimigo previu seu padrão de ATAQUE! [!]\n");
            *Ti = 100;   
            *c_op = 1;  
        } 
        else if (p_op == 1) { 
            printf("\n[!] O inimigo percebeu sua covardia e vai QUEBRAR sua guarda! [!]\n");
            *Ti = 100;
            *c_op = 2;   
            
        }
    }
}

void aux_compt_op(int *c_op){
    int chance = rand() % 101;

    if(chance < 55){
        *c_op = 2;
    } else if(chance < 90){
        *c_op = 1;
    } else{
       *c_op = 3;
    }
}

int aux_kill(int HpP, int HpI){
    if(HpP <= 0){
        // --- Renderização da Interface para a Derrota---
        clear_screen();
        draw_HpB(0,HpI);
        draw_combate();
        draw_menu_op();

        printf("\n--- VOCE MORREU ---\n");

    } else {
        // --- Renderização da Interface para a Vitoria---
        clear_screen();
        draw_HpB(HpP,0);
        draw_combate();
        draw_menu_op();
        printf("\n--- VITORIA! ---\n");
    }
    return 0;
}