#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu() {

	int opc;

	printf("1 - CALCULAR\n");
	printf("2 - SAIR\n");
	scanf("%d", &opc);

	return opc;
}

void verificaCalculos() {

	char *calculo = NULL;
	char *retSoma, *retSubtracao, *retDivisao, *retMultiplicacao;
	size_t len = 0;
	ssize_t read;

	printf("\nInforme o calculo: \n");

	while ((read = getline(&calculo, &len, stdin)) != 0) {
		if (read > 1) {

			char *verificaFlag = "0*0";
			int retFlag;

			retFlag = strcmp(calculo, "0*0");

			if (retFlag == 10) {
				exit(0);
			} else {

				retSoma = strstr(calculo, "+");
				retSubtracao = strstr(calculo, "-");
				retMultiplicacao = strstr(calculo, "*");
				retDivisao = strstr(calculo, "/");

				if (retSoma != NULL) {
					somar(calculo);
				} else if (retSubtracao != NULL) {
					subtrair(calculo);
				} else if (retMultiplicacao != NULL) {
					multiplicar(calculo);
				} else if (retDivisao != NULL) {
					dividir(calculo);
				}

				free(calculo);
				return;
			}
		}
	}
}

void somar(char *calculo) {
	printf("Somar! %s\n", calculo);
}

void subtrair(char *calculo) {
	printf("Subtrair! %s\n", calculo);
}

void dividir(char *calculo) {
	printf("Dividir! %s\n", calculo);
}

void multiplicar(char *calculo) {
	printf("Multiplicar! %s\n", calculo);
}

int main(void) {
	int opcao = 0;

	while (opcao != 2) {
		opcao = menu();
		switch (opcao) {
		case 1:
			verificaCalculos();
			break;
		case 2:
			exit(0);
			break;

		default:
			printf("Comando invalido\n\n");
		}
	}
}
