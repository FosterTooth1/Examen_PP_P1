#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Flores Lara Alberto; Luna Zamora Juan Antonio; Saucillo González Jesse Obed 	3BV2

struct Nodo{
    int valor;
    struct Nodo* NodoInferior;
};

typedef struct{
    struct Nodo* cima;
    int cursor;
}Pila;

Pila* crearPila();
void consultarCima(Pila *p);
void apilar(Pila *p, struct Nodo dato);
void Desapilar(Pila *p, struct Nodo *datoExtraido);
void vaciarPila(Pila *p);
bool isEmpty(Pila p);
void MostrarPila(Pila *p);
void Burble_sort_Ascendente(Pila *p);

Pila* crearPila(){
    Pila* pilaAsignacion=(Pila*) malloc(sizeof(Pila));
    pilaAsignacion->cima=NULL;
    pilaAsignacion->cursor=0;
    return pilaAsignacion;
}

void consultarCima(Pila *p){
    if(!isEmpty(*p)){
        printf("Valor en la cima: %d\n", p->cima->valor);
    }
}

void vaciarPila(Pila *p){
    while(!isEmpty(*p)){
        struct Nodo datoExtraido;
        Desapilar(p,&datoExtraido);
    }
}

void apilar(Pila *p, struct Nodo dato){
    struct Nodo* nodoUsuario=(struct Nodo*) malloc(sizeof(struct Nodo));
    nodoUsuario->valor=dato.valor;
    nodoUsuario->NodoInferior=p->cima;
    p->cima=nodoUsuario;
    p->cursor++;
}

void Desapilar(Pila *p, struct Nodo *datoExtraido){
        struct Nodo* aux=p->cima;
        datoExtraido->valor=aux->valor;
        p->cima=aux->NodoInferior;//p->cima=p->cima->NodoInferior
        aux->NodoInferior=NULL;
        p->cursor--;
        free(aux);
}

bool isEmpty(Pila p){
    if(p.cima==NULL){
        return true;
    } else{
        return false;   
    }
}

void MostrarPila(Pila* p){
    printf ("\nDatos en la Pila:\n\n");
    struct Nodo *aux;
    aux = p->cima; //Se trabaja con una copia de la Pila "Principal"
    if (aux == NULL) {
        printf ("No hay Datos\n");
    }
    int cantidad = p->cursor;
    while (aux) {
        printf ("%d. %d\n", cantidad, aux->valor);
        aux = aux->NodoInferior;
        cantidad--;
    }
    free(aux);
}

void Burble_sort_Ascendente(Pila *p){
    struct Nodo *aux;
    aux = p->cima; //Se trabaja con una copia de la Pila "Principal"
    if (aux == NULL) {
        printf ("No hay Datos\n");
    }else{
        while(aux!=NULL){
            struct Nodo *aux2 = aux->NodoInferior;
            while(aux2!=NULL){
                if(aux->valor>aux2->valor){
                    int aux3 = aux2->valor;
                    aux2->valor = aux->valor;
                    aux->valor=aux3;
                }
                aux2=aux2->NodoInferior;
            }
            aux=aux->NodoInferior;
        }
    }
}

int main(int argc, char** argv){
    int cantidadDatos;
    Pila *p=crearPila();
    struct Nodo dato;
    int opc;
    do{
        printf("\n------------CONTROL DE PILA---------\n");
        printf("\n1. Mostrar Datos\n");
        printf("2. Mostrar el valor en la cima de la Pila\n");
        printf("3. Agregar Datos a la Pila\n");
        printf("4. Remover Datos de la Pila\n");
        printf("5. Ordenar la pila con los datos menores hasta la cima\n");
        printf("6. Salir");
        printf("\n\nInserte su opcion: ");
        scanf("%d", &opc);
    switch (opc){
        case 1:
            MostrarPila(p);
            break;

        case 2:
            consultarCima(p);
            break;

        case 3:
            puts("Cuantos valores quieres agregar a la pila?");
            fflush(stdin);
            scanf("%d",&cantidadDatos);
            for(int i=0; i<cantidadDatos; i++){
                puts("Ingresa un valor:");
                fflush(stdin);
                scanf("%d",&dato.valor);
                apilar(p,dato);
            }
            puts("Datos agregados correctamente!");
            break;

        case 4:
            puts("Cuantos valores quiere quitar a la pila?");
            fflush(stdin);
            scanf("%d",&cantidadDatos);
            for(int i=0; i<cantidadDatos; i++){
                Desapilar(p,&dato);
                printf("Valor extraido: %d\n",dato.valor);
            }
            break;

        case 5:
            Burble_sort_Ascendente(p);
            puts("\nSus datos estan ordenados!");

        default:
            break;
        }
    }while (opc!=6);
    vaciarPila(p);
    free(p);
    return 0;
}