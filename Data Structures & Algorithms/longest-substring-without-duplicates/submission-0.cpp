class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // {Key: char, Value: Index}
        unordered_map<char, int> seen;
        // Initializing variables
        int l = 0;  // Left pointer
        int r = 0;  // Right pointer
        int maxLength = 0;
        int currentLength = 0;

        // While right pointer is less than string length
        while (r < s.length()) {
            // If we find our right pointer in our seen hashmap
            // and the right pointer index is greater than the left
            if (seen.find(s[r]) != seen.end() && seen[s[r]] >= l) {
                // Set left pointer to right index + 1 to avoid the current char it's on
                l = seen[s[r]] + 1;
                // Recalculate the current length
                currentLength = r - l + 1;  // Adjust current length calculation
            } else {
                // If no duplicate is found, just increment current length
                currentLength++;
            }

            // Set occurrence of s[r] to its latest occurrence
            seen[s[r]] = r;  
            // Find max between current and max
            maxLength = max(maxLength, currentLength);  
            // Move right pointer over one
            r++;  
        }
        return maxLength;  // Return max
    }
};
