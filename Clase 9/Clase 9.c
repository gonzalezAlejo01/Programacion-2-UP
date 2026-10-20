#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct lista{
    int a;
    struct lista* sig;
}nodo;

nodo* crear_nodo(int num){
    nodo* u=(nodo*)malloc(sizeof(nodo));
    u->a=num;
    u->sig=NULL;
    return u;
}

void apilar(nodo** p, nodo* u, int* primero, int* cant_total){
    if(*p==NULL){
        *primero=u->a;
    }
    *cant_total+=1;
    u->sig=*p;
    *p=u;
}

nodo desapilar(nodo** p){
    nodo* aux=*p;
    nodo datos=**p;
    (*p)=(*p)->sig;
    free(aux);
    return datos;
}

void mostrar(nodo p,int* cantMultiplosTres,int* cantDivisoresCuatro,int* sumaDivisoresCuatro,int* promDivisoresCuatro,int primerElemento,int* sumatoriaPrimerElem,
             int* posAct,int* maxNum,int* maxPos,int* minNum,int* minPos,int ingreso,int* aparicionesIngreso){
    printf("Se realizan los calculos sobre el nùmero: %i\n",p.a);
    if(p.a%3==0){*cantMultiplosTres+=1;}
    printf("1\n");
    if(4%(p.a)==0){printf("ENTRA");*cantDivisoresCuatro+=1;*sumaDivisoresCuatro+=p.a;}
    printf("2\n");
    if(p.a%primerElemento==0){*sumatoriaPrimerElem+=p.a;}
    printf("3\n");
    *posAct=(*posAct)-1;
    printf("4\n");
    if(p.a>*maxNum){*maxNum=p.a;*maxPos=*posAct;}
    printf("5\n");
    if(p.a<*minNum){*minNum=p.a;*minPos=*posAct;}
    printf("6\n");
    if(p.a==ingreso){*aparicionesIngreso+=1;}
    printf("7\n");
}

int main(){
    nodo* p=NULL;
    int num;
    int primero;
    int cant_total=0;
    printf("Ingrese un numero: ");
    scanf("%i",&num);
    while(num!=67){
        apilar(&p, crear_nodo(num), &primero,&cant_total);
        printf("Ingrese un numero: ");
        scanf("%i",&num);
    }
    printf("Ingrese un numero, se buscaran todas sus apariciones: ");
    scanf("%i",&num);

    int cantMultiplosTres=0;
    int cantDivisoresCuatro=0;
    int sumaDivisoresCuatro=0;
    int promDivisoresCuatro;
    int sumatoriaPrimerElem=0;
    int posAct=cant_total;
    int maxNum=primero,maxPos=posAct,minNum=primero,minPos=posAct;
    int aparicionesIngreso=0;

    while(p!=NULL){
        mostrar(desapilar(&p), &cantMultiplosTres,&cantDivisoresCuatro,&sumaDivisoresCuatro,&promDivisoresCuatro,primero,&sumatoriaPrimerElem,
                          &posAct,&maxNum,&maxPos,&minNum,&minPos,num,&aparicionesIngreso);
    }

    printf("Multiplos de 3: %i\n",cantMultiplosTres);
    if(cantDivisoresCuatro>0){
        printf("Promedio divisores 4: %f\n",(float)sumaDivisoresCuatro/cantDivisoresCuatro);
    }
    else{
        printf("No se tienen divisores de 4\n");
    }
    printf("La sumatoria de multiplos del primer elemento (%i) es: %i\n",primero,sumatoriaPrimerElem);
    printf("El maximo elemento es %i, en la posicion %i\n",maxNum,maxPos);
    printf("El minimo elemento es %i, en la posicion %i\n",minNum,minPos);
    printf("El numero %i aparece %i veces",num,aparicionesIngreso);
}
