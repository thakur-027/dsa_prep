class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int n = stockPrices.size();
        
        // Edge cases: 0 or 1 point requires 0 lines.
        if (n <= 1) {
            return 0;
        }
        
        // Sort the stock prices by day
        sort(stockPrices.begin(), stockPrices.end());
        
        // At least 2 points will form 1 initial line
        int lines = 1;
        
        for (int i = 2; i < n; i++) {
            // Calculate differences in x and y coordinates
            long long dy1 = stockPrices[i-1][1] - stockPrices[i-2][1];
            long long dx1 = stockPrices[i-1][0] - stockPrices[i-2][0];
            long long dy2 = stockPrices[i][1] - stockPrices[i-1][1];
            long long dx2 = stockPrices[i][0] - stockPrices[i-1][0];
            
            // Cross-multiply to check if slopes are different
            if (dy1 * dx2 != dy2 * dx1) {
                lines++; // Slope changed, a new line is needed
            }
        }
        
        return lines;
    }
};
