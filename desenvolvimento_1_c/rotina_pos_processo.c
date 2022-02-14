#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
	Codigo desenvolvido por Gustavo Alves Coelho, 09/06/2020
	Menu adequado, com todas funcoes funcionando, ainda sera levado ao teste definitivo.
*/

//------------------------------------------COME�O PARTE PROCESSAMENTO
struct _DADOS_ 
{
	int coluna;
	double soma_x, soma_y, soma_z;
	float x, y, z;
	struct _DADOS_ * proxima;
	struct _DADOS_ * anterior;
};
typedef struct _DADOS_ * dados;

struct _DADOS_ *inicio_colunas, *fim_colunas;
void dividir(double x);
void leitura_arquivo(char nome_in[50], int qtd_coord, int itmin, int qtd_linhas);
dados add_dados(int coluna, float x, float y,float z,double soma_x,double soma_y,double soma_z,dados anterior);
dados procurar_coluna(int coluna);
void adc_valor(double valor_x, double valor_y,double valor_z, int coluna);
void exibir_coordenadas();
void exibir_somas();
void limpar_dados();
void arq_saida(int coord, int linhas, int itmin, char nome_in[50]);
void ler_coluna(char nome_in[50],int colunas, int linhas);
//FIM

//------------------------------------------COMECO PARTE LIMPA TEXTO
struct _LETRAS_
{
	char letra;
	struct _LETRAS_ * proxima;
	struct _LETRAS_ * anterior;
};
typedef struct _LETRAS_ *letras;

void ler_caracteres();
letras add_letras(char letra, letras anterior);
letras pular_enderecos(letras aux1, char fechamento, char fechamento_2);
void retirar_letras();
void limpar_dados2(struct _LETRAS_ *lista);

struct _LETRAS_ * inicio_lista_letras, *fim_lista_letra;
struct _LETRAS_ * inicio_limpo, * fim_limpo;

void retira_parenteses(int x); //processo a ser feito apos retirar os probes ou time
//FIM

//------------------------------------------COMECO PARTE CALCULOS
void desvio_padrao(int qtd_colunas, int linhas, int itmin, int escolha, char nome_in[50], char nome_out[50], int l, int desejado); 
double media_ponto(int ponto, int escolha);

double somatorio(int desejado, int escolha, int sub, char nome_in[50],int colunas, int linhas, int itmin); //x = define se � x, y ou z
double somatorio_quadrado(int desejado, int escolha, int sub, char nome_in[50],int colunas, int linhas, int itmin);
double numerador(double soma_juntos, double somatoria_1, double somatoria_2, int sub);
double denominador(double somatoria_1, double somatoria_2, double somatoria_11, double somatoria_22, int sub);
void correlacao(int desejado_1, int desejado_2, int ponto_1, int ponto_2, int sub, char nome_in[50],int colunas, int linhas, int itmin);
double somatorio_juntos(int desejado_1, int desejado_2, int ponto_1, int ponto_2, int sub, char nome_in[50],int colunas, int linhas, int itmin); //x = define se � x, y ou z
//FIM

void arq_saida_grafico(int escolha_x, int escolha_y, int escolha_z, int escolha_geral);
void achar_time(float time_escolhido,int colunas,int itmin,char nome_in[50],int linhas);

