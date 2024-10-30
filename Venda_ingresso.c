#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>          //comando para garantir a acentuação das palavras nas strings dos códigos
#define CELSO_PRODUCOES 150 //Constante que denominei a empresa do evento e coloquei a quantidade de ingressos a serem vendidos no máximo de 150 ingressos

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

	printf("Digite o CPF do comprador:(sem pontos, apenas números)\n ");
	scanf("%s", novoIngresso.cpf);

	printf("Digite a data de nascimento do comprador (DD/MM/AAAA):\n ");
	scanf("%s", novoIngresso.data_nascimento);

	ingressos[num_ingressos++] = novoIngresso;
	printf("Ingresso vendido com sucesso!\n \n \n");
	fflush(stdin);
}
/*permitir que a função for use o num_ingrssos para executas a contagem de caracteres nas funções de .nome .cpf . data_nascimento */
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
			printf("INGRESSO VÁLIDO. Dados do comprador:\n");
			printf("Nome: %s\n", ingressos[i].nome);
			printf("CPF: %s\n", ingressos[i].cpf);
			printf("Data de nascimento: %s\n\n\n", ingressos[i].data_nascimento);
			return;
		}
	}

	printf("INGRESSO INVÁLIDO!\n");

}

void imprimirRelatorioVendas() {
    printf("===========================================================\n");
    printf("Relatório de Vendas:\n");
    printf("============================================================\n");

    float totalVendas = 0.0;

    for (int i = 0; i < num_ingressos; i++) {
        printf("Nome: %s\n", ingressos[i].nome);
        printf("CPF: %s\n", ingressos[i].cpf);
        printf("Data de Nascimento: %s\n", ingressos[i].data_nascimento);
        printf("========================================================\n");

        //Calcule o total de vendas
        //aqui voce pode calcular o valor total com base no preço do ingresso
        totalVendas  += 1.0;
    }

    printf("Total de vendas: R$ %.2f\n\n", totalVendas);
}

int main(){
    setLocale(LC_ALL, "Portuguese");//garante a acentuação dos textos entre " " no código

    int opcao;
    do{
        printf("Bem-vndo, a empresa CELSO PRODUÇÕES\n");
        printf("Escolha uma opção para realizar o serviço\n");
        printf("Menu:\n");

        printf("1. VENDER INGRESSO\n");
        printf("2. LISTAR INGRESSOS VENDIDOS\n");
        printf("3. VALIDAR INGRESSO\n");
        printf("4. RELATORIO DE VENDAS");
        printf("5. SAIR");
        printf("ESCOLHA UMA OPÇÃO:");
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
                printf("OPÇÃO INVÁLIDA, tente novamnte\n");
        }
    } while (opcao != 5);

    return 0;
}
