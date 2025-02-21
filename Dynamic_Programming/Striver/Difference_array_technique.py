# Famous technique use to efficiently apply range updates to an array(Modification in a given range)
# Helps to do multiple updates in constant time

# When to use:
# Best suited for problems where we need to perform multiple range updates
# like adding / substracting a value over a range
# we don't need to query the array frequently after updates[dont have update query]
from typing import List

# Question: Given and nx3 matrix queries. quries[i] = [start_index , end_index , value]
# add start to end index value.[inclusive]
class Solution:
    def rangeAddition(self , arr: List , queries: List) -> List:
        n = len(arr)
        
        for start , end , val in queries:
            arr[start] += val
            if end + 1 < n:
                arr[end + 1] -= val
        
        for i in  range(1 , n):
            arr[i] = arr[i] + arr[i-1]
        return arr


sol = Solution()
arr = [0,0,0,0,0]
queries = [[1,3,2] , [2,4,3] , [0,2,-2]]

print(sol.rangeAddition(arr , queries))