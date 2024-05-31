#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

int main() {
    const int size = 10;
    int matrix[size][size];
    int *ptr = &matrix[0][0];

    srand(time(0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            *(ptr + i * size + j) = rand() % 100; 
        }
    }


    cout << "main: ";
    for (int i = 0; i < size; ++i) {
        cout << *(ptr + i * size + i) << " ";
    }
    cout << endl;


    cout << "secondary: ";
    for (int i = 0; i < size; ++i) {
        cout << *(ptr + i * size + (size - 1 - i)) << " ";
    }
    cout << endl;

    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < size * size; ++i) {
        if (*(ptr + i) % 2 == 0) {
            ++evenCount;
        } else {
            ++oddCount;
        }
    }

    cout << "parni: " << evenCount << endl;
    cout << "neparni: " << oddCount << endl;

    return 0;
}
