#include <stdio.h>

using namespace std;

// Funcion de intercambio de posiciones en un vector.
template <class T> void intercambio(T* sec, int i, int j){

  T tmp = sec[i];
  sec[i] = sec[j];
  sec[j] = tmp;
}


// Funcion de Insercion.
template <class T> void insercion(T* sec, int tam){

  int i,j,pos;
  T tmp;

  // Recorremos el vector desde la posicion 1 hasta el final.
  for (i = 1; i < tam; i++){
    getchar();

    tmp = sec[i];
    j = i - 1;
    pos = j;

    cout << "Datos en la iteracion " << i << "." << endl;
    cout << "Comprobamos " << sec[i] << " con los anteriores." << endl;

    // Se comprueba la posicion actual con las anteriores.
    while ((j >= 0) && (tmp < sec[j])){
      sec[j + 1] = sec[j];
      j--;
    }

    sec[j + 1] = tmp;

    // Miramos si la posicion del valor ha cambiado.
    if(pos == j)
      cout << "No se mueve de sitio." << endl;
    else
      cout << "Se mueve a la posicion " << j+2 << endl;

    // Mostramos el vector resultante de cada iteracion.
    for(int i=0; i<tam; i++){
      cout << sec[i] << " ";
    }
    cout << endl;
  }
}


// Funcion de Seleccion.
template <class T> void seleccion (T* sec, int tam){
  int i, j, k;

  // Recorremos el vector desde la posicion 0 a la i-1.
  for (i = 0; i < tam - 1; i++){
    getchar();

    // Buscamos el mas pequeño por encima de i.
    for (k = i, j = i + 1; j < tam; j++)
      if (sec[j] < sec[k])
        k = j;

    cout << "Datos en la iteracion " << i+1 << "." << endl;

    // Si no es el mismo numero, se intercambian.
    if (k != i){
      cout << "Se intercambian v[" << k << "]= " << sec[k] << " con " << "v[" << i << "]= " << sec[i] << endl;
      intercambio (sec, i, k);
    }
    else
      cout << "No se intercambia ningun valor." << endl;

    // Mostramos el resultado del vector en cada iteracion.
    for(int i=0; i<tam; i++){
      cout << sec[i] << " ";
    }
    cout << endl;
  }
}


// Funcion de ShellShort.
template <class T> void shellsort (T* sec, int tam, double alf){

  int intervalo,k,j,i;

  // Calculamos la primera distancia.
  intervalo = tam*alf;

  while(intervalo>0){
    getchar();

    cout << "Distancia: " << intervalo << endl;

    // Vamos ordenando la secuencia de cada intervalo.
    for(i=intervalo-1; i<tam; i=i+1){
      j=i-intervalo;

      while(j>=0){

        k=j+intervalo;

        if(sec[k]<=sec[j])
          intercambio(sec,j,k);
        else
          j=0;

        j=j-intervalo;
      }
    }

    // Mostramos por pantalla los resultados de cada iteracion.
    for(int i=0; i<tam; i++){
      cout << sec[i] << " ";
    }
    cout << endl;

    // Calculamos la siguiente distancia.
    intervalo=intervalo*alf;
  }
}

// Funcion QuickSort
template <class T> void quicksort(T* sec, int tam){
  ord_quicksort(sec,0,tam-1);
}

// Funcion de ordenacion para el QuickSort
template <class T> void ord_quicksort(T* sec, int ini, int fin){
  getchar();

  int i = ini, j = fin, k = 0;

  // Cogemos el valor del pivote.
  T pivot = sec[(ini + fin) / 2];

  // Calculamos el tamaño de la cadena (k).
  while(sec[k]!='\0'){
    k++;
  }

  // Mostramos el pivote de cada iteracion.
  cout << "Pivote: " << pivot << endl;
  for(int i=0; i<k-1; i++){
    cout << sec[i] << " ";
  }
  cout << endl;

  // Intercambiamos los valores que sean mayor y menor que el pivote.
  while (i <= j) {
    while (sec[i] < pivot)  i++;
    while (sec[j] > pivot)  j--;

    if (i <= j) {
      intercambio(sec,j,i);
      i++;
      j--;
    }
  }

  // Usamos recursividad para realizar el mismo proceso con las subcadenas.
  if (ini < j)
    ord_quicksort(sec, ini, j);
  if (i < fin)
    ord_quicksort(sec, i, fin);
}

// Funcion para ordenar cada subcadena
template <class T> void ord_intercalacion (T* sec, T* tmp, int izq, int der){
  if (izq < der){
    getchar();

    // Dividimos en dos el array y ordenamos ambas partes.
    int centro = (izq + der) / 2;
    int k = 0;

    // Obtenemos el tamaño de la cadena.
    while(sec[k]!='\0'){
      k++;
    }

    // Mostramos los resultados de cada iteracion de division.
    cout << "Inicio: " << izq << " Final: " << der << " Media: " << centro << endl;
    for(int i=0; i<k-1; i++){
      cout << sec[i] << " ";
    }
    cout << endl;

    // Usamos la recursividad en ambas partes.
    ord_intercalacion (sec, tmp, izq, centro);
    ord_intercalacion (sec, tmp, centro + 1, der);

    // Aqui ambas partes deberian estar ordenadas, por lo que las unimos
    intercalar (sec, tmp, izq, centro + 1, der);
  }
}

// Funcion para unir las subcadenas.
template <class T> void intercalar (T* sec, T* tmp, int izq, int centro, int der){

  getchar();

  int ap = izq, bp = centro, cp = izq, k = 0;

  while ((ap < centro) && (bp <= der)){

    if (sec[ap] <= sec[bp]){
      tmp[cp] = sec[ap];
      ap++;
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

  // Obtenemos el tamaño de la cadena.
  while(sec[k]!='\0'){
    k++;
  }

  // Mostramos los resultados de cada iteracion.
  cout << "Mezcla. " << endl;
  for(int i=0; i<k-1; i++){
    cout << sec[i] << " ";
  }
  cout << endl;
}

// Funcion MergeSort
template <class T> void mergesort (T* sec, int tam){

  T tmp[tam];
  ord_intercalacion (sec, tmp, 0, tam-1);
}
