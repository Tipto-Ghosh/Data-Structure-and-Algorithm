# Created By: Tipto Ghosh
# Creation Time: 2025/03/29 07:56:19


from typing import List
import heapq

class Solution:
    def maximumScore(self, arr: List[int], k: int) -> int:
        mod = 10**9 + 7
        
        # Function to count distinct prime factors of a number
        def count_prime_factors(num: int) -> int:
            prime_factors = set()
            while num % 2 == 0:
                prime_factors.add(2)
                num //= 2
            
            fact = 3
            while fact * fact <= num:
                while num % fact == 0:
                    prime_factors.add(fact)
                    num //= fact
                fact += 2 
            
            if num > 1:
                prime_factors.add(num)
            return len(prime_factors)

        # Compute prime factors for each number
        prime_score = {num: count_prime_factors(num) for num in set(arr)}

        n = len(arr)
        left = [-1] * n
        right = [n] * n

        # Monotonic stack to find left boundary
        stack = []
        for i in range(n):
            while stack and prime_score[arr[stack[-1]]] < prime_score[arr[i]]:
                stack.pop()
            left[i] = stack[-1] if stack else -1
            stack.append(i)

        # Monotonic stack to find right boundary
        stack.clear()
        for i in range(n - 1, -1, -1):
            while stack and prime_score[arr[stack[-1]]] <= prime_score[arr[i]]:
                stack.pop()
            right[i] = stack[-1] if stack else n
            stack.append(i)

        # Compute contribution of each element
        elements = []
        for i in range(n):
            count = (i - left[i]) * (right[i] - i)
            elements.append((arr[i], count))

        # Sort elements based on value (high to low)
        elements.sort(reverse=True, key=lambda x: x[0])

        # Maximize the score by taking `k` elements
        score = 1
        for val, freq in elements:
            take = min(freq, k)
            score = (score * pow(val, take, mod)) % mod
            k -= take
            if k == 0:
                break

        return score


sol = Solution()

print(sol.maximumScore([1,7,11,1,5], k = 14))
print(sol.maximumScore([1,7,11,1,5], k = 14))

