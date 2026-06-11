class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;

        while (i < n) {
            int j = i;

            while (j < n && s[j] != ' ') {
                j++;
            }

           
            int l = i, r = j - 1;
            while (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }

            i = j + 1;
        }

        return s;
    }
};