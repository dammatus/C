#ifndef LSO_H_INCLUDED
#define LSO_H_INCLUDED
#include "Vendedores.h"

/*
Lista Secuencial Desordenada:
    -Con Ordenacion por Heapsort
    -Prioridad dada por campo 'cantVentas' de vendedores
    -Orden Decreciente
*/

typedef struct{
    Vendedor vipd[size];
    int ultimo;
}LSD;

void initLSD(LSD *lista){
    lista->ultimo = 0;
}

///*                   LOCALIZAR                   *///
int localizarLSD(LSD lsd, int dni){
    int i = 0;
    while (dni != lsd.vipd[i].dni && i < lsd.ultimo)
        i++;
    if(lsd.vipd[i].dni == dni)
        return 1; //EXITO
    else
        return 0; //FRACASO
}

///*                   ALTA                   *///
int altaLSD(LSD *lista, Vendedor v){
    int pos;
    if(lista->ultimo < size){
        if(0 == localizarLSD(*lista,v.dni)){
            lista->vipd[lista->ultimo] = v;
            lista->ultimo = lista->ultimo + 1;
            return 1;  //EXITOSO
        }else
            return 0;  //NO EXITOSO
    }else
        return -1;  //LISTA LLENA
}

///*               MOSTRAR LA ESTRUCTURA                   *///
void mostrarEstructuraLSD(LSD lista){
    if(lista.ultimo == 0){
        printf("###########################################################\n");
        printf("#        *ERROR* LA LISTA SE ENCUENTRA VACIA              #\n");
        printf("###########################################################\n");
        system("pause");
        system("cls");
    }else{
        for(int i = 0 ; i < lista.ultimo; i++){
            if(i%10 == 0){
                system("pause");
                system("cls");
            }
            imprimeVendedor(lista.vipd[i],i);
        }
    }
}
///*               SWAP ELEMENTO                   *///
void intercambio(Vendedor* x, Vendedor* y){
	Vendedor temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

///*               HEAPIFY                  *///
void hundir(LSD *parva, int N, int i){
    int j;
    while(2*i + 1 < N){
        j = 2*i + 1;
        if(j < N - 1 && parva->vipd[j].cantVentas > parva->vipd[j+1].cantVentas)
            j++;
        if(!(parva->vipd[i].cantVentas > parva->vipd[j].cantVentas))
            break;
        intercambio(&parva->vipd[i],&parva->vipd[j]);
        i = j;
    }
}

///*               HEAPSORT                   *///
void heapSort(LSD *parva, int N){
    //Creando parva (monticulo)
    for(int i = N / 2 - 1; i >= 0; i--)
        hundir(parva, N, i);
    //Heapsort
    for (int i = N - 1; i > 0; i--) {
        intercambio(&parva->vipd[0], &parva->vipd[i]);
        hundir(parva, i, 0);
    }
    printf("###########################################################\n");
    printf("#           SE ORDENO LA LISTA CORRECTAMENTE              #\n");
    printf("###########################################################\n");
    system("pause");
    system("cls");
}

#endif // LSO_H_INCLUDED

