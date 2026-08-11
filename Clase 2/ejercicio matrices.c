#include <stdio.h>
void cargar(int matriz[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            printf("Ingrese el numero a ubicar en %d-%d: ",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }
}

void mostrar(int matriz[4][4]){
    for (int i=0;i<4;i++){
        printf("\n------------\n");
        for (int j=0;j<4;j++){
            printf("|%i|",matriz[i][j]);
        }
    }
    printf("\n------------\n");
}

int sumatoria_fila(int fila, int matriz[4][4]){
    int suma=0;
    for (int i=0;i<4;i++){
        suma=suma+matriz[fila][i];
    }
    return suma;
}

int max_columna(int columna, int matriz[4][4]){
    int max=matriz[0][columna];
    for (int i=1;i<4;i++){
        if (matriz[i][columna]>max){
            max=matriz[i][columna];
        }
    }
    return max;
}

float prom_multiplos(int multiplo, int matriz[4][4]){
    int cont=0;
    float promedio,suma=0;
    for(int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (matriz[i][j]%5==0){
                cont++;
                suma=suma+matriz[i][j];
            }
        }
    }
    promedio=suma/cont;
    return promedio;
}

int suma_diagonal(int matriz[4][4]){
    int suma_diagonal=0;
    for (int i=0;i<4;i++){
        suma_diagonal=suma_diagonal+matriz[i][i];
    }
    return suma_diagonal;
}

int minimo_fila(int fila[4]){
    int min=fila[0];
    for (int i=1;i<4;i++){
        if (fila[i]<min){
            min=fila[i];
        }
    }
    return min;
}

void diag_sec(int matriz[4][4]){
    for (int i=0;i<4;i++){
        printf("%d ",matriz[3-i][i]);
    }
    printf("\n");
}

void elems_bajo_princ(int matriz[4][4]){
    for(int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (j<i){
                printf("%d ",matriz[i][j]);
            }
        }
    }
    printf("\n");
}

int main(){
    int matriz[4][4];
    cargar(matriz);
    mostrar(matriz); //BORRAR

    int sumSegF=sumatoria_fila(1, matriz);
    printf("La sumatoria de la segunda fila es: %d\n",sumSegF);

    int iMaySegC=max_columna(1, matriz);
    printf("El mayor valor de la segunda columna es: %d\n",iMaySegC);

    float promMulCinco=prom_multiplos(5, matriz);
    printf("El promedio de los multiplos de 5 de la matriz es: %f\n",promMulCinco);

    int sumDiagP=suma_diagonal(matriz);
    printf("La suma de los elementos de la diagonal princial es: %d\n",sumDiagP);

    for (int i=0;i<4;i++){
        int minF=minimo_fila(matriz[i]);
        printf("El minimo de la fila %d es: %d\n",i,minF);
    }

    printf("Elementos de la diagonal secundaria: ");
    diag_sec(matriz);

    printf("Elementos debajo de la diagonal principal: ");
    elems_bajo_princ(matriz);
    return 0;
}
