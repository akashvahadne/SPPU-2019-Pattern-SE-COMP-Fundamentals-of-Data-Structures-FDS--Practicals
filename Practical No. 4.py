# Write a Python program to store first year percentage of students in
# array. Write function for sorting array of floating point numbers in
# ascending order using:
# Selection Sort
# a) Bubble sort and display top five scores.

def selection_sort(arr): 
    n = len(arr) 
    for i in range(n): 
        min_idx = i 
        for j in range(i + 1, n): 
            if arr[j] < arr[min_idx]: 
                min_idx = j 
        arr[i], arr[min_idx] = arr[min_idx], arr[i] 

def bubble_sort(arr): 
    n = len(arr) 
    for i in range(n): 
        for j in range(0, n - i - 1): 
            if arr[j] > arr[j + 1]: 
                arr[j], arr[j + 1] = arr[j + 1], arr[j] 

def display_top_five(arr): 
    print("Top 5 Scores:", arr[-5:]) 

# Taking input from the user
scores_input = input("Enter scores separated by spaces: ")
scores = list(map(float, scores_input.split()))

print("Original Scores:", scores)

selection_sort(scores)
display_top_five(scores)

bubble_sort(scores)
display_top_five(scores)
