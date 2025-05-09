from math import comb


class Solution:
    def countBalancedPermutations(self, num: str) -> int:
        MOD = 10**9 + 7
        tot, n = 0, len(num)
        cnt = [0] * 10
        for ch in num:
            d = int(ch)
            cnt[d] += 1
            tot += d
        if tot % 2 != 0:
            return 0

        target = tot // 2
        max_odd = (n + 1) // 2
        f = [[0] * (max_odd + 1) for _ in range(target + 1)]
        f[0][0] = 1
        psum = tot_sum = 0
        for i in range(10):
            # Sum of the number of the first i digits
            psum += cnt[i]
            # Sum of the first i numbers
            tot_sum += i * cnt[i]
            for odd_cnt in range(
                min(psum, max_odd), max(0, psum - (n - max_odd)) - 1, -1
            ):
                # The number of bits that need to be filled in even numbered positions
                even_cnt = psum - odd_cnt
                for curr in range(
                    min(tot_sum, target), max(0, tot_sum - target) - 1, -1
                ):
                    res = 0
                    for j in range(
                        max(0, cnt[i] - even_cnt), min(cnt[i], odd_cnt) + 1
                    ):
                        if i * j > curr:
                            break
                        # The current digit is filled with j positions at odd positions, and cnt[i] - j positions at even positions
                        ways = (
                            comb(odd_cnt, j) * comb(even_cnt, cnt[i] - j) % MOD
                        )
                        res = (
                            res + ways * f[curr - i * j][odd_cnt - j] % MOD
                        ) % MOD
                    f[curr][odd_cnt] = res % MOD

        return f[target][max_odd]        
        
sol = Solution()
print(sol.countBalancedPermutations('123'))
print(sol.countBalancedPermutations('112'))
print(sol.countBalancedPermutations('12345'))

