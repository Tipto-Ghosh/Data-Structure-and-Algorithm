class Solution:
    def largestGoodInteger(self, num: str) -> str:
        n = len(num) 
        ans = ""
        max_num = 0
        
        for i in range(2 , n):
            if num[i] == num[i - 1] == num[i - 2]:
               curr_num = int(num[i] + num[i] + num[i])
               
               if curr_num >= max_num:
                   max_num = curr_num
                   ans = num[i] + num[i] + num[i]
                   
        return ans


sol = Solution()

print(sol.largestGoodInteger("677713333999"))
print(sol.largestGoodInteger("2300019"))
print(sol.largestGoodInteger("42352338"))