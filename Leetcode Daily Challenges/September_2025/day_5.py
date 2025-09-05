class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        k = 0 # count of operations
        
        while True:
            val = num1 - num2 * k
            if val < k:
                return -1
            
            if k >= val.bit_count():
                return k 
            
            k += 1 