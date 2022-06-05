class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> ss(28, 0);
        vector<int> tt(28, 0);

        for (auto i : s)
        {
            ss[i - 'a']++;
        }

        for (auto i : t)
        {
            tt[i - 'a']++;
        }
        for (int i = 0; i < 28; i++)
        {
            if (ss[i] != tt[i])
            {
                return false;
            }
        }
        return true;
    }
};