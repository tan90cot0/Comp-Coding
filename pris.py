import sys

def input_a():
    arr = [int(x) for x in input_st().split()]
    return arr

def input_n():
    n = int(input_st())
    return n

def printlist(a):
    for x in a:
        print(x, end = " ")
 
def input_st():
    global mode
    if mode==0:
        return input()
    else:
        with open('/Users/aryan/Desktop/Comp-Coding/test_case.txt') as f:
            lines = f.readlines()
        global line 
        st = lines[line][:-1]
        line+=1
        return st

test_cases = True

def computeXORValue(n):
    remainder = n % 4
    if remainder == 0:
        return n
    elif remainder == 1:
        return 1
    elif remainder == 2:
        return n + 1
    elif remainder == 3:
        return 0

def calculateXORInRange(lower, upper):
    return computeXORValue(lower - 1) ^ computeXORValue(upper)

def solve():
    start, end, shiftAmount, constantValue = input_a()
    xorTotal = calculateXORInRange(start, end)
    factor = 1 << shiftAmount
    initialValue = (start - constantValue + factor - 1) // factor
    finalValue = (end - constantValue) // factor
    rangeXOR = calculateXORInRange(initialValue, finalValue)
    shiftedXOR = rangeXOR << shiftAmount
    if (finalValue - initialValue) % 2 == 0:
        shiftedXOR ^= constantValue
    print(xorTotal ^ shiftedXOR)
    
# Initialiser Function  
mode = 0
line = 0
if len(sys.argv)>1 and sys.argv[1]=='file':
    mode = 1

if test_cases:
    k = input_n()
    for l in range(k):
        solve()
else:
    solve()