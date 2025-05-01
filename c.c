//Se desea desarrollar un programa que me permita conocer el ganador de un torneo de box, en los cuales participaran 6 competidores
//La primera etapa consistira en llaves establecidas
//La segunda etapa que sera la final sera entre aquellos competidores que allan alcanzado los dos mejhores puntajes.
//Los puntos se asiganaran de la siguiente manera
//Gnador de combate 1pto
//Y si la ganancia es por knockout 3 puntos
//Ingresar los nombres de los competidores verificar valores

#include <stdio.h>
#include <string.h>
int nombreExiste(char nombres[][50], int cantidad, char nombre[]) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nombre) == 0) 
        {
            return 1;
        }
    }
    return 0;
}
int leerEntero(int minimo, int maximo) 
{
    int valor;
    int resultado;
    do {
        resultado = scanf("%d", &valor);
        while (getchar() != '\n');
        if (resultado != 1 || valor < minimo || valor > maximo) {
            printf("Entrada inválida. Ingrese un número entre %d y %d: ", minimo, maximo);
        }
    } while (resultado != 1 || valor < minimo || valor > maximo);
    return valor;
}
void ingresarCompetidores(char nombres[][50], int puntos[], int total) {
    char nombreTemporal[50];
    for (int i = 0; i < total;) {
        printf("Ingrese el nombre del boxeador #%d: ", i);
        fgets(nombreTemporal, 50 , stdin);
        nombreTemporal[strcspn(nombreTemporal, "\n")] = '\0';
        if (strlen(nombreTemporal) == 0) {
            printf("El nombre no puede estar vacío.\n");
        } else if (nombreExiste(nombres, i, nombreTemporal)) {
            printf("Ese nombre ya fue ingresado. Intente con otro.\n");
        } else {
            strcpy(nombres[i], nombreTemporal);
            puntos[i] = 0;
            i++;
        }
    }
}
void combatesIniciales(char nombres[][50], int puntos[], int total) {
    int ganador, knockout;
    for (int i = 0; i < total; i += 2) {
        printf("\nCombate entre %s y %s\n", nombres[i], nombres[i + 1]);
        printf("Ingrese 1 si gana %s o 2 si gana %s: ", nombres[i], nombres[i + 1]);
        ganador = leerEntero(1, 2);
        printf("¿Fue por knockout? (1 = Sí, 0 = No): ");
        knockout = leerEntero(0, 1);
         if (knockout == 1) {
    puntos[i + 1] += 3;
         } else {
    puntos[i + 1] += 1;
}

    }
}
int encontrarFinalista1(int puntos[], int total) {
    int maxPuntos = -1;
    int indice = -1;
    for (int i = 0; i < total; i++) {
        if (puntos[i] > maxPuntos) {
            maxPuntos = puntos[i];
            indice = i;
        }
    }
    return indice;
}
int encontrarFinalista2(int puntos[], int total, int finalista1) {
    int maxPuntos = -1;
    int indice = -1;
    for (int i = 0; i < total; i++) {
        if (i != finalista1 && puntos[i] > maxPuntos) {
            maxPuntos = puntos[i];
            indice = i;
        }
    }
    return indice;
}
void combateFinal(char nombres[][50], int f1, int f2) {
    int ganador;
    printf("\nFINAL: %s vs %s\n", nombres[f1], nombres[f2]);
    printf("Ingrese 1 si gana %s o 2 si gana %s: ", nombres[f1], nombres[f2]);
    ganador = leerEntero(1, 2);
    if (ganador == 1) {
        printf("¡El ganador del torneo es: %s!\n", nombres[f1]);
    } else {
        printf("¡El ganador del torneo es: %s!\n", nombres[f2]);
    }
}
int main() {
    int totalCompetidores = 6;
    char nombres[6][50];
    int puntos[6];
    ingresarCompetidores(nombres, puntos, totalCompetidores);
    combatesIniciales(nombres, puntos, totalCompetidores);
    int finalista1 = encontrarFinalista1(puntos, totalCompetidores);
    int finalista2 = encontrarFinalista2(puntos, totalCompetidores, finalista1);
    combateFinal(nombres, finalista1, finalista2);
    return 0;
}
