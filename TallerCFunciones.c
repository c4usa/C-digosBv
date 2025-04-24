#include <stdio.h>
#include <string.h>
#define MAX_ESTUDIANTES 5
#define MAX_MATERIAS 5
char nombre[MAX_ESTUDIANTES][30];
char materia[MAX_MATERIAS][15];
float notas[MAX_ESTUDIANTES][MAX_MATERIAS];
int cont = 0, cont1 = 0;
void limpiarBuffer() {
    while (getchar() != '\n');
}
int esTextoValido(char texto[]) {
    for (int i = 0; texto[i] != '\0'; i++) {
        if (!((texto[i] >= 'A' && texto[i] <= 'Z') ||
              (texto[i] >= 'a' && texto[i] <= 'z') ||
              texto[i] == ' ')) {
            return 0;
        }
    }
    return 1;
}
void registrarEstudiante() {
    if (cont < MAX_ESTUDIANTES) {
        int valido;
        do {
            valido = 1;
            printf("Ingrese el nombre del estudiante %d:\n", cont);
            fgets(nombre[cont], 30, stdin);
            int len = strlen(nombre[cont]) - 1;
            if (nombre[cont][len] == '\n')
                nombre[cont][len] = '\0';
            if (!esTextoValido(nombre[cont])) {
                printf("Nombre inválido. Use solo letras y espacios.\n");
                valido = 0;
            }
        } while (!valido);
        cont++;
    } else {
        printf("Haz alcanzado el maximo de estudiantes.\n");
    }
}
void registrarMateria() {
    if (cont1 < MAX_MATERIAS) {
        int valido;
        do {
            valido = 1;
            printf("Ingrese la materia %d que quiere registrar:\n", cont1);
            fgets(materia[cont1], 15, stdin);
            int len = strlen(materia[cont1]) - 1;
            if (materia[cont1][len] == '\n')
                materia[cont1][len] = '\0';

            if (!esTextoValido(materia[cont1])) {
                printf("Materia inválida. Use solo letras y espacios.\n");
                valido = 0;
            }
        } while (!valido);
        cont1++;
    } else {
        printf("Máximo de materias ingresadas.\n");
    }
}
void ingresarNotas() {
    if (cont == 0 || cont1 == 0) {
        printf("Es necesario ingresar Estudiantes y Materias primero.\n");
        return;
    }
    for (int i = 0; i < cont; i++) {
        printf("Ingrese las notas del estudiante %s:\n", nombre[i]);
        for (int j = 0; j < cont1; j++) {
            float nota;
            int valido;
            do {
                printf("Nota en %s: ", materia[j]);
                valido = scanf("%f", &nota);
                limpiarBuffer();
                if (valido != 1 || nota < 0 || nota > 10) {
                    printf("Nota inválida. Ingrese un número entre 0 y 10.\n");
                    valido = 0;
                }
            } while (!valido);
            notas[i][j] = nota;
        }
    }
}

void verPromedioEstudiantes() {
    if (cont == 0 || cont1 == 0) {
        printf("Es necesario ingresar Estudiantes y Notas primero.\n");
        return;
    }
    printf("\n=============== REPORTE DE NOTAS CON PROMEDIOS ==========\n");
    printf("Lista\tEstudiante\t\t");
    for (int j = 0; j < cont1; j++) {
        printf("%s\t", materia[j]);
    }
    printf("Promedio\n");
    for (int i = 0; i < cont; i++) {
        float suma = 0;
        printf("%d\t%s\t\t", i + 1, nombre[i]);
        for (int j = 0; j < cont1; j++) {
            printf("%.2f\t", notas[i][j]);
            suma += notas[i][j];
        }
        printf("%.2f\n", suma / cont1);
    }
    printf("-------------------------------------------------------------------------------\n");
    printf("Promedio\t\t\t");
    for (int j = 0; j < cont1; j++) {
        float suma = 0;
        for (int i = 0; i < cont; i++) {
            suma += notas[i][j];
        }
        printf("%.2f\t", suma / cont);
    }
    printf("\n");
}
void estadisticasMateria() {
    if (cont == 0 || cont1 == 0) {
        printf("Es necesario ingresar Estudiantes y Notas primero.\n");
        return;
    }
    printf("\n=============== ESTADO POR MATERIA ===============\n");
    for (int j = 0; j < cont1; j++) {
        printf("\nMateria: %s\n", materia[j]);
        for (int i = 0; i < cont; i++) {
            printf("Estudiante: %s - Nota: %.2f - ", nombre[i], notas[i][j]);
            if (notas[i][j] >= 7.0)
                printf("APROBADO\n");
            else
                printf("REPROBADO\n");
        }
    }
    printf("\n=============== NOTAS EXTREMAS POR MATERIA ===============\n");
    for (int j = 0; j < cont1; j++) {
        float notaAlta = notas[0][j];
        float notaBaja = notas[0][j];
        int idxAlta = 0, idxBaja = 0;

        for (int i = 1; i < cont; i++) {
            if (notas[i][j] > notaAlta) {
                notaAlta = notas[i][j];
                idxAlta = i;
            }
            if (notas[i][j] < notaBaja) {
                notaBaja = notas[i][j];
                idxBaja = i;
            }
        }
        printf("Materia: %s\n", materia[j]);
        printf("  Nota más alta: %.2f - Estudiante: %s\n", notaAlta, nombre[idxAlta]);
        printf("  Nota más baja: %.2f - Estudiante: %s\n", notaBaja, nombre[idxBaja]);
    }
}


int main() {
    int opc;
    do {
        printf("\n-------------------------------------------\n");
        printf("1. Registrar Estudiante\n");
        printf("2. Registrar Materias\n");
        printf("3. Ingresar Notas\n");
        printf("4. Ver Promedios\n");
        printf("5. Ver Estadísticas por Materia\n");
        printf("6. Salir\n");
        printf("-------------------------------------------\n>> ");
        scanf("%d", &opc);
        limpiarBuffer();
        switch (opc) {
            case 1: registrarEstudiante(); break;
            case 2: registrarMateria(); break;
            case 3: ingresarNotas(); break;
            case 4: verPromedioEstudiantes(); break;
            case 5: estadisticasMateria(); break;
            case 6: printf("Saliendo del sistema educacional.\n"); break;
            default: printf("Opción inválida. Intente nuevamente.\n"); break;
        }
    } while (opc != 6);
    return 0;
}
