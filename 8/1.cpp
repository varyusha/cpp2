#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    string values;
    getline(cin, values);

    string tmpl;
    getline(cin, tmpl);

    unordered_map<string, string> value_map;
    istringstream value_stream(values);
    string pair;
    while (getline(value_stream, pair, ',')) {
        size_t equal_pos = pair.find('=');
        if (equal_pos != string::npos) {
            string name = pair.substr(0, equal_pos);
            string value = pair.substr(equal_pos + 1);
            value_map[name] = value;
        }
    }

    string result;
    size_t pos = 0;
    while (pos < tmpl.size()) {
        size_t start = tmpl.find('[', pos);
        if (start == string::npos) {
            result += tmpl.substr(pos);
            break;
        }
        result += tmpl.substr(pos, start - pos);
        size_t end = tmpl.find(']', start);
        if (end == string::npos) {
            result += tmpl.substr(start);
            break;
        }
        string key = tmpl.substr(start + 1, end - start - 1);
        if (value_map.find(key) != value_map.end()) {
            result += value_map[key];
        } else {
            result += tmpl.substr(start, end - start + 1);
        }
        pos = end + 1;
    }

    cout << result << endl;

    return 0;
}
