class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int num : stones){
            maxHeap.push(num);
        }

        while(maxHeap.size() > 1){
            int yStone = maxHeap.top();
            maxHeap.pop();
            int xStone = maxHeap.top();
            maxHeap.pop();

            if(yStone > xStone){
                maxHeap.push(yStone - xStone);
            } 
        }
        maxHeap.push(0);
        return maxHeap.top();
    }
};
