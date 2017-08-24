/*
 ============================================================================
 Name        : SampleCPP.c
 Author      : Rafael Rocha
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int num1, soma, numX;
	char resp;

	printf("Entre com o primeiro número: ");
	scanf("%i/n", &num1);

	soma = num1;

	do {

		printf("Entre com o proximo número: ");
		scanf("%i/n", &numX);

		soma = soma + numX;

		printf("Deseja continuar ? (S/N): ");
		scanf(" %c", &resp);

	} while (resp == 'S');

	printf("O resultado da soma é %i", soma);

	return 0;
}
