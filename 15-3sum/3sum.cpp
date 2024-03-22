class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> triplets;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int leftindex = i + 1;
        int rightindex = nums.size() - 1;
        while (leftindex < rightindex) {
            int sum = nums[i] + nums[leftindex] + nums[rightindex];
            if (sum == 0) {
                triplets.insert({nums[i], nums[leftindex], nums[rightindex]});
                // Update indices and skip duplicates
                while (leftindex < rightindex && nums[leftindex] == nums[leftindex + 1]) {
                    ++leftindex;
                }
                while (leftindex < rightindex && nums[rightindex] == nums[rightindex - 1]) {
                    --rightindex;
                }
                ++leftindex;
                --rightindex;
            } else if (sum < 0) {
                ++leftindex;
            } else {
                --rightindex;
            }
        }
    }
    vector<vector<int>> result(triplets.begin(), triplets.end());
    return result;
}
};