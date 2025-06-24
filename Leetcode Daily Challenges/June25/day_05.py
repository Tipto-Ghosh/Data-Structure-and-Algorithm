class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        """
        Let's make a mapping system. use the equivalance relation
        and try to minimize the character like:
        s1 = abc , s2 = cde then we can say:
        a -> a
        b -> b
        c -> a
        d -> b
        e -> a 
        
        Let's use UNION FIND to map the smallest one with larger one's
        """
        parent = list(range(26)) # union find from a to z
        
        def find(X):
            if parent[X] != X:
                parent[X] = find(parent[X]) # path comprehension
            return parent[X] # return X or parent[X] cause both are same
        
        # dont need any rank cause here character ascii is working as rank
        def union(x , y):
            # find the parent of x and y
            parent_x = find(x)
            parent_y = find(y)
            
            # if both are in same group dont need to anything
            if parent_x == parent_y:
                return
            
            # otherwise marge the connect the larger character with the smallest one
            if parent_x < parent_y:
                parent[parent_y] = parent_x
            else:
                parent[parent_x] = parent_y      
        
        for a , b in zip(s1 , s2):
            union((ord(a) - ord('a')) , (ord(b) - ord('a')))               
        
        
        ans = []
        
        for ch in baseStr:
            smallest_equiv = chr(find(ord(ch) - ord('a')) + ord('a'))
            ans.append(smallest_equiv)
        
        return ''.join(ans)
        
        
         
sol = Solution()
# print(sol.smallestEquivalentString("abc" , "cde" , "eed"))    
print(sol.smallestEquivalentString(s1 = "parker", s2 = "morris", baseStr = "parser"))    
print(sol.smallestEquivalentString(s1 = "hello", s2 = "world", baseStr = "hold"))    
print(sol.smallestEquivalentString(s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"))    
