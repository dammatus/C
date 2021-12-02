#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "Varado.h"
#include "listabi.h"

void busqueda_dni(lista_varado *v,int dni);
void busqueda_provincia(lista_varado *v,int prov);
varado carga_varados(lista_varado *v,int numero);
void cargar_lista(lista_varado *v,int cant);
void precarga_lista(lista_varado *v);
varado cargar_desde_archivo(FILE *fp);
void eliminar_varado(lista_varado *v,int pais);
void cargar_archivo_copia(lista_varado v);
void mostrar_varado(lista_varado v);
void modifica_pais_provincia(lista_varado *v,int dni);
void modifica_riesgo(lista_varado *v,int dni);
void mostrar_por_pais(lista_varado v,int pais,int cont,int aux);/*Funcion Recursiva*/
void pais_varado(lista_varado v);
char* nombre_pais(int pais);
char* nombre_provincia(int pais);
void provincia_residencia(lista_varado v);
void imprime_archivo(lista_varado v,FILE *fp);
int mod_prov(lista_varado *v);
int mod_pais(lista_varado *v);
void mostrarEstructura(lista_varado *v);


int main()
{
    lista_varado varados;
    int Menu, MenuCar, MenuBusc, MenuModif, aux;
    int longaux;

    system("Color 3F");
    SetConsoleTitle("VARADOS ARGENTINOS EN EL EXTRANJERO");

    init_lista(&varados);
    printf("===============================================================================\n");
    printf("|                                                                             |\n");
    printf("|   BIENVENIDOS AL SISTEMA DE CONTROL DE VARADOS ARGENTINOS EN EL EXTERIOR    |\n");
    printf("|                                                                             |\n");
    printf("===============================================================================\n");
    system("pause");
    do{
            system("cls");
            printf("===============================================================================\n");
            printf("|                              MENU DE OPCIONES                               |\n");
            printf("===============================================================================\n");
            printf("|   <1> CARGAR VARADOS                      <2> BUSCAR VARADOS                |\n");
            printf("|   <3> MODIFICAR/ELIMINAR VARADO           <4> COPIA DE PERSONAS EN RIESGO   |\n");
            printf("|   <5> VARADOS ARGENTINOS POR PAIS         <6> MOSTRAR TODOS LOS VARADOS     |\n");
            printf("|   <7> SALIR DEL SISTEMA                                                     |\n");
            printf("===============================================================================\n");
            printf (" Elija que accion desea realizar: ");
            fflush(stdin);
            while (!scanf("%d", &Menu)){
                printf("Ha ingresado un caracter erroneo. Intente nuevamente ");
                fflush(stdin);
            }
            switch(Menu){
                case 1:
                    {
                    system("cls");
                    printf("===============================================================================\n");
                    printf("|                       SELECCIONO CARGAR VARADOS                             |\n");
                    printf("===============================================================================\n");
                    printf("===============================================================================\n");
                    printf("|   <1> CARGAR CANTIDAD DETERMINADA DE VARADOS                                |\n");
                    printf("|   <2> CARGAR VARADOS DESDE ARCHIVO DETERMINADO                              |\n");
                    printf("|   <3> VOLVER                                                                |\n");
                    printf("===============================================================================\n");
                    printf (" Elija que accion desea realizar: ");
                    fflush(stdin);
                    while (!scanf("%d", &MenuCar)){
                            printf("Ha ingresado un caracter erroneo. Intente nuevamente:");
                            fflush(stdin);
                    }
                    switch(MenuCar){
                        case 1:
                            {
                            system("cls");
                            printf("===============================================================================\n");
                            printf("|                    CARGAR CANTIDAD DETERMINADA DE VARADOS                   |\n");
                            printf("===============================================================================\n");
                            printf ("Ingrese la cantidad de varados que desea cargar por teclado: ");
                            fflush(stdin);
                            scanf("%d", &aux);
                            while(aux<0){
                                printf ("\n\t*****ERROR - CANTIDAD INCORRECTA*****\nIngrese la cantidad de varados que desea cargar por teclado: ");
                                fflush(stdin);
                                scanf("%d", &aux);
                            }
                            cargar_lista(&varados,aux);
                            ;break;
                            }
                        case 2:
                            {
                            printf("===============================================================================\n");
                            printf("|                  CARGAR VARADOS DESDE ARCHIVO DETERMINADO                   |\n");
                            printf("===============================================================================\n");
                            precarga_lista(&varados);
                            ;break;
                            }
                        case 3: system("cls");
                                ;break;
                        default:
                            {
                                printf("\nIngrese una opcion correcta");
                                system("cls");
                                ;break;
                            }
                        }
                        ;break;
                    }
                case 2:
                    {
                    system("cls");
                    printf("===============================================================================\n");
                    printf("|                       SELECCIONO BUSCAR VARADOS                             |\n");
                    printf("===============================================================================\n");
                    if(isEmpty(varados)){
                        printf ("La lista de Varados esta vacia.\n\n");
                        system("pause");
                        system("cls");
                        ;break;
                    }
                    printf("===============================================================================\n");
                    printf("|   <1> BUSCAR VARADO MEDIANTE SU DNI                                         |\n");
                    printf("|   <2> BUSCAR VARADO POR PROVINCIA DE INGRESO                                |\n");
                    printf("|   <3> VOLVER                                                                |\n");
                    printf("===============================================================================\n");
                    printf (" Elija que accion desea realizar: ");
                    fflush(stdin);
                    while (!scanf("%d", &MenuCar)){
                        printf("Ha ingresado un caracter erroneo. Intente nuevamente:");
                        fflush(stdin);
                    }
                    switch(MenuCar){
                        case 1:
                            {
                            system("cls");
                            printf("===============================================================================\n");
                            printf("|                    SELECCIONO BUSCAR VARADO POR DNI                         |\n");
                            printf("===============================================================================\n");
                            printf("Ingrese el DNI del varado que desea buscar:");
                            scanf("%d", &longaux);
                            while(longaux<0){
                                printf("*****   ERROR   ****\nIngrese el DNI del varado que desea buscar:");
                                scanf("%d", &longaux);
                            }
                            busqueda_dni(&varados,longaux);
                            ;break;

                        }
                        case 2:
                        {
                            system("cls");
                            printf("============================================================================================\n");
                            printf("|                           SELECCIONO BUSCAR VARADO POR PROVINCIA                         |\n");
                            printf("============================================================================================\n");
                            printf("|                 SELECCIONE LA PROVINCIA QUE DESEE BUSCAR SUS VARADOS                     |\n");
                            printf("============================================================================================\n");
                            printf("|   <1> CORDOBA      <2> SANTA CRUZ <3> CHUBUT      <4> RIO NEGRO    <5> NEUQUEN           |\n");
                            printf("|   <6> LA PAMPA     <7> BS. AIRES  <8> MENDOZA     <9> SAN LUIS     <10> TIERRA DEL FUEGO |\n");
                            printf("|   <11> SANTA FE    <12> ENTRE RIOS<13> SAN JUAN   <14> LA RIOJA    <15> STGO. DEL ESTERO |\n");
                            printf("|   <16> CORRIENTES  <17> MISIONES  <18> CASTAMARCA <19> TUCUMAN     <20> CHACO            |\n");
                            printf("|   <21> FORMOSA     <22> SALTA     <23> JUJUY                                             |\n");
                            printf("============================================================================================\n");
                            scanf("%d", &aux);
                            while(aux<0 || aux>25){
                                printf("\nSELECCIONE UNA PROVINCIA CORRECTA: ");
                                scanf("%d", &aux);
                            }
                            busqueda_provincia(&varados,aux);
                            ;break;
                        }
                        case 3:
                        {
                            system("cls");
                            ;break;
                        }
                        default:
                            {
                               printf("\nIngrese una opcion correcta: ");
                                system("cls");
                                ;break;
                            }
                    };break;

                }
                case 3:
                    {
                    system("cls");
                    printf("===========================================================================================\n");
                    printf("|                         SELECCIONO ELIMINAR O MODIFICAR VARADOS                         |\n");
                    printf("===========================================================================================\n");
                    if(isEmpty(varados)){
                        printf ("La lista de Varados esta vacia.\n\n");
                        system("pause");
                        system("cls");
                        ;break;
                    }
                    printf("|   <1> ELIMINAR VARADO                             <2> MODIFICAR VARADO POR PAIS/PROV    |\n");
                    printf("|   <3> MODIFICAR EXISTENCIA DE PERSONA EN RIESGO                                         |\n");
                    printf("|   <4> SALIR                                                                             |\n");
                    printf("===========================================================================================\n");
                    printf (" Elija que accion desea realizar: ");
                    fflush(stdin);
                    while (!scanf("%d", &MenuModif)){
                        printf("Ha ingresado un caracter erroneo. Intente nuevamente ");
                        fflush(stdin);
                    }
                    switch(MenuModif){
                        case 1:
                            {
                                system("cls");
                                printf("===========================================================================================\n");
                                printf("|                                  SELECCIONO ELIMINAR VARADOS                            |\n");
                                printf("===========================================================================================\n");
                                printf("|   <1> CHILE        <2> URUGUAY    <3> BRASIL      <4> PARAGUAY     <5> PERU            |\n");
                                printf("|   <6> BOLIVIA      <7> ECUADOR    <8> COLOMBIA    <9> VENEZUELA    <10> REP. DOMINICANA|\n");
                                printf("|   <11> PUERTO RICO <12> MEXICO    <13> PANAMA     <14> EEUU        <15> CANADA         |\n");
                                printf("|   <16> ESPAÑA      <17> PORTUGAL  <18> FRANCIA    <19> PAISES BAJOS<20> ALEMANIA       |\n");
                                printf("|   <21> INGLATERRA  <22> TURQUIA   <23> JAPON      <24> AUSTRALIA   <25> MARRUECOS      |\n");
                                printf("==========================================================================================\n");
                                printf("SELECCIONE EL PAIS DEL QUE DESEE ELIMINAR SUS VARADOS: ");
                                scanf("%d", &aux);
                                while(aux<0 || aux>25){
                                    printf("\nSELECCIONE UN PAIS CORRECTO: ");
                                    scanf("%d", &aux);
                                }
                                    eliminar_varado(&varados,aux);
                                ;break;
                            }

                        case 2:
                            {
                            system("cls");
                            printf("===========================================================================================\n");
                            printf("|                                  SELECCIONO MODIFICAR  VARADOS                          |\n");
                            printf("===========================================================================================\n");
                            printf("Ingrese el DNI del varado que desea modificar: ");
                            scanf("%d", &longaux);
                            while(longaux<0){
                                printf("*****   ERROR   ****\nIngrese el DNI del varado que desea modificar: ");
                                scanf("%d", &longaux);
                            }
                            modifica_pais_provincia(&varados,longaux);
                            ;break;

                            }
                        case 3:
                            {
                                system("cls");
                                printf("===========================================================================================\n");
                                printf("|                                  SELECCIONO MODIFICAR RIESGO                            |\n");
                                printf("===========================================================================================\n");
                                printf("Ingrese el DNI del varado que desea modificar: ");
                                scanf("%d", &longaux);
                                while(longaux<0){
                                    printf("*****   ERROR   ****\nIngrese el DNI del varado que desea modificar: ");
                                    scanf("%d", &longaux);
                                }
                                modifica_riesgo(&varados,longaux);
                                ;break;
                            }
                        case 4:
                            {
                               system("cls");
                               ;break;
                            }
                        default:
                            {
                               printf("\nIngrese una opcion correcta");
                                system("cls");
                                ;break;
                            }
                    };break;

                    }
                case 4:
                    {
                        system("cls");
                        printf("==========================================================================================\n");
                        printf("|                            SELECCIONO COPIAR VARADOS EN RIESGO                         |\n");
                        printf("==========================================================================================\n");
                        if(isEmpty(varados)){
                            printf ("La lista de Varados esta vacia.\n\n");
                            system("pause");
                            system("cls");
                            ;break;
                        }
                        cargar_archivo_copia(varados);
                        ;break;

                    }
                case 5:
                    {
                    system("cls");
                    printf("==========================================================================================\n");
                    printf("|                         SELECCIONO NUMERO DE VARADOS POR PAIS                          |\n");
                    printf("===========================================================================================\n");
                    if(isEmpty(varados)){
                        printf ("La lista de Varados esta vacia.\n\n");
                        system("pause");
                        system("cls");
                        ;break;
                    }
                    printf("|                      SELECCIONE EL PAIS QUE DESEE BUSCAR SUS VARADOS                   |\n");
                    printf("===========================================================================================\n");
                    printf("|   <1> CHILE        <2> URUGUAY    <3> BRASIL      <4> PARAGUAY     <5> PERU            |\n");
                    printf("|   <6> BOLIVIA      <7> ECUADOR    <8> COLOMBIA    <9> VENEZUELA    <10> REP. DOMINICANA|\n");
                    printf("|   <11> PUERTO RICO <12> MEXICO    <13> PANAMA     <14> EEUU        <15> CANADA         |\n");
                    printf("|   <16> ESPAÑA      <17> PORTUGAL  <18> FRANCIA    <19> PAISES BAJOS<20> ALEMANIA       |\n");
                    printf("|   <21> INGLATERRA  <22> TURQUIA   <23> JAPON      <24> AUSTRALIA   <25> MARRUECOS      |\n");
                    printf("==========================================================================================\n");
                    scanf("%d", &aux);
                    while(aux<0 || aux>25){
                        printf("\nSELECCIONE UN PAIS CORRECTO ");
                        scanf("%d",&aux);
                    }
                    reset(&varados);
                    mostrar_por_pais(varados,aux,0,0);
                    ;break;
                    }
                case 6: {
                        system("cls");
                        printf("==============================================================\n");
                        printf("|  Ha seleccionado la opcion mostrar la estructura completa  |\n");
                        printf("==============================================================\n");
                        mostrarEstructura(&varados);break;
                }
                case 7:
                    {
                        system("cls");
                        printf("\n\n=============== GRACIAS POR UTILIZAR EL PROGRAMA ==============\n");
                        printf("=================PROGRAMADO POR: MATUS DAMIAN==================");
                        Sleep(2500);
                        exit(1);
                    }
                default:
                    {
                        printf("\n\n============== NUMERO DE ACCION INCORRECTO, INTENTE NUEVAMENTE!! ==============\n");
                        printf ("==============       ESPERE AL REGRESAR AL MENU PRINCIPAL        ==============\n");
                        system("pause");
                        system("cls");
                        ;break;
                    }
            }


    }while(Menu!=7);
    system("pause");
    return 0;
}

