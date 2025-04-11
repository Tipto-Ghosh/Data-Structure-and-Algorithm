class Solution:
    def countSymmetricIntegers(self, low: int, high: int) -> int:
        """
        count = 0
        
        for num in range(low , high + 1):
            num_str = str(num)
            n = len(num_str)
            if n % 2 == 1:
                continue
            
            left_sum , right_sum = 0 , 0
            left , right = 0 , n - 1
            while left < right:
                left_sum += (ord(num_str[left]) - ord('0'))
                right_sum += (ord(num_str[right]) - ord('0'))
                left += 1
                right -= 1
            
            if left_sum == right_sum:
                count += 1
        
        return count
        """
        
        
        # number can be 1 to 10000[1 digit to max 5 digit]
        # as odd number of digit can't be symmetric so number can be 2 or 4 digit
        # 2 digit --> 9 < num < 100
        # 4 digit --> 1000 < num < 9999
        
    
        count_symmetric = 0
        
        for num in range(low , high + 1):
            # if number has 2 digits
            if 9 < num < 100:
                last_digit = num % 10
                first_digit = num // 10
                if last_digit == first_digit:
                    count_symmetric += 1
                    
            elif 1000 <= num <= 9999: # if number has 4 digits
                # extract 4 digits
                d1 = num // 1000 % 10
                d2 = num // 100 % 10
                d3 = num // 10 % 10
                d4 = num % 10 # num // 1 % 10
                
                if d1 + d2 == d3 + d4:
                    count_symmetric += 1 
        
        return count_symmetric          
                
sol = Solution()

print(sol.countSymmetricIntegers(1 , 100))                
print(sol.countSymmetricIntegers(1200 , 1230))                