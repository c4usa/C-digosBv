#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char nombre[5][30], materia[5][15];
    int aux;
    float notas[5][3], PromedioE, PromediosM;
    int cont = 0, cont1 = 0, opc, len;
    do
    {
        printf("-------------------------------------------\n");
        printf("1.Registrar Estudiante.\n");
        printf("2.Registrar materias estudiantes.\n");
        printf("3.Ingrese las notas de los estudiantes.\n");
        printf("4.Ver promedio de notas de los estudiantes.\n");
        printf("5.Ver estadisticas por asignatura\n");
        printf("6.Salir del sistema.\n");
        printf("-------------------------------------------\n");
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
                int valido;
                do
                {
                    valido = 1;
                    printf("Ingrese el nombre del estudiante %d:\n", cont);
                    fgets(nombre[cont], 30, stdin);
                    len = strlen(nombre[cont]) - 1;
                    if (nombre[cont][len] == '\n')
                        nombre[cont][len] = '\0';
                    for (int i = 0; nombre[cont][i] != '\0'; i++)
                    {
                        if (!((nombre[cont][i] >= 'A' && nombre[cont][i] <= 'Z') ||
                              (nombre[cont][i] >= 'a' && nombre[cont][i] <= 'z') ||
                              nombre[cont][i] == ' '))
                        {
                            valido = 0;
                            printf("Nombre inválido. Use solo letras y espacios.\n");
                            break;
                        }
                    }
                } while (!valido);
                cont++;
            }
            else
            {
                printf("Haz alcanzado el maximo de estudiantes.\n");
            }
            break;
        case 2:
            if (cont1 < 3)
            {
                int valido;
                do
                {
                    valido = 1;
                    printf("Ingrese la materia %d que quiere registrar:\n", cont1);
                    fgets(materia[cont1], 15, stdin);
                    len = strlen(materia[cont1]) - 1;
                    if (materia[cont1][len] == '\n')
                        materia[cont1][len] = '\0';
                    for (int i = 0; materia[cont1][i] != '\0'; i++)
                    {
                        if (!((materia[cont1][i] >= 'A' && materia[cont1][i] <= 'Z') ||
                              (materia[cont1][i] >= 'a' && materia[cont1][i] <= 'z') ||
                              materia[cont1][i] == ' '))
                        {
                            valido = 0;
                            printf("Materia inválida. Use solo letras y espacios.\n");
                            break;
                        }
                    }
                } while (!valido);
                cont1++;
            }
            else
            {
                printf("Maximo de materias Ingresadas.\n");
            }
            break;
        case 3:
            if (cont == 0 || cont1 == 0)
            {
                printf("Es necesario ingresar Estudiantes y notas\n");
            }
            else
            {
                for (int i = 0; i < cont; i++)
                {
                    printf("Ingrese las notas del estudiante %s:\n", nombre[i]);
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
                                while (getchar() != '\n')
                                    ;
                            }
                        } while (validar != 1 || nota < 0 || nota > 10);
                        notas[i][j] = nota;
                    }
                }
                printf("Lista\t\tEstudiante\t\t");
                for (int j = 0; j < cont1; j++)
                {
                    printf("%s\t\t", materia[j]);
                }
                printf("\n");
                for (int i = 0; i < cont; i++)
                {
                    printf("%d\t\t%s\t\t", i + 1, nombre[i]);
                    for (int j = 0; j < cont1; j++)
                    {
                        printf("\t\t%.2f", notas[i][j]);
                    }
                    printf("\n");
                }
            }
            break;
        case 4:
            if (cont == 0 || cont1 == 0)
            {
                printf("Es necesario ingresar Estudiantes y notas\n");
            }
            else
            {
                printf("\n=============== REPORTE DE NOTAS CON PROMEDIOS ==========\n");
                printf("Lista\t\tEstudiante\t\t");
                for (int j = 0; j < cont1; j++)
                {
                    printf("%s\t\t", materia[j]);
                }
                printf("Promedio\n");
                for (int i = 0; i < cont; i++)
                {
                    float sumaEstudiante = 0;
                    printf("%d\t\t%s\t\t", i + 1, nombre[i]);
                    for (int j = 0; j < cont1; j++)
                    {
                        printf("%.2f\t\t", notas[i][j]);
                        sumaEstudiante += notas[i][j];
                    }
                    PromedioE = sumaEstudiante / cont1;
                    printf("%.2f\n", PromedioE);
                }
                printf("-------------------------------------------------------------------------------\n");
                printf("Promedio\t\t\t");
                for (int j = 0; j < cont1; j++)
                {
                    float sumaMateria = 0;
                    for (int i = 0; i < cont; i++)
                    {
                        sumaMateria += notas[i][j];
                    }
                    PromediosM = sumaMateria / cont;
                    printf("%.2f\t\t", PromediosM);
                }
                printf("\n");
            }
            break;
        case 5:
            if (cont == 0 || cont1 == 0)
            {
                printf("Es necesario ingresar Estudiantes y notas\n");
            }
            else
            {
                printf("Lista\t\tEstudiante\t\t");
                for (int j = 0; j < cont1; j++)
                {
                    printf("%s\t\t", materia[j]);
                }
                printf("Promedio\n");
                for (int i = 0; i < cont; i++)
                {
                    float sumaEstudiante = 0;
                    printf("%d\t\t%s\t\t", i + 1, nombre[i]);
                    for (int j = 0; j < cont1; j++)
                    {
                        printf("%.2f\t\t", notas[i][j]);
                        sumaEstudiante += notas[i][j];
                    }
                    PromedioE = sumaEstudiante / cont1;
                    printf("%.2f\n", PromedioE);
                }
                printf("-------------------------------------------------------------------------------\n");
                printf("Promedio\t\t\t");
                for (int j = 0; j < cont1; j++)
                {
                    float sumaMateria = 0;
                    for (int i = 0; i < cont; i++)
                    {
                        sumaMateria += notas[i][j];
                    }
                    PromediosM = sumaMateria / cont;
                    printf("%.2f\t\t", PromediosM);
                }
                printf("\n");
                printf("\n=============== ESTADO POR MATERIA ===============\n");
                for (int j = 0; j < cont1; j++)
                {
                    printf("\nMateria: %s\n", materia[j]);
                    for (int i = 0; i < cont; i++)
                    {
                        printf("Estudiante: %s - Nota: %.2f - ", nombre[i], notas[i][j]);
                        if (notas[i][j] >= 7.0)
                            printf("APROBADO\n");
                        else
                            printf("REPROBADO\n");
                    }
                }
                printf("\n=============== NOTAS EXTREMAS POR MATERIA ===============\n");
                for (int j = 0; j < cont1; j++)
                {
                    float notaAlta = notas[0][j];
                    float notaBaja = notas[0][j];
                    int idxAlta = 0, idxBaja = 0;
                    for (int i = 1; i < cont; i++)
                    {
                        if (notas[i][j] > notaAlta)
                        {
                            notaAlta = notas[i][j];
                            idxAlta = i;
                        }
                        if (notas[i][j] < notaBaja)
                        {
                            notaBaja = notas[i][j];
                            idxBaja = i;
                        }
                    }
                    printf("Materia: %s\n", materia[j]);
                    printf("  Nota más alta: %.2f - Estudiante: %s\n", notaAlta, nombre[idxAlta]);
                    printf("  Nota más baja: %.2f - Estudiante: %s\n", notaBaja, nombre[idxBaja]);
                }
            }
            break;
        default:
            break;
        }
    } while (opc != 6);
    printf("Saliendo del sistema educacional.");
    return 0;
}
