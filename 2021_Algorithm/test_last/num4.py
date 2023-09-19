# 4. 배열의 왼쪽은 자신보다 작고 오른쪽은 큰 수 찾기
def solution(arr):
    n = len(arr)
    leftMax = [0] * n
    rightMin = 9999
    leftMax[0] = -9999

    for i in range(1,n):
        if leftMax[i-1] < arr[i-1]:
            leftMax[i] = arr[i-1]
        else:
            leftMax[i] = leftMax[i-1]

    for i in range(n-2, -1, -1):
        if rightMin > arr[i+1]:
            rightMin = arr[i+1]

        if arr[i] > leftMax[i] and arr[i] < rightMin:
            return arr[i]

    return -1


arr = list(map(int, input('숫자들을 입력해주세요').split())) # 5 1 4 3 6 8 10 7 9
result = solution(arr)

if result == -1 :
    print('없다')
else:
    print(result)
