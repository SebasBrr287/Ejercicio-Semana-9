#include "funciones.h"

// Variables globales
struct Libro biblioteca[10];
int totalLibros = 0;

// Función validar entero con rango
int ValidarIntconRango(int a, int b) {

    int n, aux;

    do {

        aux = scanf("%d", &n);

        while(getchar() != '\n');

        if(aux != 1 || n < a || n > b) {

            printf("Error el valor ingresado es incorrecto\n");
            printf("Vuelva a ingresar:\n");
        }

    } while(aux != 1 || n < a || n > b);

    return n;
}

// Función leer cadena
void leerCadena(char cadena[], int n) {

    int len;

    fgets(cadena, n, stdin);

    len = strlen(cadena) - 1;

    cadena[len] = '\0';
}

// Función validar ID
int idExiste(int id) {

    int i;

    for(i = 0; i < totalLibros; i++) {

        if(biblioteca[i].id == id) {

            return 1;
        }
    }

    return 0;
}

// Registrar libro
void registrarLibro() {

    if(totalLibros >= 10) {

        printf("\nNo se pueden agregar más libros.\n");
        return;
    }

    printf("\nIngrese ID del libro: ");

    biblioteca[totalLibros].id = ValidarIntconRango(1, 9999);

    if(idExiste(biblioteca[totalLibros].id)) {

        printf("El ID ya existe.\n");
        return;
    }

    printf("Ingrese titulo: ");
    leerCadena(biblioteca[totalLibros].titulo, 100);

    printf("Ingrese autor: ");
    leerCadena(biblioteca[totalLibros].autor, 50);

    printf("Ingrese año de publicacion: ");

    biblioteca[totalLibros].anio = ValidarIntconRango(1000, 2026);

    strcpy(biblioteca[totalLibros].estado, "Disponible");

    totalLibros++;

    printf("\nLibro registrado correctamente.\n");
}

// Mostrar libros
void mostrarLibros() {

    int i;

    if(totalLibros == 0) {

        printf("\nNo hay libros registrados.\n");
        return;
    }

    printf("ID\tTitulo\t\tAutor\t\tAño\tEstado\n");

    for(i = 0; i < totalLibros; i++) {

        printf("%d\t%s\t%s\t%d\t%s\n",
               biblioteca[i].id,
               biblioteca[i].titulo,
               biblioteca[i].autor,
               biblioteca[i].anio,
               biblioteca[i].estado);
    }
}

// Buscar por ID
void buscarPorID() {

    int id;
    int i;
    int encontrado = 0;

    printf("\nIngrese ID del libro: ");

    id = ValidarIntconRango(1, 9999);

    for(i = 0; i < totalLibros; i++) {

        if(biblioteca[i].id == id) {

            printf("\nLibro encontrado\n");
            printf("ID: %d\n", biblioteca[i].id);
            printf("Titulo: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Año: %d\n", biblioteca[i].anio);
            printf("Estado: %s\n", biblioteca[i].estado);

            encontrado = 1;
        }
    }

    if(encontrado == 0) {

        printf("Libro no encontrado.\n");
    }
}

// Buscar por título
void buscarPorTitulo() {

    char titulo[100];
    int i;
    int encontrado = 0;

    printf("\nIngrese título del libro: ");

    leerCadena(titulo, 100);

    for(i = 0; i < totalLibros; i++) {

        if(strcmp(biblioteca[i].titulo, titulo) == 0) {

            printf("\nLibro encontrado\n");
            printf("ID: %d\n", biblioteca[i].id);
            printf("Titulo: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Año: %d\n", biblioteca[i].anio);
            printf("Estado: %s\n", biblioteca[i].estado);

            encontrado = 1;
        }
    }

    if(encontrado == 0) {

        printf("Libro no encontrado.\n");
    }
}

// Actualizar estado
void actualizarEstado() {

    int id;
    int i;
    int encontrado = 0;

    printf("\nIngrese ID del libro: ");

    id = ValidarIntconRango(1, 9999);

    for(i = 0; i < totalLibros; i++) {

        if(biblioteca[i].id == id) {

            if(strcmp(biblioteca[i].estado, "Disponible") == 0) {

                strcpy(biblioteca[i].estado, "Prestado");

            } else {

                strcpy(biblioteca[i].estado, "Disponible");
            }

            printf("Estado actualizado correctamente.\n");

            encontrado = 1;
        }
    }

    if(encontrado == 0) {

        printf("Libro no encontrado.\n");
    }
}

// Eliminar libro
void eliminarLibro() {

    int id;
    int i;
    int j;
    int encontrado = 0;

    printf("\nIngrese ID del libro a eliminar: ");

    id = ValidarIntconRango(1, 9999);

    for(i = 0; i < totalLibros; i++) {

        if(biblioteca[i].id == id) {

            for(j = i; j < totalLibros - 1; j++) {

                biblioteca[j] = biblioteca[j + 1];
            }

            totalLibros--;

            printf("Libro eliminado correctamente.\n");

            encontrado = 1;

            break;
        }
    }

    if(encontrado == 0) {

        printf("Libro no encontrado.\n");
    }
}

// Menú
void menu() {

    int opc;
    int opc2;

    do {

        printf("\n BIBLIOTECA \n");
        printf("1. Registrar libro\n");
        printf("2. Mostrar libros\n");
        printf("3. Buscar libro por ID\n");
        printf("4. Buscar libro por titulo\n");
        printf("5. Actualizar estado\n");
        printf("6. Eliminar libro\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");

        opc = ValidarIntconRango(1, 7);

        switch(opc) {

            case 1:
                registrarLibro();
                break;

            case 2:
                mostrarLibros();
                break;

            case 3:
                buscarPorID();
                break;

            case 4:
                buscarPorTitulo();
                break;

            case 5:
                actualizarEstado();
                break;

            case 6:
                eliminarLibro();
                break;

            case 7:
                printf("\nSaliendo del programa\n");
                break;
        }

        printf("Desea seleccionar otra opcion 1.Si/2.No: ");
        opc2 = ValidarIntconRango(1,2);

    } while(opc2 == 1);

    printf("\nPrograma finalizado.\n");
}

