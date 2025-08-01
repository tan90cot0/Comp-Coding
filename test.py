def can_complete_level(segments, k):
    current_position = 0

    for l, r in segments:
        # Try to move to the rightmost point within distance k
        current_position = max(current_position + k, l)
        
        # If the current position is outside the current segment, return False
        if current_position > r:
            return False
    
    # If the loop completes, it means the level can be completed with the given k
    return True

def min_k_to_complete_level(segments):
    # Define the search space
    low, high = 0, 10**9  # You can adjust the upper bound based on the problem constraints

    while low <= high:
        mid = (low + high) // 2
        print(mid)

        if can_complete_level(segments, mid):
            high = mid - 1
        else:
            low = mid + 1

    return low

# Example usage:
segments = [(0,0), (1, 5), (3, 4), (5, 6), (8, 10), (0, 1)]
result = min_k_to_complete_level(segments)
print(result)
