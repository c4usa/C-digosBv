#include <stdio.h> #include <string.h>

int nombreExiste(char nombres[][50], int cantidad, char nombre[]) { for (int i = 0; i < cantidad; i++) { if (strcmp(nombres[i], nombre) == 0) return 1; } return 0; }

int leerEntero(int minimo, int maximo) { int valor; int resultado; do { resultado = scanf("%d", &valor); while (getchar() != '\n'); if (resultado != 1 || valor < minimo || valor > maximo) { printf("Entrada inválida. Ingrese un número entre %d y %d: ", minimo, maximo); } } while (resultado != 1 || valor < minimo || valor > maximo); return valor; }

void ingresarCompetidores(char nombres[][50], int puntos[], int total) { char nombreTemporal[50]; for (int i = 0; i < total;) { printf("Ingrese el nombre del boxeador #%d: ", i + 1); if (fgets(nombreTemporal, sizeof(nombreTemporal), stdin) == NULL) continue; nombreTemporal[strcspn(nombreTemporal, "\n")] = '\0'; if (strlen(nombreTemporal) == 0) { printf("El nombre no puede estar vacío.\n"); } else if (nombreExiste(nombres, i, nombreTemporal)) { printf("Ese nombre ya fue ingresado. Intente con otro.\n"); } else { strcpy(nombres[i], nombreTemporal); puntos[i] = 0; i++; } } }

void combatesIniciales(char nombres[][50], int puntos[], int total) { for (int i = 0; i < total; i += 2) { int ganador, knockout; printf("\nCombate entre %s y %s\n", nombres[i], nombres[i + 1]); printf("Ingrese 1 si gana %s o 2 si gana %s: ", nombres[i], nombres[i + 1]); ganador = leerEntero(1, 2); printf("¿Fue por knockout? (1 = Sí, 0 = No): "); knockout = leerEntero(0, 1); int idx = (ganador == 1) ? i : i + 1; puntos[idx] += (knockout ? 3 : 1); } }

void empateDesempate(int indices[], int *count, char nombres[][50]) { while (*count > 2) { int a = indices[0]; int b = indices[1]; printf("\nDesempate entre %s y %s\n", nombres[a], nombres[b]); printf("Ingrese 1 si gana %s o 2 si gana %s: ", nombres[a], nombres[b]); int ganador = leerEntero(1, 2); int ganadorIdx = (ganador == 1) ? a : b; int nuevos[6]; int pos = 0; nuevos[pos++] = ganadorIdx; for (int i = 2; i < *count; i++) { nuevos[pos++] = indices[i]; } for (int i = 0; i < pos; i++) indices[i] = nuevos[i]; *count = pos; } }

int main() { const int total = 6; char nombres[6][50]; int puntos[6];

ingresarCompetidores(nombres, puntos, total);
combatesIniciales(nombres, puntos, total);

// Encontrar primer puntuación máxima
int max1 = -1;
for (int i = 0; i < total; i++) {
    if (puntos[i] > max1) max1 = puntos[i];
}
int emp1[6], cnt1 = 0;
for (int i = 0; i < total; i++) {
    if (puntos[i] == max1) emp1[cnt1++] = i;
}
if (cnt1 > 2) empateDesempate(emp1, &cnt1, nombres);

int finalistas[2];
if (cnt1 == 2) {
    finalistas[0] = emp1[0];
    finalistas[1] = emp1[1];
} else {
    finalistas[0] = emp1[0];
    // Buscar segundo lugar
    int max2 = -1;
    for (int i = 0; i < total; i++) {
        if (i != finalistas[0] && puntos[i] > max2) max2 = puntos[i];
    }
    int emp2[6], cnt2 = 0;
    for (int i = 0; i < total; i++) {
        if (i != finalistas[0] && puntos[i] == max2) emp2[cnt2++] = i;
    }
    if (cnt2 > 1) empateDesempate(emp2, &cnt2, nombres);
    finalistas[1] = emp2[0];
}

// Combate final
printf("\nFINAL: %s vs %s\n", nombres[finalistas[0]], nombres[finalistas[1]]);
printf("Ingrese 1 si gana %s o 2 si gana %s: ", nombres[finalistas[0]], nombres[finalistas[1]]);
int g = leerEntero(1, 2);
printf("¡El ganador del torneo es: %s!\n", nombres[(g == 1) ? finalistas[0] : finalistas[1]]);

return 0;

}

