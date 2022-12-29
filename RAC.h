#ifndef RAC_H_INCLUDED
#define RAC_H_INCLUDED
#include "Vendedores.h"
// Factor de RAC -> 110/0,77 = 142,..  -->149 (num primo mas cercano)
#define MRac 149

typedef struct{
    Vendedor vipd;
    int estado;  //0- Ocupado  1- Virgen  2-Libre
}balde;

typedef struct{
	balde rebalse[MRac];
	int cursor;
	int cant;
}RAC;

int hashingRAC(int dni){
    char c[8];
	int longitud, i, contador=0;
	sprintf(c,"%d",dni);
	longitud = strlen(c);
	for (i = 0; i < longitud; i++){
		contador += ((int)c[i] * (i+1));
	}
	return (contador % MRac);
}

void initRAC(RAC *rac){
	int i;
	for(i = 0; i < MRac; i++){
		rac->rebalse[i].estado = 1;
	}
	rac->cant = 0;
}

///*                      LOCALIZAR                      *///
int localizarRAC(RAC* rac, int dni){
	int i = hashingRAC(dni);
	int k = 1,j = -1, cont = 0;
	while(cont < MRac && rac->rebalse[i].estado != 1 && rac->rebalse[i].vipd.dni != dni){
        if(rac->rebalse[i].estado == 2 && j == -1)
            j = i;
		i = (i + k) % MRac;
		k++;
		cont++;
	}
	if(cont == MRac){
        if(j != -1){
            rac->cursor = j;
            return 0; //FRACASO CON CELDAS LIBRES
        }
        return 2;   //FRACASO RECORRIENDO TODOS LOS BALDES
	}

    if(j != -1 && rac->rebalse[i].estado == 1){
        rac->cursor = j;
        return 0;   //FRACASO
    }
    rac->cursor = i;
    if(rac->rebalse[i].estado == 0)
        return 1;   //EXITO
    else
        return 0;   //FRACASO
}

///*                      EVOCACION                      *///
Vendedor evocarRAC (RAC rac, int dni, int *exito, int *cursor){
	Vendedor v;
	initVendedor(&v);
	if(rac.cant != 0){
        if(localizarRAC(&rac,dni) == 1){
            *exito = 1;     //ESTA
            v = rac.rebalse[rac.cursor].vipd;
            *cursor = rac.cursor;
            return v;
        }
        else{
            *exito = 0; //NO ESTA
            return v;
        }
	}
	else{
	    *exito = -1;    //VACIO
        return v;
	}
}

///*                   ALTA                   *///
int altaRAC(RAC *rac, Vendedor v){
    if(rac->cant < MRac){
        if(localizarRAC(rac,v.dni) == 0){
            rac->rebalse[rac->cursor].vipd = v;
            rac->rebalse[rac->cursor].estado = 0;
            rac->cant++;
            return 1;   //ALTA
        }else
            return 0;   //NO INSERTO
    }else
        return -1;  //LLENO
}

///*                      BAJA                      *///
int bajaRAC(RAC *rac, int dni){
    if(rac->cant != 0){
        int desicion;
        Vendedor v;
        initVendedor(&v);
        if(localizarRAC(rac,dni) == 1){
            system("cls");
            printf("Se ha localizado el Vendedor, estos son sus datos:\n");
            imprimeVendedor(rac->rebalse[rac->cursor].vipd,rac->cursor);
            printf("###########################################################\n");
            printf("Esta seguro que quiere eliminar este Vendedor <1> SI <2> NO : ");
            scanf("%d",&desicion);
            while(desicion < 1 || desicion > 2){
                printf("Ingrese nuevamente <1>   SI <2>   NO : ");
                fflush(stdin);
                scanf("%d",&desicion);
            }
            if(desicion == 1){
                rac->rebalse[rac->cursor].vipd = v;
                rac->cant--;
                rac->rebalse[rac->cursor].estado = 2;
                return 1; //SE DIO DE BAJA
            }
            else
                return 0; //NO SE DIO DE BAJA
        }
        else
            return 2; //NO ESTA
    }
    else
        return -1; //VACIO
}

///*               MOSTRAR LA ESTRUCTURA                   *///
void mostrarEstructuraRAC(RAC rac){
    if(rac.cant == 0){
        printf("###########################################################\n");
        printf("#        *ERROR* EL REBALSE SE ENCUENTRA VACIO            #\n");
        printf("###########################################################\n");
        printf("Regresara al menu ...\n");
    }else{
        int cont = 0;
        while(cont < MRac){
            if(cont%4==0){
                system("pause");
                system("cls");
            }
            if(rac.rebalse[cont].estado == 0){
                imprimeVendedor(rac.rebalse[cont].vipd,cont);
                printf("###########################################################\n");
            }else if(rac.rebalse[cont].estado == 1){
                printf("###########################################################\n");
                printf("La celda %d esta virgen \n",cont);
            }else{
                printf("###########################################################\n");
                printf("La celda %d esta libre \n",cont);
            }
            cont++;
        }
    }
}

#endif // RAC_H_INCLUDED
