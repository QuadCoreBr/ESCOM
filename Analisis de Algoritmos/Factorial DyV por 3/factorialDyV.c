#include <stdio.h>
#include <math.h>
double factorial(double,double);
int main(){
    int f;
    printf("ingresa el valor del que deseas conocer el factorial: ");
    scanf("%d",&f);
    printf("Resultado final %e",factorial(1,f));
    return 0;
}

double factorial(double ini,double fin){
    double t = ceil((fin-ini)/3);
    double verificador = log(fin-(ini-1))/log(3);
    printf("Valores de llamada recursiva n %.2f %.2f %.2f \n",ini,fin,verificador);
    if(ceilf(verificador) == verificador){
        printf("Recursando segmento %.2f - %.2f \n",ini,fin);
        if(ini==fin){
                    return ini;
        }
        if(t==1){
            printf("Entro a t==1 de verificador\n");
                return factorial(ini,ini)*factorial(ini+t,ini+t)*factorial(fin,fin);
        }
            return factorial(ini,t)*factorial(ini+t,ini+2*t-1)*factorial(ini+2*t,fin);
    }else{
        printf("segmento no divisble de ini fin %.2f %.4f \n",ini,fin);
        if(ini==fin)
            return ini;
        if(fin-(ini-1)<3)
            return factorial(ini,ini)*factorial(fin,fin);
        if(t==1){
            return factorial(ini,ini)*factorial(ini+t,ini+t)*factorial(ini+2*t,fin);
        }
        return factorial(ini,ini+t-1)*factorial(ini+t,ini+2*t-1)*factorial(ini+2*t,fin);
    }
}
