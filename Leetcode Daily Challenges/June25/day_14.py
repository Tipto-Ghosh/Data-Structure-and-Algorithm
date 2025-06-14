class Solution:
    def minMaxDifference(self, num: int) -> int:
        """ 
        To make the maximum number we have to maximize the most significant digit[left most digit]
        To make the minimum number we have to minimize the most significant digit[left most digit]
        
        Max --> replace left most digit and all other digit equal to left most with 9
        min --> replace left most digit and all other digit equal to left most with 0
        """
        num_str = str(num)
        # ----------------- Make the minimum number-----------------
        num_list = list(num_str)
        
        # Find the first non-zero digit
        for digit in num_list:
            if digit != '0':
                min_target = digit
                break
        else:
            min_target = None 
        
        if min_target:
            min_version = ''.join(['0' if ch == min_target else ch for ch in num_list])
        else:
            min_version = num_str
        
        mini = int(min_version)
        
        #---------------- Make the max number --------------------------
        num_list = list(num_str)
        
        # find the first non - nine digit
        for digit in num_list:
            if digit != '9':
                max_target = digit 
                break
        else:
            max_target = None
        
        if max_target:
            max_version = ''.join(['9' if ch == max_target else ch for ch in num_list])
        else:
            max_version = num_str
        
        maxi = int(max_version)       
        
        return maxi - mini          


sol = Solution()

print(sol.minMaxDifference(11891))