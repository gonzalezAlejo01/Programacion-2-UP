#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alumnos{
    int nro_legajo;
    char nombre[20];
    int edad;
    char carrera[15];
    int anio;
    struct alumnos *sig;
}alumno;

void cargar(alumno *p){
    int legajo,edad,anio;
    char nombre[20],carrera[15];
    printf("Ingrese el legajo del alumno, o 0 para salir: ");
    scanf("%i",&legajo);
    while (legajo<0){
        printf("Ingrese el legajo del alumno, o 0 para salir: ");
        scanf("%i",&legajo);
    }
    if(legajo>0){
        printf("Ingrese el nombre: ");
        scanf(" %s",nombre);
        printf("Ingrese la edad: ");
        scanf("%i",&edad);
        while (edad<=17 || edad>120){
            printf("Ingrese la edad: ");
            scanf("%i",&edad);
        }
        printf("Ingrese la carrera: Seguridad o Inteligencia: ");
        scanf(" %s",carrera);
        while(strcmp(carrera,"Seguridad")!=0 && strcmp(carrera,"Inteligencia")!=0){
            printf("Ingrese la carrera: Seguridad o Inteligencia: ");
            scanf(" %s",carrera);
        }
        printf("Ingrese el anio de cursada: ");
        scanf("%i",&anio);
        while(anio<1 || anio>6){
            printf("Ingrese el anio de cursada: ");
            scanf("%i",&anio);
        }
        alumno *aux=(alumno*)malloc(sizeof(alumno));
        p->nro_legajo=legajo;
        p->edad=edad;
        p->anio=anio;
        strcpy(p->carrera,carrera);
        strcpy(p->nombre,nombre);
        p->sig=aux;
        cargar(p->sig);
    }
    else{
        p->sig=NULL;
    }
    return;
}

void mostrar(alumno *p){
    if(p->sig!=NULL){
        printf("Alumno: %s (nro %i), carrera: %s (%i anio), %i anios\n",p->nombre,p->nro_legajo,p->carrera,p->anio,p->edad);
        mostrar(p->sig);
    }
    return;
}

void ingresar_isa(alumno *p, alumno *isa){
    if(p->sig!=NULL){
        if(p->anio>2 && strcmp(p->carrera,"Inteligencia")==0){
            alumno *aux=(alumno*)malloc(sizeof(alumno));
            isa->anio=p->anio;
            isa->edad=p->edad;
            isa->nro_legajo=p->nro_legajo;
            strcpy(isa->nombre,p->nombre);
            strcpy(isa->carrera,p->carrera);
            isa->sig=aux;
            ingresar_isa(p->sig,isa->sig);
        }
        else{
            ingresar_isa(p->sig,isa);
        }
    }
    else{
        isa->sig=NULL;
    }
}

void cantsCarrera(alumno *p, char carrera[15], float *cantCarrera, float *sumEdad){
    if (p->sig!=NULL){
        if(strcmp(carrera, p->carrera)==0){
            (*cantCarrera)=(*cantCarrera)+1;
            (*sumEdad)=(*sumEdad)+(p->edad);
        }
        cantsCarrera(p->sig, carrera, cantCarrera, sumEdad);
    }
    return;
}

void vaciar(alumno *p){
    if(p->sig!=NULL){
        vaciar(p->sig);
    }
    free(p);
}

alumno* eliminar_cabeza(alumno *p, int legajo_elim){
    if(p->nro_legajo==legajo_elim){
        alumno *aux=p->sig;
        free(p);
        p=aux;
    }
    return p;
}

void eliminar_cuerpo(alumno *p, int legajo_elim){
    if(p->sig!=NULL && p->sig->sig!=NULL){
        if(p->sig->nro_legajo==legajo_elim){
            alumno *aux=p->sig->sig;
            free(p->sig);
            p->sig=aux;
        }
        eliminar_cuerpo(p->sig, legajo_elim);
    }
}

alumno* insertar_especial_head(alumno *p, int legajo_esp){
    if(p->nro_legajo==legajo_esp){
        alumno *aux=(alumno*)malloc(sizeof(alumno));
        aux->nro_legajo=9999;
        strcpy(aux->nombre, "PEPE");
        aux->edad=99;
        strcpy(aux->carrera,"Inteligencia");
        aux->anio=0;
        aux->sig=p;
        p=aux;
    }
    return p;
}

void insertar_especial_body(alumno *p, int legajo_esp){
    if(p->sig!=NULL && p->sig->sig!=NULL){
        if(p->sig->nro_legajo==legajo_esp && p->nro_legajo!=9999){
            alumno *aux=(alumno*)malloc(sizeof(alumno));
            aux->nro_legajo=9999;
            strcpy(aux->nombre, "PEPE");
            aux->edad=99;
            strcpy(aux->carrera,"Inteligencia");
            aux->anio=0;
            aux->sig=p->sig;
            p->sig=aux;
            printf("%i->%i->%i\n",aux->nro_legajo,aux->sig->nro_legajo,p->sig->nro_legajo);
            insertar_especial_body(aux->sig,legajo_esp);
        }
        else{
            insertar_especial_body(p->sig,legajo_esp);
        }
    }
}

void menu(alumno *p){
    alumno *isa=(alumno*)malloc(sizeof(alumno));//donde isa se refiere a Inteligencia Segundo Anio
    isa->sig=NULL;
    int opcion;
    printf("Ingrese la funcion a realizar:\n1) Cargar estudiantes\n2) Crear lista de inteligencia de 2do superior\n3) Calcular promedio seguridad\n4) Eliminar estudiante por legajo\n5) Insertar especial antes de alumno por legajo\n6) Salir: ");
    scanf("%i",&opcion);
    while(opcion<1||opcion>6){
        printf("Ingrese la funcion a realizar:\n1) Cargar estudiantes\n2) Crear lista de inteligencia de 2do superior\n3) Calcular promedio seguridad\n4) Eliminar estudiante por legajo\n5) Insertar especial antes de alumno por legajo\n6) Salir: ");
        scanf("%i",&opcion);
    }
    if(opcion==1){
        vaciar(p);
        p=(alumno*)malloc(sizeof(alumno));
        cargar(p);
        mostrar(p);
    }
    else if(opcion==2){
        vaciar(isa);
        ingresar_isa(p,isa);
        mostrar(isa);
    }
    else if(opcion==3){
        float cantSeg=0, sumEdad=0;
        cantsCarrera(p,"Seguridad",&cantSeg,&sumEdad);
        if(cantSeg>0){
            float prom=sumEdad/cantSeg;
            printf("El promedio de edad de quienes cursan seguridad es %f anios\n",prom);
        }
        else{
            printf("No hay alumnos de seguridad, no se puede calcular el promedio\n");
        }
    }
    else if(opcion==4){
        int legajo_elim;
        printf("Ingrese el legajo del alumno a eliminar: ");
        scanf("%i",&legajo_elim);
        p=eliminar_cabeza(p, legajo_elim);
        eliminar_cuerpo(p, legajo_elim);
        mostrar(p);
    }
    else if(opcion==5){
        int legajo_esp;
        printf("Ingrese el legajo previo al cual se ingresa el especial: ");
        scanf("%i", &legajo_esp);
        p=insertar_especial_head(p, legajo_esp);
        insertar_especial_body(p, legajo_esp);
        mostrar(p);
    }
    if(opcion!=6){
        menu(p);
    }
    else{
        printf("Se finaliza el programa.");
    }
}

int main(){
    alumno *p=(alumno*)malloc(sizeof(alumno));
    p->sig=NULL;
    menu(p);
}
