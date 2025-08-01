import math
from heapq import heappush, heappop, heappushpop, heapify
import sys
import bisect
from collections import defaultdict
import sys

#The bisect_left() method is provided by the bisect module, which returns the left-most index to insert the given element, 
#while maintaining the sorted order.
# bisect.bisect_left(list, element)

# Input Output Functions
def input_arr():
    arr = [int(x) for x in input_string().split()]
    return arr
 
def input_n():
    n = int(input_string())
    return n

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

# Helper Functions 
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
 
def frequency(arr):
    d = {x:0 for x in arr}
    for x in arr:
        d[x]+=1
    return d
            
# Write code here
  
tree = None
# function to build the tree 
def build(arr, n) :
    for i in range(n) : 
        tree[n + i] = arr[i]; 
      
    for i in range(n - 1, 0, -1) : 
        tree[i] = tree[i << 1] & tree[i << 1 | 1]; 
  
# function to update a tree node 
def updateTreeNode(p, value, n) : 
    tree[p + n] = value; 
    p = p + n; 
    i = p
      
    while i > 1 :
        tree[i >> 1] = tree[i] & tree[i ^ 1]; 
        i >>= 1; 
  
# function to get sum on interval [l, r) 
def query(l, r, n) : 
    res = -1
    l += n
    r += n
    while l < r :
        if (l & 1) :
            if res==-1:
                res = tree[l]
            else:
                res = res&tree[l]
            l += 1
        if (r & 1) :
            r -= 1
            if res==-1:
                res = tree[r]
            else:
                res = res&tree[r]
        l >>= 1
        r >>= 1
    return res

def add_dict(d, key, val):
    if key in d.keys():
        d[key]+=val
    else:
        d[key]=val

def primeFactors(n):
    m = {}
    while n % 2 == 0:
        add_dict(m,2,1)
        n = n // 2
    for i in range(3,int(math.sqrt(n))+1,2):
        while n % i== 0:
            add_dict(m,i,1)
            n = n // i
    if n > 2:
        add_dict(m,n,1)
    return m

def d(m):
    ans = 1
    for x in m.keys():
        ans*=(m[x]+1)
    return ans

def divides(a,b):
    for x in a.keys():
        if x not in b.keys():
            return False
        if a[x]>b[x]:
            return False
    return True

class TrieNode:
    def __init__(self):
        self.children = {}
        self.val = 0

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
            node.val += 1
    
    def search(self, word):
        node = self.root
        ans = 0
        for ch in word:
            if ch not in node.children:
                return ans
            node = node.children[ch]
            ans+=node.val
        return ans

def make_unidirectional(graph):
    unidirectional_graph = {}
    visited = set()

    def dfs(node):
        visited.add(node)
        for neighbor in graph[node]:
            if neighbor not in visited:
                unidirectional_graph[node].append(neighbor)
                dfs(neighbor)

    # Initialize the unidirectional graph with an empty adjacency list for each node
    for node in graph:
        unidirectional_graph[node] = []

    # Start DFS from the root node (assumed to be node 1)
    dfs(1)

    return unidirectional_graph

class FenwickTree:
    def __init__(self, size):
        self.size = size
        self.tree = [0] * (size + 1)

    def update(self, index, delta):
        while index <= self.size:
            self.tree[index] += delta
            index += index & -index

    def query(self, index):
        result = 0
        while index > 0:
            result += self.tree[index]
            index -= index & -index
        return result

def count_elements_to_right(arr):
    max_val = max(arr)
    fenwick_tree = FenwickTree(max_val)
    counts = []

    for i in range(len(arr) - 1, -1, -1):
        counts.append(fenwick_tree.query(arr[i] - 1))
        fenwick_tree.update(arr[i], 1)

    return counts[::-1]

def argmax(arr):
    return arr.index(max(arr))

def argmin(arr):
    return arr.index(min(arr))

def good_pairs(word):
    n = len(word)
    cnt=0
    for i in range(n-1):
        for j in range(i+1, n):
            if word[i]==word[j]:
                cnt+=1
                continue
            else:
                for k in range(i, j):
                    if word[k]!=word[k+1] and (word[k]!=word[i] or word[k+1]!=word[j]):
                        cnt+=1
                        break
    return cnt

def f(k, p):
    fl = math.isqrt(k + p)  # Use isqrt to avoid floating point issues
    return fl - p

def power(a, b, mod=10**9 + 7):
    result = 1
    a %= mod  # Apply modulo to the base to handle large numbers
    while b > 0:
        if b % 2 == 1:  # If b is odd, multiply result by a and take modulo
            result = (result * a) % mod
        a = (a * a) % mod  # Square the base and take modulo
        b //= 2  # Divide the exponent by 2
    return result

def f():
    new_real_times = [
    "219m15.056s", "103m11.547s", "51m21.786s", "34m10.411s",
    "17m42.162s", "9m35.252s", "8m42.122s"
]

    # Convert each time to seconds, handling the "s" suffix in seconds
    new_seconds = [int(m) * 60 + float(s[:-1]) for time in new_real_times for m, s in [time.split('m')]]
    for sec in new_seconds:
        print(sec)

test_cases = False

def solve():
    f()


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