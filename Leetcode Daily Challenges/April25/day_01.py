from typing import List


class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:
        
        # It's a Knapsack pattern question
        # So At each index we have 2 options:
        #   option-1: Solve the current index question and skip next brainpoint numbers of questions
        #           So take the point and move to currIndex + 1 + questions[currIndex]
        #   option-2: Skip the currIndex question and move the next index
        
        n = len(questions)
        
        dp = [-1] * n 
        
        def solve(currIndex: int) -> int:
            # If we are at a invalid index
            if currIndex >= n:
                return 0
            
            if dp[currIndex] != -1:
                return dp[currIndex]
            
            # Solve the current question
            solved = questions[currIndex][0] + solve(currIndex + 1 + questions[currIndex][1])
            # Skip the current question
            skip = solve(currIndex + 1)
            
            dp[currIndex] = max(solved , skip)
            return dp[currIndex] 
        
        
        return solve(0)
    
        


sol = Solution()

print(sol.mostPoints([[3,2],[4,3],[4,4],[2,5]]))        
print(sol.mostPoints([[1,1],[2,2],[3,3],[4,4],[5,5]]))