void menu()
{
	int escolha, i = 0, j = 0, lido = 0, qtd_coord, itmin, qtd_linhas, sub, ponto_1, ponto_2, desejado_1, desejado_2, ler_ok = 0;
	char nome_in[50];
	float time_escolhido = 0;
	int escolha_x = 0, escolha_y = 0, escolha_z = 0;
	
	do
	{
		
		printf("\n---ESCOLHA A OPCAO A PARTIR DO NUMERO:---");
		printf("\n---Obs: ao trabalhar com dados novos os leia---");
		printf("\n---1. FORMARTAR O TEXTO E PREPARAR PARA LEITURA---"); //funciona
		printf("\n---2. FAZER A LEITURA DOS DADOS---"); //funciona
		printf("\n---3. EXIBIR COORDENADAS---"); //funciona
		printf("\n---4. EXIBIR VELOCIDADES MEDIAS---"); //funciona
		printf("\n---5. GERAR ARQUIVO DE SAIDA---"); //funciona
		printf("\n---6. GERAR SERIE TEMPORAL---"); //funciona
		printf("\n---7. CALCULAR CORRELACAO---"); //funciona
		printf("\n---8. CALCULAR CORRELACAO DE UM UNICO PONTO---"); //correlacao de um unico ponto
		printf("\n---9. GERAR DADOS PARA CRIACAO DE GRAFICOS---"); //grafico
		printf("\n---10. ENCERRAR EXECUCAO---\n");
		printf("\nOpcao: ");
		scanf("%d",&escolha);

		system("cls || clear");
	
			switch(escolha)
			{		
				case 1:
					ler_caracteres();
					limpar_dados2(inicio_lista_letras); //fazeer limpeza automaticamente
					break;
			
				case 2:				
					printf("\nInforme o nome do arquivo a ser lido: ");
					scanf("%s",nome_in);	
					
					printf("\nQuantos pontos possui a amostra? ");
					scanf("%d",&qtd_coord);
					
					printf("\nA partir de qual iteracao deseja calcular a media? ");
					scanf("%d",&itmin);
					
					printf("\nQual o total de iteracoes? ");
					scanf("%d",&qtd_linhas);
					
					leitura_arquivo(nome_in, qtd_coord, itmin, qtd_linhas);
					ler_ok = 1;
					sub = qtd_linhas - itmin + 1;
					break;
					
				case 3:
					if(ler_ok == 1)
					{
						exibir_coordenadas();
					}else
					{ //garantir que o arquivo foi lido
						printf("\nARQUIVO NAO FOI LIDO AINDA, INFORME: ");
						printf("\nInforme o nome do arquivo a ser lido: ");
						scanf("%s",nome_in);	
						
						printf("\nQuantos pontos possui a amostra? ");
						scanf("%d",&qtd_coord);
						
						printf("\nA partir de qual iteracao deseja calcular a media? ");
						scanf("%d",&itmin);
						
						printf("\nQual o total de iteracoes? ");
						scanf("%d",&qtd_linhas);
						
						leitura_arquivo(nome_in, qtd_coord, itmin, qtd_linhas);
						sub = qtd_linhas - itmin + 1;
						ler_ok = 1;
						exibir_coordenadas();
					}
					break;
					
				case 4:
					if(ler_ok == 1)
					{
						exibir_somas();
					}else
					{
						printf("\nARQUIVO NAO FOI LIDO AINDA, INFORME: ");
						printf("\nInforme o nome do arquivo a ser lido: ");
						scanf("%s",nome_in);	
						
						printf("\nQuantos pontos possui a amostra? ");
						scanf("%d",&qtd_coord);
						
						printf("\nA partir de qual iteracao deseja calcular a media? ");
						scanf("%d",&itmin);
						
						printf("\nQual o total de iteracoes? ");
						scanf("%d",&qtd_linhas);
						
						leitura_arquivo(nome_in, qtd_coord, itmin, qtd_linhas);
						sub = qtd_linhas - itmin + 1;
						ler_ok = 1;
						exibir_somas();
					}
					break;
					
				case 5:
					if(ler_ok == 1)
					{
						arq_saida(qtd_coord, qtd_linhas, itmin,nome_in);
					}else
					{
						printf("\nARQUIVO NAO FOI LIDO AINDA, INFORME: ");
						printf("\nInforme o nome do arquivo a ser lido: ");
						scanf("%s",nome_in);	
						
						printf("\nQuantos pontos possui a amostra? ");
						scanf("%d",&qtd_coord);
						
						printf("\nA partir de qual iteracao deseja calcular a media? ");
						scanf("%d",&itmin);
						
						printf("\nQual o total de iteracoes? ");
						scanf("%d",&qtd_linhas);
						
						leitura_arquivo(nome_in, qtd_coord, itmin, qtd_linhas);
						sub = qtd_linhas - itmin + 1;
						ler_ok = 1;
						arq_saida(qtd_coord, qtd_linhas, itmin,nome_in);
					}
					break;
					
				case 6:
					ler_coluna(nome_in, qtd_coord, qtd_linhas);	
					break;	
	
				case 7:
					if(ler_ok == 1)
					{
						exibir_coordenadas();
						printf("\nDeseja calcular a correlacao entre quais pontos? \nPonto 1: ");
						scanf("%d",&ponto_1);
						printf("\nDeseja considerar qual coordenada nesse ponto?\n 1 = x, 2 = y e 3 = z: ");
						scanf("%d",&desejado_1);
						
						printf("\nPonto 2: ");
						scanf("%d",&ponto_2);
						printf("\nDeseja considerar qual coordenada nesse ponto?\n 1 = x, 2 = y e 3 = z: ");
						scanf("%d",&desejado_2);											
						
						correlacao(desejado_1, desejado_2, ponto_1, ponto_2, sub, nome_in, qtd_coord, qtd_linhas, itmin);				
					}else
					{
						printf("\nARQUIVO NAO FOI LIDO AINDA, INFORME: ");
						printf("\nInforme o nome do arquivo a ser lido: ");
						scanf("%s",nome_in);	
						getchar();
						printf("\nQuantos pontos possui a amostra? ");
						scanf("%d",&qtd_coord);
						
						printf("\nA partir de qual iteracao deseja calcular a media? ");
						scanf("%d",&itmin);
						
						printf("\nQual o total de iteracoes? ");
						scanf("%d",&qtd_linhas);
						
						leitura_arquivo(nome_in, qtd_coord, itmin, qtd_linhas);
						sub = qtd_linhas - itmin + 1;
						ler_ok = 1;
						
						exibir_coordenadas();
						printf("\nDeseja calcular a correlacao entre quais pontos? \nPonto 1: ");
						scanf("%d",&ponto_1);
						printf("\nDeseja considerar qual coordenada nesse ponto?\n 1 = x, 2 = y e 3 = z: ");
						scanf("%d",&desejado_1);
						
						printf("\nPonto 2: ");
						scanf("%d",&ponto_2);
						printf("\nDeseja considerar qual coordenada nesse ponto?\n 1 = x, 2 = y e 3 = z: ");
						scanf("%d",&desejado_2);											
						
						correlacao(desejado_1, desejado_2, ponto_1, ponto_2, sub, nome_in, qtd_coord, qtd_linhas, itmin);	
					}
					break;	
					
				case 8: //correla��o unica
				
				if(ler_ok == 1)
				{
					exibir_coordenadas();
					
					printf("Informe o valor a ser escolhido: ");
					scanf("%f",&time_escolhido);
					
					achar_time(time_escolhido,qtd_coord,0,nome_in,qtd_linhas);
				}else
				{
					printf("\nARQUIVO NAO FOI LIDO AINDA, INFORME: ");
					printf("\nInforme o nome do arquivo a ser lido: ");
					scanf("%s",nome_in);	
					getchar();
					printf("\nQuantos pontos possui a amostra? ");
					scanf("%d",&qtd_coord);
					
					printf("\nA partir de qual iteracao deseja calcular a media? ");
					scanf("%d",&itmin);
					
					printf("\nQual o total de iteracoes? ");
					scanf("%d",&qtd_linhas);
					
					leitura_arquivo(nome_in, qtd_coord, itmin, qtd_linhas);
					sub = qtd_linhas - itmin + 1;
					ler_ok = 1;
						
					exibir_coordenadas();
					
					printf("Informe o valor a ser escolhido: ");
					scanf("%f",&time_escolhido);
					
					achar_time(time_escolhido,qtd_coord,0,nome_in,qtd_linhas);
				}
				
					break;
					
				case 9: //gerar arquivo para gera��o de grafico
					
				if(ler_ok == 1)
				{
					printf("Deseja gerar grafico de X, Y ou Z: \n1 = X\n2 = Y\n3 = Z\n"); //gerar grafico de todas velocidades esta parado, mas funciona
					scanf("%d",&escolha_x);
					
					if(escolha_x != 0)
					{
						switch(escolha_x)
						{
							case 1: //procura apenas X
								escolha_x = 1;
								break;
							
							case 2: //procura apenas Y
								escolha_y = 1;
								break;
								
							case 3: //procura X e Y
								escolha_z = 1;
								break;
						}
					}
					
					arq_saida_grafico(escolha_x,escolha_y,escolha_z,0);
				}else
				{
					printf("\nARQUIVO NAO FOI LIDO AINDA, INFORME: ");
					printf("\nInforme o nome do arquivo a ser lido: ");
					scanf("%s",nome_in);	
					getchar();
					printf("\nQuantos pontos possui a amostra? ");
					scanf("%d",&qtd_coord);
					
					printf("\nA partir de qual iteracao deseja calcular a media? ");
					scanf("%d",&itmin);
					
					printf("\nQual o total de iteracoes? ");
					scanf("%d",&qtd_linhas);
					
					leitura_arquivo(nome_in, qtd_coord, itmin, qtd_linhas);
					sub = qtd_linhas - itmin + 1;
					ler_ok = 1;
					
					printf("Deseja gerar grafico de X ou Y? \n1 = X\n2 = Y\n3 = Z\n"); //gerar grafico de todas velocidades esta parado, mas funciona
					scanf("%d",&escolha_x);
					
					if(escolha_x != 0)
					{
						switch(escolha_x)
						{
							case 1: //procura apenas X
								escolha_x = 1;
								break;
							
							case 2: //procura apenas Y
								escolha_y = 1;
								break;
								
							case 3: //procura X e Y
								escolha_z = 1;
								break;
						}
					}
					
					arq_saida_grafico(escolha_x,escolha_y,escolha_z,0);
					
					break;	
				}
			}
	}while(escolha != 10);	
}

