def deci_to_binary(num: int) -> str:
    binary = []
    while num != 0:
        remain = num % 2
        num //= 2
        if remain == 1:
            binary.append('1')
        else:
            binary.append('0')
    
    return ''.join(reversed(binary))

def binary_to_deci(s: str)->int:
    pow = 0
    num = 0
    for ele in reversed(s):
        n = 1 if ele == '1' else 0
        num += (n * (2 ** pow))
        pow += 1
    
    return num

n = int(input("Enter the number: "))
b = deci_to_binary(n)
d = binary_to_deci(b)
print(b , d)