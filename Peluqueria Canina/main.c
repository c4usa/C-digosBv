#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char nombres[100][50];
    char fechas[100][11];
    int cantidad = 0;
    int opcion;

    printf("Bienvenido al Sistema de Citas de Peluquería Canina\n");

    do
    {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            registrarCita(nombres, fechas, &cantidad);
            break;
        case 2:
            buscarPorFecha(nombres, fechas, cantidad);
            break;
        case 3:
            buscarPorCliente(nombres, fechas, cantidad);
            break;
        case 4:
            mostrarTodasLasCitas(nombres, fechas, cantidad);
            break;
        case 5:
            printf("Gracias por usar el sistema.\n");
            break;
        default:
            printf("Opción inválida. Intente de nuevo.\n");
            break;
        }

        if (opcion != 5)
        {
            printf("\nPresione Enter para continuar...");
            limpiarBuffer();
            getchar();
        }

    } while (opcion != 5);

    return 0;
}
