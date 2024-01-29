#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a;
    cin >> b;

    // Print the lengths of a and b
    cout << a.size() << " " << b.size() << "\n";

    // Concatenate a and b and print the result
    cout << a + b << "\n";

    // Swap the first characters of a and b and print the result
    swap(a[0], b[0]);
    cout << a << " " << b << "\n";

    return 0;
}