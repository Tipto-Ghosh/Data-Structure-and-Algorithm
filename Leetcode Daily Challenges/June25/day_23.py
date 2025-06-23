class Solution:
    def kMirror(self, k: int, n: int) -> int:
        # check if a number is a palindrome in base-k
        def isPalindrome(x: int) -> bool:
            digit = []
            # Convert x to base-k and store digits
            while x:
                digit.append(x % k)
                x //= k
            
            return digit == digit[::-1]

        # left: starting point to generate palindromic "halves"
        # cnt: how many valid k-mirror numbers we've found
        # ans: total sum of valid k-mirror numbers
        left, cnt, ans = 1, 0, 0

        # Keep generating palindromes until we've found n of them
        while cnt < n:
            right = left * 10  # next range of numbers for palindrome halves

            # Generate both odd and even length palindromes
            for op in [0, 1]:
                # op = 0 → odd-length palindromes (e.g., 121, 131)
                # op = 1 → even-length palindromes (e.g., 1221, 1331)

                # Iterate over all possible "half" numbers in current range
                for i in range(left, right):
                    if cnt == n:
                        break  # Stop early if we've already found enough

                    combined = i  # Start with the left half
                    # For odd-length palindromes, skip the last digit in the mirror
                    x = i // 10 if op == 0 else i

                    # Mirror the digits and build the full palindrome
                    while x:
                        combined = combined * 10 + x % 10
                        x //= 10

                    # If the full number is also a palindrome in base-k
                    if isPalindrome(combined):
                        cnt += 1          # Increase count of valid numbers
                        ans += combined   # Add to total sum

            left = right  # Move to the next digit-length for the left half

        return ans  