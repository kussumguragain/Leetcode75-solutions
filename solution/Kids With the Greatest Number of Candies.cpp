class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = *max_element(candies.begin(), candies.end());//this will determine the maximum candies in the array
        vector<bool> result;//boolen vector to store the boolen value

        for(int i=0; i<candies.size(); i++){
         if(candies[i] + extraCandies >= maxCandy){//if the candy at the current position of the array plus the extracandy is greater then the max candy then only we return true otherwise false

            result.push_back(true);
            
           }else{
            result.push_back(false);
           }

        }
       
        return result;
    }
};