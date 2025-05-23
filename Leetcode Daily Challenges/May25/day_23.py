from typing import List

class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        '''
        Alice has 2 options: 
          1. Take an edge and update the value of both nodes (Flip the node values by XOR)
          2. Skip the edge (Don't flip)
        
        When not to choose an edge:
          If we take an edge [u, v] and let's say:
              nums[u] + nums[v] >= (nums[u] ^ k) + (nums[v] ^ k)
          then it's better to skip the edge, because it decreases the total sum.
        
        When we should take an edge:
          If we take an edge [u, v] and:
              nums[u] + nums[v] < (nums[u] ^ k) + (nums[v] ^ k)
          then it's better to take the edge, because it increases the total sum.
        
        1. Go to every node and find what will be the gain if we flip it.
            gain = (nums[i] ^ k) - nums[i]
        2. Store these gains.
        3. Sort the gains in descending order and pick the top even number of positive-gain nodes 
           (since we need to flip nodes in pairs). 
           If there's an odd number of such nodes, 
           consider not flipping the one with the smallest gain (i.e., least beneficial).
        '''

        base = sum(nums)  # Find the current total sum of node values
        gains = [(num ^ k) - num for num in nums]  # Calculate gain of flipping each node
        gains.sort(reverse=True)  # Sort the gains in descending order


        max_gain = base
        curr_gain = 0

        # Try all even counts of flips (i.e., prefix sums of even length from sorted gains)
        for i in range(len(gains)):
            curr_gain += gains[i]
            if (i + 1) % 2 == 0:
                max_gain = max(max_gain, base + curr_gain)

        return max_gain


if __name__ == '__main__':
   sol = Solution()
   print(sol.maximumValueSum(nums = [1,2,1], k = 3, edges = [[0,1],[0,2]]))   
   print(sol.maximumValueSum(nums = [2,3], k = 7, edges = [[0,1]]))
   print(sol.maximumValueSum(nums = [7,7,7,7,7,7], k = 3, edges = [[0,1],[0,2],[0,3],[0,4],[0,5]]))    