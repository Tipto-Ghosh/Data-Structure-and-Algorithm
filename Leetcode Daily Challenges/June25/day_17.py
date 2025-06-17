MOD = 10** 9 + 7
MX = 10**5 # Max size which factorial precomuteation needed

# Precompute factorials and inverse factorials for combinations
fact = [0] * MX        # fact[i] will store i!
inv_fact = [0] * MX    # inv_fact[i] will store modular inverse of i!


# Fast exponentiation: computes (x^n) % MOD efficiently
def qpow(x, n):
    res = 1
    while n:
        if n & 1:              # If current bit is set, multiply result
            res = res * x % MOD
        x = x * x % MOD        # Square the base
        n >>= 1                # Shift bits to the right (divide n by 2)
    return res

# Precompute factorials and inverse factorials modulo MOD
def init():
    if fact[0] != 0:
        return  # Already initialized

    fact[0] = 1
    for i in range(1, MX):
        fact[i] = fact[i - 1] * i % MOD  # Compute i! % MOD

    # Compute inverse factorial of (MX - 1)! using Fermat’s Little Theorem
    inv_fact[MX - 1] = qpow(fact[MX - 1], MOD - 2)

    # Compute all other inverse factorials using backward multiplication
    for i in range(MX - 1, 0, -1):
        inv_fact[i - 1] = inv_fact[i] * i % MOD

# Compute n choose m modulo MOD using precomputed factorials
def comb(n, m):
    if m < 0 or m > n:
        return 0  # Invalid case
    return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD


class Solution:
    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        # Step 1: Initialize factorials and inverse factorials
        init()
        
        # Step 2: Count ways to choose k positions (out of n-1) where adjacent elements are equal
        choose_equal_positions = comb(n - 1, k)
        
        # Step 3: Choose the first value of the array (can be any of m values)
        start_value_ways = m
        
        # Step 4: For the remaining (n - 1 - k) positions that must differ from previous,
        # each has (m - 1) choices (to differ from the previous one)
        change_positions_ways = qpow(m - 1, n - k - 1)
        
        # Step 5: Multiply all three parts together and return modulo MOD
        total_ways = choose_equal_positions * start_value_ways % MOD
        total_ways = total_ways * change_positions_ways % MOD

        return total_ways


sol = Solution()

print(sol.countGoodArrays(3,2,1))