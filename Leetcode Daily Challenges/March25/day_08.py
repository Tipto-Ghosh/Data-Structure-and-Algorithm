class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        # if k == n then operation needed is count of W
        # Otherwise do sliding window
        # For sliding window part
        # Take a left and right pointer.
        # Start travering from left to right of the string
        # If w then increase operation else just move right
        # When window length is greater than k then start shrinking the window
        # While shrinking if we got W then operation -= 1
        
        n = len(blocks)
        
        if n == k:
            count = 0
            for c in blocks:
                if c == 'W':
                    count += 1
            return count
        
        curr_op , operations = 0 , k 
        left , right = 0 , 0
        
        while right < n:
            if blocks[right] == 'W':
                curr_op += 1
            # If we exceed the length
            while right - left + 1 > k:
                if blocks[left] == 'W':
                    curr_op -= 1
                left += 1  
            # Check the window length
            if right - left + 1 == k:
                operations = min(operations , curr_op)
            right += 1
        
        return operations


sol = Solution()
print(sol.minimumRecolors("WBBWWBBWBW" , 7))
print(sol.minimumRecolors("B" , 1))