#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cuentas{
    int dni;
    char nombre[15];
    char tipo;
    float saldo;
    struct cuentas *siguiente;
}nodo;

void cargar(nodo *p){
    printf("Ingrese el nombre: ");
    scanf("%s",p->nombre);
    if (strcmp(p->nombre,"FIN")==0){
        p->siguiente=NULL;
        return;
    }
    else{
        printf("Ingrese el DNI: ");
        scanf("%i",&p->dni);
        printf("Ingrese el tipo de cuenta (C,E,A): ");
        scanf(" %c",&p->tipo);
        while (p->tipo!='C' && p->tipo!='E' && p->tipo!='A'){
            printf("El tipo de cuenta debe ser C, E o A: ");
            scanf(" %c", &p->tipo);
        }
        printf("Ingrese el saldo de cuenta: ");
        scanf("%f",&p->saldo);
        p->siguiente=(nodo*)malloc(sizeof(nodo));
        cargar(p->siguiente);
    }
}

nodo* buscar(nodo *p, int dni){
    if(p->siguiente==NULL){
        return NULL;
    }
    else if (p->dni==dni){
        return p;
    }
    else{
        return buscar(p->siguiente, dni);
    }
}

void contar_tipos(nodo *p, int *cant_c, int *cant_e, int *cant_a){
    if(p->siguiente==NULL){
        return;
    }
    else{
        if(p->tipo=='C'){
            *cant_c+=1;
        }
        else if(p->tipo=='E'){
            *cant_e+=1;
        }
        else{
            *cant_a+=1;
        }
        contar_tipos(p->siguiente, cant_c, cant_e, cant_a);
    }
}

int main(){
    nodo *p;
    p=(nodo*)malloc(sizeof(nodo));
    int cant_c=0, cant_e=0, cant_a=0;
    cargar(p);

    int dni;
    printf("Ingrese el DNI a buscar: ");
    scanf("%i",&dni);
    nodo *nodo_buscado=buscar(p, dni);
    if(nodo_buscado==NULL){
        printf("No se encuentra el dni en la lista");
    }
    else{
        printf("Se encuentra el dni %i en la lista, registrado con los siguientes datos:\n", dni);
        printf("Nombre: %s \nTipo de cuenta: %c \nSaldo: %f \n(Direccion en memoria: %p)", nodo_buscado->nombre,nodo_buscado->tipo,nodo_buscado->saldo,nodo_buscado);
    }

    contar_tipos(p, &cant_c, &cant_e, &cant_a);
    printf("\nCantidad de cuentas registradas por tipo:\nC: %i\nE: %i\nA: %i",cant_c,cant_e,cant_a);
    return 0;
}
