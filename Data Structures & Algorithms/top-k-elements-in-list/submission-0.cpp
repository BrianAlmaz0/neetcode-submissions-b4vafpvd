class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //we create a hashmap to keep count of the freq of the numbers
        unordered_map<int, int> counter;
        //Filling the hashmap
        for(int num : nums){
            counter[num]++; // {Key: Num, Value: Freq}
        }

        //Create a Priority Queue to sort map in descending order
        priority_queue<pair<int, int>> pq;
        //Filling the Priortiy Queue
        for(auto entry : counter){
            //Bc Priority queue sorts by first entry in pair
            pq.push({entry.second, entry.first}); //{First: Freq, Second: Key}
        }

        //Push out highest k values to our ans vector
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
