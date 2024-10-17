#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <time.h>


using namespace std;

void inPut (int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

//         1. QUICK_SORT
//----------------------------------------------------//
int partition (int arr[], int l, int r, int &dem){
    int pivotIndex = (l + r) / 2;
    int pivotValue = arr[pivotIndex];
    int i = l, j = r;

    
    while(true){
        while(arr[i] < pivotValue){
            i++;
            dem++;
        }
        while(arr[j] > pivotValue){
            j--;
            dem++;
        }
        if(i >= j){
            return j;
        }
        swap(arr[i],arr[j]);
        dem++;
        i++;
        j--;
    }
}

void quickSort (int arr[], int l, int r, int &dem){
    if(l<r){
        int pivot = partition(arr,l,r,dem);
        quickSort(arr,l,pivot,dem);
        quickSort(arr,pivot+1,r,dem);
    }
}

//----------------------------------------------------//
// Ham merge
void merge(int arr[], int l, int m, int r, int &dem) {
    int n1= m - l+1;  
    int n2= r - m;   
    
    int arr_l[n1];     
    int arr_r[n2];      

    for (int i=0; i<n1; i++){
        arr_l[i] = arr[l+i];
        dem++;
    }

    for (int i=0; i<n2; i++){
        arr_r[i] = arr[m+1+i];
        dem++;
    }

    int i = 0; 
    int j = 0;
    int k = l;
    while (i<n1 && j<n2){
        if(arr_l[i] <= arr_r[j]){
            arr[k] = arr_l[i];
            i++;
        }else{
            arr[k] = arr_r[j];

            j++;
        }
        k++;
        dem++;
    }

    while(i < n1){
        arr[k] = arr_l[i];
        i++;
        k++;
        dem++;
    }
    
    while(i < n2){
        arr[k] = arr_r[j];
        j++;
        k++;
        dem++;
    }
}


//          2. MERGE SORT
//----------------------------------------------------//
void mergeSort (int arr[], int l, int r, int &dem){
    if (l < r){
        int mid = l + (r - l) / 2;
        mergeSort (arr, l ,mid, dem);
        mergeSort (arr, mid+1 , r, dem);

        merge(arr,l,mid,r,dem);
    }
}


//         3. NATURAL MERGE_SORT
//----------------------------------------------------//
void naturalMergeSort(int arr[], int n, int &dem) {

    if (n <= 1) {
        return;
    }

    while (true) {
        int i = 0, j = 0;
        while (i < n) {
            j = i + 1;
            while (j < n && arr[j] >= arr[j - 1]) {
                ++j;
            }

            if (j == n) {
                break;
            }

            i = j - 1;
            while (i > 0 && arr[i] >= arr[i - 1]) {
                --i;
            }
 
            merge(arr, i, j - 1, min(j + (j - i - 1), n - 1),dem);
        }

        if (j == n) {
            break;
        }
    }
}


//          4. HEAP SORT
void heapify(int arr[], int n, int i){
    int max = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[max]){
        max = l;
    }
    if (r < n && arr[r] > arr[max]){
        max = r;
    }
    if (max != i){
        swap(arr[i], arr[max]); 
        heapify(arr,n,max);
    }
}

void heapSort (int arr[], int n, int &dem){
    for (int i= n / 2 -1; i>=0; i--){
        heapify(arr,n,i);
        dem++;
    }
    for (int i=n-1; i>=0; i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
        dem++;
    }
}
// 5. RADIX SORT
void countingSort(int arr[], int n, int k, int &dem){
    int phu[n];
    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < n; i++) {
        int radix = (arr[i] / k) % 10;
        count[radix]++;
        dem++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        dem++;
    }

    for (int i = n - 1; i >= 0; i--) {
        int radix = (arr[i] / k) % 10;
        phu[count[radix] - 1] = arr[i];
        count[radix]--;
        dem++;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = phu[i];
        dem++;
    }
}

