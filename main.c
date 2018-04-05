#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define MAXTAM 7

void definirDimensoes(int *pdimL, int *pdimC)
{
    do
    {
        printf("\n Entre com a qtd de linhas do seu campo (>=3 e <=%i): ", MAXTAM);
        scanf("%d", pdimL);

        if(*pdimL < 3 || *pdimL > MAXTAM)
        {
            printf("\n Qtd de Linhas inválida! Tente novamente...");
            fflush(stdin);
            getchar();
        }
        system("cls");
    }
    while(*pdimL < 3 || *pdimL > MAXTAM);

    do
    {
        printf("\n Entre com a qtd de colunas do seu campo (>=3 e <=%i): ", MAXTAM);
        scanf("%d", pdimC);

        if(*pdimC < 3 || *pdimC > MAXTAM)
        {
            printf("\n Qtd de Colunas inválida! Tente novamente...");
            fflush(stdin);
            getchar();
        }
        system("cls");
    }
    while(*pdimC < 3 || *pdimC > MAXTAM);

}

void mostrarJogo(char campo[MAXTAM][MAXTAM], int dimL, int dimC)
{
    int l, c;

    printf("\n");

    // Imprimir legenda da coluna
    printf("   ");
    for (c=1; c<dimC+1; c++)
    {
        printf("%2i ", c);
    }
    printf("\n");

    // Imprimir celulas da matriz
    for (l=0; l<dimL; l++)
    {
        printf("%2i ", l+1);

        for (c=0; c<dimC; c++)
        {
            printf(" %c ", campo[l][c]);
        }
        printf("\n");
    }
}

void limparJogo(char campo[MAXTAM][MAXTAM])
{
    int l, c;

    for (l=0; l<MAXTAM; l++)
    {
        for (c=0; c<MAXTAM; c++)
        {
            campo[l][c]='#';
        }
    }
}

float calcularQtdLetras(int dimL, int dimC, float *qtdLetras)
{
	float dicas = 0;
    *qtdLetras = roundf((dimL * dimC)/2);
    
    dicas = roundf((dimL * dimC)%2);

    printf("\nSeu jogo terá %.f Letras. E %.f Dicas. \n", *qtdLetras, dicas);
    
    return dicas;
}

void preencherTabuleiro(float qtdLetras, char campo[MAXTAM][MAXTAM], int dimL, int dimC, float dicas)
{
    int i, lAlet, cAlet, j, cAlet2, lAlet2;
    char letra;

    srand((unsigned)time(NULL) ); // Geracao da semente para gerar numeros randomicos diferentes
    
    
	for(i=1; i<=qtdLetras; i++)
    {
        letra = toupper('a' + (char)(rand()%26)); //gero uma letra random
      
		//	printf("Letra ramdon %c \n", letra);       
        
        lAlet = rand()%dimL;     // Numero aleatorio para a linha
        cAlet = rand()%dimC;     // Namero aleatorio para a coluna
        
        printf("LINHA: %i \n", lAlet);
        printf("COLUNA: %i  \n", cAlet);
        printf("CARACTER: %c \n", letra);
        
        
        if (campo[lAlet][cAlet] == '#')
        {
            
            for(j=1; j<=2; j++){
                //Aqui eu lanco as letras duas vezes, para preencher o Tabuleiro
                campo[lAlet][cAlet] = letra;
            
                lAlet = rand()%dimL;     // Numero aleatorio para a linha
                cAlet = rand()%dimC;     // Numero aleatorio para a coluna
                
                if (campo[lAlet][cAlet] == '#'){
                    campo[lAlet][cAlet] = letra;
                } else {
                
                    if(campo[lAlet][cAlet] == letra){
                        campo[lAlet][cAlet] = '#'; 
                        i--;
                    } 
                }
            }
            
        }
        else {
            i--;
        }
    }
}



int main()
{
    char campo[MAXTAM][MAXTAM];
    char tela[MAXTAM][MAXTAM];
    int dimL = 0, dimC = 0;
    float qtdLetras = 0;
    float dicas = 0;
    float qtdJogadas = 0;
    int res;

    // Configura o software para português (permitindo utilizar acentuações)
    setlocale(LC_CTYPE, "portuguese");

    // 1 Passo - Usuário escolhe as dimensões
    definirDimensoes(&dimL, &dimC);
    printf("\n Jogo com dimensoes %d X %d\n", dimL, dimC);

    // 2 Passo - Calculo a qtde de Letras e Dicas
    dicas = calcularQtdLetras(dimL, dimC, &qtdLetras);
    
    // 3 Passo - Limpar campo colocando '#'
    limparJogo(campo);
    
    // 4 Passo - Preencher os espacos do Tabuleiro
    preencherTabuleiro(qtdLetras, campo, dimL, dimC, dicas);
    
    mostrarJogo(campo, dimL, dimC);
    
    
    return 0;
    
}
