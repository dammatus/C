# Estructuras de Datos y Algoritmos en C
### [English](#Data Structures and Algorithms in C)


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

# Data Structures and Algorithms in C

This repository contains the source code and related resources for my work on Data Structures and Algorithms in the C programming language. This project was developed as part of my course on Data Structures and Algorithms at [Universidad Nacional de San Luis].

## Accuracy Disclaimer

This repository contains code and resources provided for the purpose of learning, experimentation, and collaboration. It's important to note that everything was done during my course in Data Structures and Algorithms, and that not all code is correct and efficient.

If you find errors, problems, or inaccuracies in this repository, please inform me by opening an "Issue" or a "Pull Request." Your contribution is valuable to improve the quality of this resource.

## Description

## Binary Search Tree (BST) in C

This repository contains the implementation of a Binary Search Tree (BST) in the C programming language. The BST has been implemented with the following features:

- **Replacement Policy**: Smallest of the Greater.
- **Main Functions**:
  - `initBST`: Initializes a new binary search tree.
  - `locateBST`: Searches for a value in the tree.
  - `retrieveBST`: Retrieves a value from the tree.
  - `insertBST`: Inserts a value into the tree.
  - `deleteBST`: Removes a value from the tree.
  - `showStructureBST`: Displays the current structure of the tree.

This binary search tree is used to store and manage a collection of vendors based on their identification number (DNI). The replacement policy used is "Smallest of the Greater," which means that a node with the smallest value among the greater nodes is replaced when a deletion is performed.

You can find more details about usage and implementation in the comments of the source code.

## Unordered Sequential List (USL) in C with Heapsort Sorting

This repository contains the implementation of an Unordered Sequential List (USL) in the C programming language, along with ascending sorting of elements using the Heapsort algorithm. The USL has been implemented with the following features:

- **Sorting**: Heapsort in ascending order.
- **Priority**: Field `salesQty` of the vendors.
- **Descending Order**: Sorting is performed in descending order based on the sales quantity of the vendors.

**Main Functions**:
  - `initUSL`: Initializes a new unordered sequential list.
  - `locateUSL`: Searches for a value in the list.
  - `insertUSL`: Inserts a value into the list.
  - `showStructureUSL`: Displays the current structure of the list.
  - `heapSort`: Sorts the list using the Heapsort algorithm.

This implementation of USL allows storing and managing a collection of vendors, prioritizing vendors with a higher quantity of sales. The Heapsort algorithm is used to sort the list in ascending order based on the sales quantity of the vendors.

You can find more details about usage and implementation in the comments of the source code.

## Quadratic Open Addressing Hash Table (QOAHT) in C

This repository contains the implementation of a Quadratic Open Addressing Hash Table (QOAHT) in the C programming language. The QOAHT is designed to manage a set of vendor records using a bucket structure with collision resolution through quadratic probing.

**Key Features:**
- **Table Size (M)**: 149 (the nearest prime number to 110/0.77).
- **Main Functions**:
  - `initQOAHT`: Initializes a new Quadratic Open Addressing Hash Table (QOAHT).
  - `hashingQOAHT`: Hashing function used to calculate the position of a record in the QOAHT.
  - `locateQOAHT`: Searches for a record in the QOAHT.
  - `retrieveQOAHT`: Retrieves a record from the QOAHT.
  - `insertQOAHT`: Inserts a new record into the QOAHT.
  - `deleteQOAHT`: Deletes a record from the QOAHT.
  - `showStructureQOAHT`: Displays the current structure of the QOAHT.

This QOAHT allows storing and managing a collection of vendors based on their identification number (DNI). It uses a hashing technique to calculate the position of records based on their DNIs and resolves collisions using quadratic probing. The QOAHT supports operations such as insertion, deletion, location, and retrieval of records.

You can find more details about usage and implementation in the comments of the source code.

## Separate Chaining Hash Table (SCHT) in C

This repository contains the implementation of a Separate Chaining Hash Table (SCHT) in the C programming language. The SCHT is designed to manage a set of vendor records using a bucket structure with collision resolution through singly linked lists.

**Key Features:**
- **Table Size (M)**: 60 (based on a factor of 110/1.84).
- **Main Functions**:
  - `initSCHT`: Initializes a new Separate Chaining Hash Table (SCHT).
  - `hashingSCHT`: Hashing function used to calculate the position of a record in the SCHT.
  - `locateSCHT`: Searches for a record in the SCHT.
  - `retrieveSCHT`: Retrieves a record from the SCHT.
  - `insertSCHT`: Inserts a new record into the SCHT.
  - `deleteSCHT`: Deletes a record from the SCHT.
  - `showStructureSCHT`: Displays the current structure of the SCHT.

This SCHT allows storing and managing a collection of vendors based on their identification number (DNI). It uses a hashing technique to calculate the position of records based on their DNIs and resolves collisions using singly linked lists. The SCHT supports operations such as insertion, deletion, location, and retrieval of records.

You can find more details about usage and implementation in the comments of the source code.

## Doubly Linked List (DLL) in C

This repository contains the implementation of a Doubly Linked List (DLL) in the C programming language. This data structure allows managing a collection of elements using nodes that are linked both to the next and previous nodes, facilitating navigation in both

 directions.

**Key Features:**
- **Node Structure**: Each node in the list contains an element of type `varado` and two pointers: one to the next node (`next`) and one to the previous node (`back`).
- **Main Functions**:
  - `init_list`: Initializes a new list.
  - `reset`: Resets the list's cursor to the beginning.
  - `isEmpty`: Checks if the list is empty.
  - `isFull`: Checks if it's not possible to add more elements to the list due to memory limitations.
  - `forwards`: Moves the cursor forward in the list.
  - `backwards`: Moves the cursor backward in the list.
  - `copy`: Copies the element pointed to by the cursor.
  - `isOutOfSequence`: Checks if the cursor is out of the list's sequence.
  - `remove`: Removes the element pointed to by the cursor.
  - `insert`: Inserts a new element into the list after the element pointed to by the cursor.

This implementation of a Doubly Linked List allows efficient insertion, deletion, and navigation in both directions. It's a versatile data structure useful in various applications.

## Execution Environment

Compiled with CodeBlocks

## Contribution

If you wish to contribute to this project, I encourage you to do so! You can submit proposals for changes (pull requests) or report issues you find.
