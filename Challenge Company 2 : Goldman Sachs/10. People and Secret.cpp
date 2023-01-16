/*
https://leetcode.com/problems/number-of-people-aware-of-a-secret/
*/

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int MOD = 1e9+7;
        vector<long long> dp(n+1,0);   
        dp[0] = 0;
        for(int i=1; i<=delay; i++)
            dp[i] = 1;   
        
        for(int i = delay+1; i<=n; i++){
            for(int j = delay; j<forget; j++){    
                if(i-j<=0)
                    break;
                dp[i] =(dp[i]%MOD + dp[i-j]%MOD)%MOD;
            }
            dp[i]+=1;
            
            if(i-forget>=1) dp[i]--;          
        }

        // for(auto i : dp)
        //     cout<<i<<" ";

        return dp[n]%MOD; 
    }
};
