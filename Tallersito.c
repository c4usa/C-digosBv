#include <stdio.h>
#include <string.h>

char nombres[100][30];
float precios[100];
int stocks[100];
int ids[100];
int cantidadProductos = 0;
float totalGanancias = 0;

int validar(int minimo, int maximo)
{
    int valor;
    char c;
    while (1)
    {
        if (scanf("%d%c", &valor, &c) != 2 || c != '\n' || valor < minimo || valor > maximo)
        {
            printf("Entrada inválida. Intente nuevamente: ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            return valor;
        }
    }
}

float comprobar()
{
    float numero;
    char c;
    while (1)
    {
        if (scanf("%f%c", &numero, &c) != 2 || c != '\n' || numero < 0)
        {
            printf("Entrada inválida. Intente nuevamente: ");
            while (getchar() != '\n')
                ;
        }
        else
        {
            return numero;
        }
    }
}

void ingresarProducto()
{
    if (cantidadProductos >= 100)
    {
        printf("No se pueden agregar más productos.\n");
        return;
    }

    printf("Ingrese el ID del producto: ");
    ids[cantidadProductos] = validar(1, 100);

    printf("Ingrese el nombre del producto (sin espacios): ");
    scanf("%29s", nombres[cantidadProductos]);

    printf("Ingrese la cantidad en stock: ");
    stocks[cantidadProductos] = validar(0, 100);

    printf("Ingrese el precio unitario: ");
    precios[cantidadProductos] = comprobar();

    cantidadProductos++;
    printf("Producto ingresado correctamente.\n");
}

void venderProducto()
{
    int id, cantidad, indice = -1;

    printf("Ingrese el ID del producto a vender: ");
    id = validar(1, 100);

    for (int i = 0; i < cantidadProductos; i++)
    {
        if (ids[i] == id)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        printf("Producto no encontrado.\n");
        return;
    }

    do
    {
        printf("Ingrese la cantidad a vender: ");
        cantidad = validar(0, 100);
        if (cantidad > stocks[indice])
        {
            printf("Cantidad mayor al stock disponible.\n");
        }
    } while (cantidad > stocks[indice]);

    float precioFinal = precios[indice];
    if (cantidad >= 20)
    {
        precioFinal *= 0.9;
        printf("Descuento aplicado. Precio unitario con descuento: $%.2f\n", precioFinal);
    }

    float totalVenta = cantidad * precioFinal;
    stocks[indice] -= cantidad;
    totalGanancias += totalVenta;

    printf("Venta realizada. Total: $%.2f\n", totalVenta);
}

void reabastecerProducto()
{
    int id, cantidad, indice = -1;

    printf("Ingrese el ID del producto a reabastecer: ");
    id = validar(1, 100);

    for (int i = 0; i < cantidadProductos; i++)
    {
        if (ids[i] == id)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        printf("Producto no encontrado.\n");
        return;
    }

    printf("Ingrese la cantidad a agregar: ");
    cantidad = validar(1, 100);
    stocks[indice] += cantidad;
    printf("Stock actualizado. Nuevo stock: %d\n", stocks[indice]);
}

void mostrarInformacion()
{
    for (int i = 0; i < cantidadProductos; i++)
    {
        printf("\nProducto %d\n", i + 1);
        printf("ID: %d\n", ids[i]);
        printf("Nombre: %s\n", nombres[i]);
        printf("Stock: %d\n", stocks[i]);
        printf("Precio: $%.2f\n", precios[i]);
    }
}

void mostrarGanancias()
{
    printf("Total de ganancias: $%.2f\n", totalGanancias);
}

void mostrarPrecioTotal()
{
    float total = 0;
    for (int i = 0; i < cantidadProductos; i++)
    {
        total += precios[i] * stocks[i];
    }
    printf("Precio total del inventario: $%.2f\n", total);
}

void mostrarMaxMin()
{
    if (cantidadProductos == 0)
        return;
    int max = 0, min = 0;
    for (int i = 1; i < cantidadProductos; i++)
    {
        if (precios[i] > precios[max])
            max = i;
        if (precios[i] < precios[min])
            min = i;
    }
    printf("Producto más caro: %s ($%.2f)\n", nombres[max], precios[max]);
    printf("Producto más barato: %s ($%.2f)\n", nombres[min], precios[min]);
}

void mostrarPromedio()
{
    if (cantidadProductos == 0)
        return;
    float suma = 0;
    for (int i = 0; i < cantidadProductos; i++)
    {
        suma += precios[i];
    }
    printf("Precio promedio: $%.2f\n", suma / cantidadProductos);
}

void buscarProducto()
{
    char buscado[30];
    int encontrado = 0;

    printf("Ingrese el nombre del producto a buscar: ");
    scanf("%29s", buscado);

    for (int i = 0; i < cantidadProductos; i++)
    {
        if (strcmp(nombres[i], buscado) == 0)
        {
            printf("Producto encontrado: %s - Precio: $%.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Producto no encontrado.\n");
    }
}

int main()
{
    int opcion;

    do
    {
        printf("\nMenú de Opciones:\n");
        printf("\t1. Ingresar producto (ID, nombre, stock, precio)\n");
        printf("\t2. Vender producto\n");
        printf("\t3. Reabastecer producto\n");
        printf("\t4. Mostrar información de todos los productos\n");
        printf("\t5. Mostrar total de ganancias\n");
        printf("\t6. Calcular precio total del inventario\n");
        printf("\t7. Mostrar producto más caro y más barato\n");
        printf("\t8. Mostrar precio promedio\n");
        printf("\t9. Buscar producto por nombre\n");
        printf("\t10. Salir\n");
        printf("Seleccione una opción: ");

        opcion = validar(1, 10);

        switch (opcion)
        {
        case 1:
            ingresarProducto();
            break;
        case 2:
            venderProducto();
            break;
        case 3:
            reabastecerProducto();
            break;
        case 4:
            mostrarInformacion();
            break;
        case 5:
            mostrarGanancias();
            break;
        case 6:
            mostrarPrecioTotal();
            break;
        case 7:
            mostrarMaxMin();
            break;
        case 8:
            mostrarPromedio();
            break;
        case 9:
            buscarProducto();
            break;
        case 10:
            printf("Saliendo del programa...\n");
            break;
        }
    } while (opcion != 10);

    return 0;
}



