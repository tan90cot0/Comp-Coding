def solve():
    # Read the number of test cases
    t = int(input().strip())
    results = []

    # Process each test case
    for _ in range(t):
        n, b, c = map(int, input().split())
        
        # Case 1: Impossible case with b = 0, c = 0, and n > 2
        if b == 0 and c == 0 and n > 2:
            results.append(-1)
            continue
        
        # Case 2: Constant array (b = 0)
        if b == 0:
            if c >= n:
                results.append(n)  # All values in a are c, so it takes n replacements.
            else:
                results.append(n - 1)  # It takes n - 1 replacements to create a permutation.
            continue
        
        # General case: calculate the number of replacements required
        r = n - 1 - c
        k = 1 + r // b if r >= 0 else 0
        results.append(n - k)
    
    # Print all results for each test case
    for result in results:
        print(result)

# Run the program
solve()