void main()
{
	menu();
	
	limpar_dados(inicio_colunas); //fazer limpeza ao final automaticameente
}

void arq_saida_grafico(int escolha_x, int escolha_y, int escolha_z, int escolha_geral)
{
	int l = 0;
	struct _DADOS_ *aux;
	aux = inicio_colunas;
	FILE *arq;
	int contador_y = 0, aux_cont_y = 0;
	char nome_x[50], nome_y[50], nome_z[50];
	
	/*
	printf("\n---1. SAIDA DAS VELOCIDADES DE X");
	printf("\n---2. SAIDA DAS VELOCIDADES DE Y");
	printf("\n---3. SAIDA DAS VELOCIDADES DE Z");
	printf("\n---4. SAIDA DE TODAS VELOCIDADES");
	*/
	
	if(escolha_x == 1)
	{
		printf("Informe o nome do arquivo de saida X \n(LEMBRAR NA HORA DA CHAMADA DO PYTHON)\n");
		scanf("%s",nome_x);
		
		arq = fopen(nome_x,"w+b");					
		while(aux != NULL)
		{
			fprintf(arq,"/%.30lf",aux->soma_x);
			aux = aux->proxima;
			contador_y++;
		}
		
		fprintf(arq,"/y");
		while(aux_cont_y < contador_y)
		{
			fprintf(arq,"/%d",aux_cont_y);
			aux_cont_y++;	
		}
		
		fclose(arq);
		escolha_x == 0;
	}
		
	aux = inicio_colunas;
		
	if(escolha_y == 1)
	{
		printf("Informe o nome do arquivo de saida Y \n(LEMBRAR NA HORA DA CHAMADA DO PYTHON)\n");
		scanf("%s",nome_y);
		
		arq = fopen(nome_y,"w+b");	
		while(aux != NULL)
		{
			fprintf(arq,"/%.30lf",aux->soma_y);
			aux = aux->proxima;
			contador_y++;
		}
		
		fprintf(arq,"/y");
		while(aux_cont_y < contador_y)
		{
			fprintf(arq,"/%d",aux_cont_y);
			aux_cont_y++;	
		}
		
		fclose(arq);
		escolha_y == 0;
	}
		
	aux = inicio_colunas;
		
	if(escolha_z == 1)
	{
		printf("Informe o nome da saida de Z\n(LEMBRAR NA HORA DA CHAMADA DO PYTHON)\n");
		scanf("%s",nome_z);
		
		arq = fopen(nome_z,"w+b");	
		while(aux != NULL)
		{
			fprintf(arq,"/%.30lf",aux->soma_z);
			aux = aux->proxima;
			contador_y++;
		}
		
		fprintf(arq,"/y");
		while(aux_cont_y < contador_y)
		{
			fprintf(arq,"/%d",aux_cont_y);
			aux_cont_y++;	
		}
		
		fclose(arq);
		escolha_z == 0;
	}
		
	if(escolha_geral == 1)
	{
		fprintf(arq,"Ux\tUy\tUz\t\n"); 
		while(aux != NULL)
		{
			fprintf(arq,"%.30lf\t%.30lf\t%.30lf\n",aux->soma_x,aux->soma_y,aux->soma_z);
			
			aux = aux->proxima;
		}
		fclose(arq);		
	}
}

