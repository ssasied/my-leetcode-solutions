class Solution {
public:
    /*my submisiions:
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

    //////////////////////////////////////////

     int singleNumber(vector<int>& nums) {        
        if(nums.size()<2)return nums[0];
        sort(nums.begin(),nums.end());
        if(nums[0]!=nums[1])return nums[0];
        for(int i=0;i<nums.size();i+=2){
            if(nums[i]!=nums[i+1]){
                if(i>0&&nums[i-1]!=nums[i])return nums[i];
                return nums[i+1];
            }
        }
        return 0;
    }
*/
    //smart solution idk why i didnt think of that
    //if you xor something two times it doesnt change but if u xor once you get that number
     int singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int i = 0; i<nums.size(); i++){
            xorr = xorr ^ nums[i];
        }
        return xorr;
    }
};