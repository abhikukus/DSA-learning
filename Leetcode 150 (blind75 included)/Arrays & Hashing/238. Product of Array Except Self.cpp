class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;

        int pre = 1;
        ans.push_back(pre);
        for (int i = 0; i < n - 1; i++)
        {
            pre *= nums[i];
            ans.push_back(pre);
        }

        int post = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= post;
            post *= nums[i];
        }

        return ans;
    }
};