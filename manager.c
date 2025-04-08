#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esPrimo(int numero) {
	/*Funcion que dice si un numero es primo o no
	 * E: Un numero entero positivo(preferiblemente primo)
	 * S: Un 1 si el numero es primo y un 2 si no
	 * R: La entrada tiene que ser un numero primo preferiblemente
	 * */ 
    if (numero == 0 || numero == 1) 
        return 0;
  
    if (numero == 4) 
        return 0;
  
    for (int x = 2; x < numero / 2; x++) {
    
        if (numero % x == 0) 
            return 0;
    }
  return 1;
}



int siguientePrimo(int numero){
    /*Funcion que retorna el siguiente primo al numero de la entrada
    * E: Un numero entero
    * S: Un numero entero que es primo 
    * R: La entrada preferiblemente tiene que ser un numero primo
    * */
    int actual = numero;
    while(1){
    
        actual++;
        if(esPrimo(actual)) 
        return actual;
    }
}

//--------------------------------------------------------------------
//--------------------------------------------------------------------
//FUNCOINES PARA LA LISTA DOBLE
//--------------------------------------------------------------------
//--------------------------------------------------------------------

struct nodo_lista{
	/*Struct de los nodos de las listas
	 * */
    char* nombre;
    char* link;
    char* resumen;
    struct nodo_lista* sigt;
    struct nodo_lista* ant;
};

struct lista{
	/*Struct de la listas
	 * */
    struct nodo_lista* inicio;
};

struct lista* nueva_lista(){
    /*Crear una espacio de tipo struct lista en el heap y le 
      asigna la dirreccion en memoria a nueva_lista
     * */
    struct lista *lista1 = calloc(1, sizeof(struct lista));
    return lista1;
};


struct nodo_lista* crear_nodo(char* nombre, char* link, char* resumen){
    
    /*Crear una espacio de tipo struct nodo lista en el heap y le 
      asigna la dirreccion en memoria a nuevo_nodo, ademas le ingresa 
      el valor en la seccion de valor
      **/
     
    struct nodo_lista* nuevo_nodo = NULL;
    nuevo_nodo = calloc(1, sizeof(struct nodo_lista));
    nuevo_nodo -> nombre = nombre;
    nuevo_nodo -> link = link;
    nuevo_nodo -> resumen = resumen;
    nuevo_nodo -> sigt = NULL;
    nuevo_nodo -> ant = NULL;
    return nuevo_nodo;
}

int insertar_ordenado(struct lista* lis, char* nombre,char* link,char* resumen){
    /*Funcion que inserta nodos en orden alfabetico a una lista  
     *E: Recibe un puntero de tipo struct lista y 3 punteros a char 
     *S: Crea un nodo en la lista con el valor ingresado
     *R: La lista debe tener espacio en memoria
     * */
    if (lis==NULL){
        return -1; 
    }
    
    else if (lis->inicio == NULL){
        lis->inicio = crear_nodo(nombre,link,resumen);
        return 0;
    }
    else if (strcmp(nombre,lis->inicio->nombre) < 0){
        struct nodo_lista* actual = lis->inicio;
        struct nodo_lista* nuevo_nodo = crear_nodo(nombre,link,resumen);
        lis->inicio = nuevo_nodo;
        nuevo_nodo->sigt = actual;
        actual->ant = nuevo_nodo;
        return 0;
        
    }
    else{
        struct nodo_lista* actual = lis->inicio;
        while (actual != NULL){
            if(strcmp(nombre,actual->nombre) < 0){
                struct nodo_lista* anterior = actual->ant;
                struct nodo_lista* siguiente = actual;
                struct nodo_lista* nuevo_nodo = crear_nodo(nombre,link,resumen);
                
                anterior->sigt = nuevo_nodo;
                nuevo_nodo->ant = anterior;
                
                nuevo_nodo->sigt = siguiente;
                siguiente->ant = nuevo_nodo;
                return 0;
            }
            else if (actual->sigt == NULL){
                struct nodo_lista* nuevo_nodo = crear_nodo(nombre,link,resumen);
                actual->sigt = nuevo_nodo;
                nuevo_nodo->ant = actual;
                return 0;
            }
            actual = actual->sigt;
        }
    }
}

