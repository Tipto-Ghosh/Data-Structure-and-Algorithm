class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        # https://leetcode.com/problems/compare-version-numbers/?envType=daily-question&envId=2025-09-23
        
        # count the number of dots
        def count_dots(s: str) -> int:
            count = 0
            for ch in s:
                if ch == '.':
                    count += 1
            return count
        
        count1 = count_dots(version1)
        count2 = count_dots(version2)
        max_dot_count = max(count1 , count2)
        
        def add_dots(s: str , count: int) -> str:
            s = list(s)
            dot_needed = max_dot_count - count
            for i in range(dot_needed):
                s.append('.0')
            
            return ''.join(s)
            
        if count1 > count2:
            version2 = add_dots(version2 , count2)
        else:
            version1 = add_dots(version1 , count1)
        
        # print(f"version1: {version1} | version2: {version2}")
        
        # extract all numbers
        version1 = version1.split(".")
        version2 = version2.split(".")
        
        # now compare one by one
        for i in range(len(version1)):
            val1 , val2 = version1[i] , version2[i]
            # convert into int
            val1 = int(val1)
            val2 = int(val2)
            
            if val1 > val2:
                return 1
            elif val2 > val1:
                return -1
        
        return 0        
        
    
    
sol = Solution()
print(sol.compareVersion(version1 = "1.2", version2 = "1.10"))
print(sol.compareVersion(version1 = "1.01", version2 = "1.001"))
print(sol.compareVersion(version1 = "1.0", version2 = "1.0.0.0"))