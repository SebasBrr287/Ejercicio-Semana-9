#include <stdio.h>
#include <string.h>

// Estructura
struct Libro {

    int id;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[15];
};

// Variables globales
extern struct Libro biblioteca[10];
extern int totalLibros;

// Prototipos
int ValidarIntconRango(int a, int b);
void leerCadena(char cadena[], int n);

int idExiste(int id);

void registrarLibro();
void mostrarLibros();

void buscarPorID();
void buscarPorTitulo();

void actualizarEstado();

void eliminarLibro();

void menu();