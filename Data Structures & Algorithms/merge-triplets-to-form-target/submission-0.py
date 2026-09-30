class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        xFound, yFound, zFound = False, False, False
        x, y, z = target
        for i in range(len(triplets)):
            if triplets[i][0] > x or triplets[i][1] > y or triplets[i][2] > z:
                continue
            
            if triplets[i][0] == x:
                xFound = True
            if triplets[i][1] == y:
                yFound = True
            if triplets[i][2] == z:
                zFound = True
        
        return xFound and yFound and zFound