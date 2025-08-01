from typing import List

class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        prev_sub_array = set()
        curr_sub_array = set()
        ans = set()
        
        for i in range(len(arr)):
            curr_ele = arr[i]
            
            for ele in prev_sub_array:
                val = ele | curr_ele
                curr_sub_array.add(val)
                ans.add(val)
            
          
            curr_sub_array.add(curr_ele)
            ans.add(curr_ele)     
            
            prev_sub_array = curr_sub_array.copy()
            curr_sub_array.clear()
        
        return len(ans)
        
        
        
sol = Solution()

print(sol.subarrayBitwiseORs([0]))
print(sol.subarrayBitwiseORs([1,1,2]))
print(sol.subarrayBitwiseORs([1,2,4]))