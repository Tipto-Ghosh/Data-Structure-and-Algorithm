from typing import List

class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        
        """
        diff[i] = arr[i+1] - arr[i] => arr[i + 1] = diff[i] + arr[i]
        
        Start with every possible number from lower to upper[both inclusive]
        And find the next element
        Example: diff = [1,-3,4] , lower = 1 , upper = 6
        
        1 -> [(1 + 1) = 2] -> [(2 + (-3)) = -1{-1 is invalid so not possible}]  
        2 -> [(2 + 1) = 3] -> [3 + (-3) = 0{again invalid 0 is not in range}]
        3 -> [3 + 1 = 4] -> [4 - 3 = 1] -> [1 + 4] -> 5 ==> [3,4,1,5] --> valid sequence
        4 -> [4 + 1 = 5] -> [5 + (-3) = 2] -> [2 + 4 = 6] ==> [4,5,2,6] -->  valid sequence
        5 -> [5 + 1 = 6] -> [6 - 3 = 3] -> [3+4 = 7{not is range , so invalid}]
        6 -> [6 + 1 = 7 {not valid , out of range}]
        """
        # n = len(differences)
        # def solve(index: int , curr_index_val: int) -> int:
        #     # Base case: if we got n + 1 element means if we are at index n then we got a valid seqence
        #     if index == n:
        #         return 1
            
        #     # find the next element
        #     next_index_val = curr_index_val + differences[index]
        #     # if next_index_val is invalid then no valid hidden sequence
        #     if next_index_val < lower or next_index_val > upper:
        #         return 0
        #     else: # As next_index_val is valid so find the next one
        #         return solve(index + 1 , next_index_val)
        
        # # Start we every element from lower to upper
        # count = 0
        # for start in range(lower , upper + 1):
        #     count += solve(0 , start)
        
        # return count
        
        #---------------------- More Optimized One-------------------------
        """
        prefix[0] = 0
        prefix[1] = diff[0]
        prefix[2] = diff[0] + diff[1]
        prefix[3] = diff[0] + diff[1] + diff[2]
        prefix[4] = diff[0] + diff[1] + diff[2] + diff[3]
        
        - So maintain a prev_sum
        - arr[i] = arr[0] + prefix[i]
        - Also we need to maintain that all arr[i] is in the range
        - lower <= arr[0] + min_prefix and upper >= arr[0] + max_prefix
        """
        n = len(differences)
        prefix = [0] * (n + 1) # prefix[0] = 0
        
        # find the prefix value from 1 to n index
        for i in range(1 , n + 1):
            prefix[i] = prefix[i - 1] + differences[i - 1]
        
        min_prefix = min(prefix)
        max_prefix = max(prefix)
        
        min_start = lower - min_prefix
        max_start = upper - max_prefix
        possible = 1 + (max_start - min_start)
        
        if possible < 0:
            possible = 0
        
        return possible
        
        
        
sol = Solution()

print(sol.numberOfArrays(differences = [1,-3,4], lower = 1, upper = 6))
print(sol.numberOfArrays(differences = [3,-4,5,1,-2], lower = -4, upper = 5))
print(sol.numberOfArrays(differences = [4,-7,2], lower = 3, upper = 6))