#include <stdio.h>

int sumar(int a, int b){
    int total=a+b;
    return total;
}

int restar(int a, int b);

int multiplicar(int a, int b){
    int total=a*b;
    return total;
}

int dividir(int a, int b){
    int total=a/b;
    return total;
}

int main(){
    int a,b,res;
    char signo;
    printf("Ingrese el primer numero\n");
    scanf("%d",&a);
    printf("Ingrese el segundo numero\n");
    scanf("%d",&b);
    while (a!=0 || b!=0){
        printf("Ingrese la operacion\n");
        scanf(" %c",&signo);
        while (signo!='+' && signo!='-' && signo!='*' && signo!='/'){
            printf("Operacion invalida, debe ser +, -, * o /\n");
            scanf(" %c",&signo);
        }
        if (signo=='+'){
            res=sumar(a,b);
            printf("%d+%d=%d\n",a,b,res);
        }
        else if (signo=='-'){
            res=restar(a,b);
            printf("%d-%d=%d\n",a,b,res);
        }
        else if (signo=='*'){
            res=multiplicar(a,b);
            printf("%d*%d=%d\n",a,b,res);
        }
        else{
            if(b!=0){
                res=dividir(a,b);
                printf("%d/%d=%d\n",a,b,res);
            }
            else{
                printf("No se puede dividir por cero\n");
            }
        }
        printf("Ingrese el primer numero\n");
        scanf("%d",&a);
        printf("Ingrese el segundo numero\n");
        scanf("%d",&b);
    }
    return 0;
}

int restar(int a, int b){
    int total=a-b;
    return total;
}
