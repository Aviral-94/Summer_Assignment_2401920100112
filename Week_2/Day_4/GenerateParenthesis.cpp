class Solution {
public:
  void recurse(int open ,int close ,int n,string &s ,vector<string>&ans)
  {
    if (open == n && close == n)
    {
    ans.push_back(s);
    return;
    }
if (open < n)
{
    s.push_back('(');
    recurse(open+1,close,n,s,ans);
    s.pop_back();
}
if (close < open)
{
    s.push_back(')');
    recurse(open , close+1,n,s,ans);
      s.pop_back();
}
  }
    vector<string> generateParenthesis(int n) {
       string s ;
       vector<string>ans;
       recurse(0,0,n,s,ans);
       return ans;
    }
};