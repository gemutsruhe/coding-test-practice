#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

typedef pair<int, int> pos;
typedef pair<int, int> direction;

void move(vector<vector<int>>& map, vector<direction>& move_direction, vector<int>& visited, int crt_direction, pos crt_pos, pair<int, int> move_count, int count, int& max_count) {
	if (map[crt_pos.first][crt_pos.second] == -1 || visited[map[crt_pos.first][crt_pos.second]] == true) {
		return;
	}

	if (visited[map[crt_pos.first][crt_pos.second]] == false) {
		visited[map[crt_pos.first][crt_pos.second]] = true;
		if (crt_direction == 0) {
			pos next_pos = make_pair(crt_pos.first + move_direction[0].first, crt_pos.second + move_direction[0].second);
			move(map, move_direction, visited, 0, next_pos, make_pair(move_count.first + 1, move_count.second), count + 1, max_count);
		}
		if (count > 0) {
			pos next_pos = make_pair(crt_pos.first + move_direction[1].first, crt_pos.second + move_direction[1].second);
			move(map, move_direction, visited, 1, next_pos, make_pair(move_count.first, move_count.second + 1), count + 1, max_count);
		}
		if (visited[map[crt_pos.first][crt_pos.second]] == false && move_count.first > 0 && move_count.second > 0) {
			int result_count = (move_count.first + move_count.second) * 2;
			if (max_count < result_count) {
				vector<int> visit;
				vector<direction> will_move;

				for (int i = 0; i < move_count.first; i++) {
					will_move.push_back(move_direction[2]);
				}
				for (int i = 0; i < move_count.second; i++) {
					will_move.push_back(move_direction[3]);
				}

				pos will_pos(crt_pos);
				vector<int> visit_dessert;
				for (int i = 0; i < will_move.size(); i++) {

					if (i == will_move.size() - 1) {
						max_count = max(max_count, result_count);
						break;
					}
					will_pos = make_pair(will_pos.first + will_move[i].first, will_pos.second + will_move[i].second);
					int dessert_num = map[will_pos.first][will_pos.second];
					if (dessert_num > 0 && visited[dessert_num] == false) {
						visit_dessert.push_back(dessert_num);
						visited[dessert_num] = true;
					}
					else {
						break;
					}

				}

				for (int i = 0; i < visit_dessert.size(); i++) {
					visited[visit_dessert[i]] = false;
				}
			}
		}
		visited[map[crt_pos.first][crt_pos.second]] = false;
	}
}

int main() {
	int test_num;
	cin >> test_num;

	vector<direction> move_directions = { {-1, -1}, {-1, 1}, {1, 1}, {1, -1} };

	for (int test_case = 1; test_case <= test_num; test_case++) {
		int map_size;
		cin >> map_size;

		vector<vector<int>> map(map_size + 2, vector<int>(map_size + 2, -1));

		for (int i = 1; i <= map_size; i++) {
			for (int j = 1; j <= map_size; j++) {
				cin >> map[i][j];
			}
		}

		int max_count = -1;

		for (int i = 3; i <= map_size; i++) {
			for (int j = 2; j <= map_size - 1; j++) {
				vector<int> visited(101, false);
				pos crt_pos = make_pair(i, j);
				move(map, move_directions, visited, 0, crt_pos, make_pair(0, 0), 0, max_count);
			}
		}

		cout << "#" << test_case << " " << max_count << endl;
	}

	return 0;
}