from collections import defaultdict
class Solution:
    def countLargestGroup(self, n: int) -> int:
        groups = defaultdict(int)
        largest_group_size = 0
        for num in range(1 , n + 1):
            digit_sum = 0
            
            while num > 0:
                digit = num % 10
                num //= 10
                digit_sum += digit
            
            groups[digit_sum] += 1
            largest_group_size = max(largest_group_size , groups[digit_sum])
        
        count_number_of_largest_group = 0
        for group_size in groups.values():
            if group_size == largest_group_size:
                count_number_of_largest_group += 1
                
        return count_number_of_largest_group   
        
sol = Solution()

print(sol.countLargestGroup(13))
print(sol.countLargestGroup(2))        