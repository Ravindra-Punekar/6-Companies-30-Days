/*
https://leetcode.com/problems/invalid-transactions/
*/

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<string> invalid;
        
        vector<string> name, city;
        vector<int> time, amount;

        for(auto t:transactions){
            int i=0;
            string n,ti,a,c; 
            while(t[i]!=',')    n+=t[i++];
            i++;
            while(t[i]!=',')    ti+=t[i++];
            i++;
            while(t[i]!=',')    a+=t[i++];
            i++;
            while(i<t.size())   c+=t[i++];
            name.push_back(n);
            time.push_back(stoi(ti));
            amount.push_back(stoi(a));
            city.push_back(c);
        }

        unordered_set<int> vis;
        for(int i=0; i<n; i++){
            if(amount[i]>1000){
                if(!vis.count(i)) invalid.push_back(transactions[i]);
                vis.insert(i);
                continue;
            }
            for(int j=0; j<n; j++){
                if(i==j) continue; 
                if(name[i]==name[j] && city[i]!=city[j]){
                    if(abs(time[i]-time[j])<=60){
                        if(!vis.count(i)) invalid.push_back(transactions[i]);
                        if(!vis.count(j)) invalid.push_back(transactions[j]);
                        vis.insert(i);
                        vis.insert(j);
                    }
                }
            }
        }

        return invalid;
    }
};
