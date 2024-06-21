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
int verifica_vitoria();

// MAIN
int main()
{
    int rodadas = 0, linha, coluna, modo;
    char matriz[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

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
        printf(" -- ERRO: esta opcao nao existe! -- \n SELECIONE UMA OPCAO: ");
        scanf("%i", &modo);
        print_linha();
    }
    return modo;
}

// MOSTRA MODO
int mostrar_modo(int modo)
{
    print_linha();
    printf("\t\t TIC TAC TOE \n");
    print_linha();

    switch (modo)
    {
        case 1:
            printf("\t\t Humano x Humano \n");
        break;
        case 2:
            printf("\t\t Humano x Computador \n");
        break;
        case 3:
            printf("\t Computador x Computador \n");
        break;
    }
    print_linha();
}

// MOSTRAR MATRIZ
int mostrar_matriz(char matriz[3][3], int modo){
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

int mostra_rodada(int rodadas){
    printf("\n == RODADA: %i", rodadas);
    printf(" == \n");
    return 0;
}
int verifica_rodada_jogador(int rodadas){
    int jogador;
    if ((rodadas % 2) == 0){
        int jogador = 1;
        mostra_rodada(rodadas);
        printf(" * JOGADOR 1: * \n");
    }else if((rodadas % 2) != 0){
        int jogador = 2;
        mostra_rodada(rodadas);
        printf(" * JOGADOR 2: * \n");
    }
    return jogador;
}

int humano_contra_humano(int rodadas, char matriz[3][3], int modo){
    int linha, coluna;
    
    while (rodadas < 9){
            verifica_rodada_jogador(rodadas);
            printf(" SELECIONE A LINHA: ");
            scanf("%i", &linha);
            printf(" SELECIONE A COLUNA: ");
            scanf("%i", &coluna);
            while ((linha < 0 || linha > 2)  && (coluna < 0 || coluna > 2)){
                mostrar_matriz(matriz, modo);
                verifica_rodada_jogador(rodadas);
                printf(" -- ERRO: nao e possivel marcar fora da tabela! -- \n SELECIONE A LINHA: ");
                scanf("%i", &linha);
                printf(" SELECIONE A COLUNA: ");
                scanf("%i", &coluna);
            }
            
            while(matriz[linha][coluna] == 'X' || matriz[linha][coluna] == 'O'){
                mostrar_matriz(matriz, modo);
                printf(" -- ERRO: nao e possivel sobrepor uma jogada! -- \n");
                humano_contra_humano(rodadas, matriz, modo);
            }
            
            if ((rodadas % 2) == 0){
                matriz[linha][coluna] = 'X';
            }else if((rodadas % 2) != 0){
                matriz[linha][coluna] = 'O';
            }
            
            mostrar_matriz(matriz, modo);
            rodadas++;
        }
    return 0;
}
