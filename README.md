#Estructuras de Datos y Algoritmos en C

Este repositorio contiene el código fuente y los recursos relacionados con mis trabajos de Estructura de Datos y Algoritmos en el lenguaje de programación C. Este proyecto fue desarrollado como parte de mi curso de Estructura de Datos y Algoritmos en [Universidad Nacional de San Luis].

## Aviso de Precisión

Este repositorio contiene código y recursos que se proporcionan con el propósito de aprendizaje, experimentación y colaboración. Es importante tener en cuenta que todo fue realizado durante mi cursada en la materia Estructuras de Datos y Algoritmos, y que a pesar de haber aprobado, no todo el codigo es correcto y eficiente.
Si encontras errores, problemas o inexactitudes en este repositorio, informame abriendo un "Issue" o una "Pull Request". Tu contribución es valiosa para mejorar la calidad de este recurso.

## Descripción

## Árbol Binario de Búsqueda (ABB) en C

Este repositorio contiene la implementación de un Árbol Binario de Búsqueda (ABB) en el lenguaje de programación C. El ABB se ha implementado con las siguientes características:

- **Política de Reemplazo**: Menor de los Mayores.
- **Funciones Principales**:
  - `initABB`: Inicializa un nuevo árbol binario de búsqueda.
  - `localizarABB`: Busca un valor en el árbol.
  - `evocarABB`: Recupera un valor del árbol.
  - `altaABB`: Inserta un valor en el árbol.
  - `bajaABB`: Elimina un valor del árbol.
  - `mostrarEstructuraABB`: Muestra la estructura actual del árbol.
  
Este árbol binario de búsqueda es utilizado para almacenar y gestionar una colección de vendedores según su número de identificación (DNI). La política de reemplazo utilizada es "Menor de los Mayores", lo que significa que se reemplaza un nodo con el valor más pequeño entre los nodos mayores cuando se realiza una eliminación.

Podes encontrar más detalles sobre el uso y la implementación en los comentarios del código fuente.

## Lista Secuencial Desordenada (LSD) en C con Ordenación Heapsort

Este repositorio contiene la implementación de una Lista Secuencial Desordenada (LSD) en el lenguaje de programación C, junto con una ordenación ascendente de los elementos utilizando el algoritmo Heapsort. La LSD se ha implementado con las siguientes características:

- **Ordenación**: Heapsort en orden ascendente.
- **Prioridad**: Campo `cantVentas` de los vendedores.
- **Orden Decreciente**: La ordenación se realiza de manera decreciente según la cantidad de ventas de los vendedores.

**Funciones Principales**:
  - `initLSD`: Inicializa una nueva lista secuencial desordenada.
  - `localizarLSD`: Busca un valor en la lista.
  - `altaLSD`: Inserta un valor en la lista.
  - `mostrarEstructuraLSD`: Muestra la estructura actual de la lista.
  - `heapSort`: Ordena la lista utilizando el algoritmo Heapsort.

Esta implementación de LSD permite almacenar y gestionar una colección de vendedores, priorizando a los vendedores con mayor cantidad de ventas. El algoritmo Heapsort se utiliza para ordenar la lista en orden ascendente según la cantidad de ventas de los vendedores.

Podes encontrar más detalles sobre el uso y la implementación en los comentarios del código fuente.

## Rebalse Abierto Cuadratico (RAC) en C

Este repositorio contiene la implementación de un Rebalse Abierto Cuadratico (RAC) en el lenguaje de programación C. El RAC se ha diseñado para gestionar un conjunto de registros de vendedores utilizando una estructura de balde con resolución de colisiones mediante exploración cuadrática.

**Características Principales:**
- **Tamaño del RAC (MRac)**: 149 (el número primo más cercano a 110/0.77).
- **Funciones Principales**:
  - `initRAC`: Inicializa un nuevo Rebalse Abierto Cuadratico (RAC).
  - `hashingRAC`: Función de dispersión utilizada para calcular la posición de un registro en el RAC.
  - `localizarRAC`: Busca un registro en el RAC.
  - `evocarRAC`: Recupera un registro del RAC.
  - `altaRAC`: Inserta un nuevo registro en el RAC.
  - `bajaRAC`: Elimina un registro del RAC.
  - `mostrarEstructuraRAC`: Muestra la estructura actual del RAC.

