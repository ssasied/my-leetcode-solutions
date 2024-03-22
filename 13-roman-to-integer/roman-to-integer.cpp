class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        int index=0;
        while(index<s.size()){
            switch(s[index]){
                case 'I':
                    if(index+1<s.size()){
                        if(s[index+1]=='V')
                        {
                            result+=4;
                            index++;
                            break;
                        }
                        else if(s[index+1]=='X')
                        {
                            result=result+=9;
                            index++;
                            break;
                        }                      
                    }
                    result+=1;
                    break;
                    case 'X':
                    if(index+1<s.size()){
                        if(s[index+1]=='L')
                        {
                            result+=40;
                            index++;
                            break;
                        }
                        else if(s[index+1]=='C')
                        {
                            result=result+=90;
                            index++;
                            break;
                        }                        
                    }
                    result+=10;
                    break;
                    case 'C':
                    if(index+1<s.size()){
                        if(s[index+1]=='D')
                        {
                            result+=400;
                            index++;
                            break;
                        }
                        else if(s[index+1]=='M')
                        {
                            result=result+=900;
                            index++;
                            break;
                        }                       
                    }
                    result+=100;
                    break; 
                    case 'V':
                    result+=5;                    
                    break;
                    case 'L':
                    result+=50;                    
                    break;
                    case 'D':
                    result+=500;                    
                    break;
                    case 'M':
                    result+=1000;                    
                    break;
            }
            index++;
        }
        return result;
    }
};