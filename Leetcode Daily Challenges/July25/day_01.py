class Solution:
    def possibleStringCount(self, word: str) -> int:
        count = 1 # the final string word included
        
        curr_group_len = 1
        for i in range(1 , len(word)):
            if word[i - 1] == word[i]:
                curr_group_len += 1
            else:
                count += (curr_group_len - 1)
                curr_group_len = 1
        
        # for the last group
        count += (curr_group_len - 1) 
        
        return count