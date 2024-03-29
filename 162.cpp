class Solution {
public:
    int findPeakElement(vector<int>& nums) 
{
        int e = nums.size()-1;
        int s = 0;
        int index;

        while(s<e)
        {
            int m = s + (e-s)/2;
            if(nums[m] > nums[m+1])
            {
                e = m;
            }
            else
            {
                s = m+1;
            }
        }
        return e;
    }
};
