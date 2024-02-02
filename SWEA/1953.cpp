#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> pos;
typedef pair<int, int> direction;

int main() {
	int test_num;
	cin >> test_num;

	vector<vector<int>> tunnels = { {0, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {1, 0, 0, 1} };
	vector<direction> move_directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

	for (int test_case = 1; test_case <= test_num; test_case++) {
		int height, width, time;
		pos start_pos;
		cin >> height >> width >> start_pos.first >> start_pos.second >> time;
		start_pos.first++;
		start_pos.second++;

		vector<vector<int>> map(height + 2, vector<int>(width + 2, 0));
		vector<vector<bool>> visited(height + 2, vector<bool>(width + 2, false));

		for (int i = 1; i <= height; i++) {
			for (int j = 1; j <= width; j++) {
				cin >> map[i][j];
			}
		}

		queue<pos> will_visit_pos;
		will_visit_pos.push(start_pos);
		visited[start_pos.first][start_pos.second] = true;

		int count = 1;
		int this_time = 1;
		while (!will_visit_pos.empty()) {
			if (this_time == time) break;
			int this_time_visit_num = will_visit_pos.size();
			for (int i = 0; i < this_time_visit_num; i++) {
				pos crt_pos = will_visit_pos.front();
				will_visit_pos.pop();
				
				int tunnel_type = map[crt_pos.first][crt_pos.second];
				vector<int> tunnel = tunnels[tunnel_type];

				for (int j = 0; j < tunnel.size(); j++) {
					int open_direction = tunnel[j];
					if (open_direction == 0) continue;

					direction move = move_directions[j];
					pos move_pos = { crt_pos.first + move.first, crt_pos.second + move.second };

					int move_tunnel_type = map[move_pos.first][move_pos.second];
					vector<int> move_tunnel = tunnels[move_tunnel_type];

					if (move_tunnel[(j + 2) % 4] == 1 && !visited[move_pos.first][move_pos.second]) {
						visited[move_pos.first][move_pos.second] = true;
						count++;
						will_visit_pos.push(move_pos);
					}
				}
			}
			this_time++;
			
		}
		cout << "#" << test_case << " " << count << endl;
	}

	return 0;
}