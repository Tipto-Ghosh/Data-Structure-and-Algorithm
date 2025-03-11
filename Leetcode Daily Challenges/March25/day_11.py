class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        # Take a left and right pointer and expand the right pointer until we have a valid window
        # while a valid window shrink the window and 
        # while shrinking every letter if we have a validity then also indcrese the count
        
        n = len(s)
        count = 0
        l = 0
        occ = {}
        
        for r in range(n):
            # Take the current letter
            occ[s[r]] = occ.get(s[r] , 0) + 1
            
            # Now check do we have a valid window 
            while len(occ) == 3: # While we have at these 3 letter window is valid
                # Possible sub-string is: last_index - right + 1 == n - right
                count += (n - r)
                # Now shrink the window
                left_letter = s[l]
                l += 1
                # Modify the count
                occ[left_letter] = occ.get(left_letter) - 1
                if occ.get(left_letter) == 0:
                    occ.pop(left_letter)
            
        return count   
            
            
sol = Solution()            
            
print(sol.numberOfSubstrings("abcabc"))            
            
print(sol.numberOfSubstrings("aaacb"))
print(sol.numberOfSubstrings("abc"))            