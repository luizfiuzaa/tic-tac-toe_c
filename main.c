// INCLUIDO BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

// COMPONENTIZANDO FUNCOES

int menu();
int print_linha();
int escolha_modo();
int mostrar_matriz(char matriz[3][3], int modo);
int marcar_matriz(char matriz[3][3], int linha, int coluna, int rodadas, int modo);


// MAIN
int main()
{
    int rodadas = 0, linha, coluna, modo;
    char matriz[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    menu();
    modo = escolha_modo();
    if(modo == 0){
        print_linha();
        printf("VOCE SAIU DO JOGO!");
        return 0;
        print_linha();
        
    }else{
        system("clear");
        mostrar_matriz(matriz, modo);
    }
    marcar_matriz(matriz, linha, coluna, rodadas, modo);
    mostrar_matriz(matriz, modo);
    

    return 0;
}

// FUNCOES COMPONENTIZADAS
    // PRINT LINHA
    int print_linha(){
        printf("-----------------------------------------------\n");
        return 0;
    }

    // MENU
    int menu(){
        print_linha();
        printf("\t\t TIC TAC TOE \n");
        print_linha();
        printf(" MODO DE JOGO \n");
        print_linha();
        printf(" 1 - Humano x Humano \n");
        printf(" 2 - Humano x Computador \n");
        printf(" 3 - Computador x Computador \n");
        printf(" 0 - Sair \n");
        print_linha();
        return 0;
    }

    // ESCOLHA MODO
    int escolha_modo(){
        int modo;
        printf("SELECIONE UM MODO: ");
        scanf("%i", &modo);
        
        while (modo < 0 || modo > 3)
        {
            print_linha();
            system("clear");
            menu();
            printf("ERRO: modo de jogo escolhido nao existe! \n");
            print_linha();
            printf("SELECIONE UM MODO: ");
            scanf("%i", &modo);
        }
        return modo;
    }

    // MOSTRAR MATRIZ
    int mostrar_matriz(char matriz[3][3], int modo){
        int var_linha, var_coluna;
        print_linha();
        printf("\t\t TIC TAC TOE \n");
        print_linha();
        printf("\t\t");
        
        if(modo == 1){
            printf("Humano x Humano \n");
        }
        if(modo == 2){
            printf("Humano x Computador \n");
        }
        if(modo == 3){
            printf("Computador x Computador \n");
        }
        print_linha();
        for (var_linha = 0; var_linha < 3; var_linha++){
            printf("\t\t");
            for (var_coluna = 0; var_coluna < 3; var_coluna++){
                printf("[ %c ]", matriz[var_linha][var_coluna]);
            }
            printf("\n \n");
        }
        return 0;
    }

    // MARCAR MATRIZ
    int marcar_matriz(char matriz[3][3], int linha, int coluna, int rodadas, int modo){
        switch(modo){
        case 1:
            if((rodadas % 2) == 0){
                printf("JOGADOR 1 \n");
                printf("SELECIONE A LINHA:  \n");
                scanf("%i", &linha);
                printf("SELECIONE A COLUNA:  \n");
                scanf("%i", &coluna);
                
                matriz[linha][coluna] = 'X';
                
            }
        }
        return 0;
    }
