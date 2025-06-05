#include <stdio.h>
#include <string.h>
#include "funciones.h"
int menu()
{
    int opc = 0;
    printf("Seleccione una opcion:\n");
    printf("1. Ingresar Estudiantes:\n");
    printf("Imprimir Estudiante:\n");
    printf(">>");
    return opc;
}
void leerCadena(char *cadena, int num)
{
    fflush(stdin);
    fgets(cadena, num, stdin);
    int len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

void crearMaterias(struct Materia materias[3], int cont)
{
    for (int i = 0; i < cont; i++)
    {
        printf("Ingrese el codigo de materias %d: ", i + 1);
        leerCadena(materias[i].codigo, 10);
        printf("Ingrese el nombre de la materia %d: ", i + 1);
        leerCadena(materias[i].nombre, 10);
        printf("Ingrese las calificaciones:\n");
        printf("Nota 1: ");
        scanf("%f", &materias[i].notas[0]);
        printf("Ingrese las calificaciones:\n");
        printf("Nota 2: ");
        scanf("%f", &materias[i].notas[1]);
        printf("Ingrese las calificaciones:\n");
        printf("Nota 3: ");
        scanf("%f", &materias[i].notas[2]);
        materias[i].promedio = (materias[i].notas[0] +
                                materias[i].notas[1] +
                                materias[i].notas[2]) /
                               3;
    }
}

void crearEstudiante(struct Estudiante estudiantes[3], int cont)
{
    printf("Ingrese el codigo del estudante %d: ", cont + 1);
    leerCadena(estudiantes[cont].codigo, 10);
    printf("Ingrese el nombre del estudiante %d: ", cont + 1);
    leerCadena(estudiantes[cont].nombre, 30);
    printf("Ingrese la edad del estudiante %d: ", cont + 1);
    scanf("%d", &estudiantes[cont].edad);
    printf("Ingese el numero de materias a asignar al estudiatne %d: ", cont + 1);
    scanf("%d", &estudiantes[cont].numMaterias);
    crearMaterias(estudiantes[cont].materias, estudiantes[cont].numMaterias);
}

void imprimirMaterias(struct Materia materias[3], int cont)
{
    for (int i = 0; i < cont; i++)
    {
        printf("Codigo de materias %d: ", i + 1, materias[i].codigo);
        printf("Nombres de los estudiantes %d:", cont + 1, materias[i].nombre);
        printf("Calificaciones");
        printf("Nota 1: %d", materias[i].notas[0]);
        printf("Nota 2: %d", materias[i].notas[1]);
        printf("Nota 3: %d", materias[i].notas[2]);
        printf("Promedio: %d", materias[i].promedio);
    }
}

void imprimirEstudiantes(struct Estudiante estudiantes[3], int cont)
{
    for (int i = 0; i < cont; i++)
    {
        printf("Codigo del estudiante %d es %s", cont+1, estudiantes[cont].codigo);
        printf("EL nombre del estudiante %d es %s:", cont+1,estudiantes[cont].nombre);
        printf("La materia %d es %s:", cont+1,estudiantes[cont].materias);

    }
    

}