#include <iostream>
using namespace std;

void swapNumbers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;

    cout << "Enter first number: ";
    cin >> x;

    cout << "Enter second number: ";
    cin >> y;

    cout << "\nBefore swapping:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    swapNumbers(&x, &y);

    cout << "\nAfter swapping:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}
