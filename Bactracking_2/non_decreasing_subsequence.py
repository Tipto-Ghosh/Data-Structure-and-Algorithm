from typing import List
class Solution:
    def findSubsequences(self, arr: List[int]) -> List[List[int]]:
       # for each call we have 2 choice take the curr_index , not take
       # choice-1: If we include the curr indx then add the ele and for next call index + 1
       # choice-1: If we exclude the curr indx then don't add the ele and for next call index + 1
       n = len(arr)
       ans = set()
       curr = []
       
       def backtrack(index: int , curr: list[int]) -> None:
           # Base Case:
           # Take the ans
           if len(curr) >= 2:
               ans.add(tuple(curr))
           
           # to avoid dublicate
           used = set()
           for i in range(index , n):
               if (len(curr) == 0 or curr[-1] <= arr[i]) and arr[i] not in used:
                   used.add(arr[i])
                   curr.append(arr[i])
                   backtrack(i + 1 , curr)
                   curr.pop()
       
       backtrack(0 , curr)
       return list(map(list , ans))
       
sol = Solution()
nums = [4,6,7,7]
print(sol.findSubsequences(nums))        