class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        
        forces = [0] * n 
        
        # Left to Right --> only R force applied
        force = 0
        for i in range(n):
            if dominoes[i] == 'R':
                force = n 
            elif dominoes[i] == 'L':
                force = 0
            else:
                force = max(force - 1 , 0)
            
            forces[i] += force 
        
        # Right to left only L force applied
        force = 0
        for i in range(n-1 , -1 , -1):
            if dominoes[i] == 'L':
                force = n 
            elif dominoes[i] == 'R':
                force = 0
            else:
                force = max(force - 1 , 0)
            
            forces[i] -= force 
            
        # Build the answer
        ans = []
        
        for f in forces:
            if f > 0:
                ans.append('R')
            elif f < 0:
                ans.append('L')
            else:
                ans.append('.')
        
        return ''.join(ans)
                
sol = Solution()

print(sol.pushDominoes("RR.L"))
print(sol.pushDominoes(".L.R...LR..L.."))        