/* 
 * Mariana Dabul Nazario 
 * Trabalho 1 - Sistemas Operacionais
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#include <stdlib.h>
#include <string.h>

#define COMPRIMENTO_MAXIMO_NOME			50

int main(void){
	pid_t childPid = fork();
	char *comando;
	unsigned int numeroArgumentos;
	unsigned int indice;
	char *argumentos[COMPRIMENTO_MAXIMO_NOME];
	char *auxiliar;

	if (childPid < 0){
		// fork failed
		fprintf (stderr, "Fork falhou.\n");
		exit(1);
	}
	
	else if (childPid == 0) {
		
		printf("Qual comando quer executar?"\n);
		fgets(comando, COMPRIMENTO_MAXIMO_NOME, stdin);

		//verificar se o comando existe em /bin

	  printf("Quantos argumentos voce quer digitar?\n");
		scanf("%u", &numeroArgumentos);	

		for (indice = 0; indice < numeroArgumentos; indice++){
			printf("Insira o proximo argumento:");
			fgets(auxiliar, COMPRIMENTO_MAXIMO_NOME, stdin);

			*agumentos[indice] = *auxiliar;
		}

		//Run ping command
		execlp("/bin/ping","ping","8.8.8.8","-c","50",NULL);
	} 

	else {	
		wait(NULL);
		printf("Tarefa completou.\n");
	}


	return 0;
}



