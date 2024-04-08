class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1)return {{1}};
        if(numRows==2)return {{1},{1,1}};
        vector<vector<int>>result={{1},{1,1}};
        for(int i=1;i<numRows-1;i++){
            vector<int>row(1,1);
            for(int j=1;j<i+1;j++){
                row.push_back(result[i][j-1]+result[i][j]);
            }
            row.push_back(1);
            result.push_back(row);
        }
        return result;
    }
};