from typing import List

class Solution:
    def getWordsInLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        """
        At each call we have 2 options:
        1. we can take it(if condition matches)
           condition: prev and current has same length and hamming distance is 1 and prev group not euqal to current group
        2. we can skip it
        
        we also need to use Dp. Here we can see that 2 parameter are changing: index and prev_index
        """
        inf = float('inf')
        def hamming_distance(s1: str , s2: str) -> int:
            # if both has different len , then return int
            if len(s1) != len(s2):
                return inf
            distance = 0
            for i in range(len(s1)):
                if s1[i] != s2[i]:
                    distance += 1
            
            return distance
        
        n = len(words)
        
        # Let's make the Dp table
        dp = [[None] * (n + 1) for _ in range(n + 1)]
        
        def solve(curr_index: int , prev_index: int) -> List[int]:
            # base case: if we are at index == n: we can't take anything else
            if curr_index == n:
                return []
            
            # check the dp table
            prev_key = prev_index + 1
            if dp[curr_index][prev_key] is not None:
                return dp[curr_index][prev_key]
            
            # option-01: skip the curr_index word
            skip = solve(curr_index + 1 , prev_index)
            
            # option-02: Take curr_index word if possible
            take = []
            # if we haven't take anything before we can take any word
            # Or we have taken aleast one word before then this should be matched
            # condition: prev and current has same length and hamming distance is 1 and prev group not euqal to current group
            condition_1 = len(words[prev_index]) == len(words[curr_index]) # Have to same length
            condition_2 = hamming_distance(words[curr_index] , words[prev_index]) == 1 # hamming distance is 1
            condition_3 = groups[prev_index] != groups[curr_index] # prev group not euqal to current group
            # If these 3 conditions meet then we can also take the word at curr_index
            if prev_index == -1 or (condition_1 and condition_2 and condition_3):
                curr_ans = solve(curr_index + 1 , curr_index)
                take = [curr_index] + curr_ans
            
            # choose the longer one
            dp[curr_index][prev_key] = take if len(take) >= len(skip) else skip
            return dp[curr_index][prev_key]
        
        ans_indices = solve(0 , -1) # this will give us the index that we need to take as answer
        # Now build the answer
        ans = []
        for index in ans_indices:
            ans.append(words[index])
        
        return ans 


sol = Solution()
print(sol.getWordsInLongestSubsequence(words = ["bab","dab","cab"], groups = [1,2,2])) 
print(sol.getWordsInLongestSubsequence(words = ["a","b","c","d"], groups = [1,2,3,4]))                        