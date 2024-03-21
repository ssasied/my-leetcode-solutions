


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string substring="";
        int max_length=0;
        if(s.length()==1){
            return 1;
        }
        for(char letter:s){
            auto it =find(substring.begin(),substring.end(),letter);
            if(it!=substring.end())
            {
                
                if(substring.length()>max_length){
                max_length=substring.length();}    
                int index =  std::distance(substring.begin(), it);
                substring.erase(0,index+1);
            }
            substring+=letter;
        }
         if(substring.length()>max_length){
                max_length=substring.length();}
        return max_length;
    }
};