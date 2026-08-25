#include <stdio.h>

int producto_diagonal(int matriz[5][5], int tope){
    if (tope==0){
        return matriz[0][0];
    }
    else{
        return matriz[tope][tope]*producto_diagonal(matriz, tope-1);
    }
}

void cargar(int matriz[5][5],int i, int j){
    int num;
    printf("Ingrese el elemento %i-%i: ",i,j);
    scanf("%i",&num);
    matriz[i][j]=num;
    if (j==4){
        if (i<4){
            j=0;
            cargar(matriz,i+1,j);
        }
    }
    else{
        cargar(matriz,i,j+1);
    }
}

int main(){
    int matriz[5][5];
    int i=0,j=0;
    cargar(matriz,i,j);
    int producto=producto_diagonal(matriz, 4);
    printf("Producto de la diagonal: %i",producto);
    return 0;
}
