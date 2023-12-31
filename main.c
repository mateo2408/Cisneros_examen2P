//Mateo Cisneros
//12/12/2023
//Leer README para ejercicio

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_INSUMOS 30

// Estructura para almacenar los datos de un insumo
struct insumo {
  int ingresos[12];
  int egresos[12];
};

// Función para generar datos random para los ingresos y egresos
void generar_datos(struct insumo *insumo) {
  int i;
  for (i = 0; i < 12; i++) {
    insumo->ingresos[i] = rand() % 10;
    insumo->egresos[i] = rand() % 10;
    // Si los egresos son superiores a los ingresos, intercambiarlos
    if (insumo->egresos[i] > insumo->ingresos[i]) {
      int temp = insumo->ingresos[i];
      insumo->ingresos[i] = insumo->egresos[i];
      insumo->egresos[i] = temp;
    }
  }
}

// Función para imprimir el detalle de ingresos y egresos
void imprimir_detalle(struct insumo *insumo) {
  int i, j;
  for (i = 0; i < 12; i++) {
    printf("Mes %d: Ingresos: %d, Egresos: %d\n", i + 1, insumo->ingresos[i], insumo->egresos[i]);
  }
}

// Función para obtener el total de ingresos y egresos
void obtener_totales(struct insumo *insumo) {
  int i, total_ingresos, total_egresos;
  total_ingresos = 0;
  total_egresos = 0;
  for (i = 0; i < 12; i++) {
    total_ingresos += insumo->ingresos[i];
    total_egresos += insumo->egresos[i];
  }
  printf("Total ingresos: %d\n", total_ingresos);
  printf("Total egresos: %d\n", total_egresos);
}

int main() {
  struct insumo insumos[NUM_INSUMOS];
  int opcion;

  // Inicializar los datos random
  srand(time(NULL));
  for (int i = 0; i < NUM_INSUMOS; i++) {
    generar_datos(&insumos[i]);
  }

  do {
    // Mostrar el menú
    printf("1. Imprimir detalle\n2. Obtener totales\n3. Salir\n");
    printf("Ingrese una opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
      case 1:
        // Imprimir el detalle de ingresos y egresos
        for (int i = 0; i < NUM_INSUMOS; i++) {
            printf("Insumo: %d\n", i+1);
          imprimir_detalle(&insumos[i]);
        }
        break;
      case 2:
        // Obtener el total de ingresos y egresos
        for (int i = 0; i < NUM_INSUMOS; i++) {
          printf("Insumo: %d\n", i+1);
          obtener_totales(&insumos[i]);
        }
        break;
      case 3:
        // Salir
        break;
      default:
        // Opción no válida
        printf("Opción no válida\n");
    }
  } while (opcion != 3);

  return 0;
}
