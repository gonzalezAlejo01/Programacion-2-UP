#include <stdio.h>
#include <string.h>

int main(){
    int cont=0;
    char letra;
    printf("Ingrese un texto, terminando en un .: ");
    letra=getchar();
    while(letra!='.'){
        if (letra!=' '){
            if (cont%2==0){
                if (letra>='a' && letra<='z'){
                    letra-=32;
                }
            }
        else{
            if (letra<='Z' && letra>='A'){
                letra+=32;
                }
            }
        cont+=1;
        putchar(letra);
        letra=getchar();
        }
        else{
            while (letra==' '){
                letra=getchar();
            }
            putchar(' ');
        }
    }
    return 0;
}
