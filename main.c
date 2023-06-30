#include <stdio.h>
#include <string.h>


void verProductos();
void Mostrarnuevos(int numero, int id[], char nombre[][100], char descripcion[][100], float cantidad[], float precio[]);
void IngresarProducto(int numero, int id[], char nombre[][100], char descripcion[][100], float cantidad[], float precio[]);
void EliminarProductos(int Licor, int id[], char nombre[][100], char descripcion[][100], float cantidad[], float precio[]);
void ModificarProductos(int Licor);
void Menu();


int id[7] = {1, 2, 3, 4, 5};
char nombre[7][100] = {"Jonhy's Blue", "Ron 100 Fuegos", "SKY", "Norteño", "BLACK & WHITE"};
char descripcion[7][100] = {"Whisky", "Ron", "Wodka", "Puro", "Whisky"};
float cantidad[7] = {40, 18, 23, 10, 15};
float precio[7] = {23, 20, 24, 17, 23};

int main() {
    int opcion;
    Menu();

    return 0;
}

void Menu() {
    int opcion;

    printf("MENU:------------------------------------\n");
    printf("1. Ver Productos\n");
    printf("2. Ingresar Productos\n");
    printf("3. Eliminar Productos\n");
    printf("4. Modificar Productos\n");
    printf("5. Salir\n");
    printf("-----------------------------------------\n");

    printf("Que opcion desea realizar: \n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            verProductos();
            printf("La actividad ha culminado exitosamente,que desea hacer?\n");
            Menu();
            break;

        case 2:
            IngresarProducto(5, id, nombre, descripcion, cantidad, precio);
            printf("La actividad ha culminado exitosamente,que desea hacer?\n");
            Menu();
            break;

        case 3:
            EliminarProductos(0, id, nombre, descripcion, cantidad, precio);
            printf("La actividad ha culminado exitosamente,que desea hacer?\n");
            Menu();
            break;

        case 4:
            ModificarProductos(0);
            printf("La actividad ha culminado exitosamente, ¿que desea hacer?\n");
            Menu();
            break;

        case 5:
            printf("Ha salido del programa exitosamente.\n");
            break;

        default:
            printf("Por favor, elija una opcion permitida.\n");
            Menu();
            break;
    }
}

void verProductos() {
    Mostrarnuevos(5, id, nombre, descripcion, cantidad, precio);
}

void Mostrarnuevos(int numero, int id[], char nombre[][100], char descripcion[][100], float cantidad[], float precio[]) {
    printf("-------------------LISTA DE PRODUCTOS------------------\n");
    for (int i = 0; i < numero; i++) {
        printf("ID: %d\n", id[i]);
        printf("Nombre: %s\n", nombre[i]);
        printf("Descripcion: %s\n", descripcion[i]);
        printf("Cantidad: %.2f\n", cantidad[i]);
        printf("Precio: %.2f\n", precio[i]);
        printf("\n");
    }
}

void IngresarProducto(int numero, int id[], char nombre[][100], char descripcion[][100], float cantidad[], float precio[]) {
    printf("Escriba el nuemero de licores que desea añadir: ");
    scanf("%d", &numero);

    for (int i = 0; i < numero; i++) {
        printf("Escriba el ID: ");
        scanf("%d", &id[i]);
        printf("Escriba el NOMBRE: ");
        scanf(" %[^\n]", nombre[i]);
        printf("Escriba la DESCRIPCION: ");
        scanf(" %[^\n]", descripcion[i]);
        printf("Escriba la CANTIDAD: ");
        scanf("%f", &cantidad[i]);
        printf("Escriba el PRECIO: ");
        scanf("%f", &precio[i]);
        printf("\n");
    }

    printf("El total de licores ingresados es: %d\n", numero);
}

void EliminarProductos(int Licor, int id[], char nombre[][100], char descripcion[][100], float cantidad[], float precio[]) {
    printf("Elija el licor que desea eliminar:\n");
    printf("1. Jonhy's Blue\n");
    printf("2. Ron 100 Fuegos\n");
    printf("3. SKY\n");
    printf("4. Norteño\n");
    printf("5. BLACK & WHITE\n");

    scanf("%d", &Licor);

    for (int i = 0; i < 5; i++) {
        if (id[i] == Licor) {
            id[i] = 0;
            strcpy(nombre[i], "vacio");
            cantidad[i] = 0;
            precio[i] = 0;
        }
    }
}

void ModificarProductos(int Licor) {
    printf("Ingrese el ID del producto a modificar: ");
    scanf("%d", &Licor);

    for (int i = 0; i < 5; i++) {
        if (id[i] == Licor) {
            printf("Ingrese los nuevos datos del producto:\n");
            printf("ID: ");
            scanf("%d", &id[i]);
            printf("NOMBRE: ");
            scanf(" %[^\n]", nombre[i]);
            printf("DESCRIPCION: ");
            scanf(" %[^\n]", descripcion[i]);
            printf("CANTIDAD: ");
            scanf("%f", &cantidad[i]);
            printf("PRECIO: ");
            scanf("%f", &precio[i]);
            printf("\n");
        }
    }
}
