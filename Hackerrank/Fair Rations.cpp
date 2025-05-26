#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

string fairRations(vector<int> B) {
    int n = B.size();
    int sum = accumulate(B.begin(), B.end(), 0);

    if (sum % 2 != 0) {
        return "NO";
    }

    int count = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (B[i] % 2 != 0) {
            B[i]++;
            B[i + 1]++;
            count += 2;
        }
    }
    return to_string(count);
}

int main() {
    int N;
    cin >> N;
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    string result = fairRations(B);
    cout << result << endl;
    return 0;
}