/*  FUNCIONES DE BUSQUEDA   */
int localizar(lista_varado l, int dni){
    reset(&l);
    while(!isOos(l)){
        if(muestra_dni(copi(l))==dni){
            return 1;
        }
        else{
            forwards(&l);
        }
    }
    return 0;
}
void busqueda_dni(lista_varado *v,int dni)
{
    int enc=0;
    reset(v);
    if(localizar(*v,dni)){
        printf("Se ha encontrado el Varado con DNI %d\n", dni);
        enc=1;
    }
    else{
        printf("No se ha encontrado el DNI buscado.\n");
    }
    if(enc==1){
        while(!isOos(*v)){
            if(dni==muestra_dni(copi(*v))){
                mostrar_varado(*v);
            }
            forwards(v);
        }
    }
    system("pause");
    system("cls");
}
void busqueda_provincia(lista_varado *v,int prov)
{
    lista_varado aux;
    int x=0;
    init_lista(&aux);
    reset(v);
    while(!isOos(*v)){
        if(prov==muestra_provincia(copi(*v))){
            insert(&aux,copi(*v));
            x++;
        }
        forwards(v);
    }
    if(x==1){
        printf("\nSe ha encontrado una persona de la provincia seleccionada");
        reset(v);
        while(!isOos(*v)){
            if(prov==muestra_provincia(copi(*v))){
                mostrar_varado(*v);
                system("pause");
            }
            forwards(v);
        }
    }
    else if(x>0){
        printf("\nSe han encontrado %d personas de la provincia seleccionada", x);
        reset(&aux);
        while(!isOos(aux)){
            mostrar_varado(aux);
            system("pause");
            forwards(&aux);
        }
    }
    else{
        printf("\nNo se encontro ninguna persona residente en la provincia seleccionada");
        system("pause");
    }
    printf("Pulse una tecla para continuar \n");
    getchar();
    system("cls");
}
/*  FUNCIONES DE CARGA  */
varado carga_varados(lista_varado *v,int numero)
{
        system("cls");

        char string[TAM];
        int entero, aux;
        int dni;
        fecha f;
        varado VAR;
        printf("===============================================================================\n");
        printf("|                           CARGA DE VARADO NUMERO %d                         |\n", numero+1);
        printf("===============================================================================");
        init_varado(&VAR);
        printf("\nIngrese el Apellido del varado:");
        getchar();
        scanf("%[^\n]", string);
        cargar_apell(&VAR,string);
        printf("\nIngrese el Nombre del varado:");
        getchar();
        scanf("%[^\n]", string);
        cargar_nombre(&VAR,string);
        printf("\nIngrese el DNI del varado:");
        scanf("%d", &dni);
        while(dni<0){
            printf("\n\t*****ERROR - DNI INCORRECTO*****\nIngrese el DNI del varado:");
            scanf("%d",&dni);
        }
        cargar_dni(&VAR,dni);
        printf("\nIngrese fecha de salida del pais");
        printf("\nDia:", &entero);
        fflush(stdin);
        scanf("%d", &entero);
        while(entero<0 || entero>31){
            printf("\n\t*****ERROR - DIA INCORRECTO*****\nDia:");
            scanf("%d", &entero);
        }
        f.dia=entero;
        printf("\nMes:");
        while (!scanf("%d", &entero) || (entero<1 || entero>12)){
            printf("Ha ingresado un caracter o numero erroneo. Intente nuevamente: ");
            fflush(stdin);
        }
        f.mes=entero;
        printf("\nAnio:");
        scanf("%d", &entero);
        while(entero<2018 || entero>2020){
            printf("\n\t*****ERROR - ANIO INCORRECTO*****\nAnio:");
            scanf("%d", &entero);
        }
        f.anio=entero;
        cargar_fecha(&VAR,f);
        printf("==========================================================================================\n");
        printf("|                           SELECCIONE EL PAIS EN EL QUE ESTA VARADO                     |\n");
        printf("==========================================================================================\n");
        printf("|   <1> CHILE        <2> URUGUAY    <3> BRASIL      <4> PARAGUAY     <5> PERU            |\n");
        printf("|   <6> BOLIVIA      <7> ECUADOR    <8> COLOMBIA    <9> VENEZUELA    <10> REP. DOMINICANA|\n");
        printf("|   <11> PUERTO RICO <12> MEXICO    <13> PANAMA     <14> EEUU        <15> CANADA         |\n");
        printf("|   <16> ESPAÑA      <17> PORTUGAL  <18> FRANCIA    <19> PAISES BAJOS<20> ALEMANIA       |\n");
        printf("|   <21> INGLATERRA  <22> TURQUIA   <23> JAPON      <24> AUSTRALIA   <25> MARRUECOS      |\n");
        printf("==========================================================================================\n");
        scanf("%d", &entero);
        while(entero<0 || entero>25){
            printf("\nSELECCIONE UN PAIS CORRECTO");
            scanf("%d", &entero);
        }
        cargar_pais(&VAR,entero);
        printf("\nEl Varado se encuentra acompaniado?");
        printf("\n<0> No    <1> Si");
        printf("\nSeleccione una opcion:");
        scanf("%d", &entero);
        while(entero<0 || entero>1){
            printf("\nIngrese una opcion correcta:");
            scanf("%d", &entero);
        }
        if(entero==1){
            printf("\nSeleccione la cantidad de personas (incluyendose):");
            scanf("%d", &aux);
            while(aux<0){
                printf("\nIngrese una cantidad correcta:");
                scanf("%d", &aux);
            }
            cargar_grupof(&VAR,aux);
        }
        printf("\nExisten personas en riesgo?");
        printf("\n<0> No     <1> Si");
        printf("\nSeleccione una opcion:");
        scanf("%d", &entero);
        while(entero<0 || entero>1){
            printf("\nIngrese una opcion correcta:");
            scanf("%d", &entero);
        }
        cargar_riesgo(&VAR,entero);
        printf("============================================================================================\n");
        printf("|                     SELECCIONE LA PROVINCIA DONDE DESEA INGRESAR                         |\n");
        printf("============================================================================================\n");
        printf("|   <1> CORDOBA      <2> SANTA CRUZ <3> CHUBUT      <4> RIO NEGRO    <5> NEUQUEN           |\n");
        printf("|   <6> LA PAMPA     <7> BS. AIRES  <8> MENDOZA     <9> SAN LUIS     <10> TIERRA DEL FUEGO |\n");
        printf("|   <11> SANTA FE    <12> ENTRE RIOS<13> SAN JUAN   <14> LA RIOJA    <15> STGO. DEL ESTERO |\n");
        printf("|   <16> CORRIENTES  <17> MISIONES  <18> CASTAMARCA <19> TUCUMAN     <20> CHACO            |\n");
        printf("|   <21> FORMOSA     <22> SALTA     <23> JUJUY                                             |\n");
        printf("============================================================================================\n");
        scanf("%d", &entero);
        while(entero<0 || entero>25){
            printf("\nSELECCIONE UNA PROVINCIA CORRECTA");
            scanf("%d", &entero);
        }
        cargar_provincia(&VAR,entero);

    return VAR;

}

