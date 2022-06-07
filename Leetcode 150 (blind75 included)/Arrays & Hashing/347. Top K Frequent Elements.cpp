class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]] += 1;
        }

        int n = nums.size();
        vector<vector<int>> v;
        v.resize(n + 1);
        for (auto it : umap)
        {
            v[it.second].push_back(it.first);
        }

        vector<int> ans;
        for (int i = n; i > 0; i--)
        {
            if (k <= 0)
            {
                break;
            }
            int s = v[i].size();
            for (int j = 0; j < s; j++)
            {
                if (k <= 0)
                {
                    break;
                }
                ans.push_back(v[i][j]);
                k--;
            }
        }

        return ans;
    }
};