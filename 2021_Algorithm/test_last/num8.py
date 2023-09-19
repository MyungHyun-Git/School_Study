# 8. 소수 판별
# 소수는 1과 자신을 제외 약수가 없는것 -> 2~제곱근까지까지 나누기
import math

def solution(n):
    for i in range(2, int(math.sqrt(n)+1):
        if n%i == 0:
            return i

    return -1

num = int(input('입력 : '))
a = solution(num)

if a == -1:
    print('소수입니다.')
else:
    print('소수 아닙니다. {0} 발견 '.format(a))