int eliminar_lista(struct lista* lis){
    /*Funcion que elimina listas
     *E: Un puntero a una lista
     *S: N/A
     *R: La lista debe tener espacio en memoria 
     * */
    if (lis==NULL){
        return -1; 
    }
    else if(lis!=NULL){
        struct nodo_lista* actual = lis->inicio;
        while (lis->inicio != NULL){
            
            if (actual->sigt == NULL){
                free(actual);
                lis->inicio=NULL;
                
                return 0;
            }
            
            lis->inicio = actual->sigt;
            actual->sigt->ant = NULL;
            free(actual);
            actual = lis->inicio;
            
            
        }
        return 0;
    }
}

int eliminar_elemento(struct lista* lis, char* nombre){
    /* Funcion que elimina un elemento de una lista
     * E: Un puntero a una lista y un puntero a un char
     * S: N/A
     * R: La lista tiene que tener espacio en memoria
     **/
    if (lis==NULL){
        return -1; 
    }
    else if(lis!=NULL){
        if (lis->inicio==0){
            printf("-----------------------------------------------\n");
            printf("[Err0r] Referencia inexistente.");
            return 0;
        }
        
        struct nodo_lista* actual = lis->inicio;

        if (strcmp(actual->nombre, nombre)==0){
            lis->inicio = actual->sigt;
            if (actual->sigt != NULL){
                actual->sigt->ant = NULL;
            }
            free(actual);
            actual = NULL;
            printf("-----------------------------------------------\n");
            printf("[0k] Referencia eliminada exitosamente.");
            return 0;
        }
        while (actual != NULL){
            if (strcmp(actual->nombre, nombre)==0){
                struct nodo_lista* succ = actual->sigt;
                struct nodo_lista* pred = actual->ant;
                if (succ == NULL){

                    pred->sigt = NULL;
                    free(actual);
                    actual = NULL;
                    printf("-----------------------------------------------\n");
                    printf("[0k] Referencia eliminada exitosamente.");
                    return 0;
                }
                else{
                    succ->ant = pred;
                    pred->sigt = succ;
                    free(actual);
                    actual = NULL;
                    printf("-----------------------------------------------\n");
                    printf("[0k] Referencia eliminada exitosamente.");
                    return 0;
                }
            }
            actual=actual->sigt;
        }
        printf("-----------------------------------------------\n");
        printf("[Err0r] Referencia inexistente.");
        return 0;
    }
}


int imprimir_lista(struct lista* lis){
    /* Funcion que imprime listas
     * E: Una dirrecion de memoria de una lista
     * S: imprime todos los valores de la lista
     * R: la lista no puede estar vacia 
     * */
    if (lis==NULL){
        return -1; 
    }
    
    else{
        struct nodo_lista* actual = lis->inicio;
        while (actual != NULL){
            printf("%s\n",actual->nombre);
            actual = actual->sigt;
        }
    }
}

int buscar_lista(struct lista* lis, char* nombre){
    /*Funcion que busca un nodo en especifico en una lista
    * E: Un puntero a una lista y uno a un char
    * S: Imprime en pantalla el titulo de la referencia, el link y el resumen de este
    * R: N/A
    * */
    
    struct nodo_lista* actual = lis->inicio;
    
    while(actual!=NULL){
        if (strcmp(actual->nombre, nombre)==0){
            printf("%s\n",actual->nombre);
            printf("%s\n",actual->link);
            printf("%s\n",actual->resumen);
            return 0;
        }
        actual = actual->sigt;
    }
    printf("[Err0r] Referencia inexistente.");
    return 0;
}
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//FUNCOINES PARA LA TABLA DE HASH
//--------------------------------------------------------------------
//--------------------------------------------------------------------

int largo = 11;
int largoAux=19;

int funcionhash(char* llave){
	/* Funcion hash 
	 * E: Un puntero a un char
	 * S: Un numero entero resultado del algoritmo de la funcion
	 * R: N/A
	 * */
    int contador = 0;
    int i =0;
    int j =1;
    
    while (llave[i] != '\0'){
        contador+= llave[i]*j;
        i++;
        j++;
    }

    return contador;
}

