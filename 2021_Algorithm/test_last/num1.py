# 1. 비트연산 짝 홀 판별

def sol_and(n):
    if n&1 == 1:
        print('홀수입니다.')
    else:
        print('짝수입니다.')

def sol_xor(n):
    if n^1 == n+1:
        print('짝수입니다.')
    elif n^1 == n-1:
        print('홀수입니다.')


num = int(input('숫자를 입력하세요 :'))
sol_and(num)
sol_xor(num)
