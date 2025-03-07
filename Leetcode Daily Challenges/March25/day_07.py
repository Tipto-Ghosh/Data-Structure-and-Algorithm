from typing import List

class Solution:
    # Precompute primes once
    limit = 10**6
    all_primes = [True] * (limit + 1)
    all_primes[0] = all_primes[1] = False  # 0 and 1 are not prime

    for num in range(2, int(limit ** 0.5) + 1):
        if all_primes[num]:
            for multi in range(num * num, limit + 1, num):
                all_primes[multi] = False

    def closestPrimes(self, left: int, right: int) -> List[int]:
        primeInRange = [ele for ele in range(left, right + 1) if self.all_primes[ele]]

        if len(primeInRange) < 2:
            return [-1, -1]

        # Find the pair with the minimum difference
        minDiff = float('inf')
        ans = [-1, -1]

        for i in range(1, len(primeInRange)):
            diff = primeInRange[i] - primeInRange[i - 1]
            if diff < minDiff:
                minDiff = diff
                ans = [primeInRange[i - 1], primeInRange[i]]

        return ans


# Example test cases
sol = Solution()
print(sol.closestPrimes(10, 19))  # Output: [11, 13]
print(sol.closestPrimes(4, 6))    # Output: [-1, -1]
