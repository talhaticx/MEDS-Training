def sqrt_bs(x):
    if x < 0:
        raise ValueError("Cannot compute square root of a negative number.")
    if x == 0 or x == 1:
        return x
    
    low, high = 0, x
    precision = 1e-15  # Precision level for the result
    
    while high - low > precision:
        mid = (low + high) / 2
        if mid * mid == x:
            return mid
        elif mid * mid < x:
            low = mid
        else:
            high = mid
    
    return (low + high) / 2

# Example Usage
results = [(x, sqrt_bs(x)) for x in range(26)]

# Print results in a readable format
for x, result in results:
    print(f"Input: {x}, Square Root: {result}")