void cargar_lista(lista_varado *v,int cant)
{
    varado VAR;
    int i, numero=0;
    reset(v);
    for(i=0;i<cant;i++){
        VAR=carga_varados(v,numero);
        if(localizar(*v,muestra_dni(VAR))){
            system("cls");
            printf("\t*****\tEL DNI YA EXISTE EN EL SISTEMA\t*****\n");
            printf("EL VARADO DE DNI %d NO FUE CARGADO EN EL SISTEMA\n\n\n");
        }
        else{
            numero++;
            insert(v,VAR);
        }
    }
    system("pause");
    system("cls");
}

void precarga_lista(lista_varado *v)
{
    FILE *fp;
    char archivo[TAM], s[TAM], prueba[100];
    int y=0;
    varado VAR;
    system("cls");
    reset(v);
    printf("Ingrese el nombre del archivo desde del cual desea cargar los Varados:");
    fflush(stdin);
    scanf("%s",archivo);
    fp=fopen(archivo,"r");
    if(fp==NULL){
        printf("\n======================================================\n");
        printf ("ERROR... No se ha podido abrir el archivo.");
        printf("\n=====================================================\n");
    }
    else{
        fscanf(fp,"%[^\n]\n",prueba);
        if(feof(fp)){
            printf("\n=====================================================\n");
            printf("        El archivo esta vacio.\n");
            printf("\n=====================================================\n");
        }
        else{
            rewind(fp);
            while(!feof(fp)){
                VAR=cargar_desde_archivo(fp);
                if(localizar(*v,muestra_dni(VAR))){
                    system("cls");
                    printf("\t*****\tEL DNI YA EXISTE EN EL SISTEMA\t*****\n");
                    printf("EL VARADO DE DNI %d NO FUE CARGADO EN EL SISTEMA\n\n\n",muestra_dni(VAR));
                    system("pause");
                }
                else{
                    insert(v,VAR);
                    y++;
                }
            }
        }
    }
    if(y==0)
            printf("\nNo se pudo cargar ningun varado en el archivo\n");
    else{
        printf("\n=====================================================\n");
        printf ("Los varados se han cargado exitosamente...\n");
        printf ("Ha cargado %d varados desde su archivo %s \n",y,archivo);
        printf("=====================================================\n\n");
        fclose(fp);
    }
    printf("\nPresione una tecla para regresar al menu principal...");
    getch();
    system("cls");
}

