#ifndef ABB_H_INCLUDED
#define ABB_H_INCLUDED
#include "Vendedores.h"
#include <stdlib.h>

/* POLITICA DE REEMPLAZO : MENOR DE LOS MAYORES */

struct nodo{
    Vendedor vipd;
    struct nodo *izq;
    struct nodo *der;
};

typedef struct nodo nodoABB;

typedef struct{
    nodoABB *raiz;
    nodoABB *cursor;
    nodoABB *padre;
    int cantidad;
}ABB;

void initABB(ABB *arbol){
    arbol->raiz = NULL;
    arbol->cursor = NULL;
    arbol->padre = NULL;
    arbol->cantidad = 0;
}

///*                            LOCALIZAR                            *///
int localizarABB(ABB *arbol, int dni){
    arbol->cursor = arbol->raiz;
    while(arbol->cursor != NULL && arbol->cursor->vipd.dni != dni){
        if(arbol->cursor->vipd.dni < dni){
            arbol->padre = arbol->cursor;
            arbol->cursor = arbol->cursor->der;
        }
        else{
            arbol->padre = arbol->cursor;
            arbol->cursor = arbol->cursor->izq;
        }
    }
    if(arbol->cursor == NULL)
        return 0; // FRACASO
    else
        return 1; // EXITO
}

///*                            EVOCAR                            *///
Vendedor evocarABB(ABB a, int dni, int *exito){
    Vendedor v;
    initVendedor(&v);
    if(a.raiz != NULL){
        if(localizarABB(&a,dni) == 1){
            *exito = 1; // ESTA
            v = a.cursor->vipd;
            return v;
        }else{
            *exito = 0; // NO ESTA
            return v;
        }
    }else{
        *exito = -1; // ARBOL VACIO
        return v;
    }
}

///*                            ALTA                            *///
int altaABB(ABB *arbol , Vendedor v){
    nodoABB *aux = (nodoABB*)malloc(sizeof(nodoABB));
    if(aux != NULL){
        aux->vipd = v;
        if(arbol->raiz == NULL){
            arbol->raiz = aux;
            arbol->raiz->der = NULL;
            arbol->raiz->izq = NULL;
            arbol->padre = arbol->raiz;
            arbol->cursor = arbol->raiz;
        }else{
            if(localizarABB(arbol,v.dni) == 0){
                if(arbol->padre->vipd.dni < v.dni){
                    arbol->padre->der = aux;
                    arbol->cursor = arbol->padre->der;
                }
                else{
                    arbol->padre->izq = aux;
                    arbol->cursor = arbol->padre->izq;
                }
                arbol->cursor->der = NULL;
                arbol->cursor->izq = NULL;
                arbol->cantidad++;
            }else{
                free(aux);
                return 0; // NO INSERTO
            }
        }
        return 1; // INSERTO
    }else
        return -1; // LLENO
}

