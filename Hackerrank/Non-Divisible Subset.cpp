#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> counts(k, 0);
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    counts[num % k]++;
  }

  int subset_size = 0;
  if (counts[0] > 0) {
    subset_size++;
  }

  for (int i = 1; i <= k / 2; ++i) {
    if (i != k - i) {
      subset_size += max(counts[i], counts[k - i]);
    } else if (counts[i] > 0) {
        subset_size++;
    }
  }
  
  cout << subset_size << endl;
  return 0;
}
