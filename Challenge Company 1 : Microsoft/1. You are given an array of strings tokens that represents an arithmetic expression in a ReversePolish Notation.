class Solution {
public: 
    int ans; 
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        st.push( stoi(tokens[0]));
        int i=1;

        //below is called lambda function
        unordered_map<string, function<int (int,int)>> mp = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (long a, long b) { return  a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };

        for(auto it:tokens){
            if(it.size()>1 || isdigit(it[0])){
                int n = stoi(it);
                st.push(n);
            }
            else{
                int a,b,c;
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                st.push(mp[it](b,a));
            }
        }

        return st.top();
    }
};
