/*
https://leetcode.com/problems/max-points-on-a-line/
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxPoint =0;
        int n = points.size();
        
        // max len = 300
        for(int i=0; i<n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            unordered_map<double,int> mp; //(slope, count)
            for(int j=i+1; j<n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                double slope;
                if((x2-x1)==0) {
                    slope = 100001; //take out of bound val for infinite slope
                    mp[slope]++; 
                }
                else{
                    slope = double((y2-y1))/double((x2-x1));
                    mp[slope]++;
                    // cout<<p[j][1]<<" "<<p[i][1]<<" "<<p[j][0]<<" "<<p[i][0]<<" "<<double((y2-y1))/double((x2-x1))<<endl;
                }
                maxPoint = max(maxPoint, mp[slope]);
            }
        }

        return maxPoint+1;
    }
};
