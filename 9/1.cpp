#include <string>
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string password;
    getline(cin, password);

    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    bool has_special = false;
    bool is_valid = true;

    if (password.length() < 8) {
        cout << "The password must be 8 characters long\n";
        is_valid = false;
    }

    for (char c : password) {
        if (isupper(c)) has_upper = true;
        if (islower(c)) has_lower = true;
        if (isdigit(c)) has_digit = true;
        if (ispunct(c)) has_special = true;
    }

    if (!has_upper) {
        cout << "The password must have at least one upper case letter\n";
        is_valid = false;
    }

    if (!has_lower) {
        cout << "The password must have at least one lower case letter\n";
        is_valid = false;
    }

    if (!has_digit) {
        cout << "The password must have at least one digit\n";
        is_valid = false;
    }

    if (!has_special) {
        cout << "The password must have at least one special character\n";
        is_valid = false;
    }

    if (is_valid) {
        cout << "The password is valid\n";
    }

    return 0;
}
