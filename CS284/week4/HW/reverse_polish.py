# NAME: Lian Zhu

#This program should use a stack to implement a reverse polish calculator.  e.g.  5x(2+3)   ==   5 2 3 + x
# pre-requisite knowledge: how strings are represented in python, CLA, unicode/ascii, ord(), numbers start with a digit or with a '.'
# This calculator must correctly implement, '+', '-', 'x', and '/' operations (we will use little x for multiplication, NOT *).
# THIS VERSION WILL USE Command Line Arguments (CLA)
#Read the instructions tab for all assignment information


def pop(stk,sp) :
    # YOUR CODE FOR POP GOES HERE
    if [sp[0]] == -1: # Empty stack
        return
    val = stk[sp[0]]
    sp[0] = sp[0] - 1
    return val

def push(val,stk,sp) :
    sp[0] = sp[0] + 1
    if(sp[0] == len(stk)) :
        stk.append(val)
    else :
        stk[sp[0]] = val


def calculate(str) : # needs to be cleaned up to handle illegal strings
    # creating stack.  stk[] is an empty stack so the stack pointer (sp) starts as -1.  Why is sp a list of size 1?
    stk = []
    sp = [-1]
    # YOUR CODE GOES HERE
    for x in str:
        if type(x) == float:
            push(x, stk, sp)
        else: # Now check which operation
            if (x == '+'):
                    b = pop(stk, sp)
                    a = pop(stk, sp)
                    push(a + b, stk, sp)
            elif (x == 'x'):
                    b = pop(stk, sp)
                    a = pop(stk, sp)
                    push(a * b, stk, sp)
            elif (x == '-'):
                    b = pop(stk, sp)
                    a = pop(stk, sp)
                    push(a - b, stk, sp)
            elif (x == '/'):
                    b = pop(stk, sp)
                    a = pop(stk, sp)
                    push(a / b, stk, sp)
    stk.append(0)
    return stk[0]



def convert_str_types(str) :
    # This procedure must convert the apporpriate elements of list str from strings to floats.  You can use the following command to cast the string as a float iff str[k] would mathematically be a real number.
    # str[k] = float(str[k])
    # YOUR CODE GOES HERE
    k = 0
    while (k < len(str)):
                if (ord(str[k][0]) >= 48 and ord(str[k][0]) <= 57 or str[k][0] == '.'):
                            str[k] = float(str[k])
                k+=1

################# MAIN CALLING ROUTINE ################
from sys import * # for CLA

# MUST use x instead of * for multiplation as * has meaning on the command line

str = []
k = 1 #argv[0] is always the name of the file you are running
while(k < len(argv)) :
    str.append(argv[k])
    k = k + 1
print(str)

# convert the parts of the string that are numbers to floats
convert_str_types(str)

ans = calculate(str)
print(ans)


