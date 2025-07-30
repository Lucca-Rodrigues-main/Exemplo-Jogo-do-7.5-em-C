//Definir cores para facilitar
#define		preto            0
#define		azul             1
#define		verde            2
#define		ciano            3
#define		vermelho         4
#define		magenta          5
#define		marrom           6
#define		cinza_claro      7
#define		cinza_escuro     8
#define		azul_claro       9
#define		verde_claro     10
#define		ciano_claro     11
#define		vermelho_claro  12
#define		magenta_claro   13
#define		amarelo         14
#define		branco          15

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

void SetWindow(int Width, int Height, int WidthBuffer, int HeightBuffer); //Função que muda tamanho da janela e do buffer da janela
void limpatela(); //Função para limpar a tela
void cortexto(int fundo, int letras); //Função para mudas as cores do texto e do fundo
void gerarcartasjog1(int i, int jog1, char letra[20][20], float pontoj[20]); //Função cartas jogador 1
void gerarcartasmesa(int i, int jog1, char letra2[20][20], float pontom[20]); //Função cartas mesa
void gerarcartasjog2(int i, int jog1, char letra3[20][20], float pontoj2[20]); //Função cartas jogador 2
void gerarcartasjog3(int i, int jog1, char letra4[20][20], float pontoj3[20]); //Função cartas jogador 3
float imprimirjogador1(int i, int cont, char letra[20][20], float pontoj[20], float totaljog1); //Função para imprimir as cartas do jogador 1
float imprimirmesa(int i, int contmesa, char letra2[20][20], float pontom[20], float totalmesa); //Função para imprimir as cartas da mesa
float imprimirjogador2(int i, int cont2, char letra3[20][20], float pontoj2[20], float totaljog2); //Função para imprimir as cartas do jogador 1
float imprimirjogador3(int i, int cont3, char letra4[20][20], float pontoj3[20], float totaljog3); //Função para imprimir as cartas do jogador 1

