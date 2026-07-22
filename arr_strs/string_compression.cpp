class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int write = 0;

        while (i < chars.size()) {
            char current = chars[i];
            int count = 0;

            // Count consecutive occurrences
            while (i < chars.size() && chars[i] == current) {
                i++;
                count++;
            }

            // Write the character
            chars[write++] = current;

            // Write the count if greater than 1
            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};
