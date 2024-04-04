class Solution {
public:
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
};