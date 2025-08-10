from collections import defaultdict
class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        # Get all the power of 2 from 0 to 31
        all_twos_power = [2 ** p for p in range(32)]
        
        # make a function to compute the freq of digits
        def _count_freq(num) -> int:
            freq = defaultdict(int)
            while num > 0:
                d = num % 10
                num //= 10
                freq[d] += 1
            
            return freq
        
        counts = [_count_freq(num) for num in all_twos_power]
        digit_count_n = _count_freq(n)
        
        for count in counts:
            if count == digit_count_n:
                return True
        
        return False
    
sol = Solution()

print(sol.reorderedPowerOf2(1))
print(sol.reorderedPowerOf2(10))    