# 2. 대-소문자 변경

def solution(s):
    n = len(s)
    for i in range(n):
        print(chr(ord(str[i])^32), end='')

str = input('문자열을 입력해주세요')
solution(str)
