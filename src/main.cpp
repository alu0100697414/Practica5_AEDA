#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>

#include "funciones_p1.hpp"
#include "funciones_p2.hpp"
#include "dni.hpp"

using namespace std;

int main(void){

  system("clear");

  bool first = true;

  while (first){
    int opc1;

    cout << "PRACTICA 5: ORDENACION." << endl << endl;
    cout << "Elija el programa que desea ejecutar: " << endl;
    cout << "1. Modo demostracion." << endl;
    cout << "2. Modo estadisticas." << endl;
    cout << "3. Salir." << endl << endl;
    cout << "Introduzca la opcion que desee: ";
    cin >> opc1;

    switch(opc1){

      case 1:
      {
        system("clear");

        srand (time(NULL));

        int N;

        cout << "Introduzca el tamaño de la secuencia a ordenar: ";
        cin >> N;
        cout << endl;

        DNI aleatorio[N];

        bool menu = true;

        while (menu){
          int opc2;

          cout << "Ahora indique el algoritmo que desea ejecutar." << endl;
          cout << "1. Insercion." << endl;
          cout << "2. Seleccion." << endl;
          cout << "3. Incrementos decrecientes (ShellSort)." << endl;
          cout << "4. QuickSort." << endl;
          cout << "5. MergeSort." << endl;
          cout << "6. Salir." << endl << endl;
          cout << "Introduzca la opcion que desea elegir: ";
          cin >> opc2;

          switch (opc2){

            case 1:
            // Creo el vector con los valores rand
            for(int i=0; i<N; i++){
              aleatorio[i] = DNI(30000000 + (rand()%50000000));
            }

            cout << "Datos antes de aplicar el metodo de insercion." << endl;

            for(int i=0; i<N; i++){
              cout << aleatorio[i] << " ";
            }

            cout << endl << endl;

            insercion(aleatorio,N);

            cout << endl;
            break;

            case 2:
            // Creo el vector con los valores rand
            for(int i=0; i<N; i++){
              aleatorio[i] = DNI(30000000 + (rand()%50000000));
            }

            cout << "Datos antes de aplicar el metodo de seleccion." << endl;

            for(int i=0; i<N; i++){
              cout << aleatorio[i] << " ";
            }

            cout << endl << endl;

            seleccion(aleatorio,N);

            cout << endl;
            break;

            case 3:
            // Introduzco el valor de alfa
            double alfa;
            cout << "Por favor, introduzca un valor para alfa (0<alfa<1): ";
            cin >> alfa;

            // Creo el vector con los valores rand
            for(int i=0; i<N; i++){
              aleatorio[i] = DNI(30000000 + (rand()%50000000));
            }

            cout << "Datos antes de aplicar el metodo de ShellSort." << endl;

            for(int i=0; i<N; i++){
              cout << aleatorio[i] << " ";
            }

            cout << endl << endl;

            shellsort(aleatorio,N,alfa);

            cout << endl;
            break;

            case 4:
            {
            // Creo el vector con los valores rand
            for(int i=0; i<N; i++){
              aleatorio[i] = DNI(30000000 + (rand()%50000000));
            }

            cout << "Datos antes de aplicar el metodo de QuickSort." << endl;


            for(int i=0; i<N; i++){
              cout << aleatorio[i] << " ";
            }

            cout << endl << endl;

            quicksort(aleatorio,N);

            cout << endl << "Datos despues de aplicar el metodo de QuickSort." << endl;
            for(int i=0; i<N; i++){
              cout << aleatorio[i] << " ";
            }

            cout << endl << endl;
            }
            break;

            case 5:
            {
            // Creo el vector con los valores rand
            for(int i=0; i<N; i++){
              aleatorio[i] = DNI(30000000 + (rand()%50000000));
            }

            cout << "Datos antes de aplicar el metodo de MergeSort." << endl;

            for(int i=0; i<N; i++){
              cout << aleatorio[i] << " ";
            }

            cout << endl << endl;

            mergesort(aleatorio,N);

            cout << endl;
            }
            break;

            case 6:
              system("clear");
              menu = false;
            break;

          }

        }
      }
      break;

      case 2:
      {
        system("clear");

        srand (time(NULL));

        int N,nPruebas,cont;
        double alfa;

        cout << "Introduzca el tamaño de la secuencia a ordenar: ";
        cin >> N;
        cout << endl;
        cout << "Ahora, el numero de pruebas que desea realizar: ";
        cin >> nPruebas;
        cout << endl;
        cout << "Finalmente, el valor de alfa para el metodo ShellSort: ";
        cin >> alfa;
        cout << endl;

        // Calculo de las pruebas.
        DNI aleatorio[N];
        int PruebasInsercion[nPruebas];
        int PruebasSeleccion[nPruebas];
        int PruebasShellSort[nPruebas];
        int PruebasQuickSort[nPruebas];
        int PruebasMergeSort[nPruebas];

        // Guardo el numero de comparaciones de cada prueba.
        for(int i=0; i<nPruebas; i++){
          for(int j=0; j<N; j++){
            aleatorio[j] = DNI(30000000 + (rand()%50000000));
          }

          PruebasInsercion[i] = insercion_comparacion(aleatorio,N);
          PruebasSeleccion[i] = seleccion_comparacion(aleatorio,N);
          PruebasShellSort[i] = shellsort_comparacion(aleatorio,N,alfa);

          cont = 0;
          quicksort_comparacion(aleatorio,N,cont);
          PruebasQuickSort[i] = cont;

          cont = 0;
          mergesort_comparacion(aleatorio,N,cont);
          PruebasMergeSort[i] = cont;
        }

        // Busco el maximo, minimo y la media.
        int minInsercion = minimo(PruebasInsercion,nPruebas);
        int maxInsercion = maximo(PruebasInsercion,nPruebas);
        double mediaInsercion = suma(PruebasInsercion,nPruebas)/nPruebas;

        int minSeleccion = minimo(PruebasSeleccion,nPruebas);
        int maxSeleccion = maximo(PruebasSeleccion,nPruebas);
        double mediaSeleccion = suma(PruebasSeleccion,nPruebas)/nPruebas;

        int minShellSort = minimo(PruebasShellSort,nPruebas);
        int maxShellSort = maximo(PruebasShellSort,nPruebas);
        double mediaShellSort = suma(PruebasShellSort,nPruebas)/nPruebas;

        int minQuickSort = minimo(PruebasQuickSort,nPruebas);
        int maxQuickSort = maximo(PruebasQuickSort,nPruebas);
        double mediaQuickSort = suma(PruebasQuickSort,nPruebas)/nPruebas;

        int minMergeSort = minimo(PruebasMergeSort,nPruebas);
        int maxMergeSort = maximo(PruebasMergeSort,nPruebas);
        double mediaMergeSort = suma(PruebasMergeSort,nPruebas)/nPruebas;

        // Muestra de las estadisticas por pantalla.
        cout << "ESTADISTICAS DEL NUMERO DE COMPARACIONES." << endl << endl;
        cout << "Insercion ->  MAX: " << maxInsercion << "  MIN: " << minInsercion << "  MEDIA: " << mediaInsercion << endl;
        cout << "Seleccion ->  MAX: " << maxSeleccion << "  MIN: " << minSeleccion << "  MEDIA: " << mediaSeleccion << endl;
        cout << "ShellSort ->  MAX: " << maxShellSort << "  MIN: " << minShellSort << "  MEDIA: " << mediaShellSort << endl;
        cout << "QuickSort ->  MAX: " << maxQuickSort << "  MIN: " << minQuickSort << "  MEDIA: " << mediaQuickSort << endl;
        cout << "MergeSort ->  MAX: " << maxMergeSort << "  MIN: " << minMergeSort << "  MEDIA: " << mediaMergeSort << endl;
        cout << endl;

        getchar(); getchar();

        system("clear");
      }
      break;

      case 3:
        system("clear");
        first = false;
      break;
    }
  }

  return 0;
}
