#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	int time = 0;
	vector<pair<int, int>> bridge;
	int bridgeload = 0;
	int total = 0;


	while (1) {
		time += 1;

		if (!bridge.empty()) {
			if (time - bridge[0].first == bridge_length) {
				bridgeload -= bridge[0].second;
				bridge.erase(bridge.begin());
			}
		}

		if (bridge.empty() && truck_weights.empty()) {
			break;
		}
        
        if(!truck_weights.empty()){
	    	if (weight - bridgeload >= truck_weights[0]) {
		    	bridge.push_back(make_pair(time, truck_weights[0]));
			    bridgeload += truck_weights[0];
			    truck_weights.erase(truck_weights.begin());
		    }
        }

	}

	answer = time;



	return answer;
}
