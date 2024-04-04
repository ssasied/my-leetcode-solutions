class Solution {
public:
    int singleNumber(vector<int>& nums) {        
       unordered_map<int,int>vals;
       for(int i:nums){
            vals[i]++;            
       }
       for(auto i:vals){
         if(i.second==1)return i.first;
       }
       return 9;
    }
};