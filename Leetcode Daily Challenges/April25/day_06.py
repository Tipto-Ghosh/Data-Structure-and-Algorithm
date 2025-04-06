from typing import List
from collections import defaultdict ,  deque
import heapq

"""
class Solution:
    def largestDivisibleSubset(self, arr: List[int]) -> List[int]:
        
        def can_take(curr_ele , curr_subset) -> bool:
            for index in curr_subset:
                ele = arr[index]
                if not (ele % curr_ele == 0 or curr_ele % ele == 0):
                    return False
            
            return True 
        
        n = len(arr)
        
        
        def solve(index , curr_subset) -> int:
            
            if index >= n:
                return curr_subset.copy()
            
            # skip the currIndex element
            skip = solve(index + 1 , curr_subset)
            # Take the currIndex element, but before taking check can we take the curr?
            take = set()
            if can_take(arr[index] , curr_subset):
                # curr_subset.add(arr[index])
                curr_subset.add(index)
                take = solve(index + 1 , curr_subset)
            else:
                # new = set([arr[index]])
                take = solve(index + 1 , set([index]))
            
            return max(take , skip)  
        
        Set = set()
        Set = solve(0 , Set)
        
        ans = []
        indexList = sorted(list(Set))
        for i in indexList:
            ans.append(arr[i])
        
        return ans 
"""

class Solution:
    def largestDivisibleSubset(self, arr: List[int]) -> List[int]:
        arr.sort()
        n = len(arr)
        
        dp = {}
        
        def solve(index: int , prev_index: int) -> List:
            if index >= n:
                return []
            
            key = (index , prev_index)
            if key in dp:
                return dp[key]
            
            # Skip the current element
            skip = solve(index + 1 , prev_index)
            
            # Take the currIndex element
            take = []
            
            if prev_index == -1 or arr[index] % arr[prev_index] == 0:
                take = [arr[index]] + solve(index = index + 1 , prev_index = index)
            
            dp[key] = take if len(take) > len(skip) else skip
            
            return dp[key]
        
        return solve(0 , -1)

sol = Solution()

print(sol.largestDivisibleSubset([1,2,3]))
print(sol.largestDivisibleSubset([1,2,4,8]))        
