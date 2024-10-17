#include <iostream>
using namespace std;

void heapify_min(int arr[], int n, int i) {
    int smallest = i;  // khởi tạo smallest là nút cha
    int l = 2 * i + 1;  // index của nút con trái
    int r = 2 * i + 2;  // index của nút con phải

    // Nếu nút con trái nhỏ hơn nút cha, thì gán smallest = l
    if (l < n && arr[l] < arr[smallest]) {
        smallest = l;
    }

    // Nếu nút con phải nhỏ hơn nút cha, thì gán smallest = r
    if (r < n && arr[r] < arr[smallest]) {
        smallest = r;
    }

    // Nếu smallest khác i (nút cha), thì đổi chỗ giá trị của i và smallest
    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        // Tiếp tục heapify với nút con được đổi chỗ
        heapify_min(arr, n, smallest);
    }
}

void heap_sort_min(int arr[], int n) {
    // Xây dựng heap tối thiểu từ mảng đầu vào
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_min(arr, n, i);
    }

    // Đưa phần tử nhỏ nhất (tức là phần tử đầu tiên) đến cuối cùng và heapify lại với n - 1 phần tử còn lại
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify_min(arr, i, 0);
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heap_sort_min(arr, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
