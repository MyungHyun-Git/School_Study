# 5. 연결하여 만들 수 있는 가장 큰 수 찾기

def solution(s):
    s.sort(key=lambda x: x*3, reverse=True)
    for i in range(len(s)):
        print(s[i], end='')

arr = list(map(str, input('숫자 입력 : ').split()))
solution(arr)
