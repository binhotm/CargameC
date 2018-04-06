#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define MINTAM 3
#define MAXTAM 7
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


void configHead(){
	
	printf("#==============================================================#\n");
	printf("\t\t Jogo da Memoria:\n");	
    printf("\tConfigurações de Campo:\n");
    printf("\tEntre com a qtd de linhas do seu campo (>=3 e <=%i): \n", MAXTAM);      
	printf("#==============================================================#\n");
		
	printf("=====> ");
}

void definirDimensoes(int *pdimL, int *pdimC)
{
	


	
    do
    {
    	configHead();
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
    	configHead();
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

bool validaEntrada(char tela[MAXTAM][MAXTAM], int linha, int coluna){
	if ((coluna < 1 || coluna > MAXTAM) || (linha < 1 || linha > MAXTAM)){
		printf("Entre com uma COLUNA ou LINHA VALIDA! \n");
		return false;
	}else{
		
		if(tela[linha - 1][coluna-1] != '#'){
			printf("Campo ja utilizado!\n");
			return false;
		}			
		
		return true;
	}
}

char mostraCampo(char tela[MAXTAM][MAXTAM], char campo[MAXTAM][MAXTAM], int posicaoL, int posicaoC, int dmL, int dmC, float qtdLetras, float dicas, int qtdJogadas){
	
	posicaoL = posicaoL - 1;
	posicaoC = posicaoC - 1;	
		
	if (tela[posicaoL][posicaoC] == '#'){		
		
		tela[posicaoL][posicaoC] = campo[posicaoL][posicaoC];	
		
		showHeader(dmL, dmC, qtdLetras, dicas, qtdJogadas);
		mostrarJogo( tela, dmL, dmC);	
		
		return tela[posicaoL][posicaoC];
	
	}else{
		if(tela[posicaoL][posicaoC] == '?'){
			
		}
	}
	
}

void criaHeader(){
	printf("================================================================\n");
	printf("     ___                                                       \n");
	printf("       (   _   _   _     _ ) _     )\\/)  _   _ _   _   _ o  _  \n");
	printf("     \\__) (_) (_( (_)   (_( (_(   (  (  )_) ) ) ) (_) )  ( (_( \n");
	printf("                _)                     (_                      \n");
	printf("por: Fabricio Junior da Silva\n");
	printf("por: Vagner Alves Leite\n");
}

void showHeader(int dimL, int dimC, float qtdLetras, float dicas, int qtdJogadas){
		system("cls");
		criaHeader();    
	    printf("#==============================================================#\n");
	    printf("\t\t Info: Jogo com dimensoes %d X %d\n", dimL, dimC);
	    printf("\t\tSeu jogo terá %.f Letras. E %.f Dicas. \n", qtdLetras, dicas);   
	    printf("\t\tJogadas: %d \n", qtdJogadas);
		printf("#==============================================================#\n");
}

int main()
{
    char campo[MAXTAM][MAXTAM];
    char tela[MAXTAM][MAXTAM];
    int dimL = 0, dimC = 0;
    float qtdLetras = 0;
    float dicas = 0;
    int qtdJogadas = 0;
    bool gameOn = true;
    
    char letra1, letra2;

	//Linhas e colunas Jogadas
	int cPlay1, lPlay1, cPlay2, lPlay2;
	
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
    limparJogo(tela);
    
    // 4 Passo - Preencher os espacos do Tabuleiro
    writeSpaces(qtdLetras,dicas, campo, dimL, dimC);
    
    
    while(gameOn){
    	
    	//Cria cabecalho formatado
		showHeader(dimL, dimC, qtdLetras, dicas, qtdJogadas);
    	
		mostrarJogo(tela, dimL, dimC);
		//mostrarJogo(campo, dimL, dimC);
	    	
    	printf("Entre com a linha e Coluna: ex: \n");
    	scanf("%d %d", &lPlay1, &cPlay1);
		
		if(!validaEntrada(tela, lPlay1, cPlay1)){
			system("pause");
			continue;
		}		

		letra1 = mostraCampo(tela, campo, lPlay1, cPlay1, dimL, dimC, qtdLetras, dicas, qtdJogadas);
		
		
		printf("Entre com a linha e Coluna: ex: \n");
    	scanf("%d %d", &lPlay2, &cPlay2);
		
		if(!validaEntrada(tela, cPlay2, lPlay2)){
			system("pause");
			continue;
		}
		
		letra2 = mostraCampo(tela, campo, lPlay2, cPlay2, dimL, dimC, qtdLetras, dicas, qtdJogadas);
		
		
		if( letra1 != letra2){			
			sleep(3);
			
			tela[lPlay1-1][cPlay1-1] = '#';
			tela[lPlay2-1][cPlay2-1] = '#';			
		}	
		    	
    	qtdJogadas++; 
	}
    

        
    return 0;    
}
