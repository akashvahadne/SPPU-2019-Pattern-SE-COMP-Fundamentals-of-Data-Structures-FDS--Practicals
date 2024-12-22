# Write a Python program to store first year percentage of students
# in array. Write function for sorting array of floating point
# numbers in ascending order using quick sort and display top five
# scores.

def quick_sort(arr): 
    if len(arr) <= 1: 
        return arr 
    pivot = arr[len(arr) // 2] 
    left = [x for x in arr if x < pivot] 
    middle = [x for x in arr if x == pivot] 
    right = [x for x in arr if x > pivot] 
    return quick_sort(left) + middle + quick_sort(right) 

def display_top_five(arr): 
    print("Top 5 Scores:", arr[-5:]) 

num_students = int(input("Enter the number of students: ")) 
percentages = [] 

for i in range(num_students): 
    percentage = float(input(f"Enter percentage of student {i + 1}: ")) 
    percentages.append(percentage) 

sorted_scores = quick_sort(percentages) 
display_top_five(sorted_scores)
