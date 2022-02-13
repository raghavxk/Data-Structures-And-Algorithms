class Solution
{
public:
    vector<vector<int>> ans;

    void solve(vector<int> nums, int i)
    {
        int j = 0;
        vector<int> res;
        while (i > 0)
        {
            if ((i & 1) == 1)
            {
                res.push_back(nums[j]);
            }
            ++j;
            i = i >> 1;
        }
        ans.push_back(res);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        ans.clear();
        for (int i = 0; i < pow(2, nums.size()); ++i)
        {
            solve(nums, i);
        }
        return ans;
    }
};