class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0, rp = height.size()-1;
        int ans = 0;
        while(lp<rp){
            int w = rp - lp;
            int ht = min(height[lp], height[rp]);
            int currWater = w*ht;
            ans = max(ans, currWater);
            height[lp]<height[rp]?lp++:rp--;
        }
        return ans;
    }
};
