from typing import List
from collections import defaultdict
class Solution:
    def permuteUnique(self, arr: List[int]) -> List[List[int]]:
        n = len(arr)
        ans = []
        curr = []
        count = defaultdict(int)
        
        for num in arr:
            count[num] += 1
        
        def backtrack() -> None:
            # Base Case:
            if len(curr) == n:
                ans.append(curr.copy())
                return
            # Explore all the other nums
            for num in count:
                if count[num] > 0:
                    # Do Part
                    curr.append(num)
                    count[num] -= 1
                    # Call Function
                    backtrack()
                    # Undo Part
                    curr.pop()
                    count[num] += 1
        backtrack()
        return ans    