#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    
    int size;
    cout << "enter array`s size: ";
    cin >> size;
    
    float* array = new float[size];
    
    for (int i = 0; i < size; ++i) {
        array[i] = -2 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2+2)));
    }
    
    int positiveCount = 0;
    int negativeCount = 0;
    
    for (int i = 0; i < size; ++i) {
        if (array[i] > 0)
            positiveCount++;
        else if (array[i] < 0)
            negativeCount++;
    }
    
    cout << "++: " << positiveCount << endl;
    cout << "--: " << negativeCount << endl;
    
    delete[] array;
    
    return 0;
}