int max(int arr[], int n){
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    return max;
}

void radixSort(int arr[], int n,int &dem) {
    int m = max(arr, n);
    for (int i = 1; m / i > 0; i *= 10) {
        countingSort(arr, n, i,dem);
        dem++;
    }
}
//----------------------------------------------------//


void outPut(int arr[], int n){
    for (int i=0; i<n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {10, 11, 2, 3, 14, 5, 6, 7, 8, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int dem = 0;
    
    clock_t start, end;
    double time;

    cout << "------------------------------------------\n";
    cout << "DANH SACH 5 THUAT TOAN THEO YEU CAU:" << endl;
    cout << "\t1. Thuat toan Quick Sort" << endl;
    cout << "\t2. Thuat toan Merge Sort" << endl;
    cout << "\t3. Thuat toan Natural Merge Sort" << endl;
    cout << "\t4. Thuat toan Heap Sort" << endl;
    cout << "\t5. Thuat toan Radix Sort" << endl;
    cout << "\nNhap lua chon: ";
    int lc;
    cin >> lc;
    
    cout << "\n------------------------------------------\n";
    switch (lc)
    {
    case 1:
        cout << "Mang ban dau:" << endl;
        inPut(arr,n); 
        start = clock();
        quickSort(arr,0,n-1,dem);
        end = clock();
        cout << "Mang da sap xep bang thuat toan Quick_Sort:" << endl;
        outPut(arr,n);
        cout << "Do phuc tap cua thuat toan trong truong hop trung binh la O(n log n)" << endl;
        time = double(end - start) * 1000 / CLOCKS_PER_SEC;
        break;
    
    case 2:
        cout << "Mang ban dau:" << endl;
        inPut(arr,n); 
        start = clock();
        mergeSort(arr,0,n-1,dem);
        end = clock();
        cout << "Mang da sap xep bang thuat toan Merge_Sort:" << endl;
        outPut(arr,n);
        cout << "Do phuc tap cua thuat toan trong truong hop trung binh la O(n log n)" << endl;
        time = double(end - start) * 1000 / CLOCKS_PER_SEC;
        break;

    case 3:
        cout << "Mang ban dau:" << endl;
        inPut(arr,n); 
        start = clock();
        naturalMergeSort(arr,n,dem);
        end = clock();
        cout << "Mang da sap xep bang thuat toan Natural Merge_Sort:" << endl;
        outPut(arr,n);
        cout << "Do phuc tap cua thuat toan trong truong hop trung binh la O(n log n)" << endl;
        time = double(end - start) * 1000 / CLOCKS_PER_SEC;
        break;

    case 4:
        cout << "Mang ban dau:" << endl;
        inPut(arr,n); 
        start = clock();
        heapSort(arr,n,dem);
        end = clock();
        cout << "Mang da sap xep bang thuat toan Heap_Sort:" << endl;
        outPut(arr,n);
        cout << "Do phuc tap cua thuat toan trong truong hop trung binh la O(n log n)" << endl;
        time = double(end - start) * 1000 / CLOCKS_PER_SEC;
        break;

    case 5:
        cout << "Mang ban dau:" << endl;
        inPut(arr,n); 
        start = clock();
        radixSort(arr,n,dem);
        end = clock();
        cout << "Mang da sap xep bang thuat toan Radix_Sort:" << endl;
        outPut(arr,n);
        cout << "Do phuc tap cua thuat toan trong truong hop trung binh la O(kn)" << endl;
        time = double(end - start) * 1000 / CLOCKS_PER_SEC;
        break;
    
    default:
        break;
    }
    cout << "------------------------------------------\n";
    cout << "So phan tu cua mang: " << n << endl;
    cout << "So thuc hien sap xep cac phan tu trong mang cua thuat toan: " << dem << endl;
    cout << "Thoi gian chay: " << time <<" seconds!" << endl;
    cout << "------------------------------------------\n";

    return 0;
}