#include <iostream>
#include <vector>
using namespace std;

int sansaXor(const vector<int>& arr) {
    int result = 0;
    int n = arr.size();
    
    for (int i = 0; i < n; ++i) {
        // Check if the element appears an odd number of times
        if (((i + 1) * (n - i)) % 2 != 0) {
            result ^= arr[i];
        }
    }
    
    return result;
}

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n; // Size of the array
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        cout << sansaXor(arr) << endl;
    }
    return 0;
}
