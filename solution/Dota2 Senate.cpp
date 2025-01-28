class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> ra, di;
        int n = senate.length();

        for(int i = 0; i < n; i++){
            (senate[i] == 'R')? ra.push(i) : di.push(i);
        }

            while(!ra.empty() && !di.empty()){
                int r_position = ra.front(), d_position = di.front();

                ra.pop();
                di.pop();

                (r_position < d_position)? ra.push(r_position + n) : di.push(d_position + n);
            }

        return (ra.size() > di.size())? "Radiant" : "Dire";
    }    
};