void cargar_archivo_copia(lista_varado v)
{
    FILE *fp;
    int i, cont=0;
    fp=fopen("viajan.txt","w");
    if(fp==NULL){
        printf("\n======================================================\n");
        printf ("ERROR... No se ha podido abrir el archivo.");
        printf("\n=====================================================\n");
    }
    else{
        reset(&v);
        while(!isOos(v)){
            if(muestra_riesgo(copi(v))==1){
                imprime_archivo(v,fp);
                cont++;
            }
            forwards(&v);
        }
    }
    if(cont==0){
        printf("\n=======================================================\n");
        printf("NO SE ENCONTRO NINGUN VARADO EN RIESGO EN EL SISTEMA\n");
        printf("=======================================================\n\n");
    }
    else if(cont>0){
        printf("\n============================================================================\n");
        printf ("ALMACENAMIENTO COMPLETO SE ENCONTRARON %d VARADOS EN RIESGO EN EL SISTEMA.\n", cont);
        printf("============================================================================\n\n");
    }
    fclose(fp);

    printf("\nPresione una tecla para regresar al menu principal...");
    getch();
    system("cls");
}
/*  FUNCION MOSTRAR  */
void mostrar_varado(lista_varado v)
{
    fecha f;
    f=muestra_fecha(copi(v));

    printf("\n===============================================================================\n");
    printf("-Apellido y Nombre: %s, %s\n", muestra_apellido(copi(v)),muestra_nombre(copi(v)));
    printf("-DNI: %d\n", muestra_dni(copi(v)));
    printf("-Fecha de Salida: %d/%d/%d\n", f.dia,f.mes,f.anio);
    pais_varado(v);
    printf("-Grupo Familiar: %d Personas\n", muestra_cant_personas(copi(v)));
    if(muestra_riesgo(copi(v))==1)
        printf("-Hay Personas en Riesgo\n");
    else
        printf("-NO hay Personas en Riesgo\n");
    provincia_residencia(v);
    printf("===============================================================================\n");
}

