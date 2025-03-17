#  << PEBBLE COLLECTOR SKELETON CODE>>

# In a field divided into 4 rows and 5 columns, there can be pebbles in each section (max 1 per area) or not.
# A pebble collecting robot starts at (0,0) and ends at (3,4) with the ability to move either right or down one spot at a time.
# This program finds the optimal path where the robot picks up the maximum number of pebbles.

import numpy as np

#Make a field based on user input rows and columns with 1s representing pebbles and 0s representing empty.
#There is no need to alter this functions code
def make_field(field, rows, cols):
    r = 0       
    while(r < rows):
        temp = []
        c = 0 
        while(c < cols):
            num = np.random.randint(2)
            temp.append(num)
            c += 1
        field.insert(r, temp)
        r += 1

    
#Show a list in a grid format
#There is no need to alter this functions code
def display(list, cols, name):
    r = 0
    print("\n\n", name, "\n")
    print(" ---" * cols)
    while(r < len(list)):
        c = 0
        while(c < len(list[0])):
            print("|", list[r][c], end = " ")
            c += 1
        print("|")
        print(" ---" * cols)
        r += 1

#Initialize a table with -1 for a user-given number of rows and columns
#There is no need to alter this functions code
def make_table(table, rows, cols):
    r = 0
    while(r < rows):
        temp = []
        c = 0
        while(c < cols):
            temp.append(-1)
            c += 1
        table.insert(r, temp)
        r += 1

#Recursive funstion to find maximum numbers of pebbles which can be collected in one pass using Memoization.
def max_collect_memo(field, r, c, info_table):
    if (r < 0 or c < 0):
        return 0
    
    # Base case
    if (r == 0 and c == 0):
        return field[0][0]

    if (info_table[r][c] != -1):
        return info_table[r][c]
    
    left = max_collect_memo(field, r - 1, c, info_table) 
    up = max_collect_memo(field, r, c - 1, info_table) 

    info_table[r][c] = field[r][c] + max(left, up)
    return info_table[r][c]


#Recursive funstion to find maximum numbers of pebbles which can be collected in one pass using Tabulation.
def max_collect_tab(field, rows, cols, tab_table):
    # Base case
    tab_table[0][0] = field[0][0]

    c = 1
    while (c < cols):
        tab_table[0][c] = field[0][c] + tab_table[0][c-1]
        c+=1

    r = 1
    while (r < rows):
        tab_table[r][0] = field[r][0] + tab_table[r-1][0]
        r+=1

    r = 1
    while (r < rows):
        c = 1
        while (c < cols):
            tab_table[r][c] = field[r][c] + max(tab_table[r-1][c], tab_table[r][c-1])
            c+=1
        r+=1

    return tab_table[rows-1][cols-1]


#  <<<<<<< MAIN >>>>>>>

field = []
rows = int(input("\nHow many rows?: "))
cols = int(input("How many columns? "))
if(rows < 1 or cols < 1):
    print("Invalid inputs.  Field must exist in 2D space.")
    quit()

#For using shell to display field
make_field(field, rows, cols)
display(field, cols, "FIELD")

#Make an info_table and get answer using memoization.
info_table = []
make_table(info_table, rows, cols)
ans = max_collect_memo(field, rows-1, cols-1, info_table)
print("\n\n<<<<< USING MEMOIZATION >>>>>")
display(info_table, cols, "MEMOIZATION TABLE")
print("\nThe most pebbles the robot can collect is ", ans, ".\n")


#Make a tab_table and get answer using tabulation.
tab_table = []
make_table(tab_table, rows, cols)
ans = max_collect_tab(field, rows, cols, tab_table)
print("\n\n<<<<< USING TABULATION >>>>>")
display(tab_table, cols, "TABULATION TABLE")
print("\nThe most pebbles the robot can collect is ", ans, ".\n")
