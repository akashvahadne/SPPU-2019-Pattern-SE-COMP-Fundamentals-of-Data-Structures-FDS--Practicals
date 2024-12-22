# a) Write a Python program to store roll numbers of student in array 
# who attended training program in random order. Write function 
# for searching whether particular student attended training program
# or not, using Linear search and Sentinel search.

def linear_search(roll_numbers, target): 
    for roll in range(len(roll_numbers)): 
        if roll_numbers[roll] == target: 
            return True 
    return False      

def sentinel_search(roll_numbers, target): 
    n = len(roll_numbers) 
    roll_numbers.append(target) 
    i = 0 
    while roll_numbers[i] != target: 
        i += 1 
    if(i != n): 
        return True 
    else: 
        return False 

roll_numbers = [102, 101, 105, 103, 104] 
target_roll = int(input("Enter roll number to search: ")) 
print("Linear Search Result:", linear_search(roll_numbers, target_roll)) 
print("Sentinel Search Result:", sentinel_search(roll_numbers, target_roll))
