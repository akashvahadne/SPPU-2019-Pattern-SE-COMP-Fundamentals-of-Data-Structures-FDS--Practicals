# Write a Python program to compute following computation on matrix:
#  a) Addition of two matrices
#  b) Subtraction of two matrices
#  c) Multiplication of two matrices 
#  d) Transpose of a matrix

def add_matrices(a, b): 
    return [[a[i][j] + b[i][j] for j in range(len(a[0]))] for i in range(len(a))] 

def subtract_matrices(a, b): 
    return [[a[i][j] - b[i][j] for j in range(len(a[0]))] for i in range(len(a))] 

def multiply_matrices(a, b): 
    return [[sum(a[i][k] * b[k][j] for k in range(len(b))) for j in range(len(b[0]))] for i in range(len(a))] 

def transpose_matrix(a): 
    return [[a[j][i] for j in range(len(a))] for i in range(len(a[0]))] 

r, c = map(int, input("Enter rows and columns: ").split()) 
print("Enter first matrix:") 

a = [[int(input()) for _ in range(c)] for _ in range(r)] 
print("Enter second matrix:") 

b = [[int(input()) for _ in range(c)] for _ in range(r)] 

print("Addition:", add_matrices(a, b)) 
print("Subtraction:", subtract_matrices(a, b)) 
print("Multiplication:", multiply_matrices(a, b)) 
print("Transpose of first matrix:", transpose_matrix(a))
