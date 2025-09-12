class Solution:
    def doesAliceWin(self, s: str) -> bool:
        # http://leetcode.com/problems/vowels-game-in-a-string/?envType=daily-question&envId=2025-09-12
        
        vowels = {'a' , 'e' , 'i' , 'o' , 'u'}
        
        """ 
        Alice will try to remove the largest sub-string that contains odd number of vowels.
        Bob will try to remove the largest sub-string that contains even number of vowels.
        
        If total counts of vowel is odd -> alice will win -> cause he will remove the whole string as sub-string
        if total counts of vowel is even -> alice will remove the largest odd sub-string where vowel count will be total_vowel_count - 1
        So after her turn there will be odd vowels so bob will unable to make a move so , she(bob) will loss means alice will win.
        
        So if there is any vowel in the string then alice win!!
        """
        
        for ch in s:
            if ch in vowels:
                return True
        
        return False

sol = Solution()

print(sol.doesAliceWin("leetcoder"))