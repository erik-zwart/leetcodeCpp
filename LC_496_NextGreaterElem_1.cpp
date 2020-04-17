class Solution {
    int nextGreater(vector<int>& nums, int a) {
        bool begin = false;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == a) begin = true;
            else {
                if(begin && nums[i] > a) return nums[i];
            }
        }
        return -1;
    }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(auto a : nums1) {
            res.push_back(nextGreater(nums2, a));
        }
        return res;
    }
};
