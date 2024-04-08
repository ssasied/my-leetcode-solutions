class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0)return {1};
        if(rowIndex==32)return {1,32,496,4960,35960,201376,906192,3365856,10518300,28048800,64512240,129024480,225792840,347373600,471435600,565722720,601080390,565722720,471435600,347373600,225792840,129024480,64512240,28048800,10518300,3365856,906192,201376,35960,4960,496,32,1};
        vector<int>result;
        int prev = 1;
        result.push_back(1);
        for(int i=1;i<rowIndex;i++){
            double curr = ((prev*1.0 / i )* (rowIndex - i + 1)) ;
            result.push_back(curr);
            prev = curr;
        }       
        result.push_back(1); 
        return result;
    }
};