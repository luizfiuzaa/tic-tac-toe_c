#include <stdio.h>
#include <stdlib.h>

int print_line(){
    printf("\n-----------------------------------------------\n");
    return 0;
}

int menu_escolha_modo_jogo(){
    print_line();
    printf("\t\t JOGO DA VEIA");
    print_line();
    printf("\t MODO DE JOGO");
    print_line();
    printf(" 1 - Humano x Humano \n");
    printf(" 2 - Humano x Maquina \n");
    printf(" 3 - Maquina x Maquina \n");
    printf(" 0 - Sair");
    print_line();
    return 0;
}

int escolha_modo_jogo(){
    int modo;
    printf("SELECIONE UM MODO: ");
    scanf("%i", &modo);
    
    while(modo < 0 || modo > 3){
        print_line();
        printf("ERRO: modo de jogo escolhido nao existe!");
        print_line();
        printf("SELECIONE UM MODO: ");
        scanf("%i", &modo);
    }
    
    return modo;
}

int main(){
    int modo;
    menu_escolha_modo_jogo();
    escolha_modo_jogo();
    return modo;
}
