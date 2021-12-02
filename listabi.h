#ifndef LISTABI_H_INCLUDED
#define LISTABI_H_INCLUDED
#include <malloc.h>
#include "varado.h"

typedef struct {
    varado vipd;
    struct nodo *next;
    struct nodo *back;
}nodo;

typedef struct{
    nodo *acceso;
    nodo *cursor;
}lista_varado;

void init_lista(lista_varado *v){
    (*v).acceso=NULL;
    (*v).cursor=NULL;
}
void reset(lista_varado *v){
    (*v).cursor=(*v).acceso;
}
int isEmpty(lista_varado v){
    if(v.acceso==NULL)
        return 1;
    else
        return 0;
}
 int isFull(lista_varado v){
    nodo *n;
    n=(nodo*)malloc(sizeof(nodo));
    if(n==NULL){
        free(n);
        return 1;
    }
    else{
        free(n);
        return 0;
    }
 }
 void forwards(lista_varado *v){
    (*v).cursor=(*v).cursor->next;
 }
 void backwards(lista_varado *v){
    (*v).cursor=(*v).cursor->back;
 }
 varado copi(lista_varado v){
    return v.cursor->vipd;
 }
 int isOos(lista_varado v){
    if(v.cursor==NULL)
        return 1;
    else
        return 0;
 }
 void supress(lista_varado *v){
    nodo *n1=(nodo*)malloc(sizeof(nodo));
    nodo *n2=(nodo*)malloc(sizeof(nodo));
    if((*v).cursor==(*v).acceso){
        (*v).acceso=(*v).cursor->next;
        n1=(*v).cursor;
        (*v).cursor=(*v).acceso;
        if((*v).cursor!=NULL){
            (*v).cursor->back = (*v).acceso;
        }
        free(n1);
    }
    else{
        n1=(*v).cursor->back;
        n2=(*v).cursor->next;
        n1->next = n2;
        if(n2!=NULL)
            n2->back=n1;
        n1=(*v).cursor;
        (*v).cursor=n2;
        free(n1);
    }
 }

 void insert(lista_varado *l,varado v){
    nodo *n=(nodo*)malloc(sizeof(nodo));
    nodo *n1=(nodo*)malloc(sizeof(nodo));
    (*n).vipd=v;
    if ((*l).acceso==NULL){
        (*l).acceso=n;
        (*n).next=NULL;
        (*l).cursor= n;
        (*l).cursor->back=NULL;
    }
    else{
        n->next=(*l).cursor->next;
        (*l).cursor->next=n;
        n->back=(*l).cursor;
        (*l).cursor=n;
        if((*l).cursor->next!=NULL){
                n1=(*l).cursor->next;
                n1->back= n->back ;
        }

    }
}

#endif // LISTABI_H_INCLUDED
