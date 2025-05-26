#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> waiter(vector<int> number, int q) {
    vector<int> ans;
    stack<int> a, b;
    vector<int> primes;
    
   
    int num = 2;
    while (primes.size() < q) {
        bool isPrime = true;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            primes.push_back(num);
        }
        num++;
    }

    for (int plate : number) {
        a.push(plate);
    }

    for (int i = 0; i < q; ++i) {
        stack<int> temp_a;
        while (!a.empty()) {
            int plate = a.top();
            a.pop();
            if (plate % primes[i] == 0) {
                b.push(plate);
            } else {
                temp_a.push(plate);
            }
        }
        while (!b.empty()) {
            ans.push_back(b.top());
            b.pop();
        }
        a = temp_a;
    }
    
    while (!a.empty()) {
        ans.push_back(a.top());
        a.pop();
    }

    return ans;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> number(n);
    for (int i = 0; i < n; ++i) {
        cin >> number[i];
    }
    vector<int> result = waiter(number, q);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << (i == result.size() - 1 ? "" : "\n");
    }
    cout << endl;
    return 0;
}
