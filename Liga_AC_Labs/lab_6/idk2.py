def fib_generator():
    
    a, b = 1,1 

    while True:
        yield a
        a, b = b, a + b


for number in fib_generator():
    print(number)
    if number > 100:
        break
