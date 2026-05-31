class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
      int k = 0;
      for (int i = 0; i< n ; i++)
      {
        int ch = nums[i];
        while (i < n && ch == nums[i] )
        {
                i++;
        }
        nums[k++] = ch;
        i--;
      }  

      return k;
    }
};