#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	NO* aux, *ant = primeiro;
	int inserir;

	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> inserir;

	if (primeiro == NULL)
	{

		novo->valor = inserir;
		novo->prox = NULL;
		primeiro = novo;

	}

	else if(inserir == primeiro->valor) {
			cout << "Valor digitado ja existe." << endl;
			return;
	}
	else if(inserir < primeiro->valor){
		
		novo->valor = inserir;
		novo->prox = primeiro;
			
		primeiro = novo;

	}
	else{

		aux = primeiro->prox;

			while (aux) {

				if (inserir == aux->valor) {
					cout << "Valor digitado ja existe." << endl;
					return;
				}
				if (inserir < aux->valor) {

					novo->valor = inserir;
					novo->prox = aux;
					ant->prox = novo;
					return;
				}
				ant = aux;
				aux = aux->prox;
			}
			

			novo->valor = inserir;
			novo->prox = NULL;
			ant->prox = novo;
		}
}

void excluirElemento()
{

	if (primeiro == NULL) {
		cout << "Lista vazia" << endl;
	}
	else {
		NO* aux, * ant;
		int deletar;

		aux = primeiro;

		cout << "Digite o numero que deseja excluir: \n" << endl;
		cin >> deletar;

		if (aux) {
			if (aux->valor == deletar) {
				primeiro = aux->prox;
				free(aux);
				cout << "Valor excluido" << endl;
				return;
			}
			else if (deletar < aux->valor) {
				cout << "Valor não encontrado" << endl;
				return;
			}
			else {

				ant = aux;
				aux = aux->prox;
			}

			while (aux) {

				if (aux->valor == deletar) {
					ant->prox = aux->prox;
					free(aux);
					cout << "Valor excluido" << endl;
					return;
				}
				else if (aux->valor > deletar) {
					cout << "Valor não encontrado" << endl;
					return;
				}
				else {
					ant = aux;
					aux = aux->prox;
				}

			}

		}

		}
}

void buscarElemento()
{
	NO* aux = primeiro;
	int busca;
	if (primeiro == NULL) {
		cout << "Lista vazia" << endl;
	}
	else {
		cout << "Digite o valor que deseja buscar: \n" << endl;
		cin >> busca;

		while (aux) {
			if (aux->valor == busca) {
				cout << "Valor encontrado" << endl;
				return;
			}
			else if (aux->valor < busca) {
				cout << "Valor nao encontrado" << endl;
				return;
			}
			else {
				aux = aux->prox;

			}
		}
	}

}

