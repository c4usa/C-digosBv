#include <stdio.h>
#include <string.h>

#define NUM_EQUIPOS 4

int main()
{
    char equipos[NUM_EQUIPOS][30], temp_nombre[30];
    int puntos[NUM_EQUIPOS] = {0};
    int goles_favor[NUM_EQUIPOS] = {0};
    int goles_contra[NUM_EQUIPOS] = {0};
    int diferencia_goles[NUM_EQUIPOS] = {0};
    int goles1, goles2;

    for (int i = 0; i < NUM_EQUIPOS; i++)
    {
        printf("Ingrese el nombre del equipo %d: ", i + 1);
        fgets(equipos[i], 30, stdin);
        equipos[i][strcspn(equipos[i], "\n")] = '\0';
        if (strlen(equipos[i]) == 0)
        {
            printf("Error: Nombre de equipo no puede estar vacío. Inténtelo de nuevo.\n");
            i--;
        }
    }

    for (int i = 0; i < NUM_EQUIPOS; i++)
    {
        for (int j = i + 1; j < NUM_EQUIPOS; j++)
        {
            printf("Ingrese los goles de %s contra %s: ", equipos[i], equipos[j]);
            while (scanf("%d %d", &goles1, &goles2) != 2 || goles1 < 0 || goles2 < 0)
            {
                printf("Error: Ingrese valores numéricos válidos (mayores o iguales a 0).\n");
                while (getchar() != '\n')
                    ;
                printf("Ingrese los goles de %s contra %s nuevamente: ", equipos[i], equipos[j]);
            }
            getchar();

            goles_favor[i] += goles1;
            goles_contra[i] += goles2;
            goles_favor[j] += goles2;
            goles_contra[j] += goles1;

            if (goles1 > goles2)
            {
                puntos[i] += 3;
            }
            else if (goles1 < goles2)
            {
                puntos[j] += 3;
            }
            else
            {
                puntos[i] += 1;
                puntos[j] += 1;
            }
        }
    }

    for (int i = 0; i < NUM_EQUIPOS; i++)
    {
        diferencia_goles[i] = goles_favor[i] - goles_contra[i];
    }

    for (int i = 0; i < NUM_EQUIPOS - 1; i++)
    {
        for (int j = i + 1; j < NUM_EQUIPOS; j++)
        {
            if (puntos[j] > puntos[i] ||
                (puntos[j] == puntos[i] && diferencia_goles[j] > diferencia_goles[i]))
            {
                int temp_puntos = puntos[i];
                puntos[i] = puntos[j];
                puntos[j] = temp_puntos;

                int temp_goles_favor = goles_favor[i];
                goles_favor[i] = goles_favor[j];
                goles_favor[j] = temp_goles_favor;
                int temp_goles_contra = goles_contra[i];
                goles_contra[i] = goles_contra[j];
                goles_contra[j] = temp_goles_contra;

                int temp_diferencia = diferencia_goles[i];
                diferencia_goles[i] = diferencia_goles[j];
                diferencia_goles[j] = temp_diferencia;

                strcpy(temp_nombre, equipos[i]);
                int k;
                for (k = 0; k < 30; k++)
                {
                    equipos[i][k] = equipos[j][k];
                }
                for (k = 0; k < 30; k++)
                {
                    equipos[j][k] = temp_nombre[k];
                }
            }
        }
    }

    printf("\nTabla de posiciones:\n");
    printf("Equipo\tPuntos\tGF\tGC\tDG\n");
    for (int i = 0; i < NUM_EQUIPOS; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\n", equipos[i], puntos[i], goles_favor[i], goles_contra[i], diferencia_goles[i]);
    }

    printf("\nLos equipos que jugarán la final son:\n1. %s\n2. %s\n", equipos[0], equipos[1]);

    return 0;
}


