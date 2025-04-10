#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char nombre[5][30], materia[5][15];
    float notas[5][3], suma = 0;
    int aprobados = 0, cont = 0, cont1 = 0, opc, len;

    do
    {
        printf("----------------------\n");
        printf("1. Registrar Estudiante\n");
        printf("2. Registrar Materias de Estudiantes\n");
        printf("3. Registrar Notas\n");
        printf("4. Ver Promedio de Notas por Estudiante\n");
        printf("5. Ver Estadísticas por Asignatura\n");
        printf("6. Salir\n");
        printf("----------------------\n");
        printf(">>");
        scanf("%d", &opc);
        getchar();

        if (opc < 1 || opc > 6)
        {
            printf("Opción inválida. Intente nuevamente.\n");
            continue;
        }
        switch (opc)
        {
        case 1:
            if (cont < 5)
            {
                printf("Ingrese el nombre del estudiante %d:\n", cont);
                fgets(nombre[cont], 30, stdin);
                len = strlen(nombre[cont]) - 1;
                if (nombre[cont][len] == '\n')
                    nombre[cont][len] = '\0';
                cont++;
            }
            else
            {
                printf("Has alcanzado el máximo de estudiantes.\n");
            }
            break;
            
        case 2:
            if (cont1 < 3)
            {
                printf("Ingrese la materia %d:\n", cont1);
                fgets(materia[cont1], 15, stdin);
                len = strlen(materia[cont1]) - 1;
                if (materia[cont1][len] == '\n')
                    materia[cont1][len] = '\0';
                cont1++;
            }
            else
            {
                printf("Máximo de materias ingresadas.\n");
            }
            break;

        case 3:
            if (cont == 0 || cont1 == 0)
            {
                printf("Es necesario ingresar Estudiantes y Materias.\n");
            }
            else
            {
                for (int i = 0; i < cont; i++)
                {
                    printf("Ingrese las notas del estudiante %d %s:\n", i, nombre[i]);
                    for (int j = 0; j < cont1; j++)
                    {
                        float nota;
                        int validar;
                        do
                        {
                            printf("Nota en %s: ", materia[j]);
                            validar = scanf("%f", &nota);
                            getchar();
                            if (validar != 1 || nota < 0 || nota > 10)
                            {
                                printf("Nota inválida. Ingrese un número entre 0 y 10.\n");
                                while (getchar() != '\n'); 
                            }
                        } while (validar != 1 || nota < 0 || nota > 10);
                        notas[i][j] = nota;
                    }
                }
            }
            break;

        case 4:
            for (int i = 0; i < cont; i++)
            {
                suma = 0;
                for (int j = 0; j < cont1; j++)
                {
                    suma += notas[i][j];
                }
                if (cont1 > 0)
                    printf("Promedio de %s: %.2f\n", nombre[i], suma / cont1);
            }
            break;

        case 5:
            if (cont == 0 || cont1 == 0)
            {
                printf("No hay datos suficientes para mostrar estadísticas.\n");
            }
            else
            {
                printf("\nEstadísticas por materia:\n");
                printf("Materia\t\tMejor Nota\t\tPeor Nota\t\tAprobados\n");

                for (int i = 0; i < cont1; i++)
                {
                    float maximo = notas[0][i];
                    float minimo = notas[0][i];
                    suma = 0;
                    aprobados = 0;

                    for (int j = 0; j < cont; j++)
                    {
                        float nota = notas[j][i];
                        suma += nota;
                        if (nota > maximo)
                        {
                            maximo = nota;
                        }
                        if (nota < minimo)
                        {
                            minimo = nota;
                        }
                        if (nota >= 6)
                        {
                            aprobados++;
                        }
                    }
                    printf("%s\t\t%.2f\t\t%.2f\t\t%d\n", materia[i], maximo, minimo, aprobados);
                }
            }
            break;

        case 6:
            printf("Saliendo del sistema educacional.\n");
            break;

        default:
            printf("Opción inválida. Intente nuevamente.\n");
            break;
        }

    } while (opc != 6);

    return 0;
}
