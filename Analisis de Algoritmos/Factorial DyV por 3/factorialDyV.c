#include <stdio.h>
#include <math.h>

long double factorial(double,double);
long double factorial1(long double);
int main(){
    int f=0;
    printf("ingresa el valor del que deseas conocer el factorial: ");
    scanf("%d",&f);
    printf("Resultado final %Le \n",factorial(1,(double)f));
    printf("Resultado real %Le \n",factorial1((long double)f));
    return 0;
}

long double factorial(double ini,double fin){
    double t = ceil((fin-ini)/3);
    double verificador = ((log(fin-(ini-1)))/log(3));
    if(ceilf(verificador) == verificador){
        if(ini==fin){
                    printf("VALOR DE RETORNO FINAL: %.1f\n",ini);
                    return ini;               
        }
        if(t==1){
                return factorial(ini,ini)*factorial(ini+t,ini+t)*factorial(fin,fin);
        }
            return factorial(ini,ini+t-1)*factorial(ini+t,ini+2*t-1)*factorial(ini+2*t,fin);
    }else{
        if(ini==fin){
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