void achar_time(float time_escolhido,int colunas,int itmin,char nome_in[50],int linhas)
{
	char nome_out[50];
	FILE *arq_out;
	FILE *arq;
	float aux_y=0,x=0,y=0,z=0, tempo;
	int qtd_colunas = 0, i = 0, ok_escrever = 0;
	double c_x, c_y, c_z;
	
	arq_out = fopen("arquivo_saida_coord","w+");
	arq = fopen(nome_in,"r");
	
	for(i = 0; i < colunas; i++) //LENDO AS COORDENADAS
	{ 
	fscanf(arq,"%f %f %f", &x, &y, &z); //ler Y e escrever no arq de saida seus valores ao quadrado
	
	aux_y = y*y;
	fprintf(arq_out,"%f/",aux_y);
	}
	
	fprintf(arq_out,"x/");
	
	for(i = 2; i < linhas + 2; i++) //le as linhas com os valores
	{
	fscanf(arq,"%f",&tempo); //le o tempo inicial		
	
	if(tempo == time_escolhido)
	{
		ok_escrever = 1;
	}
	
		for(qtd_colunas = 0; qtd_colunas < colunas;  qtd_colunas++) //leitura das colunas
		{	
			if(i > itmin) //pular endere�os indesejados
			{
				fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
				
				if(ok_escrever == 1) //entrega a coluna desejada
				{
					fprintf(arq_out,"%lf/", c_x);
				}
							
			}else
			{
				fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
			}		
		}
		
	if(ok_escrever == 1)
	fclose(arq_out);
	ok_escrever = 0;
	}
	
	fclose(arq);
}

void correlacao(int desejado_1, int desejado_2, int ponto_1, int ponto_2, int sub, char nome_in[50],int colunas, int linhas, int itmin)
{
	double soma_1, soma_11, soma_2, soma_22, soma_juntos, resultado;
	char nome_out[50];
	FILE *arq_out;
	
	printf("\nInforme o nome de saida da correlacao: ");
	scanf("%s",nome_out);
	
	soma_1 = somatorio(desejado_1, ponto_1, sub, nome_in, colunas, linhas, itmin);
	soma_11 = somatorio_quadrado(desejado_1, ponto_1, sub, nome_in, colunas, linhas, itmin);
	soma_2 = somatorio(desejado_2, ponto_2, sub, nome_in, colunas, linhas, itmin);
	soma_22 = somatorio_quadrado(desejado_2, ponto_2, sub, nome_in, colunas, linhas, itmin);
	
	soma_juntos = somatorio_juntos(desejado_1, desejado_2, ponto_1, ponto_2, sub, nome_in, colunas, linhas, itmin);
	arq_out = fopen(nome_out,"w+b");
	
	resultado = numerador(soma_juntos, soma_1, soma_2, sub) / denominador(soma_1,soma_2,soma_11,soma_22, sub);
	printf("\n RESULTADO: %.30lf \n", resultado);
	fprintf(arq_out,"\tCorrelacao\n%.30lf",resultado);
	fclose(arq_out);
}

double numerador(double soma_juntos, double somatoria_1, double somatoria_2, int sub)
{
	double numerador_final;
								//ler o ponto_1 e o ponto_2 juntos multiplicando eles, e depois de somar eles ja multiplicados multiplicar por sub
	numerador_final = (sub * soma_juntos) - (somatoria_1 * somatoria_2);
	return numerador_final;
}

double denominador(double somatoria_1, double somatoria_2, double somatoria_11, double somatoria_22, int sub)
{
	double denominador_final, parte1, parte2, a, b;
	
	a = sub*(somatoria_11) - (pow(somatoria_1,2));
	b = sub*(somatoria_22) - (pow(somatoria_2,2));
	
	parte1 = sqrt(a);
	parte2 = sqrt(b);
	
	denominador_final = parte1 *  parte2;
	return denominador_final;
}

