class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
		int extrapetrol = 0;
		int requiredpetrol = 0;
		for (int i = 0; i < cost.size(); i++) {
			extrapetrol+=gas[i]-cost[i];
			if(extrapetrol<0) {
				start  = i+1;
				requiredpetrol +=extrapetrol;
				extrapetrol = 0;
			}
		}
		if(requiredpetrol + extrapetrol >= 0) return start;
		return -1;
        
    }
};