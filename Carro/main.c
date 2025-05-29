#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char nombres[100][50];
    char cedulas[100][15];
    char placas[100][10];
    int estados[100];
    int cantidad = 0;
    int opcion;

    printf("Bienvenido al Sistema de Compra y Venta de Vehiculos\n");

    do
    {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregarVehiculo(nombres, cedulas, placas, estados, &cantidad);
            break;
        case 2:
            venderVehiculo(nombres, cedulas, placas, estados, cantidad);
            break;
        case 3:
            buscarVehiculoPorCedula(nombres, cedulas, placas, estados, cantidad);
            break;
        case 4:
            printf("Gracias por usar el sistema\n");
            break;
        default:
            printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
            break;
        }

        if (opcion != 4)
        {
            printf("\nPresione Enter para continuar...");
            limpiarBuffer();
            getchar();
        }

    } while (opcion != 4);

    return 0;
}