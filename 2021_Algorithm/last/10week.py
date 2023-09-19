from math import log2


def xor_c(a):
    if a^1 == a+1:
        print('even')
    elif a^1 == a-1:
        print('odd')

def and_c(a):
    if a&1 == 1:
        print('odd')
    elif a&1 == 0:
        print('even')

def change_alpha(a):
    for i in range(len(a)):
        b = ord(a[i])^32
        print(chr(b), end='')


def right_zero(a):
    b = a+1 
    c = ~a  
    d = b&c
    d= log2(d)
    print(int(d))



