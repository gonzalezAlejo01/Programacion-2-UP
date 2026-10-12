#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void cargar(FILE *arch){
    float n1,n2,prom;
    char nombre[20];
    printf("Ingrese el nombre: ");
    scanf(" %s",nombre);
    while(strcmp(nombre, "00")!=0){
        printf("Ingrese la primer nota: ");
        scanf("%f",&n1);
        printf("Y la segunda: ");
        scanf("%f",&n2);
        prom=(n1+n2)/2;
        fprintf(arch, "Alumno: %s\nNota 1: %f, Nota 2: %f (promedio: %f)\n",nombre,n1,n2,prom);
        printf("Ingrese el nombre: ");
        scanf(" %s",nombre);
    }
}

void mostrar(FILE *arch){
    float n1,n2,prom;
    char nombre[20];
    while(!feof(arch)){
        fscanf(arch, "Alumno: %s\nNota 1: %f, Nota 2: %f (promedio: %f)\n",nombre,&n1,&n2,&prom);
        printf("Alumno %s, notas: %f, %f\n",nombre,n1,n2,prom);
    }
}

int main(){
    FILE *arch=fopen("C:\\Users\\labb5\\Desktop\\Clase 8\\notas.txt","w");
    cargar(arch);
    fclose(arch);
    arch=fopen("C:\\Users\\labb5\\Desktop\\Clase 8\\notas.txt","r");
    mostrar(arch);
    fclose(arch);
}