Este RAC permite almacenar y gestionar una colección de vendedores según su número de identificación (DNI). Utiliza una técnica de dispersión para calcular la posición de los registros basada en sus DNIs y resuelve colisiones mediante exploración cuadrática. El RAC admite operaciones como alta, baja, localización y evocación de registros.

Podes encontrar más detalles sobre el uso y la implementación en los comentarios del código fuente.

## Rebalse Separado (RS) en C

Este repositorio contiene la implementación de un Rebalse Separado (RS) (RS) en el lenguaje de programación C. El RS se ha diseñado para gestionar un conjunto de registros de vendedores utilizando una estructura de baldes con resolución de colisiones mediante listas enlazadas simples.

**Características Principales:**
- **Tamaño del RS (M)**: 60 (basado en un factor de 110/1.84).
- **Funciones Principales**:
  - `initRS`: Inicializa un nuevo Rebalse Separado (RS).
  - `hashingRS`: Función de dispersión utilizada para calcular la posición de un registro en el RS.
  - `localizarRS`: Busca un registro en el RS.
  - `evocarRS`: Recupera un registro del RS.
  - `altaRS`: Inserta un nuevo registro en el RS.
  - `bajaRS`: Elimina un registro del RS.
  - `mostrarEstructuraRS`: Muestra la estructura actual del RS.

Este RS permite almacenar y gestionar una colección de vendedores según su número de identificación (DNI). Utiliza una técnica de dispersión para calcular la posición de los registros basada en sus DNIs y resuelve colisiones mediante listas enlazadas. El RS admite operaciones como alta, baja, localización y evocación de registros.

Podes encontrar más detalles sobre el uso y la implementación en los comentarios del código fuente.

## Lista Doblemente Enlazada (ListaBI) en C

Este repositorio contiene la implementación de una Lista Doblemente Enlazada (ListaBI) en el lenguaje de programación C. Esta estructura de datos permite gestionar una colección de elementos utilizando nodos que están vinculados tanto al siguiente como al nodo anterior, lo que facilita la navegación en ambas direcciones.

**Características Principales:**
- **Estructura del Nodo**: Cada nodo de la lista contiene un elemento de tipo `varado` y dos punteros: uno al nodo siguiente (`next`) y otro al nodo anterior (`back`).
- **Funciones Principales**:
  - `init_lista`: Inicializa una nueva lista.
  - `reset`: Reinicia el cursor de la lista al inicio.
  - `isEmpty`: Comprueba si la lista está vacía.
  - `isFull`: Comprueba si no es posible agregar más elementos a la lista debido a limitaciones de memoria.
  - `forwards`: Mueve el cursor hacia adelante en la lista.
  - `backwards`: Mueve el cursor hacia atrás en la lista.
  - `copi`: Copia el elemento al que apunta el cursor.
  - `isOos`: Comprueba si el cursor está fuera de la secuencia de la lista.
  - `supress`: Elimina el elemento al que apunta el cursor.
  - `insert`: Inserta un nuevo elemento en la lista después del elemento al que apunta el cursor.

Esta implementación de una Lista Doblemente Enlazada permite realizar operaciones como inserción, eliminación y navegación en ambas direcciones de manera eficiente. Es una estructura de datos versátil y útil en diversas aplicaciones.
Este código representa uno de mis primeros proyectos en C. A pesar de mi experiencia limitada en ese momento, creo haber logrado crear una implementación funcional de una lista bidireccional que permite diversas operaciones, como inserción, eliminación y navegación.

## Entorno de Ejecución

Compilado en CodeBlocks 

## Contribución

Si deseas contribuir a este proyecto, ¡te animo a hacerlo! Puedes enviar propuestas de cambios (pull requests) o informar sobre problemas (issues) que encuentres.


