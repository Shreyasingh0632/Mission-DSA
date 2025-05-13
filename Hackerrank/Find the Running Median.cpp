#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

void addNumber(priority_queue<int> &low, priority_queue<int, vector<int>, greater<int>> &high, int num) {
    if (low.empty() || num <= low.top()) {
        low.push(num);
    } else {
        high.push(num);
    }
}

void balanceHeaps(priority_queue<int> &low, priority_queue<int, vector<int>, greater<int>> &high) {
    if (low.size() > high.size() + 1) {
        high.push(low.top());
        low.pop();
    } else if (high.size() > low.size()) {
        low.push(high.top());
        high.pop();
    }
}

double findMedian(priority_queue<int> &low, priority_queue<int, vector<int>, greater<int>> &high) {
    if (low.size() == high.size()) {
        return (low.top() + high.top()) / 2.0;
    } else {
        return low.top();
    }
}

int main() {
    int n;
    cin >> n;

    priority_queue<int> low; // Max-heap for the lower half
    priority_queue<int, vector<int>, greater<int>> high; // Min-heap for the upper half

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        addNumber(low, high, num);
        balanceHeaps(low, high);

        cout << fixed << setprecision(1) << findMedian(low, high) << endl;
    }

    return 0;
}
