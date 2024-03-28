class Solution {
public:
    int lengthOfLastWord(string s) {
        int ss=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' ')ss++;
            else{
                if(ss)return ss;
            }
        }
        return ss;
    }
};