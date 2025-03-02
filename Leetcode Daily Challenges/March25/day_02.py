from typing import List 

class Solution:
    def mergeArrays(self, arr1: List[List[int]], arr2: List[List[int]]) -> List[List[int]]:
        n1 , n2  = len(arr1) , len(arr2)
        # We go with 2 pointer
        # i --> pointer1 , j --> Pointer2
        # If id of i , j match then sum the value and store. Move both pointer
        # Always move the pointer with lower id 
        ans = []
        i , j = 0 , 0
        while i < n1 and j < n2:
            id , val = min(arr1[i][0] , arr2[j][0]) ,  0
            # If both's id are same
            if arr1[i][0] == arr2[j][0]:
                val = arr1[i][1] + arr2[j][1]
                i += 1
                j += 1
            elif  arr1[i][0] < arr2[j][0]:
                val = arr1[i][1]
                i += 1
            else:
                val = arr2[j][1]
                j += 1
            ans.append([id , val])
        
        # Take remaining values
        while i < n1:
            ans.append(arr1[i])
            i += 1
        while j < n2:
            ans.append(arr2[j])
            j += 1
        
        return ans 
        
sol = Solution()

nums1 = [[1,2],[2,3],[4,5]]
nums2 = [[1,4],[3,2],[4,1]]
print(sol.mergeArrays(nums1 , nums2))


nums1 = [[2,4],[3,6],[5,5]]
nums2 = [[1,3],[4,3]]
print(sol.mergeArrays(nums1 , nums2))
        