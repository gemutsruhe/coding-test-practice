#include <iostream>

using namespace std;

void automata() {

}

int main() {
	int test_num;
	cin >> test_num;

	for (int test = 0; test < test_num; test++) {
		string electric_wave;
		cin >> electric_wave;

		int state = 0;
		int prev_state = -1;
		bool invalid = false;
		int i;
		for (i = 0; i < electric_wave.size(); i++) {
			char sign = electric_wave[i];

			if (state == 0) {
				if (sign == '0') {
					state = 1;
				}
				else if (sign == '1') {
					state = 2;
				}
				else break;
			}
			else if (state == 1) {
				if (sign == '1') state = 0;
				else break;
			}
			else if (state == 2) {
				if (sign == '0') state = 3;
				else break;
			}
			else if (state == 3) {
				if (sign == '0') state = 4;
				else break;
			}
			else if (state == 4) {
				if (sign == '0') state = 4;
				else if (sign == '1') state = 5;
				else break;
			}
			else if (state == 5) {
				if (sign == '0') state = 1;
				else if (sign == '1') state = 6;
				else break;
			}
			else if (state == 6) {
				if (sign == '1') state = 6;
				else if (sign == '0') state = 7;
				else break;
			}
			else if (state == 7) {
				if (sign == '1') state = 0;
				else if (sign == '0') state = 4;
				else break;
			}
		}

		if (i == electric_wave.size() && (state == 0 || state == 5 || state == 6)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}


	return 0;
}