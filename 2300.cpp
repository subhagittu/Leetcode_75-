class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = potions.size();
        vector<int> ans;
        sort(potions.begin(), potions.end());

        for(int i : spells) {
            int pos = lower_bound(potions.begin(), potions.end(), ceil((double)success / i)) - potions.begin();
            ans.push_back(n - pos);
        }
        return ans;
    }
};
