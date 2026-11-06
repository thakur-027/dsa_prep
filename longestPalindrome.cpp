class Solution {
public:
    int longestPalindrome(string s) {
        // Use an array to store the frequency of characters.
        // Size 128 is enough to cover all ASCII characters, 
        // though 52 would suffice for just lowercase and uppercase letters.
        int charCounts[128] = {0}; 
        for (char c : s) {
            charCounts[c]++;
        }

        int length = 0;
        bool hasOddCount = false;

        for (int count : charCounts) {
            // Add the even part of the count to the length
            length += (count / 2) * 2; 
            
            // Check if there is an odd count
            if (count % 2 == 1) {
                hasOddCount = true;
            }
        }

        // If there was any character with an odd count, 
        // we can place one in the middle of the palindrome.
        if (hasOddCount) {
            length += 1;
        }

        return length;
    }
};
