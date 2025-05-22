#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

//统计字母频率
class LetterCounter {
private:
    map<char, int> freq;

public:
    void countFromInput() {
        string line;
        while (getline(cin, line)) {
            for (char ch : line) {
                if (islower(ch)) {
                    freq[ch]++;
                }
            }
        }
    }

    map<char, int> getFrequency() const {
        return freq;
    }
};

// 显示柱状图
class HistogramPrinter {
private:
    vector<pair<char, int>> sorted_freq;
    int max_count = 0;

public:
    HistogramPrinter(const map<char, int>& freq_map) {
        for (const auto& pair : freq_map) {
            if (pair.second > 0)
                sorted_freq.push_back(pair);
        }
        sort(sorted_freq.begin(), sorted_freq.end(),
            [](const pair<char, int>& a, const pair<char, int>& b) {
                return a.second > b.second;
            });

        if (!sorted_freq.empty()) {
            max_count = sorted_freq.front().second;
        }
    }

    void print() const {
        if (sorted_freq.empty()) return;

        for (int row = max_count; row >= 1; --row) {
            for (const auto& pair : sorted_freq) {
                if (pair.second >= row) {
                    cout << "#";
                } else {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    LetterCounter counter;
    counter.countFromInput();

    HistogramPrinter printer(counter.getFrequency());
    printer.print();

    return 0;
}