class Solution {
public:
    bool isPalindrome(string s) {
        bool isp=true;
        int l=0;
        int r=s.size()-1;
        while(l<r){            
            s[l]=tolower(s[l]);
            s[r]=tolower(s[r]);
            while(!((s[l]>='a'&&s[l]<='z')||(s[l]>='0'&&s[l]<='9'))&&l<r){                
                l++;
            s[l]=tolower(s[l]);
            }
            while(!((s[r]>='a'&&s[r]<='z')||(s[r]>='0'&&s[r]<='9'))&&r>l){
                r--;                
                s[r]=tolower(s[r]);
            }
            if(!(s[l]==s[r])){isp=false;cout<<s[l]<<l<<' '<<s[r]<<r;break;}
            l++;
            r--;
        }
        return isp;
    }
};