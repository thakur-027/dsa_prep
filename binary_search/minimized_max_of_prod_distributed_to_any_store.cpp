class Solution {
public:

    // check if capacity x works
    bool canDistribute(vector<int>& quantities, int n, int x) {

        long long storesNeeded = 0;

        for(int q : quantities) {
            // split q items into groups of size x
            storesNeeded += (q + x - 1) / x;   // ceil(q/x)

            if(storesNeeded > n)
                return false;   // need more stores than available
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        int low = 1;                         // minimum capacity
        int high = *max_element(quantities.begin(), quantities.end());

        int ans = high;

        while(low <= high) {

            int mid = (low + high) / 2;

            if(canDistribute(quantities, n, mid)) {
                ans = mid;       // possible → try smaller
                high = mid - 1;
            }
            else {
                low = mid + 1;   // impossible → increase capacity
            }
        }

        return ans;
    }
};
