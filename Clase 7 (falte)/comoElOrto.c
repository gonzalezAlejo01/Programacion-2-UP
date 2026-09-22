#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//OJO QUE TOMA TEORIA

typedef struct listas_electorales{
    int nroL;
    char nomP[20];
    char nomC[20];
    int cantV;
    struct listas_electorales *sig;
}nodo;

typedef struct porcentajes{
    float pp;
    char nomP[20];
    struct porcentajes *sig;
}pctjs;

void cargar(nodo *p){
    int nroL, cantV;
    char nomP[20],nomC[20];

    printf("Ingrese el numero de lista: ");
    scanf("%i",&nroL);
    while(nroL<0){
        printf("Ingrese el numero de lista: ");
        scanf("%i",&nroL);
    }
    if (nroL>0){
        printf("Ingrese el nombre del partido: ");
        scanf(" %s",nomP);
        while(strcmp("",nomP)==0){
            printf("Ingrese el nombre del partido: ");
            scanf("%s",nomP);
        }
        printf("Ingrese el nombre del candidato: ");
        scanf(" %s",nomC);
        while(strcmp("",nomC)==0){
            printf("Ingrese el nombre del candidato: ");
            scanf("%s",nomC);
        }
        printf("Ingrese la cantidad de votos: ");
        scanf("%i",&cantV);
        while(cantV<0){
            printf("Ingrese la cantidad de votos: ");
            scanf("%i",&cantV);
        }
        p->sig=(nodo*)malloc(sizeof(nodo));
        p->nroL=nroL;
        strcpy(p->nomP,nomP);
        strcpy(p->nomC,nomC);
        p->cantV=cantV;
        cargar(p->sig);
    }
    else{
        p->sig=NULL;
    }
    return;
}

void insertar_especiales(nodo *p){
    int totVotos=0;
    while (p->sig!=NULL){
        totVotos+=p->cantV;
        if(strcmp(p->nomP,p->sig->nomP)!=0){
            nodo *aux=(nodo*)malloc(sizeof(nodo));
            aux->nroL=9999;
            strcpy(aux->nomP,"Nuevo_Partido");
            strcpy(aux->nomC,"XXXX");
            aux->cantV=totVotos;
            totVotos=0;

            aux->sig=p->sig;
            p->sig=aux;
            p=aux;
        }
        p=p->sig;
    }
    return;
}

void mostrar(nodo *p){
    if(p->sig!=NULL){
        printf("nroL: %i, nomP: %s, nomC: %s, cantV: %i\n",p->nroL,p->nomP,p->nomC,p->cantV);
        mostrar(p->sig);
    }
    return;
}

void filtrar_menos_treinta(nodo *p,nodo *q){
    if(p->sig!=NULL){
        if(p->cantV<30 && p->nroL!=9999){
            q->sig=(nodo*)malloc(sizeof(nodo));
            q->cantV=p->cantV;
            q->nroL=p->nroL;
            strcpy(q->nomC,p->nomC);
            strcpy(q->nomP,p->nomP);

            nodo *aux=p->sig->sig;
            p->cantV=p->sig->cantV;
            p->nroL=p->sig->nroL;
            strcpy(p->nomC,p->sig->nomC);
            strcpy(p->nomP,p->sig->nomP);
            free(p->sig);

            p->sig=aux;
            filtrar_menos_treinta(p,q->sig); //como se copia el siguiente en el nodo actual, es como haber hecho un p->sig, por lo que aca p->sig es aux (p->sig->sig del no borrado)
        }
        else{
            filtrar_menos_treinta(p->sig,q);
        }
    }
    else{
        q->sig=NULL;
    }
}

int cantVotos(nodo *p){
    if(p->sig!=NULL){
        if(p->nroL!=9999){
            return (p->cantV)+(cantVotos(p->sig));
        }
        else{
            return cantVotos(p->sig);
        }
    }
    return p->cantV;
}

int cantListas(nodo *p){
    if(p->sig!=NULL){
        if(p->nroL!=9999){
            return 1+cantListas(p->sig);
        }
        else{
            return cantListas(p->sig);
        }
    }
    return 0;
}

void filtrar_mayores_promedio(nodo *m, nodo *p, nodo*q, float promedio){
    if(p->sig!=NULL){
        if(p->cantV>promedio && p->nroL!=9999){
            m->nroL=p->nroL;
            m->cantV=p->cantV;
            strcpy(m->nomP,p->nomP);
            strcpy(m->nomC,p->nomC);
            m->sig=(nodo*)malloc(sizeof(nodo));
            filtrar_mayores_promedio(m->sig,p->sig,q,promedio);
        }
        else{
            filtrar_mayores_promedio(m,p->sig,q,promedio);
        }
    }
    else if(q->sig!=NULL){
        if(q->cantV>promedio){
            m->nroL=q->nroL;
            m->cantV=q->cantV;
            strcpy(m->nomP,q->nomP);
            strcpy(m->nomC,q->nomC);
            m->sig=(nodo*)malloc(sizeof(nodo));
            filtrar_mayores_promedio(m->sig,p,q->sig,promedio);
        }
        else{
            filtrar_mayores_promedio(m,p,q->sig,promedio);
        }
    }
    else{
        m->sig=NULL;
    }
}

int main(){
    nodo *listas;
    listas=(nodo*)malloc(sizeof(nodo));
    cargar(listas);
    insertar_especiales(listas);
    mostrar(listas);

    nodo *menores_treinta;
    menores_treinta=(nodo*)malloc(sizeof(nodo));
    filtrar_menos_treinta(listas, menores_treinta);

    printf("\n>=30:\n");
    mostrar(listas);
    printf("\nMenores treinta\n");
    mostrar(menores_treinta);

    int promVotos;
    int CVL=cantVotos(listas);
    int CVM=cantVotos(menores_treinta);
    int CLL=cantListas(listas);
    int CLM=cantListas(menores_treinta);
    if (CLL+CLM>0){
        promVotos=(CVL+CVM)/(CLL+CLM);
        nodo *mayores_promedio=(nodo*)malloc(sizeof(nodo));
        filtrar_mayores_promedio(mayores_promedio, listas,menores_treinta, promVotos);

        printf("\nMayores promedio (promedio %i)\n",promVotos);
        mostrar(mayores_promedio);
    }
    else{
        printf("\nNo hay ingresos en la lista, no se puede calcular un promedio\n");
    }¡
}
