#include <stdio.h>
#include <string.h>
#include "funciones.h"

void mostrarMenu()
{
    printf("\n=== SISTEMA DE COMPRA Y VENTA DE VEHICULOS ===\n");
    printf("1. Agregar vehiculo\n");
    printf("2. Vender vehiculo\n");
    printf("3. Buscar vehiculo por cedula del dueno\n");
    printf("4. Salir\n");
    printf("Seleccione una opcion: ");
}

void agregarVehiculo(char nombres[][50], char cedulas[][15], char placas[][10], int estados[], int *cantidad)
{
    if (*cantidad >= 100)
    {
        printf("No se pueden agregar mas vehiculos. Limite alcanzado.\n");
        return;
    }

    printf("\n--- AGREGAR NUEVO VEHICULO ---\n");

    printf("Ingrese el nombre del dueno: ");
    limpiarBuffer();
    fgets(nombres[*cantidad], 50, stdin);
    nombres[*cantidad][strcspn(nombres[*cantidad], "\n")] = 0;

    printf("Ingrese la cedula del dueno: ");
    fgets(cedulas[*cantidad], 15, stdin);
    cedulas[*cantidad][strcspn(cedulas[*cantidad], "\n")] = 0;

    if (!validarCedulaUnica(cedulas, *cantidad, cedulas[*cantidad]))
    {
        printf("Error: Ya existe un vehiculo registrado con esta cedula.\n");
        return;
    }

    printf("Ingrese la placa del vehiculo: ");
    fgets(placas[*cantidad], 10, stdin);
    placas[*cantidad][strcspn(placas[*cantidad], "\n")] = 0;

    if (!validarPlacaUnica(placas, *cantidad, placas[*cantidad]))
    {
        printf("Error: Ya existe un vehiculo registrado con esta placa.\n");
        return;
    }

    estados[*cantidad] = 0;

    (*cantidad)++;

    printf("Vehiculo agregado exitosamente!\n");
}

void venderVehiculo(char nombres[][50], char cedulas[][15], char placas[][10], int estados[], int cantidad)
{
    if (cantidad == 0)
    {
        printf("No hay vehiculos registrados.\n");
        return;
    }

    char placa[10];
    printf("\n--- VENDER VEHICULO ---\n");
    printf("Ingrese la placa del vehiculo a vender: ");
    limpiarBuffer();
    fgets(placa, 10, stdin);
    placa[strcspn(placa, "\n")] = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (strcmp(placas[i], placa) == 0)
        {
            if (estados[i] == 1)
            {
                printf("Este vehiculo ya fue vendido.\n");
                return;
            }

            estados[i] = 1;
            printf("Vehiculo vendido exitosamente!\n");
            printf("Detalles del vehiculo vendido:\n");
            mostrarVehiculo(nombres[i], cedulas[i], placas[i], estados[i], i + 1);
            return;
        }
    }

    printf("No se encontro un vehiculo con la placa especificada.\n");
}

void buscarVehiculoPorCedula(char nombres[][50], char cedulas[][15], char placas[][10], int estados[], int cantidad)
{
    if (cantidad == 0)
    {
        printf("No hay vehiculos registrados.\n");
        return;
    }

    char cedula[15];
    printf("\n--- BUSCAR VEHICULO POR CEDULA ---\n");
    printf("Ingrese la cedula del dueno: ");
    limpiarBuffer();
    fgets(cedula, 15, stdin);
    cedula[strcspn(cedula, "\n")] = 0;

    int encontrado = 0;

    printf("\nVehiculos encontrados:\n");
    for (int i = 0; i < cantidad; i++)
    {
        if (strcmp(cedulas[i], cedula) == 0)
        {
            mostrarVehiculo(nombres[i], cedulas[i], placas[i], estados[i], i + 1);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        printf("No se encontraron vehiculos para la cedula especificada.\n");
    }
}

int validarPlacaUnica(char placas[][10], int cantidad, char placa[])
{
    for (int i = 0; i < cantidad; i++)
    {
        if (strcmp(placas[i], placa) == 0)
        {
            return 0;
        }
    }
    return 1;
}

int validarCedulaUnica(char cedulas[][15], int cantidad, char cedula[])
{
    for (int i = 0; i < cantidad; i++)
    {
        if (strcmp(cedulas[i], cedula) == 0)
        {
            return 0;
        }
    }
    return 1;
}

void mostrarVehiculo(char nombre[], char cedula[], char placa[], int estado, int indice)
{
    printf("\n--- Vehiculo #%d ---\n", indice);
    printf("Dueno: %s\n", nombre);
    printf("Cedula: %s\n", cedula);
    printf("Placa: %s\n", placa);
    printf("Estado: %s\n", estado == 0 ? "Disponible" : "Vendido");
    printf("-------------------\n");
}

void limpiarBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}