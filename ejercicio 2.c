#include <stdio.h>
#include <string.h>

int main(){
    char letra,anterior;
    int contVC=0;
    printf("Ingrese un texto, terminando en enter: ");
    letra=getchar();
    while (letra!='\n'){
        if (letra==' '){
            while (letra==' '){
                letra=getchar();
            }
            for(int i=0;i<4;i++){
                putchar(' ');
            }
        }
        else if (letra=='a' || letra=='e' || letra=='i' ||letra=='o' || letra=='u' || letra=='A' || letra=='E' || letra=='I' || letra=='O' || letra=='U'){
            while (letra!=' ' && letra!='\n'){
                if (letra=='s'){
                    putchar('-');
                }
                else{
                    putchar(letra);
                }
                anterior=letra;
                letra=getchar();
            }
            if (anterior!='a' && anterior!='e' && anterior!='i' && anterior!='o' && anterior!='u' && anterior!='A' && anterior!='E' && anterior!='I' && anterior!='O' && anterior!='U'){
                contVC+=1;
            }
        }
        else {
            if(letra=='s'){
                putchar('-');
            }
            else{
                putchar(letra);
            }
            anterior=letra;
            letra=getchar();
        }
    }
    printf("\nHay %i palabras que empiezan con vocal y terminan en consonante", contVC);

    return 0;
}
