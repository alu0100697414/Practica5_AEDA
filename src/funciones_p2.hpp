#include <stdio.h>

using namespace std;

// Funcion que busca el minimo de comparaciones.
int minimo(int* ale, int tam){
  int min = ale[0];

  for(int i=0; i<tam; i++){
    if (min > ale[i])
      min=ale[i];
  }

  return min;
}

// Funcion que busca el maximo de comparaciones.
int maximo(int* ale, int tam){
  int max = ale[0];

  for(int i=0; i<tam; i++){
    if (max < ale[i])
      max=ale[i];
  }

  return max;
}

double suma(int* ale, int tam){
  int suma = 0.0;

  for(int i=0; i<tam; i++){

      suma +=ale[i];
  }

  return suma;
}

// Funcion de Insercion.
template <class T> int insercion_comparacion(T* sec, int tam){

  T aux[tam];
  for(int i=0; i<tam; i++){
    aux[i]=sec[i];
  }

  int i,j,cont=0;
  T tmp;

  // Recorremos el vector desde la posicion 1 hasta el final.
  for (i = 1; i < tam; i++){

    tmp = aux[i];
    j = i - 1;

    // Se comprueba la posicion actual con las anteriores.
    while ((j >= 0) && (tmp < aux[j])){
      aux[j + 1] = aux[j];
      j--;
      cont ++;
    }

    aux[j + 1] = tmp;
  }

  return cont;
}

// Funcion de Seleccion.
template <class T> int seleccion_comparacion (T* sec, int tam){

  T aux[tam];
  for(int i=0; i<tam; i++){
    aux[i]=sec[i];
  }

  int i, j, k, cont=0;

  // Recorremos el vector desde la posicion 0 a la i-1.
  for (i = 0; i < tam - 1; i++){

    // Buscamos el mas pequeño por encima de i.
    for (k = i, j = i + 1; j < tam; j++)
      if (aux[j] < aux[k]){
        k = j;
        cont ++;
      }

    // Si no es el mismo numero, se intercambian.
    if (k != i)
      intercambio (aux, i, k);

  }

  return cont;
}

// Funcion de ShellShort.
template <class T> int shellsort_comparacion (T* sec, int tam, double alf){

  T aux[tam];
  for(int i=0; i<tam; i++){
    aux[i]=sec[i];
  }

  int intervalo,k,j,i,cont=0;

  // Calculamos la primera distancia.
  intervalo = tam*alf;

  while(intervalo>0){
    // Vamos ordenando la secuencia de cada intervalo.
    for(i=intervalo-1; i<tam; i=i+1){
      j=i-intervalo;

      while(j>=0){

        k=j+intervalo;

        if(aux[k]<=aux[j]){
          intercambio(aux,j,k);
          cont ++;
        }
        else
          j=0;

        j=j-intervalo;
      }
    }

    // Calculamos la siguiente distancia.
    intervalo=intervalo*alf;
  }

  return cont;
}


// Funcion de ordenacion para el QuickSort
template <class T> void ord_quicksort_comparacion(T* sec, int ini, int fin, int& cont){

  int i = ini, j = fin, k = 0;

  // Cogemos el valor del pivote.
  T pivot = sec[(ini + fin) / 2];

  // Calculamos el tamaño de la cadena (k).
  while(sec[k]!='\0'){
    k++;
  }

  // Intercambiamos los valores que sean mayor y menor que el pivote.
  while (i <= j) {
    while (sec[i] < pivot)  i++;
    while (sec[j] > pivot)  j--;

    if (i <= j) {
      intercambio(sec,j,i);
      i++;
      j--;
      cont++;
    }
  }

  // Usamos recursividad para realizar el mismo proceso con las subcadenas.
  if (ini < j)
    ord_quicksort_comparacion(sec, ini, j, cont);
  if (i < fin)
    ord_quicksort_comparacion(sec, i, fin, cont);
}

// Funcion QuickSort
template <class T> void quicksort_comparacion(T* sec, int tam, int& cont){
  T aux[tam];
  for(int i=0; i<tam; i++){
    aux[i]=sec[i];
  }

  ord_quicksort_comparacion(aux,0,tam-1,cont);
}

// Funcion para ordenar cada subcadena
template <class T> void ord_intercalacion_comparacion (T* sec, T* tmp, int izq, int der, int &cont){
  if (izq < der){
    // Dividimos en dos el array y ordenamos ambas partes.
    int centro = (izq + der) / 2;

    // Usamos la recursividad en ambas partes.
    ord_intercalacion_comparacion (sec, tmp, izq, centro, cont);
    ord_intercalacion_comparacion (sec, tmp, centro + 1, der, cont);

    // Aqui ambas partes deberian estar ordenadas, por lo que las unimos
    intercalar_comparacion (sec, tmp, izq, centro + 1, der, cont);
  }
}

// Funcion para unir las subcadenas.
template <class T> void intercalar_comparacion (T* sec, T* tmp, int izq, int centro, int der, int& cont){

  int ap = izq, bp = centro, cp = izq;

  while ((ap < centro) && (bp <= der)){

    if (sec[ap] <= sec[bp]){
      tmp[cp] = sec[ap];
      ap++;
      cont++;
    }

    else {
      tmp[cp] = sec[bp];
      bp++;
    }

    cp++;
  }

  while (ap < centro){
    tmp[cp] = sec[ap];
    cp++;
    ap++;
  }

  while (bp <= der){
    tmp[cp] = sec[bp];
    cp++;
    bp++;
  }

  for (ap = izq; ap <= der; ap++)
    sec[ap] = tmp[ap];
}

// Funcion MergeSort
template <class T> void mergesort_comparacion (T* sec, int tam, int& cont){

  T tmp[tam];
  ord_intercalacion_comparacion (sec, tmp, 0, tam-1, cont);
}
