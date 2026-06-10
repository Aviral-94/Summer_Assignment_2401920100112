class Solution {
public:
    int strStr(string haystack, string needle) {
      int n = haystack.size();
      if (haystack.find(needle) >=0 )
      {
        return haystack.find(needle);
      }
      return -1 ;
    }
};