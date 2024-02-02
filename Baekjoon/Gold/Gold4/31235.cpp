#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main() {

	int sequence_size;

	cin >> sequence_size;

	int max_num = INT_MIN;
	int count = 1, max_count = 0;
	for (int i = 0; i < sequence_size; i++) {
		int num;
		cin >> num;

		if (max_num <= num) {
			max_num = num;
			if (count > max_count) max_count = count;
			count = 1;
		}
		else {
			count++;
		}
	}

	cout << max(max_count, count);

	return 0;
}