void mostrar_por_pais(lista_varado v,int pais,int cont,int aux)/*Funcion Recursiva*/
{
    if(isOos(v)){
        printf("===============================================================================\n");
        printf("                                   %s\n", nombre_pais(pais));
        printf("                                 %d Varados\n", cont);
        printf("===============================================================================\n");
        system("pause");
    }
    else{
        if(muestra_pais(copi(v))==pais){
            aux=muestra_cant_personas(copi(v));
            cont=(cont+aux);
            forwards(&v);
            mostrar_por_pais(v,pais,cont,aux);
        }
        else{
            forwards(&v);
            mostrar_por_pais(v,pais,cont,aux);
        }
    }
}

void eliminar_varado(lista_varado *v,int pais)
{
    system("cls");
    int cont=0;
    printf("EL SISTEMA ELIMINARA A TODOS LOS VARADOS DE %s", nombre_pais(pais));
    reset(v);
    while(!isOos(*v)){
        if(muestra_pais(copi(*v))==pais){
            printf("\n=======================================================================");
            printf("\nApellido y Nombre: %s, %s", muestra_apellido(copi(*v)),muestra_nombre(copi(*v)));
            printf("\nDNI: %d",muestra_dni(copi(*v)));
            printf("\n=======================================================================");
            supress(v);
            cont++;
        }
        else{
            forwards(v);
        }
    }
    if(cont==0){
        printf("\n===============================================\n");
        printf("NO SE ENCONTRARON VARADOS EN %s\n", nombre_pais(pais));
        printf("===============================================\n\n");
    }
    else{
        printf("\n========================================\n");
        printf("SE HAN ELIMINADO %d VARADOS CORRECTAMENTE\n",cont);
        printf("========================================\n\n");
    }
    printf("\nPresione una tecla para regresar al menu principal...");
    getch();
    system("cls");
}

