"""
class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        # Find the range of number based on digit count n
        # low = 1 , (n - 1) numbers 0
        # high = n times 9
        
        # Find all the k-palindromic numbers from low to high
        # Again start from low to high and check if we can build this number from a k-palindromic number of not
        
        low_list = ['1']
        for i in range(n - 1):
            low_list.append('0')
        
        low = int(''.join(low_list))
        # print(low)
        
        highest_list = ['9' * n]
        high = int(''.join(highest_list))
        # print(high)
        
        def is_k_palindromic(num: int) -> bool:
            if num % k != 0:
                return False
            
            num_str = str(num)
            i , j = 0 , len(num_str) - 1
            while i < j:
                if num_str[i] != num_str[j]:
                    return False
                
                i += 1
                j -= 1
            return True
        
        # find all the k-palindrome from low to high
        all_k_palindrome = set()
        for num in range(low , high + 1):
            if is_k_palindromic(num):
               num_str = str(num)
               num_str = sorted(num_str)
               all_k_palindrome.add(''.join(num_str))     
        
        count = 0
        for num in range(low , high + 1):
            num_str = str(num)
            num_str = sorted(num_str)
            num_str = ''.join(num_str)
            if num_str in all_k_palindrome:
                count += 1
        
        return count
"""
class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        # Step 1: Generate palindromes of length n divisible by k
        half_len = (n + 1) // 2
        low = 10 ** (half_len - 1)
        high = 10 ** half_len
        
        k_palindrome_keys = set()

        for half in range(low, high):
            half_str = str(half)
            if n % 2 == 0:
                full_str = half_str + half_str[::-1]
            else:
                full_str = half_str + half_str[:-1][::-1]
            
            full_num = int(full_str)
            if full_num % k == 0:
                key = ''.join(sorted(full_str))
                k_palindrome_keys.add(key)
        
        # Step 2: Count all n-digit numbers whose sorted digits match
        digit_low = 10 ** (n - 1)
        digit_high = 10 ** n
        count = 0

        for num in range(digit_low, digit_high):
            key = ''.join(sorted(str(num)))
            if key in k_palindrome_keys:
                count += 1

        return count


sol = Solution()
print(sol.countGoodIntegers(3 , 5))
print(sol.countGoodIntegers(1 , 4))
print(sol.countGoodIntegers(5 , 6))       