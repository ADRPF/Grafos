#include <iostream>

typedef struct Node {
	int num; //n�mero do v�rtice
	struct Node* prox; // pr�ximo n�
}NODE;

typedef struct Grafo {
	int v; // n�mero de vertices do grafo
	int a; // n�mero de arcos do grafo
	NODE** n;   
}GRAFO;

/*
* Fun��o de inicializa��o do grafo, passando o n�mero de vertices como par�metro
*/
GRAFO* GrafoInit(int v) {
	GRAFO* g = new GRAFO;
	g->n = new NODE*[v]; // aloca o vetor de lista ligada
	g->v = v;
	g->a = 0;
	for (int i = 0; i < v; i++) {
		g->n[i] = nullptr;
	}
	return g;
}

/*
* fun��o que insere um novo n� a lista 
*/
NODE* NEWnode(int v, NODE* prox) {
	NODE* a = new NODE;
	a->num = v;
	a->prox = prox;
	return a;
}

/*
* Procedimento de inser��o de arestas
*/
void GrafoInsertLink(GRAFO* g, int v, int w) {
	for (NODE* a = g->n[v]; a != nullptr; a = a->prox)
		if (a->num == v) return;
	g->n[v] = NEWnode(w, g->n[v]);
	g->a++;
}

int main(int argc, char **argv) {
	GRAFO* g = GrafoInit(5);
	GrafoInsertLink(g, 0, 5);
	std::cout << "no 0 est� ligado ao no " << g->n[0]->num << std::endl;

	return 0;
}