double somatorio_juntos(int desejado_1, int desejado_2, int ponto_1, int ponto_2, int sub, char nome_in[50],int colunas, int linhas, int itmin) //x = define se � x, y ou z
{ //fazer a opera��o com eles lidos separadamente!!! corrigir esse erro
	FILE *arq;
	double soma = 0, c_x = 0, c_y = 0, c_z = 0, aux = 0, val_1 = 0, val_2 = 0;
	float tempo = 0, x = 0, y = 0, z = 0;
	int i = 0, qtd_colunas = 0, aux2 = 0;
	
	arq = fopen(nome_in,"r+b");
	
	if(ponto_1 > ponto_2) //garante que o ponto 1 � menor que o 2
	{
		aux2 = ponto_2;
		ponto_2 = ponto_1;
		ponto_1 = aux2;
	}
	
	for(i = 0; i < colunas; i++) //LENDO AS COORDENADAS
	{
	fscanf(arq,"%f %f %f", &x, &y, &z);
	} //para a leitura apos as coordenadas
  	
	for(i = 2; i < linhas + 2; i++) //garante que vai parar quando chegar no final do arquivo e come�ar a partir do itmin considerado
	{	
	fscanf(arq,"%f",&tempo); //le o tempo inicial
			
		for(qtd_colunas = 0; qtd_colunas < colunas;  qtd_colunas++) //leitura das colunas
		{	
			fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
			
			if(i > itmin)
			{
				if(qtd_colunas == ponto_1) //seleciona o primeiro ponto em questao
				{		
					switch(desejado_1) //seleciona se � x, y ou z
					{
						case 1:
							val_1 = c_x;
						break;
						
						case 2:
							val_1 = c_y;
						break;
						
						case 3:
							val_1 = c_z;
						break;
					}
				}	
				
				if(qtd_colunas == ponto_2)
				{		
					switch(desejado_2)
					{
						case 1:
							val_2 = c_x;
						break;
						
						case 2:
							val_2 = c_y;
						break;
						
						case 3:
							val_2 = c_z;
						break;
					}	
					
					soma = soma + (val_1 * val_2);			
				}	
			}
		}
	}	
	
	return soma;
}

double somatorio_quadrado(int desejado, int escolha, int sub, char nome_in[50],int colunas, int linhas, int itmin) //x = define se � x, y ou z
{
	FILE *arq;
	double soma = 0, media = 0, c_x = 0, c_y = 0, c_z = 0, aux = 0;
	float tempo = 0, x = 0, y = 0, z = 0;
	int i = 0, qtd_colunas = 0;
	
	arq = fopen(nome_in,"r+b");
	
	for(i = 0; i < colunas; i++) //LENDO AS COORDENADAS
	{
	fscanf(arq,"%f %f %f", &x, &y, &z);
	}
	
	switch(desejado)
	{
		case 1: //x
			
			for(i = 2; i < linhas + 2; i++) //le as linhas com os valores
			{
			fscanf(arq,"%f",&tempo); //le o tempo inicial			
			
				for(qtd_colunas = 0; qtd_colunas < colunas;  qtd_colunas++) //leitura das colunas
				{	
					if(i > itmin) //pular endere�os indesejados
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
						
						if(qtd_colunas == escolha) //entrega a coluna desejada
						{	
							aux = c_x * c_x;
							soma = soma + aux;
						}
						
					}else
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
					}		
				}
			}			
		break; 
		
		case 2: //y
			
			for(i = 2; i < linhas + 2; i++) //le as linhas com os valores
			{
			fscanf(arq,"%f",&tempo); //le o tempo inicial
			
			
				for(qtd_colunas = 0; qtd_colunas < colunas;  qtd_colunas++) //leitura das colunas
				{	
					if(i > itmin) //pular endere�os indesejados
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
						
						if(qtd_colunas == escolha) //entrega a coluna desejada
						{	
							aux = c_y * c_y;
							soma = soma + aux;
						}
						
					}else
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
					}		
				}
			}
		break;
		
		case 3: //z
			
			for(i = 2; i < linhas + 2; i++) //le as linhas com os valores
			{
			fscanf(arq,"%f",&tempo); //le o tempo inicial
			
			
				for(qtd_colunas = 0; qtd_colunas < colunas;  qtd_colunas++) //leitura das colunas
				{	
					if(i > itmin) //pular endere�os indesejados
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
						
						if(qtd_colunas == escolha) //entrega a coluna desejada
						{	
							aux = c_z * c_z;
							soma = soma + aux;
						}
						
					}else
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
					}		
				}
			}
		break;
	}	
	
	return soma;
}

double somatorio(int desejado, int escolha, int sub, char nome_in[50],int colunas, int linhas, int itmin) //x = define se � x, y ou z
{
	FILE *arq;
	double soma = 0, media = 0, c_x = 0, c_y = 0, c_z = 0, aux = 0;
	float tempo = 0, x = 0, y = 0, z = 0;
	int i = 0, qtd_colunas = 0;
	
	arq = fopen(nome_in,"r+b");
	
	for(i = 0; i < colunas; i++) //LENDO AS COORDENADAS
	{
	fscanf(arq,"%f %f %f", &x, &y, &z);
	}
	
	switch(desejado)
	{
		case 1: //x
			
			for(i = 2; i < linhas + 2; i++) //le as linhas com os valores
			{
			fscanf(arq,"%f",&tempo); //le o tempo inicial			
			
				for(qtd_colunas = 0; qtd_colunas < colunas;  qtd_colunas++) //leitura das colunas
				{	
					if(i > itmin) //pular endere�os indesejados
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
						
						if(qtd_colunas == escolha) //entrega a coluna desejada
						{	
							soma = soma + c_x;
						}
						
					}else
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
					}		
				}
			}			
		break; 
		
		case 2: //y
			
			for(i = 2; i < linhas + 2; i++) //le as linhas com os valores
			{
			fscanf(arq,"%f",&tempo); //le o tempo inicial
			
			
				for(qtd_colunas = 0; qtd_colunas < colunas;  qtd_colunas++) //leitura das colunas
				{	
					if(i > itmin) //pular endere�os indesejados
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
						
						if(qtd_colunas == escolha) //entrega a coluna desejada
						{	
							soma = soma + c_y;
						}
						
					}else
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
					}		
				}
			}
		break;
		
		case 3: //z
			
			for(i = 2; i < linhas + 2; i++) //le as linhas com os valores
			{
			fscanf(arq,"%f",&tempo); //le o tempo inicial
			
			
				for(qtd_colunas = 0; qtd_colunas < colunas;  qtd_colunas++) //leitura das colunas
				{	
					if(i > itmin) //pular endere�os indesejados
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
						
						if(qtd_colunas == escolha) //entrega a coluna desejada
						{	
							soma = soma + c_z;
						}
						
					}else
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
					}		
				}
			}
		break;
	}	
	
	return soma;
}

