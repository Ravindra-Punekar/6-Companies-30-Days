/*
https://leetcode.com/problems/maximum-matrix-sum/
*/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        /*We can pair as much we want
        therefore if there are even negative numbers we can make every element positive
        but if there are odd we can assign odd to smallest number */
        long long ans=0;
        int negCount=0;
        int absMin=INT_MAX;
        for(auto v:matrix){
            for(auto i:v){
                if(i<0){
                    negCount++;
                }
            
                absMin=min(absMin,abs(i));
                ans+=abs(i);
            }
        }
        if(negCount %2==0){
            return ans;
        }
        ans-= 2*(absMin); //one for neg val and one for being added 
        return ans;
        
    }
        
};
