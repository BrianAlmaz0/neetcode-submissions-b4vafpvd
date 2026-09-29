class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False
        
        seen = Counter(hand)
        heap = list(seen.keys())
        heapq.heapify(heap)

        while heap:
            curr = heap[0]
            for i in range(groupSize):
                if curr not in seen:
                    return False
                
                seen[curr] -= 1
                if seen[curr] == 0:
                    if curr != heap[0]:
                        return False
                    heapq.heappop(heap)
                
                curr += 1
        
        return True
                    
                