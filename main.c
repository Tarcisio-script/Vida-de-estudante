//oração antes do codigo nessesaria: pai nosso e ave maria 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char *argv[]) {
setlocale(LC_ALL, "Portuguese");
system("color 0A");	

int resp, resp1; //sistema de menu

int mencao, i; //nota
float nota= -1, media= 0, nota_soma; 

float temp=-1, soma_temp;//tempo de estudo
int tempo_resposta;

int continua_matematica=1, i1;//matematica
float resposta=0;
	
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
				 
			printf("Digite usa Nota: ");
			scanf("%f", & nota);
			if(nota>=0 && nota<=10){
				printf("Sua nota foi registrada com sucesso!\n");
				printf("Deseja continar? 1 para sim 0 para não: ");
				scanf("%d", & resp);
				if(resp!=1)
				resp=6;
			}
		break;
		case 2:
		system("cls");
			if(temp==-1)
				printf("è sua primeira vez usando o registro de tempo de estudo do dia\n");
			printf("O que deseja saber?\n");
			printf("1-Registrar meu tempo\n");
			if(temp>0){
				printf("2-consultar meu tempo de estudo atual\n");
				printf("3-Soma mais tempo de estudo\n resposta: ");
			}
			scanf("%d", & resp1);
				if(temp==-1 && (resp1!=1)){
					printf("opção invalida");
					return 0;
				}
				if(resp1!=1 && resp1!=2 && resp1!=3){
					printf("Opção invalida!");
					return 0;}
			switch(resp1){
				case 1:
					printf("Quantas horas de estudo voce teve hoje? ");
					scanf("%f", & temp);
					if(temp>=0 && temp<=24){
					printf("Tempo registrado, deseja continuar? 1 para sim e 2 para não: ");
					scanf("%d", & resp);
					if(resp!=1)
					resp=6;}
					else{
						printf("tempo invalido");
					resp=6;
					}
				break;
				case 2:
						printf("seu tempo de estudo atual é: %.2f\n", temp);
						printf("Deseja continar? 1 para sim 0 para não: ");
					scanf("%d", & resp);
					if(resp!=1)
					resp=6;
					break;
				case 3:
					printf("quanto tempo deseja soma: ");
					scanf(" %f", & soma_temp);
					if (soma_temp > 0 && soma_temp <= 24) {
                            if ((temp + soma_temp)>24) {
                                printf("opcao invalida (ultrapassa 24h)");
                                resp = 6;
                            } 
							else {
                                temp += soma_temp;
                                printf("Tempo somado com sucesso! Total: %.2f\n", temp);
                                printf("Deseja continuar? 1 para sim e 2 para não: ");
                                scanf("%d", &resp);
                                if (resp!=1)
                                    resp=6;
                            }
                        } 
						else {
                            printf("opcao invalida");
                            resp = 6;
                        }
                        break;

                    default:
                        printf("opção invalida");
                        resp = 6;
                        break;
                }
        break;
		case 3:
		system("cls");
		media=0;	
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
		case 4:
		system("cls");
			if (nota==-1){
				printf("Voce ainda não tem nota registrada, deseja registrá-la? 1 para sim e 0 para não: ");
				scanf("%d", & resp1);
					if (resp1==1){
						printf("Digite usa Nota: ");
						scanf("%f", & nota);
						if(nota>=0 && nota<=10){
							printf("Sua nota foi registrada com sucesso!\n");
							printf("Deseja continar? 1 para sim 0 para não: ");
							scanf("%d", & resp);
							if(resp!=1)
								resp=6;
						}
					}
			}
			else
			if(nota>=0 && nota<=4){
				printf("Voce está reprovado :(\n");
				printf("Deseja continar? 1 para sim 0 para não: ");
				scanf("%d", & resp);
				if(resp!=1)
					resp=6;
			}
			else if(nota>4 && nota<=6){
				printf("Voce está recuperação :|\n");
				printf("Deseja continar? 1 para sim 0 para não: ");
				scanf("%d", & resp);
				if(resp!=1)
					resp=6;
			}
			else{
			printf("Voce está aprovado :)");
				printf("Deseja continar? 1 para sim 0 para não: ");
				scanf("%d", & resp);
				if(resp!=1)
					resp=6;
		}
		break;
		case 5:
			i1=1;
			system("cls");
			printf("Voce escolheu os desafios matematicos, seram 10 perguntas e caso voce falhe voce iniciara tudo do começo\n");
			while(continua_matematica==1){
				system("cls");
				printf("%d° pergunta\n", i1);//1
				printf("(607 - 549) + 32 = ?\n");//90
				printf("Resposta: ");
				scanf("%f", & resposta);
				if(resposta!=(607 - 549) + 32){
					printf("reposta errada, deseja continuar? 1 para sim 0 para não");
					scanf("%d", & continua_matematica);
					if (continua_matematica != 1) break;
					continue;	
				}				
				else
				i1++;
				printf("%d° pergunta\n", i1); //2
				printf("-5 * 7 + 263 = ?\n");//228
				printf("Resposta: ");
				scanf("%f", & resposta);
				if(resposta!=-5 * 7 + 263){
					printf("reposta errada, deseja continuar? 1 para sim 0 para não");
					scanf("%d", & continua_matematica);
					if (continua_matematica != 1) break;
					continue;
				}				
				else
				i1++;
				printf("%d° pergunta\n", i1);//3
				printf("100 / (20 * 10 / 100)- 7 = ?\n");//43
				printf("Resposta: ");
				scanf("%f", & resposta);
				if(resposta != 100 / (20 * 10 / 100)- 7){
					printf("reposta errada, deseja continuar? 1 para sim 0 para não");
					scanf("%d", & continua_matematica);
					if (continua_matematica != 1) break;
					continue;
				}				
				else
				i1++;
				printf("%d° pergunta\n", i1);//4
				printf("67 * 3 - 87 = ?\n");//114
				printf("Resposta: ");
				scanf("%f", & resposta);
				if(resposta != 67 * 3 - 87){
					printf("reposta errada, deseja continuar? 1 para sim 0 para não");
					scanf("%d", & continua_matematica);
					if (continua_matematica != 1) break;
					continue;
				}				
				else
				i1++;
				printf("%d° pergunta\n", i1);//5
				printf("(42 *(50 - 47)) / 3 = ?\n"); //42
				printf("Resposta: ");
				scanf("%f", & resposta);
				if(resposta != (42 *(50 - 47)) / 3){
					printf("reposta errada, deseja continuar? 1 para sim 0 para não");
					scanf("%d", & continua_matematica);
					if (continua_matematica != 1) break;
					continue;
				}				
				else
				i1++;
				printf("%d° pergunta\n", i1);//6
				printf("99 / 9 * 3 = ?\n"); //33
				printf("Resposta: ");
				scanf("%f", & resposta);
				if(resposta != 99 / 9 * 3){
					printf("reposta errada, deseja continuar? 1 para sim 0 para não");
					scanf("%d", & continua_matematica);
					if (continua_matematica != 1) break;
					continue;
				}				
				else
				i1++;
				printf("%d° pergunta\n", i1);//7
				printf("2 + 2 = ?\n");
				printf("Resposta: ");
				scanf("%f", & resposta);
				if(resposta != 4){
					printf("reposta errada, deseja continuar? 1 para sim 0 para não");
					scanf("%d", & continua_matematica);
					if (continua_matematica != 1) break;
					continue;
				}				
				else
				i1++;
				printf("%d° pergunta\n", i1);//8
				printf("2046 - 2045 * 2 = ?\n"); //-4044
				printf("Resposta: ");
				scanf("%f", & resposta);
				if(resposta != 2046 - 2045 * 2){
					printf("reposta errada, deseja continuar? 1 para sim 0 para não");
					scanf("%d", & continua_matematica);
					if (continua_matematica != 1) break;
					continue;
				}				
				else
				i1++;
				printf("%d° pergunta\n", i1);//9
				printf("(81 / 9) * 3 - 28 = ?\n"); // -1
				printf("Resposta: ");
				scanf("%f", & resposta);
				if(resposta !=(81 / 9) * 3 - 28){
					printf("reposta errada, deseja continuar? 1 para sim 0 para não");
					scanf("%d", & continua_matematica);
					if (continua_matematica != 1) break;
					continue;
				}				
				else
				i1++;
				printf("%d° pergunta\n", i1);//10
				printf("(13 * 4 - 37 ) * (2 / 2)= ?\n");//15
				printf("Resposta: ");
				scanf("%f", & resposta);
				if(resposta == (13 * 4 - 37 ) * (2 / 2)){
					system("cls");
       				printf("Parabens! Voce acertou todas as 10 perguntas e concluiu o desafio!\n\n");
     				continua_matematica = 0; 
        			printf("Deseja voltar ao menu principal? (1-Sim / 0-Nao): ");
        			scanf("%d", &resp);
     				   if (resp != 1) {
            				resp = 6; // Encerra o programa
        				}
				}
				else{
					printf("reposta errada, deseja continuar? 1 para sim 0 para não");
					scanf("%d", & continua_matematica);
					if (continua_matematica != 1) break;
					continue;
				}						
			}//while
		break;
		case 6:
			system("cls");
			printf("Programa encerrado");
			return 0;
		break;
		default: 
		system("cls");
			printf("Opção invalida\n");
			printf("Deseja continar? 1 para sim 0 para não: ");
			scanf("%d", & resp);
			if(resp!=1)
				resp=6;
		break;
		}
	}
	while(resp!=6);
	system("cls");
	printf("Programa encerrado");
return 0;
}
