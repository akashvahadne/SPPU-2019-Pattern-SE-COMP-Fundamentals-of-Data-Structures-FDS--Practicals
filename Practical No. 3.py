# In second year computer engineering class, group A student’s play
# cricket, group B students play badminton and group C students play
# football.
# Write a Python program using functions to compute following: -
# a. List of students who play both cricket and badminton
# b. List of students who play either cricket or badminton but
# not both
# c. Number of students who play neither cricket nor badminton
# d. Number of students who play cricket and football but not
# badminton.

def stu_p_both(cric, badm): 
    return list(set(cric) & set(badm)) 

def stu_p_either_not_both(cric, badm): 
    return list(set(cric) ^ set(badm)) 

def stu_p_neither(cric, badm, total): 
    return total - (len(cric) + len(badm) - len(stu_p_both(cric, badm))) 

def stu_p_cric_foot_not_badm(cric, foot, badm): 
    return list(set(cric) & set(foot) - set(badm)) 

total_students = int(input("Enter total number of students: "))

cric = input("Enter students who play Cricket (comma separated): ").split(",")
badm = input("Enter students who play Badminton (comma separated): ").split(",")
foot = input("Enter students who play Football (comma separated): ").split(",")

both = stu_p_both(cric, badm) 
either_not_both = stu_p_either_not_both(cric, badm) 
neither_count = stu_p_neither(cric, badm, total_students) 
cric_foot_not_badm = stu_p_cric_foot_not_badm(cric, foot, badm) 

print("Both:", both) 
print("Either not both:", either_not_both) 
print("Neither count:", neither_count) 
print("Cricket & Football not Badminton:", cric_foot_not_badm)
