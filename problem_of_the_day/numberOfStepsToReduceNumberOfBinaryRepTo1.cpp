class Solution {
public:
    int numSteps(string s) {

        int steps = 0;
        int carry = 0;

        // start from last bit (LSB) and stop before MSB
        for(int i = s.size() - 1; i > 0; i--) {

            int bit = (s[i] - '0') + carry;

            // even -> divide by 2
            if(bit % 2 == 0) {
                steps += 1;
            }
            // odd -> add 1 then divide
            else {
                steps += 2;
                carry = 1;
            }
        }

        // if carry remains, MSB becomes 10 -> needs one more step
        return steps + carry;
    }
};
