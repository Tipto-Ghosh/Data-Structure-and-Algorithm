# 1's complements is found by flipping all bits 
# means all 0 will be 1 and all 1 will be 0
def ones_complements(n , num_bits):
    mask = (1 << num_bits) - 1
    return ~n & mask

# 2's complements--> find ones complements and add 1
def twos_complements(n , num_bits):
    mask = (1 << num_bits) - 1
    ones_comp = ones_complements(n , num_bits)
    return (ones_comp + 1) & mask


n = 2
print(ones_complements(n , 32))
print(twos_complements(n , 32))