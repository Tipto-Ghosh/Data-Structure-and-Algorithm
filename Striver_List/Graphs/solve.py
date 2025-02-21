import sys
import time
import inspect

# Redirect I/O
sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")
sys.stderr = open("error.txt", "w")

# Fast I/O functions
def fast_input(): return sys.stdin.readline().strip()
def fast_print(*args, **kwargs): 
    sys.stdout.write(" ".join(map(str, args)) + "\n")

# 🔥 Universal Debug Function (Prints to error.txt)
DEBUG = True  # Set False to disable debugging

def debug(*args):
    """Prints variable names and values for any data type."""
    if DEBUG:
        frame = inspect.currentframe().f_back  # Get the previous frame
        variables = {id(v): k for k, v in frame.f_locals.items()}  # Map variable values to names

        for var in args:
            var_name = variables.get(id(var), "Unknown Variable")
            sys.stderr.write(f"{var_name} = {repr(var)}\n")

# Execution timer
def measure_time(func, *args, **kwargs):
    start_time = time.time()
    result = func(*args, **kwargs)
    end_time = time.time()
    sys.stderr.write(f"Execution Time: {end_time - start_time:.6f} sec\n")
    return result

# 🏆 LeetCode Problem Function (Modify Here)
def solve():
    # Example Problem: Sort an Array
    def example_function(arr):
        debug(arr)  # Debugging
        arr.sort()
        debug(arr)  # Debugging
        return arr

    # Read input (Modify based on problem)
    n = int(fast_input())  # First line: number of elements
    arr = list(map(int, fast_input().split()))  # Read list
    result = example_function(arr)

    # Print result
    fast_print(*result)

# Run & Measure Execution Time
measure_time(solve)
