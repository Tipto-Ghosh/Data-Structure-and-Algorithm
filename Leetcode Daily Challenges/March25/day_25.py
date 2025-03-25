from typing import List

class Solution:
            
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        x = [(r[0] , r[2]) for r in rectangles] # (x1 , x2)
        y = [(r[1] , r[3]) for r in rectangles] # (y1 , y2)
        
        x.sort()
        y.sort()
        
        def count_non_overlapping(intervals):
            count = 0
            prev_end = -1
            for  start , end in intervals:
                if prev_end <= start:
                    count += 1
                prev_end = max(prev_end , end)
            return count
        
        x_count = count_non_overlapping(x)
        y_count = count_non_overlapping(y)
        
        return max(x_count , y_count) >= 3
    
sol = Solution()

ans1 = sol.checkValidCuts(5 , [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]])
ans2 = sol.checkValidCuts(4 , [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]])
ans3 = sol.checkValidCuts(4 , [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]])

print(ans1 , ans2 , ans3)