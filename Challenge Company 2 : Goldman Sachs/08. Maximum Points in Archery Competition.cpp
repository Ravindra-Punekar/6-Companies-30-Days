/*
https://leetcode.com/problems/maximum-points-in-an-archery-competition/
*/

class Solution {
public:
    vector<int> BobArrows;
    int maxScore= INT_MIN;

    void backtrack(int numArrows, int section, int score, vector<int>& alice, vector<int>& temp ){
        if(section==12){
            if(score>maxScore){
                maxScore=score;
                BobArrows = temp;
                BobArrows[0] += numArrows; //use arrows is remaining
            }
            return;
        }
        
        temp.push_back(0);
        backtrack(numArrows, section+1, score, alice, temp);    //bob lose here
        temp.pop_back();

        if(alice[section]+1 <= numArrows){
            temp.push_back(alice[section]+1);
            backtrack(numArrows-(alice[section]+1), section+1, score+section, alice, temp); //bob wins here
            temp.pop_back();
        }
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> temp;
        int score=0;
        backtrack(numArrows,0,score, aliceArrows, temp);
        return BobArrows;
    }
};
