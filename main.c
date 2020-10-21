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

#include <errno.h>

#define COMPRIMENTO_MAXIMO_NOME			20
#define NUMERO_MAXIMO_ARGUMENTOS		10

int shell(void){
	unsigned int interrupcao = 1;
	unsigned int numeroArgumentos;
	unsigned int indice;
	char caminho [COMPRIMENTO_MAXIMO_NOME + 2] = {"/bin/"};
	char comando [COMPRIMENTO_MAXIMO_NOME + 2];
	char *argumentos [COMPRIMENTO_MAXIMO_NOME + 2];
	char auxiliar [COMPRIMENTO_MAXIMO_NOME + 2];
	char numeroArgumentosAuxiliar [NUMERO_MAXIMO_ARGUMENTOS + 2];
  pid_t child_pid = 0;

	// Comeco do shell	
	
	// Comando
	printf("Qual comando quer executar?\n");
	fgets(comando, COMPRIMENTO_MAXIMO_NOME + 2, stdin);
	comando [strlen (comando) - 1] = '\0';
	
	// Comando com o caminho do /bin
	strcat(caminho, comando);	
	printf("%s", caminho);

	// O comando como primeiro "argumento"
	argumentos[0] = malloc (sizeof(char) * COMPRIMENTO_MAXIMO_NOME);
	strncpy (argumentos[0], comando, COMPRIMENTO_MAXIMO_NOME);

	// Quantidade de argumentos
	printf("Quantos argumentos voce quer digitar?\n");
	fgets(numeroArgumentosAuxiliar, NUMERO_MAXIMO_ARGUMENTOS + 2, stdin);
	numeroArgumentosAuxiliar [strlen (numeroArgumentosAuxiliar) - 1] = '\0';
	numeroArgumentos = (unsigned int) strtoul(numeroArgumentosAuxiliar, NULL, 10);

	printf("O comando é %s\n", comando);
	
	// Coletar os outros argumentos
	for (indice = 1; indice <= numeroArgumentos; indice++){
		printf("\nDigite o argumento %u.\n", indice);
		fgets(auxiliar, COMPRIMENTO_MAXIMO_NOME + 2, stdin);
		auxiliar [strlen (auxiliar) - 1] = '\0';
		argumentos[indice] = malloc (sizeof(char) * COMPRIMENTO_MAXIMO_NOME);
		strncpy (argumentos[indice], auxiliar, COMPRIMENTO_MAXIMO_NOME);

		printf("\n%s\n", argumentos[indice]);
	}
	argumentos[numeroArgumentos + 1] = NULL; 

	// Nao ha preocupacao com a recepcao do sinal a partir daqui
	interrupcao = 0;

	child_pid = fork();
	if (child_pid == 0) {
		execv(caminho, argumentos);
	
		if (errno == -1)
			printf("Erro.\n");
	} 
	else {
		wait(NULL);
		printf("Tarefa finalizada.\n");
	}

	return 0;
}

// Falta tratar o signalHandler


int main(void){

	shell();

	return 0;
}



