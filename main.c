#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

#define TAM 7

void definirDimensoes(int *pdimL, int *pdimC)
{
    do
    {
        printf("\n Entre com a qtd de linhas do seu campo (>=3 e <=%i): ", TAM);
        scanf("%d", pdimL);

        if(*pdimL < 3 || *pdimL > TAM)
        {
            printf("\n Qtd de Linhas inválida! Tente novamente...");
            fflush(stdin);
            getchar();
        }
        system("cls");
    }
    while(*pdimL < 3 || *pdimL > TAM);

    do
    {
        printf("\n Entre com a qtd de colunas do seu campo (>=3 e <=%i): ", TAM);
        scanf("%d", pdimC);

        if(*pdimC < 3 || *pdimC > TAM)
        {
            printf("\n Qtd de Colunas inválida! Tente novamente...");
            fflush(stdin);
            getchar();
        }
        system("cls");
    }
    while(*pdimC < 3 || *pdimC > TAM);

}

void mostrarJogo(char campo[TAM][TAM], int dimL, int dimC)
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

void limparJogo(char campo[TAM][TAM])
{
    int l, c;

    for (l=0; l<TAM; l++)
    {
        for (c=0; c<TAM; c++)
        {
            campo[l][c]='#';
        }
    }
}

void calcularQtdLetras(int dimL, int dimC, float *qtdLetras)
{
    float dica;
    *qtdLetras = roundf((dimL * dimC)/2);
    
    dica = roundf((dimL * dimC)%2);

    printf("\nSeu jogo terá %.f Letras. E %.f Dicas.", *qtdLetras, dica);
}

void lancarLetras(float qtdLetras, char campo[TAM][TAM], int dimL, int dimC)
{
    int i, lAlet, cAlet, j, cAlet2, lAlet2;
    char letra;

    srand((unsigned)time(NULL) ); // Geracao da semente para gerar numeros randomicos diferentes
    for(i=1; i<=qtdLetras; i++)
    {
        letra = 'a' + (char)(rand()%26); //gero uma letra random
        
        
        
        lAlet = rand()%dimL;     // Numero aleatorio para a linha
        cAlet = rand()%dimC;     // Namero aleatorio para a coluna
        
        if (campo[lAlet][cAlet] == '#')
        {
            
            for(j=1; j<=2; j++){
                //Aqui eu lanco as letras duas vezes, para preencher o Tabuleiro
                campo[lAlet][cAlet] = toupper(letra);
            
                lAlet = rand()%dimL;     // Numero aleatorio para a linha
                cAlet = rand()%dimC;     // Numero aleatorio para a coluna
                
                if (campo[lAlet][cAlet] == '#'){
                    campo[lAlet][cAlet] = toupper(letra);
                } else {
                    printf("\n %c %c", toupper(campo[lAlet][cAlet]), toupper(letra));
                    if(campo[lAlet][cAlet] == toupper(letra)){
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
    char campo[TAM][TAM];
    char tela[TAM][TAM];
    int dimL = 0, dimC = 0;
    float qtdLetras = 0;
    float qtdJogadas = 0;
    int res;

    // Configura o software para português (permitindo utilizar acentuações)
    setlocale(LC_CTYPE, "portuguese");

    // 1 Passo - Usuário escolhe as dimensões
    definirDimensoes(&dimL, &dimC);
    printf("\n Jogo com dimensoes %d X %d\n", dimL, dimC);

    // 2 Passo - Calculo a qtde de Letras e Dicas
    calcularQtdLetras(dimL, dimC, &qtdLetras);
    
    // 3 Passo - Limpar campo colocando '#'
    limparJogo(campo);
    mostrarJogo(campo, dimL, dimC);
    
    // 4 Passo - Lancar Letras
    lancarLetras(qtdLetras, campo, dimL, dimC);
    mostrarJogo(campo, dimL, dimC);
    
    
    return 0;
    
}
