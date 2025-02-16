#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (i <= j) {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (j >= low && arr[j] > pivot)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high, int size) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        printArray(arr, size);
        
        quickSort(arr, low, pi - 1, size);
        quickSort(arr, pi + 1, high, size);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Initial array: \n";
    printArray(arr, size);
    
    cout << "\nQuick Sort Passes: \n";
    quickSort(arr, 0, size - 1, size);

    cout << "\nSorted array: \n";
    printArray(arr, size);

    return 0;
}
