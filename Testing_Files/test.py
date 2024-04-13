def even_fibonacci_sum(limit):
    a, b = 1, 2
    total_sum = 0
    
    while a <= limit:
        print(a)
        if a % 2 == 0:
            total_sum += a
        a, b = b, a + b
    
    return total_sum

# Calculate the sum of even-valued Fibonacci terms below 4 million
result = even_fibonacci_sum(10)
print(result)