from typing import List

class Solution:
    def isZeroArray(self, arr: List[int], queries: List[List[int]]) -> bool:
        """
        we have query [left , right] in this range(included) take a sub-set of elements and decrement them by 1
        After processing all the queries check is there any non-zero element or not
        If any non-zero remains returns False else True
        
        Take a decrement_count array as prefix array
        Take each query left , right and increment decrement_count[left] by one and increment decrement_count[right + 1] by 1
        
        Convert the decrement_count array into an count array of prefix sum, count
        
        Then go to every element in the actual array and if arr[i] > count means we can't convert this element into 0 so return False  
        """
        
        n = len(arr)
        # Make the difference array
        decrement_count = [0] * (n + 1)
        
        for l , r in queries:
            decrement_count[l] += 1
            if r + 1 < n + 1:
                decrement_count[r + 1] -= 1
        
        # convert the decrement_count into prefix array sum
        for i in range(1 , n):
            decrement_count[i] = decrement_count[i] + decrement_count[i-1]
        
        # now check every element from the actual array
        for i in range(n):
            if arr[i] > decrement_count[i]:
                return False
        
        return True

sol = Solution()

print(sol.isZeroArray([1,0,1],[[0,2]]))