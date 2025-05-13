#include <iostream>
#include <string>
using namespace std;

const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;

    long long totalSum = 0, currentMultiplier = 1;

    for (int i = s.size() - 1; i >= 0; --i) {
        totalSum = (totalSum + (s[i] - '0') * currentMultiplier * (i + 1)) % MOD;
        currentMultiplier = (currentMultiplier * 10 + 1) % MOD;
    }

    cout << totalSum << endl;
    return 0;
}
