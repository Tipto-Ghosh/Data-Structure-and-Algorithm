class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        n = len(s)
        count_len = 0
        val = 0
        power = 0
        
        for i in range(n - 1 , -1 , -1):
            # if 0 then we can take it cause val will not increase
            if s[i] == '0':
                count_len += 1
            else:
                # check power overflow
                if power < 32:
                    if val + (1 << power) <= k:
                        val += (1 << power)
                        count_len += 1
                
            power += 1
        
        return count_len    
        
sol = Solution()

print(sol.longestSubsequence(s = "1001010", k = 5))        
print(sol.longestSubsequence(s = "00101001", k = 1))