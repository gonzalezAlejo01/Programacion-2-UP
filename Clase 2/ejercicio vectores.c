#include <stdio.h>
//vector x posiciones (finaliza con ingreso de N par mayor al 3er item), mostrar max item y si cant es par la suma de los items de pos impares, si es impar la productoria de los multiplos de 5
float suma_impares(float nums[100], int tope){
    float suma=0;
    for (int i=1;i<tope;i=i+2){
        suma=suma+nums[i];
    }
    return suma;
}

float productoria_multiplos(float nums[100], int tope){
    float productoria=1;
    for(int i=0;i<tope;i++){
        if((int)nums[i]%5==0){
            productoria=productoria*nums[i];
        }
    }
    return productoria;
}

void cargar(float nums[100],int *tope){
    float ingreso;
    printf("Ingrese un numero: ");
    scanf("%f",&ingreso);
    nums[*tope]=ingreso;
    *tope=(*tope)+1;

    while ((*tope)<3||(ingreso<=nums[2] || (int)ingreso%2==1)){
        printf("Ingrese un numero: ");
        scanf("%f",&ingreso);
        nums[*tope]=ingreso;
        *tope=(*tope)+1;
    }
}

int maximo(float nums[100], int tope){
    int max_i=0;
    float max=nums[max_i];
    for (int i=1;i<tope;i++){
        if (nums[i]>max){
            max=nums[i];
            max_i=i;
        }
    }
    return max_i;
}

int main(){
    float nums[100];
    int tope=0;
    cargar(nums, &tope);
    int max=maximo(nums, tope);
    printf("El maximo numero ingresado es %f\n",nums[max]);
    if (tope%2==0){
        float suma=suma_impares(nums,tope);
        printf("La suma de los numeros de posicion impar es %f",suma);
    }
    else{
        float producto=productoria_multiplos(nums, tope);
        printf("La productoria de los multiplos de 5 es %f",producto);
    }
    return 0;
}
