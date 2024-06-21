// INCLUIDO BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>

// COMPONENTIZANDO FUNCOES
int menu();
int jogo();

int print_linha();

int escolha_modo();

int mostrar_modo();
int mostrar_tabela();

int verifica_vitoria();
int verifica_turno();
int verifica_rodada();

// MAIN
int main()
{
    int rodadas = 1;
    char tabela[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    menu();
    int modo = escolha_modo();
        switch (modo){
        case 1:
            mostrar_modo(modo);
            jogo(rodadas, tabela, modo);
        case 2: break;
        case 3: break;
        case 0:
            print_linha();
            printf(" VOCE SAIU DO JOGO! \n");
            print_linha();
        return 0;
        }
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
    printf(" SELECIONE UMA OPCAO \n");
    print_linha();
    printf(" 1 - Humano x Humano \n 2 - Humano x Computador \n 3 - Computador x Computador \n 0 - Sair \n");
    print_linha();
    return 0;
}

// ESCOLHA MODO
int escolha_modo(){
    int modo;
    printf("SELECIONE UMA OPCAO: ");
    scanf("%i", &modo);

    while (modo < 0 || modo > 3){
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
int mostrar_modo(int modo){
    print_linha();
    printf("\t\t TIC TAC TOE \n");
    print_linha();

    switch (modo){
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

// MOSTRAR TABELA
int mostrar_tabela(char tabela[3][3]){
    int linha, coluna;
    for (linha = 0; linha < 3; linha++){
        printf("\t\t");
        for (coluna = 0; coluna < 3; coluna++)
        {
            printf("[ %c ]", tabela[linha][coluna]);
        }
        printf("\n \n");
    }
    return 0;
}

int mostra_rodada(int rodadas){
    printf("\n == RODADA: %i == \n", rodadas);
    return 0;
}

int verifica_turno(int rodadas){
    if ((rodadas % 2) != 0){
        mostra_rodada(rodadas);
        printf(" * JOGADOR 1 * \n");
    }else if((rodadas % 2) == 0){
        mostra_rodada(rodadas);
        printf(" * JOGADOR 2 * \n");
    }
}

int verifica_vitoria(int tabela[3][3]){
    int sequencia = 0;
    
}

int jogo(int rodadas, char tabela[3][3], int modo){
    int linha, coluna, vitoria;
    
    while (rodadas < 10){
        mostrar_modo(modo);
        mostrar_tabela(tabela);
        verifica_turno(rodadas);
        printf(" SELECIONE A LINHA: ");
        scanf("%i", &linha);
        printf(" SELECIONE A COLUNA: ");
        scanf("%i", &coluna);
        while ((linha < 0 || linha > 2)  && (coluna < 0 || coluna > 2)){
            mostrar_tabela(tabela);
            verifica_turno(rodadas);
            printf(" -- ERRO: nao e possivel marcar fora da tabela! -- \n SELECIONE A LINHA: ");
            scanf("%i", &linha);
            printf(" SELECIONE A COLUNA: ");
            scanf("%i", &coluna);
        }
        if(tabela[linha][coluna] == 'X' || tabela[linha][coluna] == 'O'){
            mostrar_tabela(tabela);
            printf(" -- ERRO: nao e possivel sobrepor uma marcacao na tabela! -- \n");
            jogo(rodadas, tabela, modo);
        }
        if ((rodadas % 2) == 0){
            tabela[linha][coluna] = 'O';
        }
        tabela[linha][coluna] = 'X';
        mostrar_tabela(tabela);
        rodadas++;
        if (rodadas > 10){
            return 0;
        }
    }
}
