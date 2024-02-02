#include <iostream>

using namespace std;

int main() {
	int n, l;

	cin >> n >> l;

	bool is_valid = false;

	for (int i = l; i <= 100; i++) {
		if ((n - i * (i + 1) / 2) % i == 0) {
			int base_num = (n - i * (i - 1) / 2) / i;
			if (base_num < 0) continue;
			for (int j = 0; j < i; j++) {
				cout << base_num + j << " ";
			}
			
			is_valid = true;
			break;
		}	
	}

	if (!is_valid) cout << -1;


	return 0;
}