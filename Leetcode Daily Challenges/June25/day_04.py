class Solution: 
    # Function to find the lexicographically last substring in the input string
    def lastSubstring(self, s: str) -> str:
        i, j, n = 0, 1, len(s)  # i and j are two pointers, n is the length of the string

        # The idea is to use a two-pointer technique to compare suffixes
        while j < n:
            k = 0  # k is used to compare characters offset from i and j

            # Compare characters at current offsets from i and j until they differ
            while j + k < n and s[i + k] == s[j + k]:
                k += 1

            # If characters differ and the suffix starting at j is larger
            if j + k < n and s[i + k] < s[j + k]:
                # Move i to j since suffix at j is better, and update j
                i, j = j, max(j + 1, i + k + 1)
            else:
                # If suffix at i is better or equal, just move j to skip compared part
                j = j + k + 1

        # Return the suffix of the string starting at index i
        return s[i:]

    # Function to return the final answer string from the game
    def answerString(self, word: str, numFriends: int) -> str:
        # If there's only one friend, the whole word is the only possible split
        if numFriends == 1:
            return word

        # Find the lexicographically largest suffix
        last = self.lastSubstring(word)
        n, m = len(word), len(last)

        # The longest piece from 'last' that can be one of the parts in any valid split
        # Can't be longer than (n - numFriends + 1), because we need at least 1 char per friend
        return last[: min(m, n - numFriends + 1)]
