#include <iostream>

using namespace std;

bool isPrime(int number) {
    if (number < 2) {
        return false;
    }
    
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false; 
        }
    }
    
    return true; 
}

int main() {
    int num;
    cout << "enter num: ";
    cin >> num;
    
    if (isPrime(num)) {
        cout << num << " - proste" << endl;
    } else {
        cout << num << " - ne proste" << endl;
    }
    
    return 0;
}

