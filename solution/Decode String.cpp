class Solution {
public:
    string decodeString(string s) {
        std::stack<int> numberStack;       
        std::stack<std::string> stringStack; 
        std::string currentString = "";    
        int number = 0;                    

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                //to process both single and multi digits
                number = number * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                // push current number and string to their stacks
                numberStack.push(number);
                stringStack.push(currentString);
                number = 0;  
                currentString = "";  
            } else if (s[i] == ']') {
                
                int repeatCount = numberStack.top();
                numberStack.pop();
                std::string temp = currentString;
                currentString = stringStack.top();
                stringStack.pop();
                
                for (int j = 0; j < repeatCount; j++) {
                    currentString += temp;
                }
            } else {
                
                currentString += s[i];
            }
        }

        return currentString;  
    }
};