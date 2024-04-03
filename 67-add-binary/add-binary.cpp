class Solution {
public:
    string addBinary(string a, string b) {
        string result="";
        bool carry=false;
        int ita=a.size()-1;
        int itb=b.size()-1;
        while(ita>=0&&itb>=0){
            // cout<<a[ita]<<" "<<b[itb]<<'\n';
            // if(carry)cout<<1<<'\n';
            // else cout<<0<<'\n';
            if(a[ita]=='1'&&b[itb]=='1'){
                if(carry)result='1'+result;
                else result='0'+result;
                carry=true;
            }
            else if(a[ita]=='1'&&b[itb]=='0'){
                if(carry)result='0'+result;
                else result='1'+result;
            }
            else if(a[ita]=='0'&&b[itb]=='1'){                
                if(carry)result='0'+result;
                else result='1'+result;
            }
            else if(a[ita]=='0'&&b[itb]=='0'){                
                if(carry)result='1'+result;
                else result='0'+result;
                carry=false;
            }
            ita--;
            itb--;
        }
        if(itb>=0){
            for(int i=itb;i>=0;i--){
            //     cout<<b[itb]<<'\n';
            // if(carry)cout<<1<<'\n';
            // else cout<<0<<'\n';
                if(b[i]=='1'){
                    if(carry)result='0'+result;
                    else {result='1'+result;carry=false;}
                }
                else if(b[i]=='0'){
                    carry?result='1'+result:result='0'+result;
                    carry=false;                
                }
            }
        }
        else{
            for(int i=ita;i>=0;i--){
            //     cout<<a[ita]<<'\n';
            // if(carry)cout<<1<<'\n';
            // else cout<<0<<'\n';
                if(a[i]=='1'){
                    if(carry)result='0'+result;
                    else {result='1'+result;carry=false;}
                }
                else if(a[i]=='0'){
                    carry?result='1'+result:result='0'+result;
                    carry=false;                
                }
            }
        }
        if(carry)result='1'+result;
        return result;
    }
};