# Used to find occurrences of a pattern (substring) within a text
# TC = O(m + n) where m is length of the pattern and n is the length of the text
# When To Use:
#  1. Pattern Matching Problems
#        . Searching for a word or phrase in a large text 
#         Finding occurrences of DNA sequences in genomics data. 
#         
#   LPS --> Longest Prefix suffix equal length
#   lps[j] --> 0 to j what is lsngth of longest suffix prefix equal length

# make a function to build the lps array
from typing import List
def build_lps(pattern: str) -> List:
    n = len(pattern)
    lps = [0] * n
    curr_lps = 0
    i = 1
    while i < n:
        if pattern[i] == pattern[curr_lps]:
            curr_lps += 1
            lps[i] = curr_lps
            i += 1
        else:
            if curr_lps != 0:
                curr_lps = lps[curr_lps - 1]
            else:
                lps[i] = 0
                i += 1
    return lps

def kmp_search(text: str , pattern: str) -> int: # return the start index if pattern
    # Build the Longest preffix suffix
    lps = build_lps(pattern)
    n , m = len(text) , len(pattern)
    i , j = 0 , 0
    while i < n:
        if text[i] == pattern[j]:
            i += 1
            j += 1
        # If we got the pattern
        if j == m:
            return i - j 
        elif i < n and text[i] != pattern[j]:
            if j != 0:
                j = lps[j-1]
            else:
                i += 1
    
    return -1 # if not found
             