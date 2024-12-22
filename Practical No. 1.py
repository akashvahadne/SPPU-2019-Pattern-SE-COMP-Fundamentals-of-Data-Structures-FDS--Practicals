# Write a Python program to store marks scored in subject
# “Fundamental of DataStructure” by N students in the class. Write
# functions to compute following:
# a) The average score of class
# b) Highest score and lowest score of class
# c) Count of students who were absent for the test
#  Display mark with highest frequency

cnt=0  
total=0  
avg=0  
Marks=[]  
n=int(input("Enter number of Element:"))  
for i in range(0,n):  
    ele =int(input())  
    Marks.append(ele)  
print(Marks)  
n=len(Marks)  
print("Number of Element in list:",n)  
for num in Marks:  
    if num==-1:  
        cnt=cnt+1  
    else:  
        total=total+num  
print("Total of all:",total)  
  
# to calculate average score of the class  
avg=(total/(n-cnt))  
print("The Average Score:",avg)  
  
# to calculate the highest score  
hscore=0  
for n1 in Marks:  
    if n1 > hscore:  
        hscore=n1  
print("Highest Score is:",hscore)  
  
# to calculate the lowest score  
lscore=n1  
for n2 in Marks:  
    if n2 < lscore and n2!=-1:  
        lscore=n2  
print("Lowest score is: ",lscore)  
  
# to calculate no of absent students  
absent=0  
for n3 in Marks:  
    if n3==-1:  
        absent=absent+1  
print("Total Absent:",absent) 