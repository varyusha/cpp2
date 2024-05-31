#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    
    const int rows = 3;
    const int cols = 3;
    
    int** array = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = rand() % 10; 
        }
    }
    
    cout << "el o main: ";
    for (int i = 0; i < rows; ++i) {
        cout << array[i][i] << " ";
    }
    cout << endl;
    
    cout << "el on secondary: ";
    for (int i = 0; i < rows; ++i) {
        cout << array[i][rows - 1 - i] << " ";
    }
    cout << endl;
    
    int evenCount = 0;
    int oddCount = 0;
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (array[i][j] % 2 == 0)
                evenCount++;
            else
                oddCount++;
        }
    }
    
    cout << "parni: " << evenCount << endl;
    cout << "neparni: " << oddCount << endl;
    
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
    
    return 0;
}
