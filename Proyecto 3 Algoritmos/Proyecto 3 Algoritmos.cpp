
#include <iostream>
#include <stdio.h>
#include <chrono>
using std::cout;
using std::endl;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;
using namespace std;

//selection Sorte ascendente
auto selectionSort(int arr[], int size)
{   
    auto start = high_resolution_clock::now();

    int i, j, indiceBajo;


    for (i = 0; i < size - 1; i++) {

    
        indiceBajo = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[indiceBajo])
                indiceBajo = j;
        }

        if (indiceBajo != i)
            swap(arr[indiceBajo], arr[i]);
    }

    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start);

}

//selection Sorte descendente 
auto selectionSortRevez(int arr[], int size)
{   
    auto start = high_resolution_clock::now();
    int i, j, indiceAlto;


    for (i = 0; i < size - 1; i++) {


        indiceAlto = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] > arr[indiceAlto])
                indiceAlto = j;
        }

        if (indiceAlto != i)
            swap(arr[indiceAlto], arr[i]);
    }

   
    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start);
}


//bubble sort ascendente
auto bubbleSort(int arr[], int size)
{
    auto start = high_resolution_clock::now();
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = false;
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        
        if (swapped == false)
            break;
    }

   
    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start);
}


//bubble sort descendente
auto bubbleSortRevez(int arr[], int size)
{
    auto start = high_resolution_clock::now();
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++) {
        swapped = false;
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }


        if (swapped == false)
            break;
    }

    
    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start);
}




//insertion sort ascendente
auto insertion_sort(int arr[], int size)
{   
    auto start = high_resolution_clock::now();
    for (int step = 1; step < size; step++)
    {
        int key = arr[step];
        int j = step - 1;
        while (key < arr[j] && j >= 0)
        {
            
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }

   
    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start);
}

//insertion Sorte descendente 
auto insertion_sortRevez(int arr[], int size)
{   
    auto start = high_resolution_clock::now();
    for (int step = 1; step < size; step++)
    {
        int key = arr[step];
        int j = step - 1;
        while (key > arr[j] && j >= 0)
        {
            
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }


    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start);
}

// Shell sort ascendente
auto shellSort(int arr[], int size) {
    
    auto start = high_resolution_clock::now();
    for (int interval = size / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < size; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }



    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start);
}

// Shell sort descendente
auto shellSortRevez(int arr[], int size) {

    auto start = high_resolution_clock::now();
    for (int interval = size / 2; interval > 0; interval /= 2) {
        for (int i = interval; i < size; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j - interval] < temp; j -= interval) {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }


    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start);
}

//QuickSort ascendente
//particiones y ordenamiento parcial de quick sort
int partition(int arr[], int low, int high)
{
    
    int pivot = arr[high];

   
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        if (arr[j] < pivot) {

        
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

//main quick sort
void quickSort(int arr[], int low, int size)
{
    if (low < size) {

       
        int pi = partition(arr, low, size);

      
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, size);
    }

}

//tiempo transcurrido de quick sort
auto quickSortTimer(int arr[], int size)
{
    auto start = high_resolution_clock::now();

    quickSort(arr, 0, size-1);

    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start);

}

//QuickSort descendiente
//particiones del quick sort descendente y ordenamiento
int partitionRevez(int arr[], int low, int high)
{

    int pivot = arr[high];


    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        if (arr[j] > pivot) {


            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

//main quick sort al revez
void quickSortRevez(int arr[], int low, int size)
{
    if (low < size) {


        int pi = partitionRevez(arr, low, size);


        quickSortRevez(arr, low, pi - 1);
        quickSortRevez(arr, pi + 1, size);
    }

  
  
}


//tiempo del quick sort descendente
auto  quickSortTimerRevez(int arr[], int size)
{
    auto start = high_resolution_clock::now();

    quickSortRevez(arr, 0, size - 1);
    

    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start);

}





//menuPrincipal del player
void menuprincipal() {

    //creacion de arreglos aleatorio
    srand((unsigned)time(NULL));
    int size = 10;
    int arr[10];
    int arr1[10];
    int arr2[10];
    int arr3[10];
    int arr4[10];
    int arr5[10];
   

    for (int i = 0; i < size; i++) {
        int random = rand();
        arr[i] = arr1[i] = arr2[i] = arr3[i] = arr4[i] = arr5[i] = random;

    }
        

    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
    //elegir ascendente o descendente
    int selector;
    cout << "Carreras de algoritmos\n";
    cout << "1. Ascedente.\n2. Descendente.\n\n";
    cout << "Opcion elegida :";
    cin >> selector;


    //llamar a las funciones de orden y sus tiempos
    if (selector == 1) {
        auto time_takenSelection = selectionSort(arr, size);
        cout << "Execution time selection Sort: " << time_takenSelection.count() << " seconds" << endl;
        auto time_takenBubble = bubbleSort(arr1, size);
        cout << "Execution time bubble Sort: " << time_takenBubble.count() << " seconds" << endl;
        auto time_takenInsertion = insertion_sort(arr2, size);
        cout << "Execution time insertion sort : " << time_takenInsertion.count() << " seconds" << endl;
        auto time_takenShell = shellSort(arr3, size);
        cout << "Execution time shell sort : " << time_takenShell.count() << " seconds" << endl;
        auto time_takenQuick = quickSortTimer(arr4, size);
        cout << "Execution time quick sort : " << time_takenQuick.count() << " seconds" << endl;
        
    }
    else if(selector == 2){
        auto time_takenSelection = selectionSortRevez(arr, size);
        cout << "Execution time selection Sort: " << time_takenSelection.count() << " seconds" << endl;
        auto time_takenBubble = bubbleSortRevez(arr1, size);
        cout << "Execution time bubble Sort: " << time_takenBubble.count() << " seconds" << endl;
        auto time_takenInsertion = insertion_sortRevez(arr2, size);
        cout << "Execution time insertion sort : " << time_takenInsertion.count() << " seconds" << endl;
        auto time_takenShell = shellSortRevez(arr3, size);
        cout << "Execution time shell sort : " << time_takenShell.count() << " seconds" << endl;
        auto time_takenQuick = quickSortTimerRevez(arr4, size);
        cout << "Execution time quick sort : " << time_takenQuick.count() << " seconds" << endl;
    }
    else {
        system("cls");
        cout << "eliga una opcion abilitada\n\n";
        menuprincipal();
    }

    //testear denuevo o salir
    cout << "\n\n\n";
    cout << "Probar denuevo\n";
    cout << "1. Si\n2. No\n\n";
    cout << "Opcion elegida :";
    cin >> selector;
    if (selector == 1) {

        system("cls");
        menuprincipal();
    }
    else {
        
        return;
    }

}


int main()
{
   
    menuprincipal();
    return 0;
}

