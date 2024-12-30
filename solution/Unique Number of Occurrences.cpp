class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::vector<int> occurrences; // To store frequencies of each number
        std::vector<int> checked; // To store the numbers we've already checked

        for (int i = 0; i < arr.size(); i++) {
            int count = 0; 
            bool found = false;

            // we check if this number has already been checked
            for (int j = 0; j < checked.size(); j++) {
                if (arr[i] == checked[j]) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                // Count occurrences of arr[i] in the array
                for (int j = 0; j < arr.size(); j++) {
                    if (arr[i] == arr[j]) {
                        count++;
                    }
                }

                for (int k = 0; k < occurrences.size(); k++) {
                    if (occurrences[k] == count) {
                        return false; // we found the duplicate frequency
                    }
                }

                checked.push_back(arr[i]);
                occurrences.push_back(count);
            }
        }

        return true;
    }

};