/*  FUNCIONES MODIFICAR   */
void modifica_pais_provincia(lista_varado *v,int dni)
{
    int provincia,pais;
    varado VAR;
    reset(v);
    int x=0, menu;
    while(!isOos(*v)){
        if(muestra_dni(copi(*v))==dni){
            x=1;
            VAR=copi(*v);
            printf("|                   Se encontro el Varado con DNI %d                    |\n", dni);
            printf("===============================================================================\n");
            printf("|   <1> MODIFICAR PAIS                                                        |\n");
            printf("|   <2> MODIFICAR PROVINCIA                                                   |\n");
            printf("===============================================================================\n");
            printf("Elija una opcion:");
            scanf("%d", &menu);
            while(menu<1 || menu>2){
                printf("\nIngrese una opcion correcta");
                scanf("%d", &menu);
            }
            if(menu==1){
                    pais=mod_pais(v);
                    modifica_pais(&VAR,pais);
                    supress(v);
                    insert(v,VAR);
                    printf("\nSe modifico el pais correctamente\n");
            }
            if(menu==2){
                    provincia=mod_prov(v);
                    modifica_provincia(&VAR,provincia);
                    supress(v);
                    insert(v,VAR);
                    printf("===============================================================================\n");
                    printf("\nSe modifico la provincia correctamente\n");
                    printf("===============================================================================\n");
            }
        }
        forwards(v);
    }
    if(x==0){
        printf("\n*****No se encontro el Varado con DNI %d*****\n\n", dni);
    }
    printf("\nPresione una tecla para regresar al menu principal...");
    getch();
    system("cls");
}

void modifica_riesgo(lista_varado *v,int dni)
{
    system("cls");
    int riesgo;
    varado VAR;
    reset(v);
    printf("===============================================================================\n");
    printf("|                    SELECCIONO MODIFICAR RIESGO DE VARADO                    |\n");
    printf("===============================================================================\n");
    while(!isOos(*v)){
        if(muestra_dni(copi(*v))==dni){
             printf("|                 Se encontro el Varado con DNI %d                  |\n", dni);
             printf("|      Si el Varado esta en \"Riesgo\" cambiara a \"Sin Riesgo\"    |\n", dni);
             if(1==muestra_riesgo(copi(*v))){
                VAR=copi(*v);
                cargar_riesgo(&VAR,0);
                supress(v);
                insert(v,VAR);
                printf("===============================================================================\n");
                printf("                  Se Modifico el Riesgo el Varado con DNI %d\n", dni);
                printf("===============================================================================\n");
                system("pause");
                system("cls");
             }
             else{
                VAR=copi(*v);
                cargar_riesgo(&VAR,1);
                supress(v);
                insert(v,VAR);
                printf("===============================================================================\n");
                printf("                  Se Modifico el Riesgo el Varado con DNI %d\n", dni);
                printf("===============================================================================\n");
                system("pause");
                system("cls");
             }
        }
        forwards(v);
    }
}

/*  FUNCIONES AUXILIARES   */
void pais_varado(lista_varado v)
{
    if(muestra_pais(copi(v))==1)
        printf("-Pais donde espera: Chile\n");
    if(muestra_pais(copi(v))==2)
        printf("-Pais donde espera: Uruguay\n");
    if(muestra_pais(copi(v))==3)
        printf("-Pais donde espera: Brasil\n");
    if(muestra_pais(copi(v))==4)
        printf("-Pais donde espera: Psaraguay\n");
    if(muestra_pais(copi(v))==5)
        printf("-Pais donde espera: Peru\n");
    if(muestra_pais(copi(v))==6)
        printf("-Pais donde espera: Bolivia\n");
    if(muestra_pais(copi(v))==7)
        printf("-Pais donde espera: Ecuador\n");
    if(muestra_pais(copi(v))==8)
        printf("-Pais donde espera: Colombia\n");
    if(muestra_pais(copi(v))==9)
        printf("-Pais donde espera: Venezuela\n");
    if(muestra_pais(copi(v))==10)
        printf("-Pais donde espera: Republica Dominicana\n");
    if(muestra_pais(copi(v))==11)
        printf("-Pais donde espera: Puerto Rico\n");
    if(muestra_pais(copi(v))==12)
        printf("-Pais donde espera: Mexico\n");
    if(muestra_pais(copi(v))==13)
        printf("-Pais donde espera: Panama\n");
    if(muestra_pais(copi(v))==14)
        printf("-Pais donde espera: Estados Unidos\n");
    if(muestra_pais(copi(v))==15)
        printf("-Pais donde espera: Canada\n");
    if(muestra_pais(copi(v))==16)
        printf("-Pais donde espera: España\n");
    if(muestra_pais(copi(v))==17)
        printf("-Pais donde espera: Portugal\n");
    if(muestra_pais(copi(v))==18)
        printf("-Pais donde espera: Francia\n");
    if(muestra_pais(copi(v))==19)
        printf("-Pais donde espera: Paises Bajos\n");
    if(muestra_pais(copi(v))==20)
        printf("-Pais donde espera: Alemania\n");
    if(muestra_pais(copi(v))==21)
        printf("-Pais donde espera: Inglaterra\n");
    if(muestra_pais(copi(v))==22)
        printf("-Pais donde espera: Turquia\n");
    if(muestra_pais(copi(v))==23)
        printf("-Pais donde espera: Japon\n");
    if(muestra_pais(copi(v))==24)
        printf("-Pais donde espera: Australia\n");
    if(muestra_pais(copi(v))==25)
        printf("-Pais donde espera: Marruecos\n");
}

