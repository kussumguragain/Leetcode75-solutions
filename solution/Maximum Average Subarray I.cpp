class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0; i < k; i++){
            sum += nums[i];
        }

        int maxSum = sum;

        int startIndex = 0;
        int endIndex = k;
        while(endIndex < nums.size()){ //loop will run till the last index

            sum -= nums[startIndex]; //Removing the value in the first index
            startIndex++; //incrementing the first index

            sum += nums[endIndex]; //Adding the value of the first index
            endIndex++;

            maxSum = max(maxSum, sum); //getting maximum sum
        }

        return (double) maxSum / k; //getting the average value
    }
};