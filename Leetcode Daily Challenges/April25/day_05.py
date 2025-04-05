from typing import List

class Solution:
    def subsetXORSum(self, arr: List[int]) -> int:
        # n = len(arr)
        
        # subsets = []
        
        # def all_sub_set(index: int , curr_set: List[int]):
           
        #     # If we are out of bounds
        #     if index >= n:
        #         # take the curr_set as a subset
        #         subsets.append(curr_set.copy())
        #         return
            
        #     # exclude the currIndex element
        #     all_sub_set(index + 1 , curr_set)
            
        #     # include the currIndex element
        #     curr_set.append(arr[index])
        #     all_sub_set(index + 1 , curr_set)
        #     curr_set.pop()
        
        # all_sub_set(0 , [])    
        # # print(subsets)
        # ans = 0
        
        # for subset in subsets:
            
        #     curr = 0
        #     for i in range(len(subset)):
        #         curr ^= subset[i]
            
        #     ans += curr
        
        # return ans 
# ----------------------------------- Instead Of Generating all the subset--------------------------
        n = len(arr)
        
        xor_sum = 0
        
        def solve(index: int , curr_xor_sum: int):
            nonlocal xor_sum
            # If we are out of bounds
            if index >= n:
                # take the curr_set as a subset
                # subsets.append(curr_set.copy())
                # instead of taking the subset take the curr_subset_sum
                xor_sum += curr_xor_sum
                return
            
            # exclude the currIndex element
            # all_sub_set(index + 1 , curr_set)
            solve(index + 1 , curr_xor_sum)
            
            # include the currIndex element
            # curr_set.append(arr[index])
            
            # all_sub_set(index + 1 , curr_set)
            # curr_set.pop()
            # Instead of appending and poping we will just take the xor
            solve(index + 1 , curr_xor_sum ^ arr[index])
        
        solve(0 , 0)
        return xor_sum
                
sol = Solution()

print(sol.subsetXORSum([1,3]))
print(sol.subsetXORSum([5 , 1 , 6]))
print(sol.subsetXORSum([3,4,5,6,7,8]))