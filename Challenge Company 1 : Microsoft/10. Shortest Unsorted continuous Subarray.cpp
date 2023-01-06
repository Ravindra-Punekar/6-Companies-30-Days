/*
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l=n-1, r=0;  // 1st wrong ind from dir
        
        stack<int> st1;
        for(int i=0; i<n; i++){
            while(!st1.empty() && nums[st1.top()] > nums[i]){
                 l = min(st1.top(), l);
                st1.pop();
            }
            st1.push(i);
        }
        if(l==n-1) return 0; //already sorted

        stack<int> st2;
        for(int i=n-1; i>=0; i--){
            while(!st2.empty() && nums[st2.top()] < nums[i]){
                r = max(st2.top(), r);
                st2.pop();
            }
            st2.push(i);
        }

        return r-l+1;
    }
};


/* Monotonic Stack for (duplicates and more than one peak ) wont work
below solution only traverse till one peak arrived
it doesnt work for eg: 1,1,3,3,4,2,1
 therefore use stack of ind

*/
        // int n = nums.size();
        // int l=0, r=0;
        // int check=1;
        // int dup = 0;
        
        // stack<int> st;
        // st.push(nums[0]);
        // for(int i=1; i<n && check; i++){
        //     if(st.top() < nums[i]){
        //         st.push(nums[i]);
        //         dup=0;
        //     }
        //     else if(st.top()==nums[i]) dup++;
        //     else{
        //         l = i-1 - dup;
        //         check = 0;    
        //     }
        // }
        // if(check) return 0;

        // stack<int> st2;
        // check=1, dup =0;

        // st2.push(nums[n-1]);
        // for(int i=n-2; i>=0 && check; i--){
        //     if(st2.top() > nums[i]){
        //         st2.push(nums[i]);
        //         dup=0;
        //     }
        //     else if(st2.top()==nums[i]) dup++;
        //     else{
        //         r = i+1 + dup;
        //         check=0;    
        //     }
        // }
        // cout<<l<<" "<<r;
        // return r-l+1;
