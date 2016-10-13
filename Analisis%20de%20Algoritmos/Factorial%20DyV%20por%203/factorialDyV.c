#include <stdio.h>
#include <math.h>

long double factorial(double,double);
long double factorial1(long double);
int main(){
    int f=0;
    printf("ingresa el valor del que deseas conocer el factorial: ");
    scanf("%d",&f);
    printf("Resultado final %e \n",factorial(1,(double)f));
    printf("Resultado real %e \n",factorial1((long double)f));
    return 0;
}

long double factorial(double ini,double fin){
    printf("Valores de llamada recursiva n %.2f %.2f\n",ini,fin);
    double t = ceil((fin-ini)/3);
    printf("Valor de t %.2f \n",t);
    double verificador = ((log(fin-(ini-1)))/log(3));
    printf("Valor de verificador %.2f \n",verificador);
    printf("Valores de llamada recursiva ini fin verificador %.2f %.2f %.2f \n",ini,fin,verificador);
    if(ceilf(verificador) == verificador){
        printf("Recursando segmento %.2f - %.2f \n",ini,fin);
        if(ini==fin){
                    printf("VALOR DE RETORNO FINAL: %.1f",ini);
                    return ini;
                    
        }
        if(t==1){
            printf("Entro a t==1 de verificador\n");
                return factorial(ini,ini)*factorial(ini+t,ini+t)*factorial(fin,fin);
        }
            return factorial(ini,ini+t-1)*factorial(ini+t,ini+2*t-1)*factorial(ini+2*t,fin);
    }else{
        printf("segmento no divisble de ini fin %.2f %.4f \n",ini,fin);
        if(ini==fin){
            printf("VALOR DE RETORNO FINAL DE SEGMENTO NO DIVISIBLE %.1f",ini);
            return ini;
        }
        if(fin-(ini-1)<3)
            return factorial(ini,ini)*factorial(fin,fin);
        if(t==1){
            return factorial(ini,ini)*factorial(ini+t,ini+t)*factorial(ini+2*t,fin);
        }
        return factorial(ini,ini+t-1)*factorial(ini+t,ini+2*t-1)*factorial(ini+2*t,fin);
    }
}
long double factorial1(long double n){
    return n<=1?1: n*factorial1(n-1);
}
