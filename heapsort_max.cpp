#include <iostream>
#include <fstream>
using namespace std;
void docFile(int arr[], int &n)
{
          ifstream inputFile;
          inputFile.open("input.txt");
          inputFile >> n;
          for (int i = 0; i < n; i++)
          {
                    inputFile >> arr[i];
          }
          inputFile.close();
}
void heapify_max(int arr[], int n, int i) {
    int largest = i;  // khởi tạo largest là nút cha
    int l = 2 * i + 1;  // index của nút con trái
    int r = 2 * i + 2;  // index của nút con phải

    // Nếu nút con trái lớn hơn nút cha, thì gán largest = l
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    // Nếu nút con phải lớn hơn nút cha, thì gán largest = r
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    // Nếu largest khác i (nút cha), thì đổi chỗ giá trị của i và largest
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Tiếp tục heapify với nút con được đổi chỗ
        heapify_max(arr, n, largest);
    }
}

void heap_sort_max(int arr[], int n) {
    // Xây dựng heap tối đa từ mảng đầu vào
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_max(arr, n, i);
    }

    // Đưa phần tử lớn nhất (tức là phần tử đầu tiên) đến cuối cùng và heapify lại với n - 1 phần tử còn lại
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify_max(arr, i, 0);
    }
}
void ghiFile(int arr[], int n)
{
          ofstream outputFile;
          outputFile.open("output.txt");
          for (int i = 0; i < n; i++)
          {
                    outputFile << arr[i] << " ";
          }
          outputFile.close();
}
int main() {
    int arr[8];
    int n = sizeof(arr) / sizeof(arr[0]);
    docFile(arr, n);
    heap_sort_max(arr, n);
    ghiFile(arr,n);

   // cout << "Mang sau khi sap xep: ";
    //for (int i = 0; i < n; i++) {
     //   cout << arr[i] << " ";
    

    return 0;
}
