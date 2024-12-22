# b) Write a Python program to store roll numbers of student array
# who attended training
# program in sorted order. Write function for searching whether
# particular student attended training program or not, using Binary
# search and Fibonacci search.

def binary_search(roll_numbers, target): 
    left, right = 0, len(roll_numbers) - 1 
    while left <= right: 
        mid = (left + right) // 2 
        if roll_numbers[mid] == target: 
            return True 
        elif roll_numbers[mid] < target: 
            left = mid + 1 
        else: 
            right = mid - 1 
    return False 

def fibonacci_search(roll_numbers, target): 
    fib_m2 = 0 
    fib_m1 = 1 
    fib_m = fib_m2 + fib_m1 
    while fib_m < len(roll_numbers): 
        fib_m2, fib_m1 = fib_m1, fib_m 
        fib_m = fib_m2 + fib_m1 
    offset = -1 
    while fib_m > 1: 
        i = min(offset + fib_m2, len(roll_numbers) - 1) 
        if roll_numbers[i] < target: 
            fib_m = fib_m1 
            fib_m1 = fib_m2 
            fib_m2 = fib_m - fib_m1 
            offset = i 
        elif roll_numbers[i] > target: 
            fib_m = fib_m2 
            fib_m1 -= fib_m2 
            fib_m2 = fib_m1 - fib_m2 
        else: 
            return True 
    if fib_m1 and offset + 1 < len(roll_numbers) and roll_numbers[offset + 1] == target: 
        return True 
    return False 

roll_numbers = [101, 102, 103, 104, 105] 
target_roll = int(input("Enter roll number to search: ")) 
print("Binary Search Result:", binary_search(roll_numbers, target_roll)) 
print("Fibonacci Search Result:", fibonacci_search(roll_numbers, target_roll))
