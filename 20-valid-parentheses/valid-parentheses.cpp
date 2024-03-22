class Solution {
public:
    bool isValid(string s) {
        if(s.size()<=1)return false;
        if(s[0]==')'||s[0]=='}'||s[0]==']')return false;
        deque<char>par;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                par.push_back(s[i]);
                continue;
            }
            if(s[i]==')'||s[i]=='}'||s[i]==']'){
                if(par.empty())return  false;
                
                switch(s[i]){
                case ')':
                    if(par.back()=='(')par.pop_back();
                    else return false;
                break;
                case '}':
                    if(par.back()=='{')par.pop_back();
                    else return false;
                break;
                case ']':
                    if(par.back()=='[')par.pop_back();
                    else return false;                
                break;
                };
            }
        }
        if(par.empty())return true;
        return false;
    }
};