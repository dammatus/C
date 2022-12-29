#ifndef RS_H_INCLUDED
#define RS_H_INCLUDED
#include "Vendedores.h"
// Factor de RS -> 110/1.84 = 59,78
#define M 60

typedef struct {
    Vendedor vipd;
    struct nodO *sig;
}nodO;

typedef struct{
    nodO *inicio;
}baldE;

typedef struct{
	baldE rebalse[M];
	nodO *cursor;
    nodO *anterior;
	int indice;
	int cant;
}RS;

///*                 FUNCION HASH                 *///
int hashingRS(int dni){
    char c[8];
	int longitud, i, contador=0;
	sprintf(c,"%d",dni);
	longitud = strlen(c);
	for (i = 0; i < longitud; i++){
		contador += ((int)c[i] * (i+1));
	}
	return (contador % M);
}

void initBalde(baldE *balde){
    balde->inicio = NULL;
}

void initRS(RS *rs){
	int i;
	for(i = 0;i < M;i++){
        initBalde(&(rs->rebalse[i]));
	}
	rs->cant = 0;
}

///*                      LOCALIZAR                      *///
int localizarRS(RS *rs, int dni){
	int i = hashingRS(dni);
	nodO *p = rs->rebalse[i].inicio;
	rs->indice = i;
	rs->cursor = p;
	while(p != NULL && p->vipd.dni != dni ){
		rs->anterior = rs->cursor;
		rs->cursor = rs->cursor->sig;
		p = rs->cursor;
	}
    if(p != NULL)
        return 1;  // EXITO
    else
        return 0;  // FRACASO
}

///*                      EVOCACION                      *///
Vendedor evocarRS(RS rs, int dni, int *exito, int *cursor){
	Vendedor v;
	initVendedor(&v);
	if(rs.cant != 0){
        if(localizarRS(&rs,dni)){
            *exito = 1; //ESTA
            v = rs.cursor->vipd;
            *cursor = rs.indice;
            return v;
        }
        else{
            *exito = 0; //NO ESTA
            return v;
        }
	}else{
        *exito = -1; //VACIO
        return v;
	}
}

///*                   ALTA                   *///
int altaRS(RS *rs, Vendedor v){
    nodO *aux = (nodO*)malloc(sizeof(nodO));
    if(aux != NULL){
        aux->vipd = v;
        aux->sig = NULL;
        if(0 == localizarRS(rs,v.dni)){
            if(rs->rebalse[rs->indice].inicio == NULL){
                rs->rebalse[rs->indice].inicio = aux;
                rs->cant++;
                return 1;   //INSERTA
            }else{
                rs->cursor = aux;
                rs->anterior->sig = rs->cursor;
                rs->cant++;
                return 1;   //INSERTA
            }
        }else{
            free(aux);
            return 0;   //NO INSERTA
        }
    }else
        return -1;  //LLENO
}

///*                      BAJA                      *///
int bajaRS(RS *rs, int dni){
    if(rs->cant != 0){
        int desicion;
        if(localizarRS(rs,dni)){
            system("cls");
            printf("Se ha localizado el Vendedor, estos son sus datos:\n");
            imprimeVendedor(rs->cursor->vipd,rs->indice);
            printf("###########################################################\n");
            printf("Esta seguro que quiere eliminar este Vendedor <1> SI <2> NO : ");
            scanf("%d",&desicion);
            while(desicion < 1 || desicion > 2){
                printf("###########################################################\n");
                printf("\nIngrese nuevamente <1>  SI  <2>   NO : ");
                fflush(stdin);
                scanf("%d",&desicion);
            }
            if(desicion == 1){
                if(rs->rebalse[rs->indice].inicio == rs->cursor){
                    rs->rebalse[rs->indice].inicio = rs->cursor->sig;
                    free(rs->cursor);
                }else{
                    rs->anterior->sig = rs->cursor->sig;
                    free(rs->cursor);
                    rs->cursor = rs->anterior;
                }
                rs->cant--;
                return 1; //SE DIO DE BAJA
            }
            else{
                return 0; //NO SE DIO DE BAJA
            }
        }else
            return 2; //NO ESTA
    }else
        return -1; //VACIO
}

///*               MOSTRAR LA ESTRUCTURA                   *///
void mostrarEstructuraRS(RS rs){
    int cont = 0;
    while(cont < M){
        if(cont %4 == 0){
            system("pause");
            system("cls");
        }
        if(rs.rebalse[cont].inicio == NULL){
            printf("###########################################################\n");
            printf("La celda %d esta libre \n",cont);
        }
        else{
            rs.cursor = rs.rebalse[cont].inicio;
            while(rs.cursor != NULL){
                imprimeVendedor(rs.cursor->vipd,cont);
                rs.cursor = rs.cursor->sig;
            }
        }
        cont++;
    }
}

#endif // RS_H_INCLUDED
