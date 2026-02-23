class Solution {
public:

    bool checkPalindrome(int left, int right, string &s){
        while(left < right){
            if(s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void substring(string &s, vector<vector<string>> &ans, int index, vector<string> &arr){

        if(index == s.size()){
            ans.push_back(arr);
            return;
        }

        for(int i = index; i < s.size(); i++){

            if(checkPalindrome(index, i, s)){

                arr.push_back(s.substr(index, i-index+1));

                substring(s, ans, i+1, arr);

                arr.pop_back(); // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> arr;

        substring(s, ans, 0, arr);
        return ans;
    }
};