struct nodo_tabla{
	/*Struct de un nodo de la tabla hash
	 * */
    char* llave;
    struct lista* Lista;
};

struct nodo_tabla** nueva_tabla(int largo_tabla){
    /*Crear una espacio de tipo struct nodo_tabla** en el heap y le 
      asigna la dirreccion en memoria a nueva_lista
     * */
    struct nodo_tabla** tabla_hash = calloc(largo_tabla, sizeof(struct nodo_tabla*));
    return tabla_hash;
};


struct nodo_tabla* crear_nodo_tabla(char* llave){
    /* Funcion que crea nodos de tabla de hash asignandoles espacio en memoria
     * E: Un puntero a un char
     * R: N/A
     * */
    struct nodo_tabla* nuevo_nodo = NULL;
    struct lista * lista1 = NULL;
    
    nuevo_nodo = calloc(1, sizeof(struct nodo_tabla));
    nuevo_nodo -> llave = llave;
    
    
    lista1 = nueva_lista();
    nuevo_nodo -> Lista = lista1;
    return nuevo_nodo;
}

int insertar_categoria(struct nodo_tabla** tabla_hash, char* llave){
	/*Funcion que inserta categorias en la tabla de hash
	 * E: Un puntero a la tabla de hash y un puntero a un char que 
	 * es la llave y el nombre de la categoria
	 * S: N/A
	 * R: N/A
	 * */

    struct nodo_tabla* nn = crear_nodo_tabla(llave);
    int valor_hash = funcionhash(llave);
    int posicion = valor_hash%largo;
    if (tabla_hash[posicion]==NULL){
        tabla_hash[posicion]=nn;
        
        printf("-----------------------------------------------\n");
        printf("[0k] Categoria agregada exitosamente.\n");
        return 0;
    }
        
    else{
        while (tabla_hash[posicion]!=NULL){
            if (posicion==largo-1){
                posicion=-1;
            }
            posicion++;
        }
        tabla_hash[posicion]=nn;
        printf("-----------------------------------------------\n");
        printf("[0k] Categoria agregada exitosamente.\n");
        return 0;
    }

    
    
}


int insertar_referencia(struct nodo_tabla** tabla_hash, char* llave,char* nombre, char* link ,char* resumen){
    /* Funcion que inseta temas a las categorias
     * E: Un puneto a una tabla de hash y y cuatro punteros a char que 
     * son los que componen un nodo
     * S: N/A
     * R: N/A
     * */
    
    int cantidad_de_vueltas=0;
    int valor_hash = funcionhash(llave);
    int posicion = valor_hash%largo;
    
    if (tabla_hash[posicion]!=NULL){
        if (strcmp(tabla_hash[posicion]->llave, llave)==0){
            insertar_ordenado(tabla_hash[posicion]->Lista,nombre,link, resumen);
            printf("-----------------------------------------------\n");
            printf("[0k] Referencia agregada exitosamente.");
            return 0;
        }
    }
    
    while(1){
        if(posicion==largo-1){
            posicion=0;
        }
        
        if(cantidad_de_vueltas==largo-1){
            printf("-----------------------------------------------\n");
            printf("[Err0r] Categoria inexistente");
            return 0;
        }
        
        if (tabla_hash[posicion]!=NULL){
            if (strcmp(tabla_hash[posicion]->llave, llave)==0){
                insertar_ordenado(tabla_hash[posicion]->Lista,nombre,link, resumen);
                printf("-----------------------------------------------\n");
                printf("[0k] Referencia agregada exitosamente.");
                return 0;
            }
        }
        posicion++;
        cantidad_de_vueltas++;
    }
    printf("-----------------------------------------------\n");
    printf("[Err0r] Categoria inexistente"); 
    return 0;
}

