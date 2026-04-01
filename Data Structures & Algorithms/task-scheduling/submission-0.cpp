class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char ch : tasks){
            freq[ch - 'A']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());
        int count = 0;
        for(int num : freq){
            if(num == maxFreq){
                count++;
            }
        }

        int skeleton = (maxFreq - 1) * (n + 1) + count;
        return max(skeleton, (int)tasks.size());
    }
};
