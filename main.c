#include <stdio.h>
#include <stdlib.h>

// MENU
int print_line()
{
    printf("-----------------------------------------------\n");
    return 0;
}

int menu()
{
    print_line();
    printf("\t\t TIC TAC TOE \n");
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

int escolha_menu()
{
    int modo;
    printf("SELECIONE UM MODO: ");
    scanf("%d", &modo);

    while (modo < 0 || modo > 3)
    {
        print_line();
        system("clear");
        menu();
        printf("ERRO: modo de jogo escolhido nao existe! \n");
        print_line();
        printf("SELECIONE UM MODO: ");
        scanf("%i", &modo);
    }
    return modo;
}

int mostrar_matriz(int matriz[3][3])
{
    int var_linha, var_coluna;

    for (var_linha = 0; var_linha < 3; var_linha++)
    {
        printf("\t");
        for (var_coluna = 0; var_coluna < 3; var_coluna++)
        {
            printf("%i", matriz[var_linha][var_coluna]);
            printf(" | ");
        }
        printf("\n \n");
    }

    return 0;
}

int main()
{
    int modo;

    int matriz[3][3] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
    };

    menu();
    escolha_menu();
    system("clear");

    mostrar_matriz(matriz);

    return 0;
}
