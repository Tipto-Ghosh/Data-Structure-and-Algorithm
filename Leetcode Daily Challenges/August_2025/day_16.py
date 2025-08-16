class Solution:
    def maximum69Number (self, num: int) -> int:
        num_str = str(num)
        num_list = []
        # print(f"Before: {num_list}")
        # to make the max number just change the left most 6 to 9
        isChanged = False
        
        for i in range(len(num_str)):
            if num_str[i] == '6' and not isChanged:
                num_list.append('9')
                isChanged = True
            else:
                num_list.append(num_str[i])
                
        # print(f"After: {num_list}")
        return int(''.join(num_list))


sol = Solution()

print(sol.maximum69Number(9669))
print(sol.maximum69Number(9996))
print(sol.maximum69Number(999))