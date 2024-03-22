class Solution {
public:
     
    //this is a super dumb solution and is in no means correct.
    //did it just for fun


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
    vector<string> generateParenthesis(int n) {       
        string par="(";
        vector<string>result;
        for(int i=0;i<n-1;i++){
            par+='(';
        }
        for(int i=0;i<n;i++){
            par+=')';
        }
        do{
            if(isValid(par))result.push_back(par);
        }while(next_permutation(par.begin()+1,par.end()));
        return result;
   
    }
};