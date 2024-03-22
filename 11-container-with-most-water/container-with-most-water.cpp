class Solution {
public:
int maxArea(vector<int>& height) {
    int v = min(height[0], height[height.size() - 1]) * (height.size() - 1);
    int l = 0;
    int r = height.size() - 1;
    while (l < r) {
        int mm = min(height[l], height[r]);
        v = max(mm * (r - l), v);
        if(height[l] < height[r]) l++;
        else if(height[l] > height[r]) r--;
        else {
            l++;
            r--;
        }
    }
    return v;
}
};