#include <iostream>
#include <ctime>

using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

Date today() {
    time_t t = time(NULL); 
    tm* now = localtime(&t); 
    Date current_date; 
    current_date.year = now->tm_year + 1900; 
    current_date.month = now->tm_mon + 1; 
    current_date.day = now->tm_mday; 
    return current_date;
}

int daysBetween(Date date1, Date date2) {
    if (date1.year > date2.year || 
        (date1.year == date2.year && date1.month > date2.month) ||
        (date1.year == date2.year && date1.month == date2.month && date1.day > date2.day)) {
        swap(date1, date2);
    }
    
    int days = 0;
    
    for (int year = date1.year; year < date2.year; ++year) {
        if (isLeap(year)) 
            days += 366;
        else
            days += 365;
    }
    
    for (int month = date1.month; month <= 12; ++month) {
        days += monthLength(date1.year, month) - date1.day;
        if (date1.year == date2.year && month == date2.month)
            break;
        date1.day = 0;
    }
    
    return days;
}

int main(void) {
    Date birthday = {2005, 4, 21}; 
    Date current_date = today(); =
    int days_passed = daysBetween(birthday, current_date); 
    cout << "days after HB: " << days_passed << endl;
    return 0;
}