void ler_coluna(char nome_in[50], int colunas, int linhas)
{
	int i = 0, coluna_desejada = 0, qtd_colunas = 0;
	FILE *arq, *arq_out;
	float x,y,z,tempo;
	double c_x, c_z, c_y;	
	char nome_out[50];
	
	arq = fopen(nome_in,"r+b");
	
	for( i = 0; i < colunas; i++) //passando quantas coordenadas tem
	{
	fscanf(arq,"%f %f %f", &x, &y, &z);
	printf("%d.\t%f\t%f\t%f \n",i, x, y, z);
	}
	
	printf("\n Escolha, pelo numero, de qual ponto deseja a serie: ");
	scanf("%d",&coluna_desejada);
	
	printf("\n Escolha o nome de saida para essa serie temporal: ");
	scanf("%s",nome_out);
	
	arq_out = fopen(nome_out,"w+b");
	
	fprintf(arq_out,"Time\tUx\tUy\tUz\n"); 
	for(i = 0; i < linhas; i++) //le as linhas com os valores
	{
	fscanf(arq,"%f",&tempo); //le o tempo inicial

	fprintf(arq_out,"%f\t",tempo);	
	
		for(qtd_colunas = 0; qtd_colunas < colunas;  qtd_colunas++) //leitura das colunas
		{	
			fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
			
			if(qtd_colunas == coluna_desejada)
			{		
				fprintf(arq_out,"%.30lf\t%.30lf\t%.30lf \n",c_x, c_y, c_z);
			}		
		}
	}
	
	fclose(arq);
	fclose(arq_out);
}

void arq_saida(int qtd_coord, int linhas, int itmin, char nome_in[50])
{
	int escolha, l = 0, desejado;
	struct _DADOS_ *aux;
	aux = inicio_colunas;
	FILE *arq;
	char nome_out[50];
	
	printf("\n---0. RETORNAR AO MENU PRINCIPAL");
	printf("\n---1. SAIDA DAS VELOCIDADES DE X");
	printf("\n---2. SAIDA DAS VELOCIDADES DE Y");
	printf("\n---3. SAIDA DAS VELOCIDADES DE Z");
	printf("\n---4. SAIDA DE TODAS VELOCIDADES");
	printf("\n---5. SAIDA DAS COORDENADAS DOS PONTOS");
	printf("\n---6. SAIDA DOS DESVIOS PADROES\n");	
	printf("\nOpcao: ");
	scanf("%d",&escolha);	
	
	if(escolha == 0 || escolha > 6)
	return;
	
	printf("\nEscolha o nome do arquivo a ser gerado: ");
	scanf("%s",nome_out);
	
	arq = fopen(nome_out,"w+b");
		
	switch(escolha)
	{
		case 1:						
			fprintf(arq,"Ux\n"); 
			while(aux != NULL)
			{
				fprintf(arq,"%.30lf \n",aux->soma_x);
				aux = aux->proxima;
			}
			fclose(arq);
			break;
			
		case 2:	
			fprintf(arq,"Uy\t\n"); 
			while(aux != NULL)
			{
				fprintf(arq,"%.30lf \n",aux->soma_y);
				aux = aux->proxima;
			}
			fclose(arq);
			break;
			
		case 3:	
			fprintf(arq,"Uz\t\n"); 
			while(aux != NULL)
			{
				fprintf(arq,"%.30lf \n",aux->soma_z);
				aux = aux->proxima;
			}
			fclose(arq);
			break;
			
		case 4:	
			fprintf(arq,"Ux\tUy\tUz\t\n"); 
			while(aux != NULL)
			{
				fprintf(arq,"%.30lf\t%.30lf\t%.30lf\n",aux->soma_x,aux->soma_y,aux->soma_z);
				
				aux = aux->proxima;
			}
			fclose(arq);		
			break;
				
		case 5:			
			fprintf(arq,"x\ty\tz\t\n"); 
			while(aux != NULL)
			{
				fprintf(arq,"%f\t%f\t%f \n",aux->x, aux->y, aux->z);
				aux = aux->proxima;
			}
			fclose(arq);
			break;
			
		case 6:
			printf("De qual coordenada deseja calcular os desvios padroes?\n(x = 1, y = 2, z = 3)\t Opcao: ");
			scanf("%d",&desejado);
			printf("(PODE DEMORAR UM POUCO!!!)");
			for(escolha = 0; escolha < qtd_coord; escolha++)
			{
			desvio_padrao(qtd_coord, linhas, itmin, escolha, nome_in, nome_out, l, desejado);
			l++;
			}
			break;
			
		default:
			return;
			break;
	}
}

