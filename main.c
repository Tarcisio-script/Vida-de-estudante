#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
setlocale(LC_ALL, "Portuguese");
system("color 0A");	

int resp, resp1; //sistema de menu

int mencao, i; //nota
float nota= -1, media, nota_soma; 

float temp=-1, soma_temp;//tempo de estudo
int tempo_resposta;
	
	do
	{
		//Mensagem pro usuario
		system("cls");
		printf("********************VIDA DE ESTUDANTE ***************\n");
		printf("Digite o que queira realizar\n");
		printf("1-Registrar nota\n");
		printf("2-Registrar tempo de estudo\n");
		printf("3-Calcular média\n");
		printf("4-Verificar situação\n");
		printf("5-Desafio de matemática\n");
		printf("6-sair\n");
		printf("Digite sua resposta: ");
		scanf("%d", & resp);
		
		//sistema do menu
		switch (resp){
		case 1:
		system("cls");
			if(nota== -1)
				printf("é sua primeira vez usando o registro de nota\n");
			printf("O que deseja saber?\n");
			printf("1-Descobrir a sua nota média\n");
			printf("2-Incerir nova nota\n");
			if(nota>0)
				printf("3-Ver minha nota\n");
			scanf("%d", & resp1);
			
			switch(resp1){ 
				case 1: //escolha de nota do usuario
					printf("Quantas menções se professor(a) usa: ");
					scanf("%d", & mencao);
					if(mencao<=0){
						printf("numero invalido");
						return 0;
					}
					for(i=1; i<=mencao;i++){
						printf("digite sua %d° nota de 0 a 10: ", i);
						scanf("%f", & nota_soma);
						if(nota_soma>=0 && nota_soma<=10)
					media+=nota_soma;
						else{
							printf("Numero invalido!");
							return 0;
						}
					}
					nota=media/mencao;
					printf("Sua nota média é: %.2f\n", nota);
					printf("Deseja continar? 1 para sim 0 para não: ");
					scanf("%d", & resp);
					if(resp!=1)
					resp=6;
				break;
				case 2:
					printf("Digite usa Nota: ");
					scanf("%f", & nota);
					if(nota>=0 && nota<=10){
					printf("Deseja continar? 1 para sim 0 para não: ");
					scanf("%d", & resp);
					if(resp!=1)
					resp=6;
				}
				break;
				case 3:
					if(nota!=-1){
					printf("Sua nota atual é: %.2f\n", nota);
					printf("Deseja continar? 1 para sim 0 para não: ");
					scanf("%d", & resp);
					if(resp!=1)
					resp=6;}
				break;
				default: 
					printf("Opção invalida!");
				break;	
			}
		break;
		case 2:
			if(temp==-1)
				printf("è sua primeira vez usando o registro de tempo de estudo do dia\n");
			printf("O que deseja saber?\n");
			printf("1-Registrar meu tempo\n");
			if(temp>0)
				printf("2-consultar meu tempo de estudo atual ou atualizalo: ");
			scanf("%d", & resp1);
				if(temp==-1 && (resp1!=1)){
					printf("opção invalida");
					return 0;
				}
				if(resp1!=1 && resp1!=2){
					printf("Opção invalida!");
					return 0;}
			switch(resp1){
				case 1:
					printf("Quantas horas de estudo voce teve hoje? ");
					scanf("%f", & temp);
					if(temp>=0 && temp<=24){
					printf("Tempo registrado, deseja continuar? 1 para sim e 2 para não");
					scanf("%d", & resp);
					if(resp!=1)
					resp=6;}
					else{
						printf("tempo invalido");
					resp=6;
					}
				break;
				case 2:
				printf("O que voce deseja fazer? 1-para ver a minhas horas de estudos totais 2-para somar tempo de estudo: ");
				scanf("%d", & resp1);
			if (resp1 != 1 && resp1 != 2) 
    			resp = 6; // Valor inválido
				switch(resp1){
					case 1:
						printf("seu tempo de estudo atual é: %.2f\n", temp);
						printf("Deseja continar? 1 para sim 0 para não: ");
					scanf("%d", & resp);
					if(resp!=1)
					resp=6;
					break;
					case 2:
						printf("quanto tempo deseja soma: ");
						scanf("%f", & soma_temp);
						if(soma_temp<=0 || soma_temp>24)
						temp+=soma_temp;
						if(temp>=24.99)
						{
							printf("opção invalida");
						resp=6;
						}
				default:
					printf("opção invalida");
					resp=6;
				break;
			}
		}
		
		break;
		case 3:
		
		break;
		case 4:
			
		break;
		case 5:
			
		break;
		case 6:
			
		break;
		default: 
		break;
		}
	}
	while(resp!=6);
return 0;
}
