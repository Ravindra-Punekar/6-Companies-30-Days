/*
https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
*/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k>s.size()) return false;
        unordered_set<string> st;

        string win = s.substr(0, k);
        st.insert(win);
        
        for(int i=1; i<=s.size()-k; i++){
            win.erase(win.begin());
            win+= s[i+k-1];
            // cout<<win<<" ";
            st.insert(win);
        }
        // for(auto str:st) cout<<str<<" ";
        return st.size()==pow(2,k);
    }
};
