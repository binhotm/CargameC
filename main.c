#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>

#define MAXTAM 7
#define MINTAM 3
#define MAXLETRASIGUAIS 2

/***
 *         ¦¦+ ¦¦¦¦¦¦+  ¦¦¦¦¦¦+  ¦¦¦¦¦¦+     ¦¦¦+   ¦¦¦+¦¦¦¦¦¦¦+¦¦¦+   ¦¦¦+ ¦¦¦¦¦¦+ ¦¦¦¦¦¦+ ¦¦+ ¦¦¦¦¦+ 
 *         ¦¦¦¦¦+---¦¦+¦¦+----+ ¦¦+---¦¦+    ¦¦¦¦+ ¦¦¦¦¦¦¦+----+¦¦¦¦+ ¦¦¦¦¦¦¦+---¦¦+¦¦+--¦¦+¦¦¦¦¦+--¦¦+
 *         ¦¦¦¦¦¦   ¦¦¦¦¦¦  ¦¦¦+¦¦¦   ¦¦¦    ¦¦+¦¦¦¦+¦¦¦¦¦¦¦¦+  ¦¦+¦¦¦¦+¦¦¦¦¦¦   ¦¦¦¦¦¦¦¦¦++¦¦¦¦¦¦¦¦¦¦¦
 *    ¦¦   ¦¦¦¦¦¦   ¦¦¦¦¦¦   ¦¦¦¦¦¦   ¦¦¦    ¦¦¦+¦¦++¦¦¦¦¦+--+  ¦¦¦+¦¦++¦¦¦¦¦¦   ¦¦¦¦¦+--¦¦+¦¦¦¦¦+--¦¦¦
 *    +¦¦¦¦¦+++¦¦¦¦¦¦+++¦¦¦¦¦¦+++¦¦¦¦¦¦++    ¦¦¦ +-+ ¦¦¦¦¦¦¦¦¦¦+¦¦¦ +-+ ¦¦¦+¦¦¦¦¦¦++¦¦¦  ¦¦¦¦¦¦¦¦¦  ¦¦¦
 *     +----+  +-----+  +-----+  +-----+     +-+     +-++------++-+     +-+ +-----+ +-+  +-++-++-+  +-+
 *
 * Por: Fabricio Junior da Silva, Vager Alves Leite
 * Fatec Americana
 *                                                                                                     
 */


int getRandL(dimL){	
	return rand()%dimL;  //Retorna numero aleatorio da Linha      
}

int getRandC(dimC){
	return rand()%dimC; //Retonar numero aleatorio da Coluna
}

void definirDimensoes(int *pdimL, int *pdimC)
{
    do
    {
        printf("\n Entre com a qtd de linhas do seu campo (>=3 e <=%i): ", MAXTAM);
        scanf("%d", pdimL);

        if(*pdimL < MINTAM || *pdimL > MAXTAM)
        {
            printf("\n Qtd de Linhas inválida! Tente novamente...");
            fflush(stdin);
            getchar();
        }
        system("cls");
    }
    while(*pdimL < MINTAM || *pdimL > MAXTAM);

    do
    {
        printf("\n Entre com a qtd de colunas do seu campo (>=3 e <=%i): ", MAXTAM);
        scanf("%d", pdimC);

        if(*pdimC < MINTAM || *pdimC > MAXTAM)
        {
            printf("\n Qtd de Colunas inválida! Tente novamente...");
            fflush(stdin);
            getchar();
        }
        system("cls");
    }
    while(*pdimC < MINTAM || *pdimC > MAXTAM);

}

