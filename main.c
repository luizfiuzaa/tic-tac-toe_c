// Incluindo Bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Componentizando Funcoes

int menu();
int print_linha();
int escolha_modo();
int mostrar_matriz(char matriz[3][3]);

// Funcao Main
int main()
{
    int rodadas = 0, linha, coluna, modo, rodadas;
    char matriz[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
};

    menu();
    modo = escolha_modo();
    if (modo == 0)
    {
        print_linha();
        printf("VOCE SAIU DO JOGO!");
        return 0;
        print_linha();
    }
    else
    {
        system("clear");
        mostrar_matriz(matriz);
    }

    return 0;
}

// FUNCOES COMPONENTIZADAS
// PRINT LINHA
int print_linha()
{
    printf("-----------------------------------------------\n");
    return 0;
}

// MENU
int menu()
{
    print_linha();
    printf("\t\t TIC TAC TOE \n");
    print_linha();
    printf(" MODO DE JOGO \n");
    print_linha();
    printf(" 1 - Humano x Humano \n");
    printf(" 2 - Humano x Maquina \n");
    printf(" 3 - Maquina x Maquina \n");
    printf(" 0 - Sair \n");
    print_linha();
    return 0;
}

// ESCOLHA MODO
int escolha_modo()
{
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
int mostrar_matriz(char matriz[3][3])
{
    int var_linha, var_coluna;

    print_linha();
    printf("\t\t TIC TAC TOE \n");
    print_linha();
    printf(" MODO DE JOGO \n");
    print_linha();
    for (var_linha = 0; var_linha < 3; var_linha++)
    {
        printf("\t");
        for (var_coluna = 0; var_coluna < 3; var_coluna++)
        {
            printf("[ %c ]", matriz[var_linha][var_coluna]);
        }
        printf("\n \n");
    }

    return 0;
}