int eliminar_categoria(struct nodo_tabla** tabla_hash, char* llave){
    /*Funcion que elimina categorias de la tabla de hash
     * E: Un puntero a una tabla de hash y otro a un char 
     * S: N/A
     * R: N/A
     * */
	int cantidad_de_vueltas=0;
    int valor_hash = funcionhash(llave);
    int posicion = valor_hash%largo;
	
	if (tabla_hash[posicion]!=0){
        if (strcmp(tabla_hash[posicion]->llave, llave)==0){
            if (tabla_hash[posicion]->Lista!=NULL){
                eliminar_lista(tabla_hash[posicion]->Lista);
                free(tabla_hash[posicion]);
                tabla_hash[posicion]=NULL;
                printf("-----------------------------------------------\n");
                printf("[0k] Categoria eliminada exitosamente");
                return 0;
            }
        }
    }
    while (1){
        if(posicion==largo-1){
            posicion=0;
        }
        
        if(cantidad_de_vueltas==largo-1){
			printf("-----------------------------------------------\n");
            printf("[Err0r] Categoria inexistente");
            return 0;
        }
        
        if (tabla_hash[posicion]!=0){
            if (strcmp(tabla_hash[posicion]->llave, llave)==0){
                if (tabla_hash[posicion]->Lista!=NULL){
                    eliminar_lista(tabla_hash[posicion]->Lista);
                    free(tabla_hash[posicion]);
                    tabla_hash[posicion]=NULL;
                    printf("-----------------------------------------------\n");
                    printf("[0k] Categoria eliminada exitosamente");
                    return 0;
                }
            }
        }
        posicion++;
        cantidad_de_vueltas++;
    }
}

int eliminar_referencia(struct nodo_tabla** tabla_hash, char* llave, char* nombre){
    /* Funcion que elimina referencias de una categoria
     * E: Un puntero a una tabla de hash y otros dos a un char
     * S: N/A
     * R: N/A
     * */
    int cantidad_de_vueltas=0;
    int valor_hash = funcionhash(llave);
    int posicion = valor_hash%largo;

    if (tabla_hash[posicion]!=0){
        if (strcmp(tabla_hash[posicion]->llave, llave)==0){
            eliminar_elemento(tabla_hash[posicion]->Lista,nombre);
            return 0;
        }
    }
    
    
    while (1){
        if(posicion==largo-1){
            posicion=0;
        }
        
        if(cantidad_de_vueltas==largo-1){
            printf("-----------------------------------------------\n");
            printf("[Err0r] Categoria inexistente");
            return 0;
        }
        
        if (tabla_hash[posicion]!=0){
            if (strcmp(tabla_hash[posicion]->llave, llave)==0){
                eliminar_elemento(tabla_hash[posicion]->Lista,nombre);
                return 0;
            }
        }
        posicion++;
        cantidad_de_vueltas+=1;
    }
}

int imprimir_categorias(struct nodo_tabla** tabla_hash){
	/*Funcion que imprime cada categoria de una tabla de hash
	 * E: Un puntero a una tabla de hash
	 * S: Imprime en pantalla cada categoria 
	 * R: N/A
	 * */
    for (int i=0;i<largo;i++){ 
        if (tabla_hash[i]!= NULL){
            printf("%s\n",tabla_hash[i]->llave);
        }
    }
}

int imprimir_referencias(struct nodo_tabla** tabla_hash, char* llave){
    /*Funcion que muestra en pantalla las refernecias de una categoria en especifico
     * E: Un puntero a una tabla_hash
     * S: Muestra en pantalla las categorias
     * R: N/A
     * */
    
    //calcula la posicion
    int cantidad_de_vueltas=0;
    int valor_hash = funcionhash(llave);
    int posicion = valor_hash%largo;
    
    if (tabla_hash[posicion]!=0){
        if (strcmp(tabla_hash[posicion]->llave, llave)==0){
            imprimir_lista(tabla_hash[posicion]->Lista);
            return 0;
        }
    }
    
    while (1){
        if(posicion==largo-1){
            posicion=0;
        }
        
        if(cantidad_de_vueltas==largo-1){
            printf("-----------------------------------------------\n");
            printf("[Err0r] Categoria inexistente.");
            return 0;
        }
        
        if (tabla_hash[posicion]!=0){
            if (strcmp(tabla_hash[posicion]->llave, llave)==0){
            imprimir_lista(tabla_hash[posicion]->Lista);
            return 0;
            }
        }
        posicion++;
        cantidad_de_vueltas+=1;
    }
}
    

