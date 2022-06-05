class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        unordered_map<string, vector<string>> umap;

        for (int i = 0; i < strs.size(); i++)
        {
            int idx[26] = {0};
            string w = strs[i];
            for (int j = 0; j < w.size(); j++)
            {
                idx[w[j] - 'a'] += 1;
            }

            string key = "";
            for (auto x : idx)
            {
                key += x;
            }

            umap[key].push_back(w);
        }

        vector<vector<string>> ans;
        for (auto x : umap)
        {
            ans.push_back(x.second);
        }

        return ans;
    }
};