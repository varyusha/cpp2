#include <iostream>
using namespace std;
int main() {
    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
    int n = sizeof(vector) / sizeof(vector[0]);
    int *ptr = vector;         
    int *endPtr = vector + n;  
    int minElement = *ptr;     
    for (; ptr < endPtr; ++ptr) {  
        if (*ptr < minElement) {
            minElement = *ptr;     
        }
    }

    cout << "min el. array: " << minElement << endl;

    return 0;
}
