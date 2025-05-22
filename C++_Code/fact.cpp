#include <iostream>
#include <string>
using namespace std;

// 求阶乘
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

int main() {
    int number;
    cin >> number;
    string s = to_string(number);
    int sum = 0;
    cout << number << ",";
    for (size_t i = 0; i < s.size(); ++i) {
        int digit = s[i] - '0';
        sum += factorial(digit);
        cout << digit << "!";
        if (i < s.size() - 1)
            cout << "+";
    }
    cout << "=" << sum << endl;
    if (sum == number)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

