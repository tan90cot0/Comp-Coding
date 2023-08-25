import math
from heapq import heappush, heappop, heappushpop
import sys
import bisect
 
#The bisect_left() method is provided by the bisect module, which returns the left-most index to insert the given element, 
#while maintaining the sorted order.
# bisect.bisect_left(list, element)
 
def is_prime(n):
    for i in range(2, int(math.sqrt(n)+1)):
        if n%i==0:
            return False
    return True
 
 
 
M = int(1e9 + 7)
k = int(2e5+1)
fact = [0,1]
for i in range(2,k):
    fact.append((fact[i-1]*i)%M)
 
primes = []
for i in range(2, k):
    if is_prime(i):
        primes.append(i)
 
def mul(x, y, p):
    return (x%p * y%p) % p
 
def add(x, y, p):
    return (x%p + y%p) % p
 
def input_arr():
    arr = [int(x) for x in input_string().split()]
    return arr
 
def input_n():
    n = int(input_string())
    return n
 
def sub_list(a,b):
    c = []
    for i in range(len(a)):
        c.append(a[i]-b[i])
    return c
 
def sub_const(a, c):
    b = []
    for x in a:
        b.append(x-c)
    return b
 
def binary_search(arr, low, high, x):
    if x<arr[0]:
        return -1
    mid = (high + low) // 2
    if high >= low:
        mid = (high + low) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] >= x:
            return binary_search(arr, low, mid - 1, x)
        else:
            return binary_search(arr, mid + 1, high, x)
    else:
        return high
    
def printlist(a):
    for x in a:
        print(x, end = " ")
 
def input_string():
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
 
def pow_modp(x, y, p):
    if y<0:
        return 1
    res = 1
    x%=p
    while (y > 0):
        if ((y & 1) != 0):
            res = ((res%p) * (x%p))%p
        y = y >> 1  # y = y/2
        x = (x%p * x%p)%p  # Change x to x^2
    return res % p
 
def inv(x):
    return pow_modp(x,M-2,M)
 
def ncr_modp(n, r, p):
    if n<=0 or r<=0 or (n-r)<=0:
        return 1
    return fact[n]*((inv(fact[r])*inv(fact[n-r]))%p)%p
 
def ncr(n, r):
    return math.comb(n, r)
 
def binary(n):
    return format(n, 'b')
# binary to decimal is int(s,2)
 
def connected_components(adj):
    connected = 0
    k = 1
    n = len(adj.keys())
    visited = set()
    while k<=n:
        if k in visited:
            k+=1
            continue
        q = [k]
        while q:
            elem = q.pop(-1)
            if elem not in visited:
                q = q + adj[elem]
                visited.add(elem)
        connected+=1
        k+=1
    return connected
 
def adjacency_matrix(edges, n):
    adj = {}
    double = 0
    for i in range(n):
        if edges[i][0] not in adj:
            adj[edges[i][0]] = [edges[i][1]]
        else:
            if edges[i][1] in adj[edges[i][0]]:
                double+=1
            else:
                adj[edges[i][0]].append(edges[i][1])
 
        if edges[i][1] not in adj:
            adj[edges[i][1]] = [edges[i][0]]
        else:
            if edges[i][0] in adj[edges[i][1]]:
                double+=1
            else:
                adj[edges[i][1]].append(edges[i][0])
    return adj, double
 
def frequency(arr):
    d = {x:0 for x in arr}
    for x in arr:
        d[x]+=1
    return d
 
def solve():
    w, f = input_arr()
    n = input_n()
    arr = input_arr()
    s = 0
    for x in arr:
        s+=x
    sums = [0 for i in range(s+1)]
    sums[0] = 1
    for x in arr:
        for y in range(s, x-1, -1):
            sums[y] = sums[y] | sums[y-x]
    ans = 100000000000
    for sum in range(len(sums)):
        if sums[sum]==1:
            ans = min(ans, max(math.ceil(sum/w) , math.ceil((s-sum)/f)))
    print(ans)


    # largest difference + max element
    # 2 5 1 10 6
    # 0 1 2 3 4 

    # 1 2 5 6 10
    # 2 0 1 4 3

    # 1 3 1 4

    # 1 4 4 

    # 1 4 1 3

    # query is 1 7





t = True    

mode = 0
line = 0
if len(sys.argv)>1 and sys.argv[1]=='file':
    mode = 1

if t:
    k = input_n()
    for l in range(k):
        solve()
else:
    solve()