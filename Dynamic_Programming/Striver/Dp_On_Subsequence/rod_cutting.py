from sys import stdin
import sys

def cutRod(price, n):
    # we can cut 1 to n
    # For each index we have 2 option cut , dont cut
    # func(x , n) -> means till index x what is max price can be optained
    # dp = [[-1] * (n + 1) for _ in range(n)]
    
    # def solve_memo(index: int , rodLength: int) -> int:
    #     if index == 0:
    #         # now we can only length 1 so price will be rodLength * price[index]
    #         return price[0] * rodLength
    #     if dp[index][rodLength] != -1:
    #         return dp[index][rodLength]
            
    #     dont_cut = solve_memo(index - 1 , rodLength)
    #     cut = 0
    #     if rodLength >= index + 1:
    #         cut = price[index] + solve_memo(index , rodLength - (index + 1))
    #     dp[index][rodLength] = max(cut , dont_cut)
    #     return dp[index][rodLength]
     
    # return solve_memo(n - 1 , n)
    
    # Solve Using Tabulation
    dp = [[0] * (n + 1) for _ in range(n)]
    # for all row 0 value will be rodLength * price[0]
    for rod in range(n + 1):
        dp[0][rod] = price[0] * rod
    # we have done with cut off 1 unit
    for index in range(1 , n):
        for rodLength in range(n + 1):
            dont_cut = dp[index - 1][rodLength]
            cut = 0
            if rodLength >= index + 1:
                cut = price[index] + dp[index][rodLength - (index + 1)]
            dp[index][rodLength] = max(cut , dont_cut)
    
    return dp[n-1][n]        
        
               
# Taking input using fast I/O.
def takeInput():
    n = int(input())

    price = list(map(int, input().strip().split(" ")))

    return price, n


# Main.
t = int(input())
while t:
    # print("Test Case: " , t)
    price, n = takeInput()
    # ans = cutRod(price , n)
    # print("Ans" , ans)
    print(cutRod(price, n))
    t = t-1
