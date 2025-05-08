def exp(x:float, times:int = 30)->float:
    """Using Taylor series, exp(x) = Sum ((x^n)/n!)
    """
    result = 0
    factorial = 1 # Avoid repeated calcs
    
    for n in range(times):
        if n > 0:
            factorial *= n
        
        result += (x**n)/factorial
    
    return result

# Testing
print("Self implemented exp: ")
print([exp(x) for x in range(10)])

# Checking
import math
print("\n Built-in exp:")
print([math.exp(x) for x in range(10)])

# OR 

# Precision Checking

print("\nPrecision Check")
for times in range(0, 25, 3): # 0 to 30
    print()
    print([f"{exp(x, times):.6f}" for x in range(5)])
