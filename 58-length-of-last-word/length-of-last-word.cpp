class Solution {
public:
    int lengthOfLastWord(string s) {
        int ssi=s.size()-1;
        while(ssi>=0&&s[ssi]==' '){ssi--;}
        int s2=ssi;
        while(s2>=0&&s[s2]!=' '){s2--;}
        return ssi-s2;
    }
};