/*
https://leetcode.com/problems/bulls-and-cows/
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        string ans;
        int n = secret.size();
        int b=0,c=0;
        
        vector<int> v1(10,0);
        vector<int> v2(10,0);
        
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                b++;
            }else{
                v1[(secret[i]-'0')]++;
                v2[(guess[i]-'0')]++;
            }
        }

        for(int i=0;i<10;i++){
           c += min(v1[i],v2[i]);
        }

        ans = (to_string(b) + "A" + to_string(c) + "B");
        
        return ans;
    }
};
