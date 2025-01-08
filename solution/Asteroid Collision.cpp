class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> answer; 

        for (int asteroid : asteroids) {
            bool destroyed = false; // Flag to track if the current asteroid is destroyed

            while (!answer.empty() && asteroid < 0 && answer.back() > 0) {
                if (abs(asteroid) == abs(answer.back())) {
                    // If both asteroids are of the same size, destroy both
                    answer.pop_back();
                    destroyed = true;
                    break;
                } else if (abs(asteroid) > abs(answer.back())) {
                    // If the current asteroid is larger, destroy the last one in the list
                    answer.pop_back();
                } else {
                    // If the last asteroid in the list is larger, destroy the current one
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                // If the asteroid survives, add it to the list
                answer.push_back(asteroid);
            }
        }

        // Convert list to vector for the final result
        return vector<int>(answer.begin(), answer.end());
    }
};