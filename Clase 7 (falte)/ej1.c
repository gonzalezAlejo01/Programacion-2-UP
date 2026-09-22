#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *sig;
}nodo;

void cargar(nodo *p){
    int numero;
    printf("Ingrese un entero, mayor o igual a sus anteriores: ");
    scanf("%i",&numero);
    while (numero!=1000){
        p->num=numero;
        printf("Ingrese un entero, mayor o igual a sus anteriores: ");
        scanf("%i",&numero);
        while(p->num>numero){
            printf("El numero debe ser mayor o igual a su anterior: ");
            scanf("%i",&numero);
        }
        if(numero!=1000){
            p->sig=(nodo*)malloc(sizeof(nodo));
            p=p->sig;
        }
    }
    p->sig=NULL;
}

void mostrar(nodo *p){
    printf("%i, ",p->num);
    if (p->sig!=NULL){
        mostrar(p->sig);
    }
    return;
}

void agregar_tercer_consecutivo(nodo *p){
    if(p->sig!=NULL){
        if(p->num==((p->sig)->num)-1){
            p=p->sig;
            nodo *aux;
            aux=(nodo*)malloc(sizeof(nodo));
            aux->num=(p->num)+1;
            aux->sig=p->sig;
            p->sig=aux;
            agregar_tercer_consecutivo(aux->sig);
        }
        else{
            agregar_tercer_consecutivo(p->sig);
        }
    }
    return;
}

void eliminar_primer_consecutivo(nodo *p){
    if(p!=NULL && p->sig!=NULL){
        if(p->num==(p->sig)->num-1){
            if(p->sig->sig!=NULL){
                p->num=p->sig->num;
                nodo *aux=p->sig->sig;
                free(p->sig);
                p->sig=aux;
            }
            else{
                p->num=p->sig->num;
                free(p->sig);
                p->sig=NULL;
            }
        }
        eliminar_primer_consecutivo(p->sig);
    }
    return;
}

void eliminar_segundo_consecutivo(nodo *p){
    if(p->sig!=NULL && p->sig->sig!=NULL){
        if(p->num==(p->sig)->num-1){
            nodo *aux=p->sig->sig;
            free(p->sig);
            p->sig=aux;
        }
        eliminar_segundo_consecutivo(p->sig);
    }
    return;
}

int main(){
    nodo *p;
    p=(nodo*)malloc(sizeof(nodo));
    p->sig=NULL;
    cargar(p);
    //agregar_tercer_consecutivo(p);
    eliminar_primer_consecutivo(p);
    //eliminar_segundo_consecutivo(p);
    mostrar(p);
}
