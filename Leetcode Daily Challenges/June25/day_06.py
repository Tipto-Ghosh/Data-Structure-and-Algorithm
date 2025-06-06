from collections import deque

class Solution:
    def robotWithString(self, s: str) -> str:
        """ 
        As we have to always remove first letter of s so we need a queue
        And we have to remove the last letter of t so we need a stack(list in python)
        
        We want to simulate two operations: till s and t are equal
        1. Move the first character from s to the end of t.
        2. Move the last character from t to the end of output string paper.
           
        At each step we have choose to
        either push a character to t from front of s
        OR
        pop a character from end of t and push it to paper so that p becomes smallest
        
        precalculate the count of minimum letter that we have
        """
        n = len(s)
        # precompute the next min letters
        min_suffix = [None] * n
        min_suffix[-1] = s[-1]
        for  i in range(n - 2 , -1 , -1):
            min_suffix[i] = min(min_suffix[i + 1] , s[i])
        
        # take the paper and stack
        stack_t = []
        paper = []
        
        # simulate the operations
        for i in range(n):
            # add the letter of s to t
            stack_t.append(s[i])
            
            # while t is not empty and top <= smallest remaining char in s
            while stack_t and (i == n - 1 or stack_t[-1] <= min_suffix[i + 1]):
                paper.append(stack_t.pop())
        
        # take the remain letter
        while stack_t:
            paper.append(stack_t.pop())
        
        return ''.join(paper)
                


sol = Solution()

print(sol.robotWithString("zza"))        