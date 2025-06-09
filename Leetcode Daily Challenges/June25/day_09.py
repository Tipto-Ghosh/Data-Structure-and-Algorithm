class Solution:
    def count_steps(self , prefix , n):
        """
        Count how many numbers exist between prefix and prefix+1 in lexicographical order,
        but not exceeding n. This simulates how many numbers are in the subtree rooted at prefix.
        """
        steps = 0
        
        first = last = prefix
        
        while first <= n: # while we are in range of n
            # counts nodes between first and last that are within the bounds of n
            
            # 100 to 109 there are 10 numbers. we have to take the count which are in range
            steps += min(n , last) - first + 1 
            # go one level deeper in the trie(add a digit): if we are at 10 then go to 100
            first *= 10
            # update last also
            last = last * 10 + 9
        
        return steps  
        
        
    def findKthNumber(self, n: int, k: int) -> int:
        curr = 1 # start from the lowest lexo number 1
        k -= 1 # already know the lowest , now have to find k-1 th number
        
        while k > 0:
            steps = self.count_steps(curr , n) # Count how many numbers are in the subtree rooted at `curr`
            
            if steps <= k:
                # If the entire subtree has ≤ k nodes, skip this subtree and move to the next root
                k -= steps
                curr += 1 # Move to the next prefix.(from 1 to 2 , then 2--> 3 so on)
            else:
                # If subtree has > k nodes , go deeper in this subtree
                curr = curr * 10 # move to the next level: from 1 to 10 , 10 --> 100
                k -= 1
        
        return curr

sol = Solution()

print(sol.findKthNumber(13 , 2))   

