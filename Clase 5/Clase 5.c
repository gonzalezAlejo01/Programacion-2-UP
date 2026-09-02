#include <stdio.h>
//Array de enteros ordenado de menor a mayor. Eliminar duplicados (c/u aparece una vez). Modificar el array directamente mediante punteros, devolver la nueva longitud sin duplicados
//Elementos mas alla del nuevo len no importan

void cargar(int *ptr){
    printf("Ingrese un entero, cada uno debe ser mayor o igual al previo: ");
    scanf("%i",ptr);
    for (int i=1;i<10;i++){
        printf("Ingrese un entero, cada uno debe ser mayor o igual al previo: ");
        scanf("%i",ptr+i);
        while(*(ptr+i)<*(ptr-1+i)){
            printf("El numero debe ser mayor o igual a su anterior: ");
            scanf("%i",ptr+i);
        }
    }
}

void mostrar(int *ptr){
    for (int i=0;i<10;i++){
        printf("%i\n",*(ptr+i));
    }
}

int eliminar_repetidos(int *ptr){
    int salto=0, i=1;
    while ((i+salto)<10){
        while(*(ptr+i)<=*(ptr+i-1) && i+salto<10){
            if(*(ptr+i+salto)>*(ptr+i)){
                *(ptr+i)=*(ptr+i+salto);
            }
            else{
                salto+=1;
            }
        }
        if (i+salto<10){
            i+=1;
        }
    }
    printf("\n%i\n",i);
    return i;
}

int main(){
    int longitud=10;
    int vec[longitud];
    int *ptr=vec;
    cargar(ptr);
    mostrar(ptr);
    longitud=eliminar_repetidos(ptr);
    mostrar(ptr);
    return 0;
}
