class Solution {
public:

// check palindrome using indices instead of creating new string
void helper(string &s, int start, int end, int &maxcount, string &ans)
{
    int i = start;
    int j = end;

    while (i < j)
    {
        if (s[i] != s[j])
            return;
        i++;
        j--;
    }

    int len = end - start + 1;

    if (len > maxcount)
    {
        maxcount = len;
        ans = s.substr(start, len);
    }
}

string longestPalindrome(string s) {

    int n = s.size();
    int maxcnt = 0;
    string ans = "";

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            helper(s, i, j, maxcnt, ans);
        }
    }

    return ans;
}
};