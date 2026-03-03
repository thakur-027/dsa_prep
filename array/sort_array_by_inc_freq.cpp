class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        unordered_map<int,int> freq;

        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            freq[x]++;
        }

        // Sort with custom comparator
        sort(nums.begin(), nums.end(), [&](int a, int b){
            
            if(freq[a] == freq[b]) 
                return a > b;          // if same freq → bigger number first
            
            return freq[a] < freq[b];  // smaller freq first
        });

        return nums;
    }
};
