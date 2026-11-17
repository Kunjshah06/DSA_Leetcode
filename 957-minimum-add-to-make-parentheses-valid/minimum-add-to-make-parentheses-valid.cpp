class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;   // unmatched '('
        int add = 0;    // additions needed
        
        for(char c : s) {
            if(c == '(') {
                open++;
            }
            else { // ')'
                if(open > 0) {
                    open--;  // match with previous '('
                } 
                else {
                    add++;   // need an extra '('
                }
            }
        }
        
        return add + open;
    }
};
