class Solution {
public:
    int maxVowels(string s, int k) {
        int maxVowels = 0; //maximum number of vowels in any window of size k
        int currentVowels = 0; //vowel count at the current sliding window

        //Define a set of vowels
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        //count the vowels in the first window of size k
           for(int i = 0; i < k; i++){
           if (vowels.find(s[i]) != vowels.end()){ //if the character is vowel it increment currentvowels
                currentVowels++;
            }

           }

            maxVowels = currentVowels; //Initialize maxVowels with the first window's count

            for(int i = k; i < s.size(); i++){
                ////removing the vowelcount of the character that is sliding out of the window
                if (vowels.find(s[i - k]) != vowels.end()){
                    currentVowels--;
                }
                
                //Add the impact of the character that is sliding into the window
                if (vowels.find(s[i]) != vowels.end()){
                    currentVowels++; 
                }

                maxVowels = max(currentVowels, maxVowels);
            }

        return maxVowels; 
    }
};