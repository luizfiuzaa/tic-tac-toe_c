// INCLUIDO BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// COMPONENTIZANDO FUNCOES
int menu();
int header();
int print_linha();
int fim_jogo();

int mostrar_modo();
int mostrar_tabela();
int mostrar_rodada();

int verificar_vitoria();
int verificar_rodada_jogador();

int escolher_modo();

int humano_contra_humano();
int humano_contra_maquina();
int maquina_contra_maquina();

int randomizador();

// MAIN
int main(){
    int rodadas = 1, linha, coluna, modo;
    char tabela[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    menu();
    modo = escolher_modo();

    mostrar_tabela(tabela, modo);
    switch (modo){
        case 1:
            system("clear");
            humano_contra_humano(rodadas, tabela, modo);
            return 0;
        case 2: 
            system("clear");
            humano_contra_maquina(rodadas, tabela, modo);
            return 0;
        case 3:
            system("clear");
            maquina_contra_maquina(rodadas, tabela, modo);
            return 0;
        case 0:
            system("clear");
            menu();
            printf(" VOCE SAIU DO JOGO! \n");
            print_linha();
            return 0;
        }
    }

// FUNCOES COMPONENTIZADAS
// PRINT LINHA

int header(){
    print_linha();
    printf("\t\t TIC TAC TOE \n");
    print_linha();
    return 0;
}

int print_linha(){
    printf("-----------------------------------------------\n");
    return 0;
}

// MENU
int menu(){
    header();
    printf(" SELECIONE UMA OPCAO \n");
    print_linha();
    printf(" 1 - Humano x Humano \n 2 - Humano x Computador \n 3 - Computador x Computador \n 0 - Sair \n");
    print_linha();
    return 0;
}

int randomizador() {
    return rand()%3;
}

// ESCOLHA MODO
int escolher_modo(){
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
    return 0;
}

// MOSTRAR tabela
int mostrar_tabela(char tabela[3][3], int modo){
    int linha, coluna;
    mostrar_modo(modo);
    for (linha = 0; linha < 3; linha++)
    {
        printf("\t\t");
        for (coluna = 0; coluna < 3; coluna++)
        {
            printf("[ %c ]", tabela[linha][coluna]);
        }
        printf("\n \n");
    }
    return 0;
}

int mostrar_rodada(int rodadas){
    printf("\n == RODADA: %i == \n", rodadas);
    return 0;
}

int fim_jogo(int rodadas){
    printf(" -- FIM DE JOGO! -- \n");
    return 0;
}

int verificar_vitoria(char tabela[3][3], int jogador){
    int vitoria, linha, coluna, sequencia;
    for(coluna = 0; coluna < 2; coluna++){
        
    }
}

int verificar_rodada_jogador(int rodadas){
    int jogador;
    if ((rodadas % 2) != 0){
        jogador = 1;
        return jogador;
    }else{
        jogador = 2;
        return jogador;
    }
}

int marcar_tabela(int jogador, char tabela[3][3], int linha, int coluna){
    if (jogador == 2){
        tabela[linha][coluna] = 'O';
    }else{
        tabela[linha][coluna] = 'X';
    }
    return 0;
}

int humano_contra_humano(int rodadas, char tabela[3][3], int modo){
    int linha, coluna, jogador, vitoria;
    while (rodadas < 10 || vitoria == 0){
        jogador = verificar_rodada_jogador(rodadas);
        header();
        mostrar_tabela(tabela, modo);
        mostrar_rodada(rodadas);
        printf(" * JOGADOR %i * \n", jogador);
        printf(" SELECIONE A LINHA: ");
        scanf("%i", &linha);
        printf(" SELECIONE A COLUNA: ");
        scanf("%i", &coluna);
        while(tabela[linha][coluna] == 'X' || tabela[linha][coluna] == 'O'){
            mostrar_tabela(tabela, modo);
            printf(" -- ERRO: nao e possivel sobrepor uma marcacao! -- \n");
            mostrar_rodada(rodadas);
            printf(" * JOGADOR %i * \n", jogador);
            printf(" SELECIONE A LINHA: ");
            scanf("%i", &linha);
            printf(" SELECIONE A COLUNA: ");
            scanf("%i", &coluna);
        }
        while ((linha < 0 || linha > 2) && (coluna < 0 || coluna > 2)){
            mostrar_tabela(tabela, modo);
            printf(" -- ERRO: nao e possivel marcar fora da tabela! -- \n");
            mostrar_rodada(rodadas);
            printf(" * JOGADOR %i * \n", jogador);
            printf(" SELECIONE A LINHA: ");
            scanf("%i", &linha);
            printf(" SELECIONE A COLUNA: ");
            scanf("%i", &coluna);
        }
        marcar_tabela(jogador, tabela, linha, coluna);
        rodadas++;
        if(rodadas > 9){
            fim_jogo(rodadas);
            return 0;
        }
    }
}

int humano_contra_maquina(int rodadas, char tabela[3][3], int modo){
    int linha, coluna, jogador, vitoria;
    while(rodadas < 10 || vitoria == 0){
        jogador = verificar_rodada_jogador(rodadas);
        header();
        mostrar_tabela(tabela, modo);
        mostrar_rodada(rodadas);
        if(jogador == 2){
            linha = randomizador();
            coluna = randomizador();
            while(tabela[linha][coluna] == 'X' || tabela[linha][coluna] == 'O'){
                linha = randomizador();
                coluna = randomizador();
            }
            while((linha < 0 || linha > 2) && (coluna < 0 || coluna > 2)){
                linha = randomizador();
                coluna = randomizador();
            }
            
            marcar_tabela(jogador, tabela, linha, coluna);
        }
        else if(jogador == 1){
            printf(" * JOGADOR %i * \n", jogador);
            printf(" SELECIONE A LINHA: ");
            scanf("%i", &linha);
            printf(" SELECIONE A COLUNA: ");
            scanf("%i", &coluna);
            while(tabela[linha][coluna] == 'X' || tabela[linha][coluna] == 'O'){
                mostrar_tabela(tabela, modo);
                printf(" -- ERRO: nao e possivel sobrepor uma marcacao! -- \n");
                mostrar_rodada(rodadas);
                printf(" * JOGADOR %i * \n", jogador);
                printf(" SELECIONE A LINHA: ");
                scanf("%i", &linha);
                printf(" SELECIONE A COLUNA: ");
                scanf("%i", &coluna);
            }
            while ((linha < 0 || linha > 2) && (coluna < 0 || coluna > 2)){
                mostrar_tabela(tabela, modo);
                printf(" -- ERRO: nao e possivel marcar fora da tabela! -- \n");
                mostrar_rodada(rodadas);
                printf(" * JOGADOR %i * \n", jogador);
                printf(" SELECIONE A LINHA: ");
                scanf("%i", &linha);
                printf(" SELECIONE A COLUNA: ");
                scanf("%i", &coluna);
            }
            marcar_tabela(jogador, tabela, linha, coluna);
        }
        rodadas++;
        if(rodadas > 9){
            fim_jogo(rodadas);
            return 0;
        }
    }
    
}
