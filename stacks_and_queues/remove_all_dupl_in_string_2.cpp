#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    string removeDuplicates(string s, int k) {
        // Use the formal stack library
        stack<pair<char, int>> st;
        
        for (char c : s) {
            if (!st.empty() && st.top().first == c) {
                // Increment count if it matches the top element
                st.top().second++;
                
                // Pop immediately if it reaches k
                if (st.top().second == k) {
                    st.pop();
                }
            } else {
                // Push new character with a count of 1
                st.push({c, 1});
            }
        }
        
        // Reconstruct the string
        string result = "";
        while (!st.empty()) {
            result.append(st.top().second, st.top().first);
            st.pop();
        }
        
        // Since we popped from a LIFO data structure, the string is backwards
        reverse(result.begin(), result.end());
        
        return result;
    }
};
