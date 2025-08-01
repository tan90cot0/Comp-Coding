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

# Example usage:
arr = [4, 2, 8, 1, 6]
counts = count_elements_to_right(arr)

print("Number of elements to the right that are less than each element:")
print(counts)
