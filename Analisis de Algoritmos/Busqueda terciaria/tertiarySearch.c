#include <stdio.h>
#define TAM_ARR 300
int tertiarySearch(int [],int,int,int);

int main(){
    int dataSet3[TAM_ARR];
    int factor;
    for (int i = 0; i < TAM_ARR; i++)
    {
        dataSet3[i]=i;
    }
    printf("Valores de arreglo:");
    for (int i = 0; i < TAM_ARR; i++)
    {
        printf("%d ",dataSet3[i]);
    }
    printf("\n");
    int elementToLookFor, start, end;
    printf( "Ingresa el valor a buscar:"); scanf("%d",&elementToLookFor);
    printf(" Ingresa el inicio del rango de busqueda:"); scanf("%d",&start);
    printf("Ingresa el fin del rango de busqueda: "); scanf("%d",&end);
    printf("Resultado (encontrado en posicion): %d \n",tertiarySearch(dataSet3,start,end,elementToLookFor));
}

int tertiarySearch(int data[],int start,int end, int element){
    int third = (end-start+1)/3;
    if(start<=end){
        if(data[start+third] == element)
            return start+third;
        if(data[start+third]>element)
            return tertiarySearch(data,start,start+third-1,element); 
        if(data[end-third]==element)
            return end-third;
        if(data[end-third]>element)
            return tertiarySearch(data,start+third+1,end-third-1,element);
        return tertiarySearch(data,end-third+1,end,element);
    }
    return -1;
}