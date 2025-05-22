from typing import List
from heapq import heappush, heappop

class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        # Sort the queries based on their start index 
        # This helps us process relevant queries for each index `i` in `nums` as we iterate
        queries.sort(key=lambda x: x[0])

        heap = []  # Max-heap (we use min-heap with negative values)
        deltaArray = [0] * (len(nums) + 1)  # Used for efficient range updates using prefix sum technique
        operations = 0  # Total operations (decrements) available at current index
        j = 0  # Pointer for traversing queries list

        # Iterate over each index of the nums array
        for i, num in enumerate(nums):
            operations += deltaArray[i]  # Apply any deferred changes to operations count

            # Push queries that start at index `i` into the heap
            # The heap stores the right end `r` of queries (negated for max-heap behavior)
            while j < len(queries) and queries[j][0] == i:
                heappush(heap, -queries[j][1])
                j += 1

            # While we need more operations at this index and there are valid queries in the heap
            while operations < num and heap and -heap[0] >= i:
                operations += 1  # Use one operation from a query
                # Schedule an "end" of this query's effect at index r+1 (to decrement operation count later)
                deltaArray[-heappop(heap) + 1] -= 1

            # After trying all valid queries, if still not enough operations to make nums[i] zero
            if operations < num:
                return -1  # Not possible to make array zero

        # All nums[i] can be reduced to zero, return how many queries are left unused (i.e., still in heap)
        return len(heap)
        
sol = Solution()
print(sol.maxRemoval([2,0,2], queries = [[0,2],[0,2],[1,1]]))