///*                            BAJA                            *///
int bajaABB(ABB *a, int dni){
    if(a->raiz != NULL){
        int opcion = 0;
        a->cursor = a->raiz;
        nodoABB *aux;
        if(localizarABB(a,dni) == 1){
            printf("Se ha localizado el Vendedor, estos son sus datos:\n");
            imprimeVendedor(a->cursor->vipd,0);
            printf("###########################################################\n");
            printf("Esta seguro que quiere eliminar a este Vendedor <1> Si   <0> No : ");
            scanf("%d",&opcion);
            if(opcion == 1){
                if(a->cursor->izq == NULL && a->cursor->der == NULL){ // SIN HIJOS
                    if(a->cursor == a->raiz){
                        free((void*)a->cursor);
                        a->raiz = NULL;
                        a->cursor = NULL;
                        a->padre = NULL;
                        a->cantidad--;
                        return 1;
                    }else{
                        if(a->cursor->vipd.dni < a->padre->vipd.dni){
                            a->padre->izq = NULL;
                            free((void*)a->cursor);
                            a->cursor = NULL;
                            a->cantidad--;
                            return 1;
                        }else{
                            a->padre->der = NULL;
                            free((void*)a->cursor);
                            a->cursor = NULL;
                            a->cantidad--;
                            return 1;
                        }
                    }
                }
                if(a->cursor->der == NULL && a->cursor->izq != NULL){ // HIJO A LA IZQUIERDO
                    if(a->cursor == a->raiz){
                        free((void*)a->cursor);
                        a->raiz = a->raiz->izq;
                        a->padre = a->raiz;
                        a->cursor = a->raiz;
                        a->cantidad--;
                        return 1;
                    }else{
                        if(a->cursor->vipd.dni < a->padre->vipd.dni){
                            free((void*)a->cursor);
                            a->padre->izq = a->cursor->izq;
                            a->cantidad--;
                            return 1;
                        }else{
                            free((void*)a->cursor);
                            a->padre->der = a->cursor->izq;
                            a->cantidad--;
                            return 1;
                        }
                    }
                }
                if(a->cursor->izq == NULL && a->cursor->der != NULL){ // HIJO A LA DERECHA
                    if(a->cursor == a->raiz){
                        a->padre = a->cursor->izq;
                        free((void*)a->cursor);
                        a->cursor = a->padre;
                        a->raiz = a->cursor;
                        a->cantidad--;
                        return 1;
                    }else{
                        if(a->cursor->vipd.dni < a->padre->vipd.dni){
                            a->padre->izq = a->cursor->der;
                            free((void*)a->cursor);
                            a->cantidad--;
                            return 1;
                        }else{
                            a->padre->der = a->cursor->der;
                            free((void*)a->cursor);
                            a->cantidad--;
                            return 1;
                        }
                    }
                }
                if(a->cursor->izq != NULL && a->cursor->der != NULL){ //Hijo I/D
                    aux = a->cursor;
                    a->padre = a->cursor;
                    a->cursor = a->cursor->der;
                    while(a->cursor->izq != NULL){
                        a->padre = a->cursor;
                        a->cursor = a->cursor->izq;
                    }
                    if(a->padre->der->vipd.dni == a->cursor->vipd.dni){ //Sin Hijo Izquierdo
                        a->padre->der = a->cursor->der;
                        a->padre->vipd = a->cursor->vipd;
                        free((void*)(*a).cursor);
                    }else{                                              // Con Hijo Derecho
                        a->padre->izq = a->cursor->der;
                        aux->vipd = a->cursor->vipd;
                        free((void*)(*a).cursor);
                    }
                    a->cantidad--;
                }
                return 1; // SE DIO DE BAJA
            }
            return 0; // NO SE DIO DE BAJA
        }
    }
    return -1; // EL ARBOL ESTA VACIO
}

///*                            IMPRIME NODO                            *///
void imprimeNodo(nodoABB *arbol){
    if(arbol != NULL){
        imprimeVendedor(arbol->vipd,0);
        if(arbol->izq != NULL)
            printf("El hijo izquierdo es: %d\n", arbol->izq->vipd.dni);
        else
            printf("El hijo izquierdo es: Nodo Vacio\n");
        if(arbol->der != NULL)
            printf("El hijo derecho es: %d\n", arbol->der->vipd.dni);
        else
            printf("El hijo derecho es: Nodo Vacio\n");
    }
}

///*                            MUESTRA                            *///
void preOrden(nodoABB *hoja, int *i){
    if((*i)%3 == 0){
            system("pause");
            system("cls");
    }
    if(hoja != NULL){
        (*i)++;
        imprimeNodo(hoja);
        preOrden(hoja->izq,i);
        preOrden(hoja->der,i);
    }
    else
        (*i)++;
}

void mostrarEstructuraABB(ABB a){
    if(a.raiz == NULL){
        printf("###########################################################\n");
        printf("#        *ERROR* EL ARBOL SE ENCUENTRA VACIO              #\n");
        printf("###########################################################\n");
        printf("AGUARDE... VOLVERA AL MENU PRINCIPAL");
        Sleep(2500);
        system("cls");
    }else{
        int i = 0;
        preOrden(a.raiz,&i);
    }
}

#endif // ABB_H_INCLUDED
