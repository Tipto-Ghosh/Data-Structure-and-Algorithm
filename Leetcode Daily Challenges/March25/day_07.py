from typing import List
class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        # make a array by using sieve algo to store all the primes
        # then traverse from left to right and get all the primes
        # Now check difference. for every element check difference with it;s left and right element
        # maintain a minDiff to find min difference
        
        # range can be 1 to 10**6 so make a array
        limit=10**6
        all_primes = [True] * (limit + 1)
        all_primes[0] = all_primes[1] = False # 0 and 1 are not prime
        
        for num in range(2 , int(limit ** 0.5) + 1):
            # if num is a prime then it's multipliar are not prime
            if all_primes[num]:
                for multi in range(num * num , limit + 1 , num): # loop from 1 to 10
                    all_primes[multi] = False
        
        
        primeInRange = []
        for ele in range(left , right + 1):       
            if all_primes[ele]: # if ele is a prime then take it
                primeInRange.append(ele)
        # if we dont get a pair then return [-1,-1]
        if len(primeInRange) < 2:
            return [-1 , -1]
        elif len(primeInRange) == 2:
            return primeInRange
        # Otherwise find the min difference pair
        minDiff = float('inf')
        ans = [-1 , -1]
        for i in range(1 , len(primeInRange)):
            if primeInRange[i] - primeInRange[i-1] < minDiff:
                minDiff = primeInRange[i] - primeInRange[i-1]
                ans[0] , ans[1] = primeInRange[i-1] , primeInRange[i]    
        
        return ans  
    

sol = Solution()

print(sol.closestPrimes(10 , 19))
print(sol.closestPrimes(4 , 6))