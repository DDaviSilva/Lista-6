typedef struct elemento{
	int valor;
	struct elemento *prox;
}Elemento;

typedef struct{
	int qtd;
	struct elemento *ini;
}Lista;

Lista *cria_lista(int tamanho);
int resolve_problema(Lista *li, int n);
int print_lista(Lista *li);
int libera_lista(Lista *li); 
