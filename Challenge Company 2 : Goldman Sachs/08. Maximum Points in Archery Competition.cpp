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

        backtrack(numArrows, section+1, score, alice, temp);    //bob lose here(Don't Shoot)

        if(alice[section]+1 <= numArrows){
            temp[section] = alice[section]+1;   //bob wins here by shooting 1 more arrow than alice
            backtrack(numArrows-(alice[section]+1), section+1, score+section, alice, temp); 
            temp[section] = 0;  //backtrack
        }
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> temp(12,0);
        int score=0;
        backtrack(numArrows,0,score, aliceArrows, temp);
        return BobArrows;
    }
};