void desvio_padrao(int colunas, int linhas, int itmin, int escolha, char nome_in[50], char nome_out[50], int l, int desejado)
{
	FILE *arq_out, *arq;
	double soma = 0, media = 0, c_x = 0, c_y = 0, c_z = 0, aux = 0;
	float sub = 0, tempo = 0, x = 0, y = 0, z = 0;
	int i = 0, qtd_colunas = 0;
	
	sub = linhas - itmin + 1; //n no desvio padr�o	
	
	arq = fopen(nome_in,"r+b");
	arq_out = fopen(nome_out,"a+b");
	
	if(l == 0)
	fprintf(arq_out,"Pontos\tDesvios\n");
	
	media = media_ponto(escolha,desejado);
	
	for(i = 0; i < colunas; i++) //LENDO AS COORDENADAS
	{
	fscanf(arq,"%f %f %f", &x, &y, &z);
	}
	
	switch(desejado)
	{
		case 1: //x
			
			for(i = 2; i < linhas + 2; i++) //le as linhas com os valores
			{
			fscanf(arq,"%f",&tempo); //le o tempo inicial			
			
				for(qtd_colunas = 0; qtd_colunas < colunas;  qtd_colunas++) //leitura das colunas
				{	
					if(i > itmin) //pular endere�os indesejados
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
						
						if(qtd_colunas == escolha) //entrega a coluna desejada
						{	
							aux = c_x - media;
							soma = soma + pow(aux, 2);
						}
						
					}else
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
					}		
				}
			}			
		break; 
		
		case 2: //y
			
			for(i = 2; i < linhas + 2; i++) //le as linhas com os valores
			{
			fscanf(arq,"%f",&tempo); //le o tempo inicial
			
			
				for(qtd_colunas = 0; qtd_colunas < colunas;  qtd_colunas++) //leitura das colunas
				{	
					if(i > itmin) //pular endere�os indesejados
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
						
						if(qtd_colunas == escolha) //entrega a coluna desejada
						{	
							aux = c_y - media;
							soma = soma + pow(aux, 2);
						}
						
					}else
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
					}		
				}
			}
		break;
		
		case 3: //z
			
			for(i = 2; i < linhas + 2; i++) //le as linhas com os valores
			{
			fscanf(arq,"%f",&tempo); //le o tempo inicial
			
			
				for(qtd_colunas = 0; qtd_colunas < colunas;  qtd_colunas++) //leitura das colunas
				{	
					if(i > itmin) //pular endere�os indesejados
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
						
						if(qtd_colunas == escolha) //entrega a coluna desejada
						{	
							aux = c_z - media;
							soma = soma + pow(aux, 2);
						}
						
					}else
					{
						fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
					}		
				}
			}
		break;
	}
	
	soma = sqrt(soma / sub);
	
	fprintf(arq_out,"%d\t",escolha);
	fprintf(arq_out,"%.30lf\n",soma);
	
	fclose(arq);
	fclose(arq_out);
}

double media_ponto(int ponto, int decisao)
{
	struct _DADOS_ *aux;
	double resultado;
	
	aux = procurar_coluna(ponto);
	
	switch(decisao)
	{
		case 1:			
			resultado = aux->soma_x;
		break;
		
		case 2:
			resultado = aux->soma_y;
		break;
		
		case 3:
			resultado = aux->soma_z;
		break;
	}
	
	return resultado;
}

void exibir_coordenadas()
{
	struct _DADOS_ *aux; 
	aux = inicio_colunas; //inicio_colunas = lista que contem os dados lidos
	
	printf("\n"); //Pula uma linha
	while(aux != NULL) 
	{
		printf("%d:\t%f\t%f\t%f\n",aux->coluna, aux->x, aux->y, aux->z); //exibir a posi��o das colunas e as respectivas posi��es
		aux = aux->proxima; //pula para o proximo endere�o
	}
}

void exibir_somas()
{
	struct _DADOS_ *aux;
	aux = inicio_colunas;
	
	printf("\n");
	while(aux != NULL)
	{
		printf("%lf %lf %lf \n",aux->soma_x, aux->soma_y, aux->soma_z);
		aux = aux->proxima;
	}	
}

void leitura_arquivo(char nome_in[50], int qtd_coord, int itmin, int qtd_linhas) 
{
	FILE *arq;
	float x, y, z, tempo;
	int i, qtd_colunas, j = 0, inicio;
	double c_x, c_z, c_y, sub;
	struct _DADOS_ *aux;
	char teste = 'c';
	
	arq = fopen(nome_in,"r+b");
	
	inicio = ftell(arq);
	fread(&teste,8,1,arq);
	
	if(teste == '#')
	{
		printf("\nTEXTO SUJO, LIMPE O TEXTO!!\n");	
		system("pause");	
	}else
	{
	
		fseek(arq,inicio,SEEK_SET);
		
		while(!arq)
		{
			printf("\nArquivo vazio, tente novamente: ");
			
			printf("\nInforme o nome do arquivo a ser lido: ");
			scanf("%s",nome_in);
			arq = fopen(nome_in,"r+b");
		}
			
		for( i = 0; i < qtd_coord; i++) //passando quantas coordenadas tem
		{
		fscanf(arq,"%f %f %f", &x, &y, &z);
		
			if(j != 0)
			{
				aux->proxima = add_dados(i,x,y,z,0,0,0,aux); //adicionando as coordenadas na lista
				aux = aux->proxima;
			}else
			{
				inicio_colunas = add_dados(i,x,y,z,0,0,0,NULL); //criando lista inicial
				aux = inicio_colunas;
				j++;
			}
		}
		
		for(i = 2; i < qtd_linhas + 2; i++) //le as linhas com os valores
		{
			fscanf(arq,"%f",&tempo); //le o tempo inicial
			printf("Timestep: %f %c", tempo,13); //exibicao do tempo durante o processo
			
			for(qtd_colunas = 0; qtd_colunas < qtd_coord;  qtd_colunas++) //leitura das colunas
			{	
				if(i > itmin)
				{
					fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
					adc_valor(c_x,c_y,c_z,qtd_colunas);				
				}
				else
				{				
					fscanf(arq,"%lf %lf %lf",&c_x, &c_y, &c_z);	
				}
				
			}
		}
		fclose(arq);
		
		fim_colunas = aux;
		
		sub = (qtd_linhas - itmin + 1);
	
		dividir(sub);
	}
	
	system("cls || clear");
}

