class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        sort(nums.begin(),nums.end());
        int longest=0;
        int current=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                current++;
            }
            else if(nums[i]==nums[i-1])continue;
            else if(current>longest){               
                longest=current;
                current=0;
            }
            else{
                current=0;
            }
        }
        if(longest<current)longest=current;
        return longest+1;
    }
};