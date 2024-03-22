class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp=strs[0];
        int strsize=strs.size();
        for(int i=1;i<strsize;i++){
            int counter=0;
            for(int j=0;j<strs[i].length();j++){
                if(lcp[j]!=strs[i][j])break;
                counter++;
            }
            if(counter<lcp.length()){
                lcp.erase(lcp.begin()+counter,lcp.end());
            }
            counter=0;
        }
        return lcp;
    }
};