import heapq
class Solution:
    def clearStars(self, s: str) -> str:
        """
        Take a min_heap. Heap will store the pair of (letter , index)
        This heap will give the lowest left character
        If there are same letter then top will be letter with large index
        
        Go through every character:
        If it's a letter and store it with it's index in the heap
        If it's a * then remove the top element(left samllest letter)
        
        After All of this take all the remaining letters from the heap in a list and
        Sort them based on the index and re-build the string
        """
        
        n = len(s)
        min_heap = []
        
        for index , ch in enumerate(s):
            # if it's not a letter then remove the left smallest letter
            if ch == '*' and len(min_heap) != 0:
                heapq.heappop(min_heap)
            else: # It's a letter so store it
                heapq.heappush(min_heap , (ch , -index))
        
        # Now take the remaining element from the heap
        remaining_elements = []
        while min_heap:
            letter , index = heapq.heappop(min_heap)
            remaining_elements.append((-index , letter))
        
        # sort the elements by it's index
        remaining_elements = sorted(remaining_elements)
        
        ans = []
        for _ , letter in remaining_elements:
            ans.append(letter)
        
        return ''.join(ans)
        
            
             

sol = Solution()

print(sol.clearStars("aaba*"))   