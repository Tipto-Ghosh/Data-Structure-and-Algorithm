from typing import List

class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)
        self.build(arr, 0, 0, self.n - 1)
        
    def build(self, arr, node, start, end):
        if start == end:
            self.tree[node] = arr[start]
        else:
            mid = (start + end) // 2
            self.build(arr, 2 * node + 1, start, mid)
            self.build(arr, 2 * node + 2, mid + 1, end)
            self.tree[node] = self.tree[2 * node + 1] + self.tree[2 * node + 2]
    
    def update(self, idx, val, node=0, start=None, end=None):
        if start is None:
            start = 0
            end = self.n - 1
        if start == end:
            self.tree[node] = val
        else:
            mid = (start + end) // 2
            if idx <= mid:
                self.update(idx, val, 2 * node + 1, start, mid)
            else:
                self.update(idx, val, 2 * node + 2, mid + 1, end)
            self.tree[node] = self.tree[2 * node + 1] + self.tree[2 * node + 2]
    
    def query(self, l, r, node=0, start=None, end=None):
        if start is None:
            start = 0
            end = self.n - 1
        if l > end or r < start:
            return 0
        if l <= start and end <= r:
            return self.tree[node]
        mid = (start + end) // 2
        leftSum = self.query(l, r, 2 * node + 1, start, mid)
        rightSum = self.query(l, r, 2 * node + 2, mid + 1, end)
        return leftSum + rightSum

class Solution(object):
    def goodTriplets(self, nums1, nums2):
        mpp = {}
        idx = 1
    
        for x in nums1:
            mpp[x] = idx
            idx += 1
    
        for i in range(len(nums2)):
            nums2[i] = mpp[nums2[i]]
    
        n = len(nums1)
        leftArr = [0] * n
        rightArr = [1] * n
        leftTree = SegmentTree(leftArr)
        rightTree = SegmentTree(rightArr)
        leftTree.update(nums2[0] - 1, 1)
        rightTree.update(nums2[0] - 1, 0)
        total = 0
    
        for i in range(1, n - 1):
            idx = nums2[i]
            rightTree.update(idx - 1, 0)
            left = leftTree.query(0, idx - 2) if idx - 2 >= 0 else 0
            right = rightTree.query(idx, n - 1)
            total += left * right
            leftTree.update(idx - 1, 1)
    
    
        return total        
        
        
        
        
sol = Solution()

print(sol.goodTriplets(nums1 = [2,0,1,3], nums2 = [0,1,2,3]))        
print(sol.goodTriplets(nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]))     