#include <iostream>
using namespace std;

int recMul(const int a[], int n) {
    if (n == 0) {
        return 1;
    } else {
        return recMul(a, n - 1) * a[n - 1];
    }
}

int main() {

    int arr[4] = {4, 2, 5, 6};

    cout << recMul(arr, 4) << endl;

    return 0;
}