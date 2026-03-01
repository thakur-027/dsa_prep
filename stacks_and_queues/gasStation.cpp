class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totalFuel = 0;
        int currFuel = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); i++) {

            int diff = gas[i] - cost[i];

            totalFuel += diff;
            currFuel += diff;

            // cannot reach next station
            if(currFuel < 0) {
                start = i + 1;
                currFuel = 0;
            }
        }

        return totalFuel >= 0 ? start : -1;
    }
};
