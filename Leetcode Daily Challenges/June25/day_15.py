class Solution:
    
    def findMaxNumber(self , num:int) -> int:
        num_str = str(num)
        num_list = list(num_str)
        
        # Find left most non-nine digit
        for i in range(len(num_list)):
            if num_list[i] != '9':
                max_target = num_list[i]
                break
        else: # All digit's are nine
            max_target = None
        
        
        if max_target:
            # replace all max_target by 9
            max_num_str = ''.join(['9' if digit == max_target else digit for digit in num_list])
        else: # All nine
            max_num_str = num_str
        
        return int(max_num_str)
    
    # Find the min number
    def findMinNumber(self , num: int) -> int:
        num_str = str(num)
        num_list = list(num_str)
        
        # If first digit is not 1
        if num_list[0] != '1':
            min_target = num_list[0]
            
            min_num_str = ''.join(['1' if d == min_target else d for d in num_list])
            return int(min_num_str)
        else:
            for i in range(1 , len(num_list)):
                if num_list[i] not in ('0' , '1'):
                    min_target = num_list[i]
                    
                    min_num_str = ''.join(['0' if d == min_target else d for d in num_list])
                    return int(min_num_str)
            
            return num
               
    def maxDiff(self, num: int) -> int:
        return self.findMaxNumber(num) - self.findMinNumber(num)
        
        
sol = Solution()

print(sol.maxDiff(555))
print(sol.maxDiff(9))
print(sol.maxDiff(9878))