char* nombre_pais(int pais)
{
    char *p;
    p=(char*)malloc(sizeof(char)*TAM);
    if(p!=NULL){
        if(pais==1)
            strcpy(p,"Chile");
        if(pais==2)
            strcpy(p,"Uruguay");
        if(pais==3)
            strcpy(p,"Brasil");
        if(pais==4)
            strcpy(p,"Paraguay");
        if(pais==5)
            strcpy(p,"Peru");
        if(pais==6)
            strcpy(p,"Bolivia");
        if(pais==7)
            strcpy(p,"Ecuador");
        if(pais==8)
            strcpy(p,"Colombia");
        if(pais==9)
            strcpy(p,"Venezuela");
        if(pais==10)
            strcpy(p,"Republica Dominicana");
        if(pais==11)
            strcpy(p,"Puerto Rico");
        if(pais==12)
            strcpy(p,"Mexico");
        if(pais==13)
            strcpy(p,"Panama");
        if(pais==14)
            strcpy(p,"Estados Unidos");
        if(pais==15)
            strcpy(p,"Canda");
        if(pais==16)
            strcpy(p,"España");
        if(pais==17)
            strcpy(p,"Portugal");
        if(pais==18)
            strcpy(p,"Francia");
        if(pais==19)
            strcpy(p,"Paises Bajos");
        if(pais==20)
            strcpy(p,"Alemania");
        if(pais==21)
            strcpy(p,"Inglaterra");
        if(pais==22)
            strcpy(p,"Turquia");
        if(pais==23)
            strcpy(p,"Japon");
        if(pais==24)
            strcpy(p,"Australia");
        if(pais==25)
            strcpy(p,"Marruecos");
    }
    return p;
}
char* nombre_provincia(int pais)
{
    char *p;
    p=(char*)malloc(sizeof(char)*TAM);
    if(p!=NULL){
        if(pais==1)
            strcpy(p,"Cordoba");
        if(pais==2)
            strcpy(p,"Santa Cruz");
        if(pais==3)
            strcpy(p,"Chubut");
        if(pais==4)
            strcpy(p,"Rio Negro");
        if(pais==5)
            strcpy(p,"Neuquen");
        if(pais==6)
            strcpy(p,"La Pampa");
        if(pais==7)
            strcpy(p,"buenos Aires");
        if(pais==8)
            strcpy(p,"Mendoza");
        if(pais==9)
            strcpy(p,"San Luis");
        if(pais==10)
            strcpy(p,"Tierra del Fuego");
        if(pais==11)
            strcpy(p,"Santa Fe");
        if(pais==12)
            strcpy(p,"Entre Rios");
        if(pais==13)
            strcpy(p,"San Juan");
        if(pais==14)
            strcpy(p,"La Rioja");
        if(pais==15)
            strcpy(p,"Santiago del Estero");
        if(pais==16)
            strcpy(p,"Corrientes");
        if(pais==17)
            strcpy(p,"Misiones");
        if(pais==18)
            strcpy(p,"Catamarca");
        if(pais==19)
            strcpy(p,"Tucuman");
        if(pais==20)
            strcpy(p,"Chaco");
        if(pais==21)
            strcpy(p,"Formosa");
        if(pais==22)
            strcpy(p,"Salta");
        if(pais==23)
            strcpy(p,"Jujuy");
    }
    return p;
}
void provincia_residencia(lista_varado v)
{
    if(muestra_provincia(copi(v))==1)
        printf("-Provincia de Ingreso: Cordoba\n");
    if(muestra_provincia(copi(v))==2)
        printf("-Provincia de Ingreso: Santa Cruz\n");
    if(muestra_provincia(copi(v))==3)
        printf("-Provincia de Ingreso: Chubut\n");
    if(muestra_provincia(copi(v))==4)
        printf("-Provincia de Ingreso: Rio Negro\n");
    if(muestra_provincia(copi(v))==5)
        printf("-Provincia de Ingreso: Neuquen\n");
    if(muestra_provincia(copi(v))==6)
        printf("-Provincia de Ingreso: La Pampa\n");
    if(muestra_provincia(copi(v))==7)
        printf("-Provincia de Ingreso: Buenos Aires\n");
    if(muestra_provincia(copi(v))==8)
        printf("-Provincia de Ingreso: Mendoza\n");
    if(muestra_provincia(copi(v))==9)
        printf("-Provincia de Ingreso: San Luis\n");
    if(muestra_provincia(copi(v))==10)
        printf("-Provincia de Ingreso: Tierra del Fuego\n");
    if(muestra_provincia(copi(v))==11)
        printf("-Provincia de Ingreso: Santa Fe\n");
    if(muestra_provincia(copi(v))==12)
        printf("-Provincia de Ingreso: Entre Rios\n");
    if(muestra_provincia(copi(v))==13)
        printf("-Provincia de Ingreso: San Juan\n");
    if(muestra_provincia(copi(v))==14)
        printf("-Provincia de Ingreso: La Rioja\n");
    if(muestra_provincia(copi(v))==15)
        printf("-Provincia de Ingreso: Santiago del Estero\n");
    if(muestra_provincia(copi(v))==16)
        printf("-Provincia de Ingreso: Corrientes\n");
    if(muestra_provincia(copi(v))==17)
        printf("-Provincia de Ingreso: Misiones\n");
    if(muestra_provincia(copi(v))==18)
        printf("-Provincia de Ingreso: Catamarca\n");
    if(muestra_provincia(copi(v))==19)
        printf("-Provincia de Ingreso: Tucuman\n");
    if(muestra_provincia(copi(v))==20)
        printf("-Provincia de Ingreso: Chaco\n");
    if(muestra_provincia(copi(v))==21)
        printf("-Provincia de Ingreso: Formosa\n");
    if(muestra_provincia(copi(v))==22)
        printf("-Provincia de Ingreso: Salta\n");
    if(muestra_provincia(copi(v))==23)
        printf("-Provincia de Ingreso: Jujuy\n");
}

