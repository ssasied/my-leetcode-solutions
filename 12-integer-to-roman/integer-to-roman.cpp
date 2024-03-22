class Solution {
public:
    string intToRoman(int num) {
        int mult=1;
        int mult2=10;
        string result="";

        int nom=(num/mult)%10;
        int index=0;
        char t[4]={'I','X','C','M'};        
        char f[3]={'V','L','D'};
        while(num/mult){            
            switch (nom){
                case 0:                
                    break;
                case 1:
                    result=t[index]+result;
                    break;
                case 2:
                    result=t[index]+result;
                    result=t[index]+result;
                    break;
                case 3:           
                    result=t[index]+result;
                    result=t[index]+result;
                    result=t[index]+result;
                    break;
                case 4:
                    result=f[index]+result;
                    result=t[index]+result;
                    break;
                case 5:
                    result=f[index]+result;
                    break;
                case 6:
                    result=t[index]+result;
                    result=f[index]+result;
                    break;
                case 7:
                    result=t[index]+result;
                    result=t[index]+result;
                    result=f[index]+result;
                    break;
                case 8:
                    result=t[index]+result;
                    result=t[index]+result;                    
                    result=t[index]+result;
                    result=f[index]+result;
                    break;
                case 9:
                    result=t[index+1]+result;
                    result=t[index]+result;
                    break;
                }
                mult*=10;
                nom=(num/mult)%10;
                index++;
        }
        return result;
    }
};