from typing import List

class Solution:
    def triangleType(self, arr: List[int]) -> str:
        triangle_types = {
            1 : 'equilateral',
            2 : 'isosceles',
            3 : 'scalene',
            4 : 'none'
        }
        
        # check is possible to form a triangle
        if (arr[0] < (arr[1] + arr[2])) and (arr[1] < (arr[0] + arr[2])) and (arr[2] < (arr[0] + arr[1])):
            # if 3 sides are equal
            if arr[0] == arr[1] == arr[2]:
                return triangle_types[1]
            elif (arr[0] == arr[1]) or (arr[0] == arr[2]) or (arr[1] == arr[2]):
                return triangle_types[2]
            else:
                return triangle_types[3] 
        else:
            return triangle_types[4]

sol = Solution()

print(sol.triangleType([3,3,3]))
print(sol.triangleType([3,4,5]))