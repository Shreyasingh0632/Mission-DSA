#include <iostream>
#include <vector>
using namespace std;
int nums[100001]; // ratings
int allocated[100001]; // candies given. defaults to 0 (not processed)
vector<int> pos_by_rating[100001];
int main()
{
	int N;
	cin >> N;
	
	for (int x = 0; x < N; x++)
	{
		cin >> nums[x];
		allocated[x] = 0;
		pos_by_rating[nums[x]].push_back(x);
	}

	for (int rating = 1; rating <= 100000; rating++)
	{
		for (int q = 0; q < pos_by_rating[rating].size(); q++)
		{
			int pos = pos_by_rating[rating][q];
			int m = 0;
			if (pos > 0 && nums[pos-1] < nums[pos])
			{
				m = max(m, allocated[pos-1]);
			}

			if (pos < N-1 && nums[pos+1] < nums[pos])
			{
				m = max(m, allocated[pos+1]);
			}

			allocated[pos] = m+1;
		}
	}
		
	int sum = 0;
	for (int x = 0; x < N; x++)
	{
		//cout << allocated[x] << endl;
		sum += allocated[x];
	}
	cout << sum << endl;

	return 0;
}
