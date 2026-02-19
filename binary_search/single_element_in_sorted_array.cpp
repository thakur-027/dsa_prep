class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            // make mid even
            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1]) {
                // single element is on right
                s = mid + 2;
            } else {
                // single element is on left including mid
                e = mid;
            }
        }

        return nums[s];
    }
};

