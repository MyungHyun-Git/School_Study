# 3. 가장 오른쪽 비트 0을 1로 바꾸기
import math

def solution(n):
    position = int(math.log2((n+1)&~n) + 1)
    print('가장 오른쪽 0의 자리는 {0}'.format(position))

    result = (1 << (position-1)) | n
    print('0을 1로 바꾼 결과값은 : {0}'.format(result))


num = int(input('숫자를 입력해주세요 : '))
solution(num)
