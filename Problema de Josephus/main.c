#include<stdio.h>
#include<stdlib.h>
#include"jos.h"

int main(){

Lista *li = cria_lista(5);

print_lista(li);

printf("Resposta: %d\n\n",resolve_problema(li,4));

libera_lista(li);

return 0;
}
