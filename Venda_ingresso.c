#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>          //comando para garantir a acentua��o das palavras nas strings dos c�digos
#define CELSO_PRODUCOES 150 //Constante que denominei a empresa do evento e coloquei a quantidade de ingressos a serem vendidos no m�ximo de 150 ingressos

typedef struct {             //permite que seja definido um novo nome para um tipo de dado
	char nome[50];
	char cpf[11];
	char data_nascimento[10];
} Ingresso;

Ingresso ingressos[CELSO_PRODUCOES];


int num_ingressos = 0;

void venderIngresso() {
	if(num_ingressos >= CELSO_PRODUCOES) {
		printf("Limite de ingressos atingido!\n");
		return;
	}

	Ingresso novoIngresso;

	printf("Digite o nome do comprador:\n ");
	scanf("%s", novoIngresso.nome);

	printf("Digite o CPF do comprador:(sem pontos, apenas n�meros)\n ");
	scanf("%s", novoIngresso.cpf);

	printf("Digite a data de nascimento do comprador (DD/MM/AAAA):\n ");
	scanf("%s", novoIngresso.data_nascimento);

	ingressos[num_ingressos++] = novoIngresso;
	printf("Ingresso vendido com sucesso!\n \n \n");
	fflush(stdin);
}
/*permitir que a fun��o for use o num_ingrssos para executas a contagem de caracteres nas fun��es de .nome .cpf . data_nascimento */
void listarIngresso() {
	printf("=========================================================\n");
	printf("Ingressos vendidos:\n");
	printf("=========================================================\n");
	for(int i = 0; i < num_ingressos; i++){
		printf("Nome: %s\n", ingressos[i].nome);
		printf("CPF: %s\n", ingressos[i].cpf);
		printf("Data de nascimento: %s\n", ingressos[i].data_nascimento);
		printf("======================================================\n");
	}
}

void validarIngresso() {

	char cpf[11];
	printf("Digite o CPF para validar o ingresso: ");
	scanf("%s", cpf);
	for (int i = 0; i < num_ingressos; i++) {
		if(strcmp(cpf, ingressos[i].cpf) == 0) {
			printf("=========================================================\n");
			printf("INGRESSO V�LIDO. Dados do comprador:\n");
			printf("Nome: %s\n", ingressos[i].nome);
			printf("CPF: %s\n", ingressos[i].cpf);
			printf("Data de nascimento: %s\n\n\n", ingressos[i].data_nascimento);
			return;
		}
	}

	printf("INGRESSO INV�LIDO!\n");

}

void imprimirRelatorioVendas() {
    printf("===========================================================\n");
    printf("Relat�rio de Vendas:\n");
    printf("============================================================\n");

    float totalVendas = 0.0;

    for (int i = 0; i < num_ingressos; i++) {
        printf("Nome: %s\n", ingressos[i].nome);
        printf("CPF: %s\n", ingressos[i].cpf);
        printf("Data de Nascimento: %s\n", ingressos[i].data_nascimento);
        printf("========================================================\n");

        //Calcule o total de vendas
        //aqui voce pode calcular o valor total com base no pre�o do ingresso
        totalVendas  += 1.0;
    }

    printf("Total de vendas: R$ %.2f\n\n", totalVendas);
}

int main(){
    setLocale(LC_ALL, "Portuguese");//garante a acentua��o dos textos entre " " no c�digo

    int opcao;
    do{
        printf("Bem-vndo, a empresa CELSO PRODU��ES\n");
        printf("Escolha uma op��o para realizar o servi�o\n");
        printf("Menu:\n");

        printf("1. VENDER INGRESSO\n");
        printf("2. LISTAR INGRESSOS VENDIDOS\n");
        printf("3. VALIDAR INGRESSO\n");
        printf("4. RELATORIO DE VENDAS");
        printf("5. SAIR");
        printf("ESCOLHA UMA OP��O:");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                venderIngresso();
                break;
            case 2:
                listarIngresso();
                break;
            case 3:
                validarIngresso();
                break;
            case 4:
                imprimirRelatorioVendas();
                break;
            case 5:
                printf("Encerrando o programa\n");
                break;
            default:
                printf("OP��O INV�LIDA, tente novamnte\n");
        }
    } while (opcao != 5);

    return 0;
}
