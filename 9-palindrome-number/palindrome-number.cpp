class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int x2=x;
        long int reversed=0;
        while(x2){
            reversed=reversed*10+x2%10;
            x2/=10;
        }       
        return reversed==x;
    }
};