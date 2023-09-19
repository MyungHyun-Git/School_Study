# 6. #지도 2개 합치기

def solution(n, arr1, arr2):
    for i in range(n):
        row = arr1[i] | arr2[i]

        for j in range(n-1, -1, -1):
            if (row >> j)&1 == 1:
                print('#', end='')
            else:
                print(' ', end='')

        print('')


n = 5
arr1 = [9, 20, 28, 18, 11]
arr2 = [30, 1, 21, 17, 28]

solution(n, arr1, arr2)