int main()
{
    //Especificando altura e largura da janela e do buffer
    int larguraJanela = 80; //A largura da janela
    int alturaJanela = 25; //A altura da janela
    int tamanhoLarguraBuffer = larguraJanela + 200; //A largura do buffer
    int tamanhoAlturaBuffer  = alturaJanela  + 800; //A altura do buffer
    SetWindow(larguraJanela,alturaJanela,tamanhoLarguraBuffer,tamanhoAlturaBuffer);

    setlocale(LC_ALL,"Portuguese");

    char jogar, mais;
    char letra[20][20], letra2[20][20], letra3[20][20], letra4[20][20];
    int qnt = 0, jog1 = 0, i = 0, cont = 1, contmesa = 1, cont2 = 1, cont3 = 1;
    float totaljog1 = 0, totalmesa = 0, totaljog2 = 0, totaljog3 = 0, maior = 0;
    bool esquecer = false;

    printf("\n");
    cortexto(branco, azul_claro);
    printf("-----------------------Bem-vindo(a) ao jogo do 7 e meio!-----------------------");
    cortexto(preto, cinza_claro);
    printf("\n\nO usuário e a mesa devem somar a maior quantidade pontos, porém, sem exceder");
    printf("\n7.5 pontos. A dama (Q), o valete (J) e o rei (K) valem 0.5 pontos, as cartas");
    printf("\n8, 9, 10 não entram no jogo, o As vale 1 e as outras cartas tem o valor igual");
    printf("\nao impresso na mesma. \nGanha quem fizer mais pontos, e caso empate, a mesa ganha.");
    printf("\n\nQuer iniciar uma partida (s/n)? ");
    scanf("\n%c%*c", &jogar);
    printf("\n");
    while(jogar == 's'){
        do{
            //Inicializando os arrays de pontos flutuantes que serão preenchidos com o valor de cartas aleatórias
            float pontoj[20] = {'\0'}; //Jogador 1
            float pontoj2[20] = {'\0'}; //Jogador 2
            float pontoj3[20] = {'\0'}; //Jogador 3
            float pontom[20] = {'\0'}; //Mesa
            printf("Quantos jogadores querem jogar? ");
            scanf("\n%d", &qnt);
            switch (qnt)
            {
                case 1 :
                    gerarcartasjog1(i, jog1, letra, pontoj); //Cartas jogador 1
                    gerarcartasmesa(i, jog1, letra2, pontom); //Cartas mesa

                    do{ //Vez do jogador 1
                        cortexto(branco, vermelho_claro);
                        printf("\n\nVEZ DO JOGADOR 1\n\n");
                        cortexto(preto, cinza_claro);

                        printf("\n\nCartas do jogador 1:\n\n");
                        totaljog1 = imprimirjogador1(i, cont, letra, pontoj, totaljog1);

                        if(totaljog1 > 7.5){
                            cortexto(preto, vermelho_claro);
                            printf("\n\nJogador 1 desqualificado!\n");
                            cortexto(preto, cinza_claro);
                        }

                        printf("\n\nCartas da mesa:\n\n");
                        imprimirmesa(i, contmesa, letra2, pontom, totalmesa);

                        if(totaljog1 > 7.5){
                            totaljog1 = 0;
                            cortexto(preto, amarelo);
                            printf("\n\nMesa ganhou!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        }

                        printf("\n\nO jogador 1 deseja puxar mais uma carta (s/n)? ");
                        scanf("\n%c%*c", &mais);
                        if (mais == 's'){
                            cont += 1;
                            limpatela();
                        }
                    }while(mais == 's');
                    if(totaljog1 == 0){
                        break;
                    }
                    limpatela();

                    do{ //Vez da mesa
                        cortexto(branco, vermelho_claro);
                        printf("\n\nVEZ DA MESA\n\n");
                        cortexto(preto, cinza_claro);

                        printf("\n\nCartas do jogador 1:\n\n");
                        imprimirjogador1(i, cont, letra, pontoj, totaljog1);

                        printf("\n\nCartas da mesa:\n\n");
                        totalmesa = imprimirmesa(i, contmesa, letra2, pontom, totalmesa);

                        //Comparações para ver quem ganha
                        if(totalmesa > 7.5){
                            cortexto(preto, vermelho_claro);
                            printf("\n\nMesa desqualificada!\n");
                            cortexto(preto, amarelo);
                            printf("\n\nJogador 1 ganhou!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        } else if((totalmesa >= totaljog1)&&(totalmesa <= 7.5)){
                            cortexto(preto, amarelo);
                            printf("\n\nMesa ganhou!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        }

                        Sleep(1000);
                        contmesa += 1;
                        limpatela();
                    }while(totalmesa < totaljog1);

                    break;

                case 2 :
                    gerarcartasjog1(i, jog1, letra, pontoj); //Cartas jogador 1
                    gerarcartasmesa(i, jog1, letra2, pontom); //Cartas mesa
                    gerarcartasjog2(i, jog1, letra3, pontoj2); //Cartas jogador 2

                    do{ //Vez do jogador 1
                        cortexto(branco, vermelho_claro);
                        printf("\n\nVEZ DO JOGADOR 1\n\n");
                        cortexto(preto, cinza_claro);

                        printf("\n\nCartas do jogador 1:\n\n");
                        totaljog1 = imprimirjogador1(i, cont, letra, pontoj, totaljog1);

                        printf("\n\nCartas do jogador 2:\n\n");
                        imprimirjogador2(i, cont2, letra3, pontoj2, totaljog2);

                        printf("\n\nCartas da mesa:\n\n");
                        imprimirmesa(i, contmesa, letra2, pontom, totalmesa);

                        if(totaljog1 > 7.5){
                            totaljog1 = 0;
                            cortexto(preto, vermelho_claro);
                            printf("\n\nJogador 1 desqualificado!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        }

                        printf("\n\nO jogador 1 deseja puxar mais uma carta (s/n)? ");
                        scanf("\n%c%*c", &mais);
                        if (mais == 's'){
                            cont += 1;
                            limpatela();
                        }
                    }while(mais == 's');
                    maior = totaljog1;
                    limpatela();

                    do{ //Vez do jogador 2
                        cortexto(branco, vermelho_claro);
                        printf("\n\nVEZ DO JOGADOR 2\n\n");
                        cortexto(preto, cinza_claro);

                        printf("\n\nCartas do jogador 1:\n\n");
                        imprimirjogador1(i, cont, letra, pontoj, totaljog1);
                        if(totaljog1 == 0){
                            cortexto(preto, vermelho_claro);
                            printf("\n\nJogador 1 desqualificado!\n");
                            cortexto(preto, cinza_claro);
                        }

                        printf("\n\nCartas do jogador 2:\n\n");
                        totaljog2 = imprimirjogador2(i, cont2, letra3, pontoj2, totaljog2);

                        printf("\n\nCartas da mesa:\n\n");
                        imprimirmesa(i, contmesa, letra2, pontom, totalmesa);

                        if(totaljog2 > 7.5){
                            totaljog2 = 0;
                            cortexto(preto, vermelho_claro);
                            printf("\n\nJogador 2 desqualificado!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        }

                        printf("\n\nO jogador 2 deseja puxar mais uma carta (s/n)? ");
                        scanf("\n%c%*c", &mais);
                        if (mais == 's'){
                            cont2 += 1;
                            limpatela();
                        }
                    }while(mais == 's');
                    if(maior < totaljog2){
                        maior = totaljog2;
                    }
                    limpatela();

                    do{ //Vez da mesa
                        cortexto(branco, vermelho_claro);
                        printf("\n\nVEZ DA MESA\n\n");
                        cortexto(preto, cinza_claro);

                        printf("\n\nCartas do jogador 1:\n\n");
                        imprimirjogador1(i, cont, letra, pontoj, totaljog1);
                        if(totaljog1 == 0){
                            cortexto(preto, vermelho_claro);
                            printf("\n\nJogador 1 desqualificado!\n");
                            cortexto(preto, cinza_claro);
                        }

                        printf("\n\nCartas do jogador 2:\n\n");
                        imprimirjogador2(i, cont2, letra3, pontoj2, totaljog2);
                        if(totaljog2 == 0){
                            cortexto(preto, vermelho_claro);
                            printf("\n\nJogador 2 desqualificado!\n");
                            cortexto(preto, cinza_claro);
                        }

                        printf("\n\nCartas da mesa:\n\n");
                        totalmesa = imprimirmesa(i, contmesa, letra2, pontom, totalmesa);

                        //Comparações para ver quem ganha
                        if(totalmesa > 7.5){
                            totalmesa = 0;
                            esquecer = true;
                            cortexto(preto, vermelho_claro);
                            printf("\n\nMesa desqualificada!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        } else if((totalmesa >= maior)&&(totalmesa <= 7.5)){
                            maior = totalmesa;
                            cortexto(preto, amarelo);
                            printf("\n\nMesa ganhou!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        }

                        Sleep(1000);
                        contmesa += 1;
                        limpatela();
                    }while(totalmesa < maior);

                    //Comparações para ver quem ganha
                    if(esquecer == false){
                        break;
                    } else if (esquecer == true){
                        if(totaljog1 == maior){
                            cortexto(preto, amarelo);
                            printf("\n\nJogador 1 ganhou!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        } else if(totaljog2 == maior){
                            cortexto(preto, amarelo);
                            printf("\n\nJogador 2 ganhou!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        }
                        break;
                    }

                    break;

                case 3 :
                    gerarcartasjog1(i, jog1, letra, pontoj); //Cartas jogador 1
                    gerarcartasmesa(i, jog1, letra2, pontom); //Cartas mesa
                    gerarcartasjog2(i, jog1, letra3, pontoj2); //Cartas jogador 2
                    gerarcartasjog3(i, jog1, letra4, pontoj3); //Cartas jogador 3

                    do{ //Vez do jogador 1
                        cortexto(branco, vermelho_claro);
                        printf("\n\nVEZ DO JOGADOR 1\n\n");
                        cortexto(preto, cinza_claro);

                        printf("\n\nCartas do jogador 1:\n\n");
                        totaljog1 = imprimirjogador1(i, cont, letra, pontoj, totaljog1);

                        printf("\n\nCartas do jogador 2:\n\n");
                        imprimirjogador2(i, cont2, letra3, pontoj2, totaljog2);

                        printf("\n\nCartas do jogador 3:\n\n");
                        imprimirjogador3(i, cont3, letra4, pontoj3, totaljog3);

                        printf("\n\nCartas da mesa:\n\n");
                        imprimirmesa(i, contmesa, letra2, pontom, totalmesa);

                        if(totaljog1 > 7.5){
                            totaljog1 = 0;
                            cortexto(preto, vermelho_claro);
                            printf("\n\nJogador 1 desqualificado!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        }

                        printf("\n\nO jogador 1 deseja puxar mais uma carta (s/n)? ");
                        scanf("\n%c%*c", &mais);
                        if (mais == 's'){
                            cont += 1;
                            limpatela();
                        }
                    }while(mais == 's');
                    maior = totaljog1;
                    limpatela();

                    do{ //Vez do jogador 2
                        cortexto(branco, vermelho_claro);
                        printf("\n\nVEZ DO JOGADOR 2\n\n");
                        cortexto(preto, cinza_claro);

                        printf("\n\nCartas do jogador 1:\n\n");
                        imprimirjogador1(i, cont, letra, pontoj, totaljog1);
                        if(totaljog1 == 0){
                            cortexto(preto, vermelho_claro);
                            printf("\n\nJogador 1 desqualificado!\n");
                            cortexto(preto, cinza_claro);
                        }

                        printf("\n\nCartas do jogador 2:\n\n");
                        totaljog2 = imprimirjogador2(i, cont2, letra3, pontoj2, totaljog2);

                        printf("\n\nCartas do jogador 3:\n\n");
                        imprimirjogador3(i, cont3, letra4, pontoj3, totaljog3);

                        printf("\n\nCartas da mesa:\n\n");
                        imprimirmesa(i, contmesa, letra2, pontom, totalmesa);

                        if(totaljog2 > 7.5){
                            totaljog2 = 0;
                            cortexto(preto, vermelho_claro);
                            printf("\n\nJogador 2 desqualificado!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        } else

                        printf("\n\nO jogador 2 deseja puxar mais uma carta (s/n)? ");
                        scanf("\n%c%*c", &mais);
                        if (mais == 's'){
                            cont2 += 1;
                            limpatela();
                        }
                    }while(mais == 's');
                    if(maior < totaljog2){
                        maior = totaljog2;
                    }
                    limpatela();

                    do{ //Vez do jogador 3
                        cortexto(branco, vermelho_claro);
                        printf("\n\nVEZ DO JOGADOR 3\n\n");
                        cortexto(preto, cinza_claro);

                        printf("\n\nCartas do jogador 1:\n\n");
                        imprimirjogador1(i, cont, letra, pontoj, totaljog1);
                        if(totaljog1 == 0){
                            cortexto(preto, vermelho_claro);
                            printf("\n\nJogador 1 desqualificado!\n");
                            cortexto(preto, cinza_claro);
                        }

                        printf("\n\nCartas do jogador 2:\n\n");
                        imprimirjogador2(i, cont2, letra3, pontoj2, totaljog2);
                        if(totaljog2 == 0){
                            cortexto(preto, vermelho_claro);
                            printf("\n\nJogador 2 desqualificado!\n");
                            cortexto(preto, cinza_claro);
                        }

                        printf("\n\nCartas do jogador 3:\n\n");
                        totaljog3 = imprimirjogador3(i, cont3, letra4, pontoj3, totaljog3);

                        printf("\n\nCartas da mesa:\n\n");
                        imprimirmesa(i, contmesa, letra2, pontom, totalmesa);

                        if(totaljog3 > 7.5){
                            totaljog3 = 0;
                            cortexto(preto, vermelho_claro);
                            printf("\n\nJogador 3 desqualificado!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        } else

                        printf("\n\nO jogador 3 deseja puxar mais uma carta (s/n)? ");
                        scanf("\n%c%*c", &mais);
                        if (mais == 's'){
                            cont3 += 1;
                            limpatela();
                        }
                    }while(mais == 's');
                    if(maior < totaljog3){
                        maior = totaljog3;
                    }
                    limpatela();

                    do{ //Vez da mesa
                        cortexto(branco, vermelho_claro);
                        printf("\n\nVEZ DA MESA\n\n");
                        cortexto(preto, cinza_claro);

                        printf("\n\nCartas do jogador 1:\n\n");
                        imprimirjogador1(i, cont, letra, pontoj, totaljog1);
                        if(totaljog1 == 0){
                            cortexto(preto, vermelho_claro);
                            printf("\n\nJogador 1 desqualificado!\n");
                            cortexto(preto, cinza_claro);
                        }

                        printf("\n\nCartas do jogador 2:\n\n");
                        imprimirjogador2(i, cont2, letra3, pontoj2, totaljog2);
                        if(totaljog2 == 0){
                            cortexto(preto, vermelho_claro);
                            printf("\n\nJogador 2 desqualificado!\n");
                            cortexto(preto, cinza_claro);
                        }

                        printf("\n\nCartas do jogador 3:\n\n");
                        imprimirjogador3(i, cont3, letra4, pontoj3, totaljog3);
                        if(totaljog3 == 0){
                            cortexto(preto, vermelho_claro);
                            printf("\n\nJogador 3 desqualificado!\n");
                            cortexto(preto, cinza_claro);
                        }

                        printf("\n\nCartas da mesa:\n\n");
                        totalmesa = imprimirmesa(i, contmesa, letra2, pontom, totalmesa);

                        //Comparações para ver quem ganha
                        if(totalmesa > 7.5){
                            totalmesa = 0;
                            esquecer = true;
                            cortexto(preto, vermelho_claro);
                            printf("\n\nMesa desqualificada!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        } else if((totalmesa >= maior)&&(totalmesa <= 7.5)){
                            maior = totalmesa;
                            cortexto(preto, amarelo);
                            printf("\n\nMesa ganhou!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        }

                        Sleep(1000);
                        contmesa += 1;
                        limpatela();
                    }while(totalmesa < maior);

                    //Comparações para ver quem ganha
                    if(esquecer == false){
                        break;
                    } else if (esquecer == true){
                        if(totaljog1 == maior){
                            cortexto(preto, amarelo);
                            printf("\n\nJogador 1 ganhou!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        } else if(totaljog2 == maior){
                            cortexto(preto, amarelo);
                            printf("\n\nJogador 2 ganhou!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        } else if(totaljog3 == maior){
                            cortexto(preto, amarelo);
                            printf("\n\nJogador 3 ganhou!\n");
                            cortexto(preto, cinza_claro);
                            break;
                        }
                        break;
                    }

                    break;

                default :
                    //Caso não insira de 1 a 4 jogadores, acusa erro
                    printf ("\nOpção inválida!\n");
                    printf ("\nPressione enter para continuar...");
                    while(getchar() != '\n');
                    getchar();
            }
            //Retornando variáveis aos valores iniciais
            esquecer = false;
            maior = 0;
            totaljog1 = 0;
            totalmesa = 0;
            totaljog2 = 0;
            totaljog3 = 0;
            cont = 1;
            contmesa = 1;
            cont2 = 1;
            cont3 = 1;
            for (i = 1; i <= 20; i++){
                pontoj[i] = 0;
            }
            printf("\nQuer jogar novamente (s/n)? ");
            scanf("\n%c%*c", &jogar);
            limpatela();
        }while(jogar == 's');
    }
	return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------------------

void SetWindow(int Width, int Height, int WidthBuffer, int HeightBuffer) //Função que muda tamanho da janela e do buffer da janela
{
    struct _COORD coord;
    coord.X = WidthBuffer;
    coord.Y = HeightBuffer;

    struct _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

//----------------------------------------------------------------------------------------------------------------------------------------------

void limpatela() //Função para limpar a tela
{
    WORD wColor = ((preto & 0x0F) << 4) + (cinza_claro & 0x0F);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SetConsoleTextAttribute(hStdOut, wColor);
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
        SetConsoleCursorPosition(hStdOut, coord);
    }
    return;
}

//----------------------------------------------------------------------------------------------------------------------------------------------

void cortexto(int fundo, int letras) //Função para mudas as cores do texto e do fundo
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letras | (fundo << 4));
}

//----------------------------------------------------------------------------------------------------------------------------------------------

void gerarcartasjog1(int i, int jog1, char letra[20][20], float pontoj[20]) //Função cartas jogador 1
{
    for(i = 1; i<16; i++){
        //Gera cartas suficientes para até a chance mínima de todas as cartas valerem 0.5 pontos
        jog1 = rand() % 10 + 1;
        if (jog1 == 1){
            strcpy(letra[i], "A");
            pontoj[i] += 1;
        } else if (jog1 == 8){
            strcpy(letra[i], "Q");
            pontoj[i] += 0.5;
        } else if (jog1 == 9){
            strcpy(letra[i], "J");
            pontoj[i] += 0.5;
        } else if (jog1 == 10){
            strcpy(letra[i], "K");
            pontoj[i] += 0.5;
        } else{
            itoa(jog1, letra[i], 10);
            pontoj[i] += jog1;
        }
    }
    return;
}

//----------------------------------------------------------------------------------------------------------------------------------------------

void gerarcartasmesa(int i, int jog1, char letra2[20][20], float pontom[20]) //Função cartas mesa
{
    for(i = 1; i<16; i++){
        //Gera cartas suficientes para até a chance mínima de todas as cartas valerem 0.5 pontos
        jog1 = rand() % 10 + 1;
        if (jog1 == 1){
            strcpy(letra2[i], "A");
            pontom[i] += 1;
        } else if (jog1 == 8){
            strcpy(letra2[i], "Q");
            pontom[i] += 0.5;
        } else if (jog1 == 9){
            strcpy(letra2[i], "J");
            pontom[i] += 0.5;
        } else if (jog1 == 10){
            strcpy(letra2[i], "K");
            pontom[i] += 0.5;
        } else{
            itoa(jog1, letra2[i], 10);
            pontom[i] += jog1;
        }
    }
    return;
}

//----------------------------------------------------------------------------------------------------------------------------------------------

void gerarcartasjog2(int i, int jog1, char letra3[20][20], float pontoj2[20]) //Função cartas jogador 2
{
    for(i = 1; i<16; i++){
        //Gera cartas suficientes para até a chance mínima de todas as cartas valerem 0.5 pontos
        jog1 = rand() % 10 + 1;
        if (jog1 == 1){
            strcpy(letra3[i], "A");
            pontoj2[i] += 1;
        } else if (jog1 == 8){
            strcpy(letra3[i], "Q");
            pontoj2[i] += 0.5;
        } else if (jog1 == 9){
            strcpy(letra3[i], "J");
            pontoj2[i] += 0.5;
        } else if (jog1 == 10){
            strcpy(letra3[i], "K");
            pontoj2[i] += 0.5;
        } else{
            itoa(jog1, letra3[i], 10);
            pontoj2[i] += jog1;
        }
    }
    return;
}

//----------------------------------------------------------------------------------------------------------------------------------------------

void gerarcartasjog3(int i, int jog1, char letra4[20][20], float pontoj3[20]) //Função cartas jogador 3
{
    for(i = 1; i<16; i++){
        //Gera cartas suficientes para até a chance mínima de todas as cartas valerem 0.5 pontos
        jog1 = rand() % 10 + 1;
        if (jog1 == 1){
            strcpy(letra4[i], "A");
            pontoj3[i] += 1;
        } else if (jog1 == 8){
            strcpy(letra4[i], "Q");
            pontoj3[i] += 0.5;
        } else if (jog1 == 9){
            strcpy(letra4[i], "J");
            pontoj3[i] += 0.5;
        } else if (jog1 == 10){
            strcpy(letra4[i], "K");
            pontoj3[i] += 0.5;
        } else{
            itoa(jog1, letra4[i], 10);
            pontoj3[i] += jog1;
        }
    }
    return;
}

//----------------------------------------------------------------------------------------------------------------------------------------------

float imprimirjogador1(int i, int cont, char letra[20][20], float pontoj[20], float totaljog1) //Função para imprimir as cartas do jogador 1
{
    totaljog1 = 0;
    for(i=1;i<cont+1;i++)
    {
        //Gerar um novo total, de acordo com a quantidade de cartas
        totaljog1 += pontoj[i];
    }
    //Imprimir cartas
    cortexto(branco, preto);
    for(i=0;i<cont;i++)
    {
        printf(" _____ ");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, preto);
    }
    printf("\n");
    for(i=0;i<cont;i++)
    {
        printf("|%s    |",letra[i+1]);
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, preto);
    }
    printf("\n");
    for(i=0;i<cont;i++)
    {
        printf("|     |");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, preto);
    }
    printf("\n");
    for(i=0;i<cont;i++)
    {
        printf("|     |");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, preto);
    }
    printf("\n");
    for(i=0;i<cont;i++)
    {
        printf("|     |");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, preto);
    }
    printf("\n");
    for(i=0;i<cont;i++)
    {
        printf("|    %s|",letra[i+1]);
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, preto);
    }
    printf("\n");
    for(i=0;i<cont;i++)
    {
        printf(" ----- ");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, preto);
    }
    cortexto(preto, cinza_claro);
    printf("\n");
    printf("\nPontos: %.1f", totaljog1);
    return totaljog1; //Retorna o total para ser analisado
}

//----------------------------------------------------------------------------------------------------------------------------------------------

float imprimirmesa(int i, int contmesa, char letra2[20][20], float pontom[20], float totalmesa) //Função para imprimir as cartas da mesa
{
    totalmesa = 0;
    for(i=1;i<contmesa+1;i++)
    {
        //Gerar um novo total, de acordo com a quantidade de cartas
        totalmesa += pontom[i];
    }
    //Imprimir cartas
    cortexto(branco, vermelho_claro);
    for(i=0;i<contmesa;i++)
    {
        printf(" _____ ");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, vermelho_claro);
    }
    printf("\n");
    for(i=0;i<contmesa;i++)
    {
        printf("|%s    |",letra2[i+1]);
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, vermelho_claro);
    }
    printf("\n");
    for(i=0;i<contmesa;i++)
    {
        printf("|     |");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, vermelho_claro);
    }
    printf("\n");
    for(i=0;i<contmesa;i++)
    {
        printf("|     |");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, vermelho_claro);
    }
    printf("\n");
    for(i=0;i<contmesa;i++)
    {
        printf("|     |");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, vermelho_claro);
    }
    printf("\n");
    for(i=0;i<contmesa;i++)
    {
        printf("|    %s|",letra2[i+1]);
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, vermelho_claro);
    }
    printf("\n");
    for(i=0;i<contmesa;i++)
    {
        printf(" ----- ");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, vermelho_claro);
    }
    cortexto(preto, cinza_claro);
    printf("\n");
    printf("\nPontos: %.1f", totalmesa);
    return totalmesa; //Retorna o total para ser analisado
}

//----------------------------------------------------------------------------------------------------------------------------------------------

float imprimirjogador2(int i, int cont2, char letra3[20][20], float pontoj2[20], float totaljog2) //Função para imprimir as cartas do jogador 1
{
    totaljog2 = 0;
    for(i=1;i<cont2+1;i++)
    {
        //Gerar um novo total, de acordo com a quantidade de cartas
        totaljog2 += pontoj2[i];
    }
    //Imprimir cartas
    cortexto(branco, azul_claro);
    for(i=0;i<cont2;i++)
    {
        printf(" _____ ");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, azul_claro);
    }
    printf("\n");
    for(i=0;i<cont2;i++)
    {
        printf("|%s    |",letra3[i+1]);
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, azul_claro);
    }
    printf("\n");
    for(i=0;i<cont2;i++)
    {
        printf("|     |");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, azul_claro);
    }
    printf("\n");
    for(i=0;i<cont2;i++)
    {
        printf("|     |");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, azul_claro);
    }
    printf("\n");
    for(i=0;i<cont2;i++)
    {
        printf("|     |");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, azul_claro);
    }
    printf("\n");
    for(i=0;i<cont2;i++)
    {
        printf("|    %s|",letra3[i+1]);
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, azul_claro);
    }
    printf("\n");
    for(i=0;i<cont2;i++)
    {
        printf(" ----- ");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, azul_claro);
    }
    cortexto(preto, cinza_claro);
    printf("\n");
    printf("\nPontos: %.1f", totaljog2);
    return totaljog2; //Retorna o total para ser analisado
}

//----------------------------------------------------------------------------------------------------------------------------------------------

float imprimirjogador3(int i, int cont3, char letra4[20][20], float pontoj3[20], float totaljog3) //Função para imprimir as cartas do jogador 1
{
    totaljog3 = 0;
    for(i=1;i<cont3+1;i++)
    {
        //Gerar um novo total, de acordo com a quantidade de cartas
        totaljog3 += pontoj3[i];
    }
    //Imprimir cartas
    cortexto(branco, verde);
    for(i=0;i<cont3;i++)
    {
        printf(" _____ ");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, verde);
    }
    printf("\n");
    for(i=0;i<cont3;i++)
    {
        printf("|%s    |",letra4[i+1]);
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, verde);
    }
    printf("\n");
    for(i=0;i<cont3;i++)
    {
        printf("|     |");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, verde);
    }
    printf("\n");
    for(i=0;i<cont3;i++)
    {
        printf("|     |");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, verde);
    }
    printf("\n");
    for(i=0;i<cont3;i++)
    {
        printf("|     |");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, verde);
    }
    printf("\n");
    for(i=0;i<cont3;i++)
    {
        printf("|    %s|",letra4[i+1]);
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, verde);
    }
    printf("\n");
    for(i=0;i<cont3;i++)
    {
        printf(" ----- ");
        cortexto(preto, cinza_claro);
        printf("\t");
        cortexto(branco, verde);
    }
    cortexto(preto, cinza_claro);
    printf("\n");
    printf("\nPontos: %.1f", totaljog3);
    return totaljog3; //Retorna o total para ser analisado
}
