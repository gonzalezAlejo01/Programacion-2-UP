#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct arbol{
	int dato;
	struct arbol *izq;
	struct arbol *der;
}nodo;

typedef struct nodo{
    int num;
    struct nodo *sig;
}nPila;

void insertar (nodo **hoja, int elem){
    if(elem==-1){
        return;
    }
    if (*hoja==NULL){
        (*hoja)=(nodo*)malloc(sizeof(nodo));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }
    else{
        if(elem>(*hoja)->dato){
            insertar(&(*hoja)->der,elem);
        }
        else{
            insertar(&(*hoja)->izq,elem);
        }
    }
    return;
}

void crear (nodo **hoja){
    int num;
    printf("Ingrese num: ");
    scanf("%i",&num);
    while(num!=-1){
        insertar(&(*hoja),num);
        printf("Ingrese otro: ");
        scanf("%i",&num);
    }
}

void mostrarOrd(nodo *hoja){
	if (hoja!=NULL){
		mostrarOrd(hoja->izq);
		printf("%i\n",hoja->dato);
		mostrarOrd(hoja->der);
	}
}

void mostrarPreOrd(nodo *hoja){
	if (hoja!=NULL){
		printf("%i\n",hoja->dato);
		mostrarPreOrd(hoja->izq);
		mostrarPreOrd(hoja->der);
	}
}

void mostrarPostOrd(nodo *hoja){
	if (hoja!=NULL){
		mostrarPostOrd(hoja->izq);
		mostrarPostOrd(hoja->der);
		printf("%i\n",hoja->dato);
	}
}

void sumatoria(nodo *hoja, int *sum){
    if(hoja!=NULL){
        if(hoja->dato % 9 == 0 && (hoja->izq != hoja->der && (hoja->izq==NULL || hoja->der == NULL))){
            *sum+=hoja->dato;
        }
        sumatoria(hoja->izq, sum);
        sumatoria(hoja->der, sum);
    }
}

void maxNoMultRaiz(nodo *hoja, int raiz, int *maxNoMult){
    if(hoja!=NULL){
        if(hoja->dato%raiz!=0){
            if(*maxNoMult==raiz || *maxNoMult<hoja->dato){
                *maxNoMult=hoja->dato;
            }
        }
        maxNoMultRaiz(hoja->izq, raiz, maxNoMult);
        maxNoMultRaiz(hoja->der, raiz, maxNoMult);
    }
}

int buscarNivel(nodo *hoja, int num, int nivel){
    if(hoja!=NULL){
        if(hoja->dato==num){
            return nivel;
        }
        else if(hoja->dato<num){
            return buscarNivel(hoja->der, num, nivel+1);
        }
        else{
            return buscarNivel(hoja->izq, num, nivel+1);
        }
    }
    else{
        return 0;
    }
}

nPila* crearNodo(int num){
    nPila *aux=(nPila*)malloc(sizeof(nPila));
    aux->num=num;
    aux->sig=NULL;
    return aux;
}

void apilar(nPila **pila, nPila *aux, int *cont, int *segElem){
    aux->sig=*pila;
    *pila=aux;
    *cont+=1;
    if(*cont==2){
        *segElem=aux->num;
    }
}

void crearPila(nPila **pila, int *cont, int *segElem){
    int num;
    printf("Ingrese un numero (999 para salir): ");
    scanf("%i",&num);
    while(num!=999){
        apilar(pila, crearNodo(num), cont, segElem);
        printf("Ingrese otro: ");
        scanf("%i",&num);
    }
}

nPila desapilar(nPila **pila, int *segElem, int *cantMayoresSeg, int *ingreso, int *cont){
    nPila *aux=*pila;
    nPila item=**pila;
    (*pila)=(*pila)->sig;
    free(aux);

    if(item.num==*segElem){
        *cantMayoresSeg+=1;
    }
    if(item.num==*ingreso){
        *cont+=1;
    }

    return item;
}

void mostrarPila(nPila item){
    printf("Valor del item actual: %i\n",item.num);
}

int main(){
    /*
    nodo* arbol=NULL;
    crear(&arbol);
    printf("ARBOL CREADO: \n");
    printf("\nEn orden:\n");
    mostrarOrd(arbol);

    int sum=0, maxNoMult=arbol->dato, num, nivel=1;
    sumatoria(arbol, &sum);
    printf("Sumatoria de multiplos de 9 con un solo hijo: %i\n",sum);

    maxNoMultRaiz(arbol, arbol->dato, &maxNoMult);
    printf("Maximo no multiplo de %i: %i\n",arbol->dato,maxNoMult);

    printf("Ingrese un numero a buscar: ");
    scanf("%i",&num);
    nivel=buscarNivel(arbol, num, nivel);
    if(nivel>0){
        printf("El numero esta en el arbol, en el nivel %i", nivel);
    }
    else{
        printf("El numero no esta en el arbol");
    }
    */

    nPila* pila=NULL;
    int segElem, cantMayoresSeg=0, ingreso, cont=0;
    crearPila(&pila, &segElem, &cont);
    cont=0;
    printf("Ingrese un numero, y se buscaran todas sus apariciones: ");
    scanf("%i",&ingreso);
    while(pila!=NULL){
        mostrarPila(desapilar(pila, &segElem, &cantMayoresSeg, &ingreso, &cont));
    }

    printf("En la pila hay %i elementos mayores al segundo (%i)\n", cantMayoresSeg, segElem);
    printf("El numero ingresado aparece %i veces en la pila",cont);

    /*
    |     |      /\      /-----  |------  |-----\
    |     |     /  \     |       |        |      |
    |-----|    /----\    |       |---     |_____/
    |     |   /      \   |       |        |   \  
    |     |  /        \  \_____  |______  |    \    

    (el de colas, me da paja terminarlo)
    */

    return 0;
}
