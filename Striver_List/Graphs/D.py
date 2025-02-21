from typing import List
class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        # find The digit sum of a number
        def digitSum(n: int) -> int:
            res = 0
            while n > 0:
                digit = n % 10
                n //= 10
                res += digit
            
            return res


        # hashmap = defaultdict(int)
        hashmap = {}
        n = len(arr)
        for i in range(n):
            




