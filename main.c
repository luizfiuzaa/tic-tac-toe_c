// INCLUIDO BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

// COMPONENTIZANDO FUNCOES
int menu();
int print_linha();
int escolha_modo();
int mostrar_modo();
int mostrar_matriz();
int humano_contra_humano();

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
    if (modo == 0)
    {
        print_linha();
        printf(" VOCE SAIU DO JOGO!");
        return 0;
        print_linha();
    }
    else
    {
        mostrar_matriz(matriz, modo);
        switch (modo)
        {
        case 1:
            humano_contra_humano(rodadas, matriz, modo);
        }
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
    printf(" SELECIONE UMA OPCAO \n");
    print_linha();
    printf(" 1 - Humano x Humano \n 2 - Humano x Computador \n 3 - Computador x Computador \n 0 - Sair \n");
    print_linha();
    return 0;
}

// ESCOLHA MODO
int escolha_modo()
{
    int modo;
    printf("SELECIONE UMA OPCAO: ");
    scanf("%i", &modo);

    while (modo < 0 || modo > 3)
    {
        print_linha();
        system("clear");
        menu();
        printf(" ERRO: esta opcao nao existe! \n");
        print_linha();
        printf(" SELECIONE UMA OPCAO: ");
        scanf("%i", &modo);
    }
    return modo;
}

// MOSTRA MODO
int mostrar_modo(int modo)
{
    print_linha();
    printf("\t\t TIC TAC TOE \n");
    print_linha();

    if (modo == 1)
    {
        printf("\t\t");
        printf("Humano x Humano \n");
    }
    if (modo == 2)
    {
        printf("\t\t");
        printf("Humano x Computador \n");
    }
    if (modo == 3)
    {
        printf("\t");
        printf(" Computador x Computador \n");
    }
    print_linha();
}

// MOSTRAR MATRIZ
int mostrar_matriz(char matriz[3][3], int modo)
{
    int linha, coluna;
    mostrar_modo(modo);
    for (linha = 0; linha < 3; linha++)
    {
        printf("\t\t");
        for (coluna = 0; coluna < 3; coluna++)
        {
            printf("[ %c ]", matriz[linha][coluna]);
        }
        printf("\n \n");
    }
    return 0;
}

int humano_contra_humano(int rodadas, char matriz[3][3], int modo)
{
    int linha, coluna;
    while (rodadas < 9)
    {
        do 
        {
            printf(" * JOGADOR 1 * \n SELECIONE A LINHA: ");
            scanf("%i", &linha);
            while (linha < 0 || linha > 2)
            {
                printf(" -- ERRO: linha nao existe na matriz! -- \n * JOGADOR 1 * \n SELECIONE A LINHA: ");
                scanf("%i", &linha);
            }
            printf(" SELECIONE A COLUNA: ");
            scanf("%i", &coluna);
            while (coluna < 0 || coluna > 2)
            {
                printf(" -- ERRO: coluna nao existe na matriz! -- \n * JOGADOR 1 * \n SELECIONE A COLUNA: ");
                scanf("%i", &coluna);
            }
            matriz[linha][coluna] = 'X';
            mostrar_matriz(matriz, modo);
        } while ((rodadas % 2) == 0);
        do
        {
            printf(" * JOGADOR 2 * \n SELECIONE A LINHA: ");
            scanf("%i", &linha);
            while (linha < 0 || linha > 2)
            {
                printf(" -- ERRO: linha nao existe na matriz! -- \n * JOGADOR 2 * \n SELECIONE A LINHA: ");
                scanf("%i", &linha);
            }
            printf(" SELECIONE A COLUNA: ");
            scanf("%i", &coluna);
            while (coluna < 0 || coluna > 2)
            {
                printf(" -- ERRO: coluna nao existe na matriz! -- \n * JOGADOR 2 * \n SELECIONE A COLUNA: ");
                scanf("%i", &coluna);
            }
            matriz[linha][coluna] = 'O';
            mostrar_matriz(matriz, modo);
        } while ((rodadas % 2) != 0);
        rodadas++;
    }
}
