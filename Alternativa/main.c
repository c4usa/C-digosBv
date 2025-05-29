#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main()
{
    int opcion;
    int inicializado = 0;
    do
    {
        mostrarMenu();
        opcion = leerEntero("Seleccione una opcion: ");
        switch (opcion)
        {
        case 1:
            ingresarInventario();
            inicializado = 1;
            break;
        case 2:
            if (!inicializado)
                printf("Primero debe ingresar inventario.\n");
            else
                mostrarInventario();
            break;
        case 3:
            if (!inicializado)
                printf("Primero debe ingresar inventario.\n");
            else
                producirProducto();
            break;
        case 4:
            if (!inicializado)
                printf("Primero debe ingresar inventario.\n");
            else
                editarDatos();
            break;
        case 5:
            if (!inicializado)
                printf("Primero debe ingresar inventario.\n");
            else
                eliminarDatos();
            break;
        case 6:
            mostrarResumenDemanda();
            break;
        case 7:
            mostrarEstadisticasProduccion();
            break;
        case 8:
            printf("Saliendo de EMSI SYSTEM.....\n");
            break;
        case 9:
            if (!inicializado)
                printf("Primero debe ingresar el inventario.\n");
            else
                mostrarFabricables();
            break;
        default:
            printf("Opcion invalida. Intente de nuevo\n");
        }
    } while (opcion != 8);
    return 0;
}