from typing import List

class Solution:
    def divideArray(self, arr: List[int], k: int) -> List[List[int]]:
        arr.sort()
        # print(arr)
        
        n = len(arr)
        ans = []
        
        for i in range(2 , n , 3):
            a , b , c = arr[i - 2] , arr[i - 1] , arr[i]
            
            if (c - a <= k) and (c - b <= k) and (b - a <= k):
                ans.append([a , b , c])
            else:
                return []  
        
        return ans
        

sol = Solution()
print(sol.divideArray([1,3,4,8,7,9,3,5,1], k = 2))
print(sol.divideArray([2,4,2,2,5,2], k = 2))
print(sol.divideArray([4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11], k = 14))        