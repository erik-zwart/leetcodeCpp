class Solution {
    /*
    Algorithm:
    1. Find the max elem and max index of nums.
    2. maintain a res[] 
    3. add maxElem to stack
    4. start from j = maxIndex - 1, decrement j till you reach maxIndex + 1
    5. while(top(stack) < nums[j]) pop(stack)
       nextGreater(ums[j]) = top(stack)
    6. Push nums[j] on stack
    */
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.empty()) return nums;
        std::stack<int> stk;
        int max = std::numeric_limits<int>::min();
        int maxIndex = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > max) {
                max = nums[i];
                maxIndex = i;
            }
        }
        
        int j = maxIndex - 1;
        if(j == -1) j = nums.size() - 1;
        stk.push(max);
        vector<int> res(nums.size());
        res[maxIndex] = -1;
        while(j != maxIndex) {
            auto t = stk.top();
            auto currNum = nums[j];
            while(!stk.empty() && stk.top() <= currNum) stk.pop();
            if(!stk.empty()) res[j] = stk.top();
            else res[j] = -1;
            stk.push(currNum);
            j--;
            if(j == -1) j = nums.size() - 1;
        }
        return res;
    }
};
