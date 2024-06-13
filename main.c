#include <stdio.h>
#include <stdlib.h>

#define LINHA 3
#define COLUNA 3

// VISUAL
int print_line(){
    printf("-----------------------------------------------\n");
    return 0;
}

int menu_escolha_modo_jogo(){
    print_line();
    printf("\t\t JOGO DA VELHA \n");
    print_line();
    printf(" MODO DE JOGO \n");
    print_line();
    printf(" 1 - Humano x Humano \n");
    printf(" 2 - Humano x Maquina \n");
    printf(" 3 - Maquina x Maquina \n");
    printf(" 0 - Sair \n");
    print_line();
    return 0;
}

int escolha_modo_jogo(){
    int modo;
    printf("SELECIONE UM MODO: ");
    scanf("%i", &modo);
    
    while(modo < 0 || modo > 3){
        print_line();
        system("clear");
        menu_escolha_modo_jogo();
        printf("ERRO: modo de jogo escolhido nao existe!");
        print_line();
        printf("SELECIONE UM MODO: ");
        scanf("%i", &modo);
    }
    
    return modo;
}

int ganhou(int rodadas){
    if()
}

// JOGO

int jogo_partida(){
    int modo;
    int rodadas;
    escolha_modo_jogo();
    char matriz[LINHA][COLUNA];
    
        if(modo == 1){
            humano_contra_humano();
        }
    
    return 0;
}

int humano_contra_humano(){

}





int main(){
    int modo;
    
    menu_escolha_modo_jogo();

    
    return 0;
}
