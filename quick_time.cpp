#include <iostream>
#include <time.h>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    clock_t start_time, end_time;
    start_time = clock();

    quicksort(arr, 0, n - 1);

    end_time = clock();
    double t = (double(end_time - start_time) / CLOCKS_PER_SEC);
    
    cout << "Do phuc tap cua thuat toan la O(n log n)" << endl;
    cout << "Thoi gian thuc hien thuat toan la: " << t*1000<< " mili giay" << endl;
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
