class Solution {
public:
    bool isPalindrome(string s) {
        bool isp=true;
        int l=0;
        int r=s.size()-1;
        while(l<r){
            while(!((s[l]>='a'&&s[l]<='z')||(s[l]>='A'&&s[l]<='Z')||(s[l]>='0'&&s[l]<='9'))&&l<r){
                l++;
            }
            cout<<'\n';
            while(!((s[r]>='a'&&s[r]<='z')||(s[r]>='A'&&s[r]<='Z')||(s[r]>='0'&&s[r]<='9'))&&r>l){
                r--;
            }
            s[l]=tolower(s[l]);
            s[r]=tolower(s[r]);
            if(!(s[l]==s[r])){isp=false;break;}
            l++;
            r--;
        }
        return isp;
    }
};