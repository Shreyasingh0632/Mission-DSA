#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int count = 0;
    for (int i = 0; i < n; ) {
        int best_pos = -1;
        for (int j = max(0, i - k + 1); j < min(n, i + k); ++j) {
            if (arr[j] == 1) {
                best_pos = j;
            }
        }
        if (best_pos == -1) {
            cout << -1 << endl;
            return 0;
        }
        count++;
        i = best_pos + k;
    }
    cout << count << endl;
    return 0;
}
