#include<iostream>
using namespace std;


void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right, int size) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, size);
        mergeSort(arr, mid + 1, right, size);
        
        merge(arr, left, mid, right);
        
        // Print the array after every merge pass
        printArray(arr, size);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Initial array: \n";
    printArray(arr, size);
    
    cout << "\nMerge Sort Passes: \n";
    mergeSort(arr, 0, size - 1, size);

    cout << "\nSorted array: \n";
    printArray(arr, size);

    return 0;
}