int busqueda_especifica(struct nodo_tabla** tabla_hash, char* llave, char* nombre){
	/*Funcio que busca en una categoria en especifico una referencia
	 * E: Un puntero a una tabla hash y otros dos a un char
	 * S: N/A
	 * R: N/A
	 * */
	
	
    int cantidad_de_vueltas=0;
    int valor_hash = funcionhash(llave);
    int posicion = valor_hash%largo;
    
    if (tabla_hash[posicion]!=NULL){
        if (strcmp(tabla_hash[posicion]->llave, llave)==0){
            buscar_lista(tabla_hash[posicion]->Lista, nombre);
            return 0;
        }
    }
    
    while (1){
        if(posicion==largo-1){
            posicion=0;
        }
        
        if(cantidad_de_vueltas==largo-1){
            printf("-----------------------------------------------\n");
            printf("[Err0r] Categoria inexistente.");
            return 0;
        }
        
        if (tabla_hash[posicion]!=0){
            if (strcmp(tabla_hash[posicion]->llave, llave)==0){
            buscar_lista(tabla_hash[posicion]->Lista, nombre);
            return 0;
            }
        }
        posicion++;
        cantidad_de_vueltas++;
    }
}

int busqueda_general(struct nodo_tabla** tabla_hash,  char* nombre){
	/* Funcion que busca en todas las clases una referncia en especifico
	 * E: Un puntero a una tabla hash y otro a un char
	 * S: N/A
	 * R: N/A
	 * */

    for (int i=0;i<largo;i++){
        if (tabla_hash[i]!=NULL){
            buscar_lista(tabla_hash[i]->Lista, nombre);
            return 0;
        }
    }
    printf("-----------------------------------------------\n");
    printf("[Err0r] Referencia inexistente.");
}

