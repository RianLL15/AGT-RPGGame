#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "Aux/aux.h"      
#include "../Clear_Screen/clear.h" 
#include "Draw/draw.h"   


void combat_scenes() {
    srand(time(NULL)); 

    char chp_op[20]; int c_op, opV, p_op;               // Opções do (Player/Inimigo)
    int HpP = 100, HpI = 100;                           // Vida inicial (Player/Inimigo)
    int Tp = 50, Ti = 50;                               // Taxas de sucesso (Player/Inimigo)

    while (HpP > 0 && HpI > 0) {

        // --- Renderização da Interface ---
        clear_screen();
        draw_HpB(HpP, HpI);
        draw_combate();
        draw_menu_op();


        // --- Entrada de Dados ---
        printf("\n>> ");
        fflush(stdout);

        if (fgets(chp_op, sizeof(chp_op), stdin) != NULL) {
            chp_op[strcspn(chp_op, "\n")] = '\0';
        }

        opV = sscanf(chp_op, "%d", &p_op);
        aux_compt_op(&c_op);

        clear_screen();
        draw_HpB(HpP, HpI);
        draw_combate();
        draw_menu_op();

        // --- Lógica de Combate e Atualização ---
        if(aux_validate_input(opV, p_op) == 0){
            continue;
        }

        clear_screen();
        draw_HpB(HpP, HpI);
        draw_combate();
        draw_menu_op(p_op);

        aux_spamm(p_op, &c_op, &Ti);

        draw_option_select(p_op, c_op);
        aux_combat(p_op, c_op, &HpP, &HpI, Tp, Ti);
        
        // Intervalo entre turnos
        printf("\nProximo turno em 2 segundos...\n");
        sleep(2);
    }

    aux_kill(HpP, HpI);
}