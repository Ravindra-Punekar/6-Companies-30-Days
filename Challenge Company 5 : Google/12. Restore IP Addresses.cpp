/*
https://leetcode.com/problems/restore-ip-addresses/
*/

class Solution {
public:
    void solve(string& s, vector<string>& ans, string cur_str, string lastdig, int i, int dots ){
       
        if( stoi(lastdig)>255|| dots>3 || i>s.size())
            return;
        if(lastdig[0]=='0' && lastdig.size()>1)return;
        
        if(i==s.size()){
            if(dots==3)
                ans.push_back(cur_str);
            return ;
        }

        string t="";
        solve(s, ans, cur_str+"."+s[i], t+s[i], i+1, dots+1);   // take .

        solve(s, ans, cur_str+s[i], lastdig+s[i], i+1, dots);   // skip .
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string cur_str;
        solve(s, ans, cur_str+s[0], cur_str+s[0], 1, 0);
        return ans;
    }
};