void dividir(double x)
{
	struct _DADOS_ *aux;
	
	aux = inicio_colunas;
	
	while(aux != NULL)
	{
		aux->soma_x = aux->soma_x / x;
		aux->soma_y = aux->soma_y / x;
		aux->soma_z = aux->soma_z / x;	
		
		aux = aux->proxima;
	}
}

void adc_valor(double valor_x, double valor_y,double valor_z, int coluna) //funcao responsavel por realizar a soma dos valores
{
	struct _DADOS_ *aux;
	aux = inicio_colunas;
	
	aux = procurar_coluna(coluna);
	aux->soma_x += valor_x;
	aux->soma_y += valor_y;
	aux->soma_z += valor_z;
}

dados procurar_coluna(int coluna) //responsavel por direcionar para a coluna certa
{
	struct _DADOS_ *aux;
	aux = inicio_colunas;
	
	while(aux->coluna != coluna)
	{
		aux = aux->proxima;
	}
	
	return aux;
}

void limpar_dados(struct _DADOS_ *colunas)
{
	struct _DADOS_ *atual, *prox;
	
	if(colunas == NULL)
	{
		return;
	}
	
	atual = colunas->proxima;
	
	while(atual != NULL)
	{
		prox = atual->proxima;
		free(atual);
		atual = prox;
	}
}

dados add_dados(int coluna, float x, float y,float z,double soma_x,double soma_y,double soma_z,dados anterior)
{
	dados M = malloc(sizeof(struct _DADOS_));
	M->coluna = coluna;
	M->x = x;
	M->y = y;
	M->z = z;
	M->soma_x = soma_x;
	M->soma_y = soma_y;
	M->soma_z = soma_z;
	M->proxima = NULL;
	M->anterior = anterior;
	
	return M;
}
//FIM

//COMECO PARTE LIMPA TEXTO
void retirar_letras()
{
	FILE *arq_out;
	struct _LETRAS_ *aux;
	aux = inicio_lista_letras;
	char nome_out[50];
	
	printf("\nInforme o nome do arquivo de saida, formatado,\nsera usado para ler depois: ");
	scanf("%s",nome_out);
	
	arq_out = fopen(nome_out,"w+b");
	
	while(aux->proxima != NULL)
	{	
	
		switch(aux->letra)
		{
			case '#': 
			aux = pular_enderecos(aux,'(','\n');	
			break;			
			
			case ')':
			aux = aux->proxima;
			break;
		}	
	
		if(aux->letra != '(')
		fprintf(arq_out,"%c",aux->letra);
		
		aux = aux->proxima; 		
	}
	
	fclose(arq_out);
}

letras pular_enderecos(letras aux1, char fechamento, char fechamento_2)
{
	struct _LETRAS_ *aux;
	aux = aux1; //salva o endereco que parar em aux para poder continuar
	
	while(aux->letra != fechamento && aux->letra != fechamento_2) //enquanto nao passar por o fechamento da condicao
	{
		aux = aux->proxima;
	} //sair com o endere�o apos condicao
	
	return aux;
}

void ler_caracteres()
{
	char letra, letra_ant, teste;
	FILE *arq_ler, *arq_saida;
	int i = 0;
	letras aux;
	char nome_in[50];
	
	printf("\nInforme o nome do arquivo a ser lido: ");
	scanf("%s",nome_in);
	
	arq_ler = fopen(nome_in,"rb");
	
	while(!arq_ler)
	{
		printf("\n ARQUIVO U NAO ENCONTRADO, OPERACAO CANCELADA!!!");
		
		printf("\nInforme o nome do arquivo a ser lido: ");
		scanf("%s",nome_in);
				
		arq_ler = fopen(nome_in,"rb");
	}
	printf("\n FORMATANDO O TEXTO E PREPARANDO O MESMO PARA LEITURA. \n(PODE DEMORAR UM POUCO) \n");
	
	//informa ao usuario que o aplicativo em questao esta vazio	
	if(arq_ler == NULL)
	{
		printf("\n\n Arquivo vazio ");
		return;
	}
	
	while(!feof(arq_ler))
	{
		fscanf(arq_ler,"%c",&letra);
		
		if(i != 0)
		{
			aux->proxima = add_letras(letra, aux);
			aux = aux->proxima;
		}else
		{
			inicio_lista_letras = add_letras(letra,NULL);
			aux = inicio_lista_letras;
			i++;
		}
	}
	
	retirar_letras();
}

void limpar_dados2(struct _LETRAS_ *lista)
{
	struct _LETRAS_ *atual, *prox;
	
	if(lista == NULL)
	{
		return;
	}
	
	atual = lista->proxima;
	
	while(atual != NULL)
	{
		prox = atual->proxima;
		free(atual);
		atual = prox;
	}
}

letras add_letras(char letra, letras anterior)
{
	letras L;
	L = malloc(sizeof(struct _LETRAS_));
	L->letra = letra;
	L->proxima = NULL;
	L->anterior = anterior;
	
	return L;
}
//FIM
