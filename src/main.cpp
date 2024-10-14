#include <iostream>
#include <iomanip>
#include "../include/main.h"

using namespace std;

int main() {
    int n;
    cout << "Enter a value for n: ";
    cin >> n;

    int a[n];
    CreateArray(a, n, 0);

    cout << "The array is: ";
    PrintArray(a, n, 0);

    cout << endl;

    cout << "The largest absolute value in the array is: " << FindTheLargest(a, n, 0) << endl;

    cout << "The sum between the first two positive numbers is: " << Sum(a, n, 0, 0) << endl;

    Sort(a, n);

    cout << "The modified array is: " << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(4) << a[i];
    }

    return 0;
}