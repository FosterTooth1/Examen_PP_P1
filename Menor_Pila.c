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
void apilar(Pila *p, struct Nodo dato);
void Desapilar(Pila *p, struct Nodo *datoExtraido);
bool isEmpty(Pila p);
void MostrarPila(Pila *p);
void MenorPila(Pila *p);
void vaciarPila(Pila *p);

Pila* crearPila(){
    Pila* pilaAsignacion=(Pila*) malloc(sizeof(Pila));
    pilaAsignacion->cima=NULL;
    pilaAsignacion->cursor=0;
    return pilaAsignacion;
}

void apilar(Pila *p, struct Nodo dato){
    struct Nodo* nodoUsuario=(struct Nodo*) malloc(sizeof(struct Nodo));
    nodoUsuario->valor=dato.valor;
    nodoUsuario->NodoInferior=p->cima;
    p->cima=nodoUsuario;
    p->cursor++;
}

void vaciarPila(Pila *p){
    while(!isEmpty(*p)){
        struct Nodo datoExtraido;
        Desapilar(p,&datoExtraido);
    }
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
}

void MenorPila(Pila* p){
    struct Nodo *aux;
    aux = p->cima;
    if (aux == NULL) {
        printf ("No hay Datos\n");
    }
    int menor = aux->valor;
    while (aux) {
        if(menor > aux->valor){
            menor=aux->valor;
        }
        aux = aux->NodoInferior;
    }
    printf("El dato menor de la pila es: %d", menor);
}

int main(int argc, char** argv){
    int cantidadDatos;
    Pila *p=crearPila();
    struct Nodo dato;
    int opc;
    do{
        printf("\n------------CONTROL DE PILA---------\n");
        printf("\n1. Mostrar Datos\n");
        printf("2. Agregar Datos a la Pila\n");
        printf("3. Remover Datos de la Pila\n");
        printf("4. Mostrar el dato menor de la Pila\n");
        printf("5. Salir");
        printf("\n\nInserte su opcion: ");
        scanf("%d", &opc);
    switch (opc){
        case 1:
            MostrarPila(p);
            break;

        case 2:
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

        case 3:
            puts("Cuantos valores quiere quitar a la pila?");
            fflush(stdin);
            scanf("%d",&cantidadDatos);
            for(int i=0; i<cantidadDatos; i++){
                Desapilar(p,&dato);
                printf("Valor extraido: %d\n",dato.valor);
            }
            break;

        case 4:
            MenorPila(p);
            break;
 
        default:
            break;
        }
    }while (opc!=5);
    vaciarPila(p);
    free(p);
    return 0;
}