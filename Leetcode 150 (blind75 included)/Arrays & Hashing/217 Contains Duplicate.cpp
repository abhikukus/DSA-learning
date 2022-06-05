class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        int map[2 * 1000000001] = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            if (x < 0)
            {
                x = -1 * x;
                map[x * 2]++;
            }
            else
            {
                map[x]++;
            }
        }

        for (int i = 0; i < map.length; i++)
        {
            if (map[i] > 1)
            {
                return true;
            }
        }

        return false;
    }
};