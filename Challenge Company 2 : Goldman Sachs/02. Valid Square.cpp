/*
https://leetcode.com/problems/valid-square/
*/

class Solution {
public:
    int dist(vector<int>& a, vector<int>& b){
        return (b[0]-a[0])*(b[0]-a[0]) + (b[1]-a[1])*(b[1]-a[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        //edge case - two points can be equal
        if(p1==p2 || p1==p3 || p1==p4 || p2==p3 || p2==p4 || p3==p4) return false;

        /* if we pick any two points of square randomly, 
        then line formed by it can either hypotenues or side of square*/
        
        unordered_set<int> s;
        s.insert(dist(p1,p2));
        s.insert(dist(p1,p3));
        s.insert(dist(p1,p4));
        s.insert(dist(p2,p3));
        s.insert(dist(p2,p4));
        s.insert(dist(p3,p4));

        
        if(s.size()>2) return false;
        return true;
    }
};
