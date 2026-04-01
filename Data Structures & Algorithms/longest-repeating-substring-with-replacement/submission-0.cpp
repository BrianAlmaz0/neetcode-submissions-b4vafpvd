class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;  // Map to keep track of character frequencies in the current window
        int maxCount = 0;  // Tracks the highest frequency of any single character in the window
        int maxLength = 0;  // Stores the length of the longest valid substring
        int l = 0;  // Left pointer for the sliding window

        // Iterate over the string with the right pointer 'r'
        for (int r = 0; r < s.length(); r++) {
            count[s[r]]++;  // Increase the frequency count of the character at position 'r'
            
            // Update maxCount to reflect the most frequently occurring character in the window
            maxCount = max(maxCount, count[s[r]]);
            
            // Check if the current window is invalid
            // If the number of characters to change exceeds 'k', shrink the window from the left
            while ((r - l + 1) - maxCount > k) {
                count[s[l]]--;  // Decrease the frequency of the character at the left pointer
                l++;  // Shrink the window by moving the left pointer to the right
            }
            
            // Calculate the length of the current valid window
            // No need to increment 'r' again here, the loop already does that
            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;  // Return the longest valid substring length
    }
};