varado cargar_desde_archivo(FILE *fp)
{
    varado VAR;
    char str[TAM];
    int x;
    fecha f;
    init_varado(&VAR);
    fscanf(fp,"%[^\n]\n",str);
    cargar_apell(&VAR,str);
    fscanf(fp,"%[^\n]\n",str);
    cargar_nombre(&VAR,str);
    fscanf(fp,"%d\n",&x);
    cargar_dni(&VAR,x);
    //UTILIZAR EL LOCALIZAR MAN
    fscanf(fp,"%d/%d/%d\n",&f.dia,&f.mes,&f.anio);
    cargar_fecha(&VAR,f);
    fscanf(fp,"%d\n",&x);
    cargar_pais(&VAR,x);
    fscanf(fp,"%d\n",&x);
    cargar_grupof(&VAR,x);
    fscanf(fp,"%d\n",&x);
    cargar_riesgo(&VAR,x);
    fscanf(fp,"%d\n",&x);
    cargar_provincia(&VAR,x);
    return VAR;
}

void imprime_archivo(lista_varado v,FILE *fp)
{
    int x;
    fecha f;
    fprintf(fp,"Apellido y Nombre del Varado: %s,%s\n", muestra_apellido(copi(v)),muestra_nombre(copi(v)));
    fprintf(fp,"DNI: %d\n", muestra_dni(copi(v)));
    fprintf(fp,"Pais donde se encuentra: %s\n", nombre_pais(muestra_pais(copi(v))));
    fprintf(fp,"Grupo familiar: %d persona/s\n", muestra_cant_personas(copi(v)));
    if(muestra_riesgo(copi(v))==1)
        fprintf(fp,"Hay personas en riesgo\n");
    else
        fprintf(fp,"No hay personas en riesgo\n");
    fprintf(fp,"Provincia a la que desea ingresar: %s\n", nombre_provincia(muestra_provincia(copi(v))));
    fprintf(fp,"----------------------------------------------------------------------");
}
int mod_pais(lista_varado *v)
{
    int aux;
    system("cls");
    printf("===========================================================================================\n");
    printf("|   <1> CHILE        <2> URUGUAY    <3> BRASIL      <4> PARAGUAY     <5> PERU            |\n");
    printf("|   <6> BOLIVIA      <7> ECUADOR    <8> COLOMBIA    <9> VENEZUELA    <10> REP. DOMINICANA|\n");
    printf("|   <11> PUERTO RICO <12> MEXICO    <13> PANAMA     <14> EEUU        <15> CANADA         |\n");
    printf("|   <16> ESPAÑA      <17> PORTUGAL  <18> FRANCIA    <19> PAISES BAJOS<20> ALEMANIA       |\n");
    printf("|   <21> INGLATERRA  <22> TURQUIA   <23> JAPON      <24> AUSTRALIA   <25> MARRUECOS      |\n");
    printf("==========================================================================================\n");
    printf("SELECCIONE EL PAIS A MODIFICAR:");
    scanf("%d", &aux);
    while(aux<0 || aux>25){
        printf("\nSELECCIONE UN PAIS CORRECTO");
        scanf("%d", &aux);
    }
    return aux;
}

int mod_prov(lista_varado *v)
{
    int aux;
    system("cls");
    printf("============================================================================================\n");
    printf("|   <1> CORDOBA      <2> SANTA CRUZ <3> CHUBUT      <4> RIO NEGRO    <5> NEUQUEN           |\n");
    printf("|   <6> LA PAMPA     <7> BS. AIRES  <8> MENDOZA     <9> SAN LUIS     <10> TIERRA DEL FUEGO |\n");
    printf("|   <11> SANTA FE    <12> ENTRE RIOS<13> SAN JUAN   <14> LA RIOJA    <15> STGO. DEL ESTERO |\n");
    printf("|   <16> CORRIENTES  <17> MISIONES  <18> CASTAMARCA <19> TUCUMAN     <20> CHACO            |\n");
    printf("|   <21> FORMOSA     <22> SALTA     <23> JUJUY                                             |\n");
    printf("============================================================================================\n");
    printf("SELECCIONE LA PROVINCIA A MODIFICAR:");
    scanf("%d", &aux);
    while(aux<0 || aux>25){
        printf("\nSELECCIONE UNA PROVINCIA CORRECTA");
        scanf("%d", &aux);
    }
    return aux;

}

void mostrarEstructura(lista_varado *v){
    int i=0;
    system("pause");
    system("cls");
    reset(v);
    while(!isOos(*v)){
        mostrar_varado(*v);
        forwards(v);
        i++;
        if(i%3==0){
            system("pause");
            system("cls");
        }
    }
    printf("\nVolvera al menu principal.\n");
    system("pause");
}