void mostrarJogo(char campo[MAXTAM][MAXTAM], int dimL, int dimC)
{
    int l, c;
    char c1 = '-';
	    
    printf("\n");
	
	printf("     ");
    // Imprimir legenda da coluna
    for (c=1; c<dimC+1; c++)
    {
        printf(" %3d ", c);
        
    }
     	
 	printf("\n");
 	printf("     ");
 
    
    for (c=1; c<dimC+1; c++)
    {
        printf(" %3c ", c1);
        
    }
 	
 	printf("\n");

    // Imprimir celulas da matriz
    for (l=0; l<dimL; l++)
    {
   		
   		printf(" %3d|", l+1);
        
        for (c=0; c<dimC; c++)
        {
          
			printf(" %3c ", campo[l][c]);
		
        }
        printf("\n\n");
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

float calcularQtdLetras(int dimL, int dimC)
{
    return roundf((dimL * dimC)/2);
}

float calcularDicas(int dimL, int dimC)
{    
	return roundf((dimL * dimC)%2);	
}

bool verificaLetra(char letra, char campo[MAXTAM][MAXTAM]){
	
	int l, c;

    for (l=0; l<MAXTAM; l++)
    {
        for (c=0; c<MAXTAM; c++)
        {
            
			if (campo[l][c] == letra){
				return true;
			}	
	
        }
    }
    
    return false;	
}

void adicionaDica(char campo[MAXTAM][MAXTAM]){
	
	int l, c;

    for (l=0; l<MAXTAM; l++)
    {
        for (c=0; c<MAXTAM; c++)
        {
            
			if (campo[l][c] == '#'){
				campo[l][c]='?';
			}	
	
        }
    }
}

void writeSpaces(float qtdLetras,float dicas, char campo[MAXTAM][MAXTAM], int dimL, int dimC)
{
	int i, lAlet, cAlet, qtLetras;   
    char letra;
    
    qtLetras = (int)qtdLetras; 
	int d = (int)dicas;    

    srand((unsigned)time(NULL)); // Geracao da semente para gerar numeros randomicos diferentes
       
	while(qtLetras > 0)
    {
        letra = toupper('a' + (char)(rand()%26)); //gero uma letra random
        int totalLetras = 1;
        bool ret = verificaLetra(letra, campo);
          
        //Verifica se Letra ja foi lancada
        if(ret == false){
        		while(totalLetras <= MAXLETRASIGUAIS){			
				  
			        lAlet = getRandL(dimL);    // Numero aleatorio para a linha
			        cAlet = getRandC(dimC);    // Namero aleatorio para a coluna       
			    		   
			        if (campo[lAlet][cAlet] == '#')
			        {
			            campo[lAlet][cAlet] = letra;  
			            totalLetras++;
			        }				
				}				
					
				qtLetras--;	
		
		}	     
             
   }
   
   //Dica 
	if(d > 0){
		adicionaDica(campo);
	}  	
   
}

bool validaEntrada(int coluna, int linha){
	if ((coluna < 1 || coluna > MAXTAM) || (linha < 1 || linha > MAXTAM)){
		printf("Entre com uma COLUNA ou LINHA VALIDA! \n");
		return false;
	}else{
		return true;
	}
}

void criaHeader(){
	printf("================================================================\n");
	printf("     ___                                                       \n");
	printf("       (   _   _   _     _ ) _     )\\/)  _   _ _   _   _ o  _  \n");
	printf("     \\__) (_) (_( (_)   (_( (_(   (  (  )_) ) ) ) (_) )  ( (_( \n");
	printf("                _)                     (_                      \n");

}

int main()
{
    char campo[MAXTAM][MAXTAM];
    char tela[MAXTAM][MAXTAM];
    int dimL = 0, dimC = 0;
    float qtdLetras = 0;
    float dicas = 0;
    float qtdJogadas = 0;
    

	//Linhas e colunas Jogadas
	int cPlay, lPlay;
	
    // Configura o software para português (permitindo utilizar acentuações)
    setlocale(LC_CTYPE, "portuguese");

    // 1 Passo - Usuário escolhe as dimensões
    definirDimensoes(&dimL, &dimC);
    
    //Calcula Letras e Dicas
    qtdLetras = calcularQtdLetras(dimL, dimC);
    dicas = calcularDicas(dimL, dimC);
    
    printf("\t\tSeu jogo terá %.f Letras. E %.f Dicas. \n", qtdLetras, dicas);  
     
    // 3 Passo - Limpar campo colocando '#'
    limparJogo(campo);
    
    // 4 Passo - Preencher os espacos do Tabuleiro
    writeSpaces(qtdLetras,dicas, campo, dimL, dimC);
    
    
    while(true){
    	system("cls");
    	
    	criaHeader();    
	    printf("#==============================================================#\n");
	    printf("\t\t Info: Jogo com dimensoes %d X %d\n", dimL, dimC);
	    printf("\t\tSeu jogo terá %.f Letras. E %.f Dicas. \n", qtdLetras, dicas);   
	    printf("\t\tJogadas: %d \n", qtdJogadas);
		printf("#==============================================================#\n");
		
		mostrarJogo(campo, dimL, dimC);
	    	
    	printf("Entre com a linha e Coluna: ex: \n");
    	scanf("%d %d", &lPlay, &cPlay);
		
		if(!validaEntrada(cPlay, lPlay)){
			system("pause");
			continue;
		}
		    	
    	qtdJogadas = qtdJogadas + 1; 
	}
    

        
    return 0;    
}
