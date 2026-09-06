class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        if(n==1){
            return k==0?1:0;
        }
        int same = 0;
        for(int i=0; i<n-1; i++){
            if(s[i]==s[i+1]){
                same++;
            }
        }
        if(s[n-1]==s[0]){
            same++;
        }
        if(k==same){
            return n-same;
        }
        if(k==same-1){
            return same;
        }
        return 0;
    }
};
