class Solution {
public:
    string addBinary(string a, string b) {
        //popatrzyem na rozwiazanie i doznalem olsnienia
        string result="";
        int carry=0;
        int ita=a.size()-1;
        int itb=b.size()-1;
        while(ita>=0||itb>=0||carry){
            if(ita>=0){
                carry+=a[ita--]-'0';
            }
            if(itb>=0){
                carry+=b[itb--]-'0';
            }      
            char a=carry%2+'0';     
            result=a+result;
            carry*=0.5;
        }
        return result;
    }
};