int menu(){
	
	// Funcion que muestra el menu
	
	
    struct nodo_tabla** tabla_hash = NULL;
    tabla_hash = nueva_tabla(largo);
    int opcion;
    char llave[100];
    char nombre[100];
    char link[100];
    char resumen[400];
    insertar_categoria(tabla_hash,"Estado de la emergencia climatica");
    insertar_categoria(tabla_hash,"Soluciones desde el Anarquismo solarpunk");
    insertar_categoria(tabla_hash,"Entretenimiento solarpunk");
    
    while(1){
        printf("\n");
        printf("-----------------------------------------------\n");
        printf("Que desea hacer?\n\n");
        printf("1. Agregar categoria\n"); 
        printf("2. Agregar referencia\n"); 
        printf("3. Eliminar categoria\n"); 
        printf("4. Eliminar referencia\n"); 
        printf("5. Ver todas las categorias\n"); 
        printf("6. Ver todas las referencias de una categoria\n"); 
        printf("7. Buscar por categoria y nombre de la referencia \n"); 
        printf("8. Buscar por nombre de la referencia\n"); 
        printf("9. Salir\n"); 
        printf("Ingrese una opcion => ");
        scanf("%d",&opcion);
        while(getchar()!='\n');
        printf("\n");
        
        
        
        
        if (opcion==9){
            break;
        }
        
        if (opcion==1){
			printf("\n");
            printf("Nombre de la categoria: ");
            scanf("%[^\n]",llave);
            while(getchar()!='\n');
             
            
            char* llave_heap = calloc(100,sizeof(char));
            strcpy(llave_heap,llave);
            insertar_categoria(tabla_hash,llave_heap);
            
            /*
             * Aqui se hace el redimencionamiento de la tabla, ya que si
             * se llena al 75%, la tabla cambia a un largo mas grande
             * 
             */
             
            int espacios_ocupados = 0;
            
            for (int i =0;i<largo;i++){
                if (tabla_hash[i]!=NULL){
                    espacios_ocupados++;
                }
            }  
             
            if (75*largo/100 == espacios_ocupados){
                struct nodo_tabla** siguiente_hash = nueva_tabla(largoAux);
        
                for (int i =0;i<largo;i++){
                    if (tabla_hash[i]!=NULL){
                        int valor_hash = funcionhash(tabla_hash[i]->llave);
                        int posicion = valor_hash%largoAux;
                        if (siguiente_hash[posicion]!=NULL){
                            while (siguiente_hash[posicion]!=NULL){
                                if (posicion==largoAux-1){
                                    posicion=-1;
                                }
                                posicion++;
                            }
                            siguiente_hash[posicion]=tabla_hash[i];
                            tabla_hash[i]=0;
                        }
                        else{
                            siguiente_hash[posicion]=tabla_hash[i];
                            tabla_hash[i]=0;
                        }
                    }
                }
                free(tabla_hash);
                tabla_hash=siguiente_hash;
                siguiente_hash=0;
                largo=largoAux;
                largoAux=siguientePrimo(largoAux);
            }
            espacios_ocupados = 0;
        }   


        if (opcion==2){
			
			printf("\n");
            printf("Nombre de la categoria: ");
            scanf("%[^\n]",llave);
            while(getchar()!='\n');
             
            
            char* llave_heap = calloc(100,sizeof(char));
            strcpy(llave_heap,llave);
            
            
            printf("Titulo de la referencia: ");
			scanf("%[^\n]",nombre);
            while(getchar()!='\n');          
            char* nombre_heap = calloc(100,sizeof(char));
            strcpy(nombre_heap,nombre);
            
            
            printf("link: ");
			scanf("%[^\n]",link);
            while(getchar()!='\n');
            char* link_heap = calloc(100,sizeof(char));
            strcpy(link_heap,link);
            
            
            printf("Resumen del link: ");
            scanf("%[^\n]",resumen);
            while(getchar()!='\n');
            
            char* resumen_heap = calloc(400,sizeof(char));
            strcpy(resumen_heap,resumen);
            

            insertar_referencia(tabla_hash,llave_heap,nombre_heap,link_heap,resumen_heap);
        }
        
        if (opcion==3){
            printf("Nombre de la categoria: ");
			scanf("%[^\n]",llave);
            while(getchar()!='\n'); 
			           
            char* llave_heap = calloc(100,sizeof(char));
            strcpy(llave_heap,llave);
            
            
            eliminar_categoria(tabla_hash,llave_heap);
            free(llave_heap);

        }
        
        if (opcion==4){

            printf("Nombre de la categoria: ");
            scanf("%[^\n]",llave);
            while(getchar()!='\n');  
            
            char* llave_heap = calloc(100,sizeof(char));
            strcpy(llave_heap,llave);
            
            
            printf("Titulo de la referencia: ");
            
            scanf("%[^\n]",nombre);
            while(getchar()!='\n'); 
            
            char* nombre_heap = calloc(100,sizeof(char));
            strcpy(nombre_heap,nombre);

            eliminar_referencia(tabla_hash,llave_heap,nombre_heap);

        }
        
        if (opcion==5){
            printf("Las categorias son: \n\n");
            imprimir_categorias(tabla_hash);
        }
        
        if (opcion==6){

            printf("Nombre de la categoria: ");
            scanf("%[^\n]",llave);
            while(getchar()!='\n'); 
            
            char* llave_heap = calloc(100,sizeof(char));
            strcpy(llave_heap,llave);
            

            imprimir_referencias(tabla_hash,llave_heap);
            free(llave_heap);
        }
        
        if (opcion==7){
            printf("Nombre de la categoria: ");
            scanf("%[^\n]",llave);
            while(getchar()!='\n'); 
            
            char* llave_heap = calloc(100,sizeof(char));
            strcpy(llave_heap,llave);
            
            
            printf("Titulo de la referencia: ");
            scanf("%[^\n]",nombre);
            while(getchar()!='\n'); 
            
            char* nombre_heap = calloc(100,sizeof(char));
            strcpy(nombre_heap,nombre);
            
            
            busqueda_especifica(tabla_hash,llave_heap,nombre_heap);
            free(llave_heap);
            free(nombre_heap);
        }
        
        if (opcion==8){

            printf("Titulo de la referencia: ");
            scanf("%[^\n]",nombre);
            while(getchar()!='\n'); 
            
            char* nombre_heap = calloc(100,sizeof(char));
            strcpy(nombre_heap,nombre);
            

            busqueda_general(tabla_hash,nombre_heap);
            free(nombre_heap);
        }
        
        if (opcion>9 || opcion<1){
            printf("Escoga una opcion valida");
        }
        
    }
}


int main() {
    
    menu();
    
    return 0;
}
