#include <iostream>
#include <vector>
#include <map>


using namespace std;

typedef struct {
	int origin_group;
	int weight;
}sample;

void solve(int test_case) {
	int sample_num, task_num;

	cin >> sample_num >> task_num;
	
	vector<sample> samples(sample_num + 1, {0, 0});
	vector<vector<int>> belong_groups;

	map<pair<int, int>, int> relative_weight;
	//vector<vector<pair<int, int>>> relative_weight(1);


	int group_count = 0;
	cout << "#" << test_case << " ";
	for (int i = 0; i < task_num; i++) {
		char c;
		cin >> c;
		if (c == '!') {
			int light, heavy, diff;
			cin >> light >> heavy >> diff;
			if (samples[light].origin_group != 0 && samples[heavy].origin_group) { // new group
				group_count++;

				belong_groups.push_back(vector<int>());

				samples[light].origin_group = samples[heavy].origin_group = group_count;
				belong_groups[group_count].push_back(group_count);

				samples[light].weight = 0;
				samples[heavy].weight = diff;
			} else if (samples[light].origin_group != 0 && samples[heavy].origin_group != 0) {
				int now_group_light = belong_groups[light].back();
				int now_group_heavy = belong_groups[heavy].back();
				if (now_group_light == now_group_heavy) continue;
				
				if (now_group_light < now_group_heavy) {
					belong_groups[heavy].push_back(now_group_light);
				} else {
					belong_groups[light].push_back(now_group_heavy);
				}

				//relative_weight[samples[light].origin_group].push_back({ samples[heavy].origin_group, diff});
				//relative_weight[samples[heavy].origin_group].push_back({ samples[light].origin_group, -diff });

				//group의 가장 작은 것과 거리를 계산해서 저장
				//group min -> now_gourp 거리 = group_min -> now_group간의 거리 + group_min -> now_group_light or now_gruop_heavy 거리

				//relative_weight.insert({ { samples[light].origin_group, samples[heavy].origin_group }, diff });
				//relative_weight.insert({ { samples[heavy].origin_group, samples[light].origin_group }, -diff });

				int small_group_num = min(now_group_light, now_group_heavy);

				//if (samples[light].belong_groups.back() == samples[heavy].belong_groups.back()) continue;
				//int remain_group = samples[light].group_num;
				//int remain_base_num = samples[light].weight;

				//int light_now_group = samples[light].belong_groups.back();
				//int heavy_now_group = samples[heavy].belong_groups.back();

				//int merge_base_num = samples[heavy].weight;

				//merge_group[remain_group].push_back({ merge_target_group, remain_base_num + diff + merge_base_num });
				//merge_group[merge_target_group].push_back({})

				/*for (int merge_sample : group[merge_group]) {
					samples[merge_sample].group_num = remain_group;
					samples[merge_sample].weight = remain_base_num + diff - samples[merge_sample].weight + merge_base_num;
				}*/
			} else {
				if (samples[light].origin_group == 0) {
					samples[light].origin_group = samples[heavy].origin_group;
					samples[light].weight = samples[heavy].weight - diff;
				}
				else {
					samples[heavy].origin_group = samples[light].origin_group;
					samples[heavy].weight = samples[light].weight + diff;
				}
			}
		}
		else if (c == '?') {
			int first, second;
			cin >> first >> second;
			int origin1 = samples[first].origin_group;
			int origin2 = samples[second].origin_group;
			if (origin1 != 0 && origin2 != 0
				&& belong_groups[origin1].back() == belong_groups[origin2].back()) {
				//origin1->belong_groups[origin1].back()->origin2

				for(int belonged_group : belong_groups[origin1] )


				cout <<  samples[second].weight - samples[first].weight << " ";
			} else {
				cout << "UNKNOWN ";
			}
		}
	}
	cout << endl;
}