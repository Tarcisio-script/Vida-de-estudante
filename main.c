#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	system("color 0A");
	srand((unsigned) time(NULL));

	int resp, resp1;            // sistema de menu
	int continuar = 1;          // 1 = continua no programa, 0 = encerra

	int mencao, i;              // nota
	float nota = -1, media, nota_soma, nova_nota;

	float temp = -1, soma_temp, novo_temp;   // tempo de estudo

	int a, b, resposta_desafio; // desafio de matemática

	do
	{
		// Mensagem pro usuário
		system("cls");
		printf("******************** VIDA DE ESTUDANTE ********************\n");
		printf("Digite o que deseja realizar\n");
		printf("1-Registrar nota\n");
		printf("2-Registrar tempo de estudo\n");
		printf("3-Calcular média\n");
		printf("4-Verificar situação\n");
		printf("5-Desafio de matemática\n");
		printf("6-Sair\n");
		printf("Digite sua resposta: ");
		if (scanf("%d", &resp) != 1) {          // evita travar se digitar letra
			while (getchar() != '\n');
			resp = 0;
		}

		// sistema do menu
		switch (resp) {
		case 1: // Registrar nota
			system("cls");
			if (nota == -1)
				printf("É sua primeira vez usando o registro de nota\n");
			printf("O que deseja fazer?\n");
			printf("1-Inserir nova nota\n");
			if (nota >= 0)
				printf("2-Ver minha nota\n");
			printf("Digite sua resposta: ");
			if (scanf("%d", &resp1) != 1) {
				while (getchar() != '\n');
				resp1 = 0;
			}

			switch (resp1) {
				case 1:
					printf("Digite sua nota (0 a 10): ");
					if (scanf("%f", &nova_nota) != 1) {
						while (getchar() != '\n');
						nova_nota = -1;
					}
					if (nova_nota >= 0 && nova_nota <= 10) {
						nota = nova_nota;
						printf("Nota registrada!\n");
					} else {
						printf("Nota inválida!\n");
					}
				break;
				case 2:
					if (nota >= 0)
						printf("Sua nota atual é: %.2f\n", nota);
					else
						printf("Opção inválida!\n");
				break;
				default:
					printf("Opção inválida!\n");
				break;
			}
		break;

		case 2: // Registrar tempo de estudo
			system("cls");
			if (temp == -1)
				printf("É sua primeira vez usando o registro de tempo de estudo do dia\n");
			printf("O que deseja fazer?\n");
			printf("1-Registrar meu tempo\n");
			if (temp >= 0) {
				printf("2-Consultar meu tempo de estudo atual\n");
				printf("3-Somar tempo de estudo\n");
			}
			printf("Digite sua resposta: ");
			if (scanf("%d", &resp1) != 1) {
				while (getchar() != '\n');
				resp1 = 0;
			}

			switch (resp1) {
				case 1:
					printf("Quantas horas de estudo você teve hoje? ");
					if (scanf("%f", &novo_temp) != 1) {
						while (getchar() != '\n');
						novo_temp = -1;
					}
					if (novo_temp >= 0 && novo_temp <= 24) {
						temp = novo_temp;
						printf("Tempo registrado!\n");
					} else {
						printf("Tempo inválido! Digite um valor entre 0 e 24.\n");
					}
				break;
				case 2:
					if (temp >= 0)
						printf("Seu tempo de estudo atual é: %.2f horas\n", temp);
					else
						printf("Opção inválida!\n");
				break;
				case 3:
					if (temp >= 0) {
						printf("Quanto tempo deseja somar (em horas)? ");
						if (scanf("%f", &soma_temp) != 1) {
							while (getchar() != '\n');
							soma_temp = -1;
						}
						if (soma_temp <= 0)
							printf("Valor inválido!\n");
						else if (temp + soma_temp > 24)
							printf("O total não pode passar de 24 horas por dia!\n");
						else {
							temp += soma_temp;
							printf("Tempo atualizado: %.2f horas\n", temp);
						}
					} else {
						printf("Opção inválida!\n");
					}
				break;
				default:
					printf("Opção inválida!\n");
				break;
			}
		break;

		case 3: // Calcular média
			system("cls");
			printf("Quantas menções seu professor(a) usa: ");
			if (scanf("%d", &mencao) != 1) {
				while (getchar() != '\n');
				mencao = 0;
			}
			if (mencao <= 0) {
				printf("Número inválido!\n");
			} else {
				media = 0;                  // começa zerada (antes tinha lixo de memória)
				int valida = 1;             // controla se todas as notas foram válidas
				for (i = 1; i <= mencao && valida; i++) {
					printf("Digite sua %dª nota de 0 a 10: ", i);
					if (scanf("%f", &nota_soma) != 1) {
						while (getchar() != '\n');
						nota_soma = -1;
					}
					if (nota_soma >= 0 && nota_soma <= 10)
						media += nota_soma;
					else {
						printf("Número inválido!\n");
						valida = 0;
					}
				}
				if (valida) {
					nota = media / mencao;
					printf("Sua nota média é: %.2f\n", nota);
				}
			}
		break;

		case 4: // Verificar situação
			system("cls");
			if (nota < 0)
				printf("Você ainda não registrou nenhuma nota nem calculou a média.\n");
			else if (nota >= 6)
				printf("Nota %.2f - APROVADO(A)!\n", nota);
			else if (nota >= 4)
				printf("Nota %.2f - EM RECUPERAÇÃO.\n", nota);
			else
				printf("Nota %.2f - REPROVADO(A).\n", nota);
		break;

		case 5: // Desafio de matemática
			system("cls");
			a = rand() % 10 + 1;
			b = rand() % 10 + 1;
			printf("***** DESAFIO DE MATEMÁTICA *****\n");
			printf("Quanto é %d x %d? ", a, b);
			if (scanf("%d", &resposta_desafio) != 1) {
				while (getchar() != '\n');
				printf("Resposta inválida!\n");
			} else if (resposta_desafio == a * b) {
				printf("Parabéns, resposta correta!\n");
			} else {
				printf("Errou! A resposta certa era %d.\n", a * b);
			}
		break;

		case 6: // Sair
			printf("Até logo, bons estudos!\n");
		break;

		default:
			printf("Opção inválida!\n");
		break;
		}

		// Pergunta se continua (depois de qualquer opção, exceto sair)
		if (resp != 6) {
			printf("\nDeseja continuar? 1 para sim 0 para não: ");
			if (scanf("%d", &continuar) != 1) {
				while (getchar() != '\n');
				continuar = 0;
			}
		}
	}
	while (resp != 6 && continuar == 1);

	return 0;
}
