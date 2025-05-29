#include <stdio.h>
#include <string.h>
#include "funciones.h"

void mostrarMenu()
{
    printf("\n=== SISTEMA DE CITAS - PELUQUERÍA CANINA ===\n");
    printf("1. Registrar cita\n");
    printf("2. Buscar por fecha\n");
    printf("3. Buscar por cliente\n");
    printf("4. Mostrar todas las citas\n");
    printf("5. Salir\n");
    printf("Seleccione una opcion: ");
}

void registrarCita(char nombres[][50], char fechas[][11], int *cantidad)
{
    if (*cantidad >= 100)
    {
        printf("No se pueden registrar más citas. Límite alcanzado.\n");
        return;
    }

    printf("\n--- REGISTRAR NUEVA CITA ---\n");

    printf("Ingrese el nombre del cliente: ");
    limpiarBuffer();
    fgets(nombres[*cantidad], 50, stdin);
    nombres[*cantidad][strcspn(nombres[*cantidad], "\n")] = 0;

    char fecha[11];
    printf("Ingrese la fecha (dd/mm/aaaa): ");
    fgets(fecha, 11, stdin);
    fecha[strcspn(fecha, "\n")] = 0;

    if (!validarFormatoFecha(fecha))
    {
        printf("Fecha inválida. Debe tener el formato dd/mm/aaaa.\n");
        return;
    }

    strcpy(fechas[*cantidad], fecha);
    (*cantidad)++;
    printf("Cita registrada exitosamente.\n");
}

void buscarPorFecha(char nombres[][50], char fechas[][11], int cantidad)
{
    if (cantidad == 0)
    {
        printf("No hay citas registradas.\n");
        return;
    }

    char fechaBuscada[11];
    printf("\n--- BUSCAR CITAS POR FECHA ---\n");
    limpiarBuffer();
    printf("Ingrese la fecha (dd/mm/aaaa): ");
    fgets(fechaBuscada, 11, stdin);
    fechaBuscada[strcspn(fechaBuscada, "\n")] = 0;

    int encontrado = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (strcmp(fechas[i], fechaBuscada) == 0)
        {
            printf("Cliente: %s - Fecha: %s\n", nombres[i], fechas[i]);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        printf("No se encontraron citas para esa fecha.\n");
    }
}

void buscarPorCliente(char nombres[][50], char fechas[][11], int cantidad)
{
    if (cantidad == 0)
    {
        printf("No hay citas registradas.\n");
        return;
    }

    char clienteBuscado[50];
    printf("\n--- BUSCAR CITAS POR CLIENTE ---\n");
    limpiarBuffer();
    printf("Ingrese el nombre del cliente: ");
    fgets(clienteBuscado, 50, stdin);
    clienteBuscado[strcspn(clienteBuscado, "\n")] = 0;

    int encontrado = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (strcmp(nombres[i], clienteBuscado) == 0)
        {
            printf("Cliente: %s - Fecha: %s\n", nombres[i], fechas[i]);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        printf("No se encontraron citas para ese cliente.\n");
    }
}

void mostrarTodasLasCitas(char nombres[][50], char fechas[][11], int cantidad)
{
    if (cantidad == 0)
    {
        printf("No hay citas registradas.\n");
        return;
    }

    printf("\n--- LISTADO DE TODAS LAS CITAS ---\n");
    printf("%-4s %-30s %-12s\n", "No", "Nombre del Cliente", "Fecha");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < cantidad; i++)
    {
        printf("%-4d %-30s %-12s\n", i + 1, nombres[i], fechas[i]);
    }
}

int validarFormatoFecha(char fecha[])
{
    if (strlen(fecha) != 10)
        return 0;
    if (fecha[2] != '/' || fecha[5] != '/')
        return 0;
    return 1;
}

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
