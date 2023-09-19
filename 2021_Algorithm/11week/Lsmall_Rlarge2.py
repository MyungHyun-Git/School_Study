def findElement(arr, n):
    leftMax = [0] * n
    leftMax[0] = -9999
    rightMin = 9999

    for i in range(1, n):
        if (leftMax[i - 1] > arr[i - 1]):
            leftMax[i] = leftMax[i - 1]  # leftmax 이전게 arr에 있던것보다 크면 이전과 똑같은 수로 채움
        else:
            leftMax[i] = arr[i - 1]  # leftmax가 더 작으면 arr에서 가져와서 채움

    # 왼쪽은 왼쪽의 값중 제일 큰 값을 넣고
    # 오른쪽은 오른쪽의 값중 제일 작은것을 넣는다.

    for i in range(n - 2, -1, -1):
        if rightMin > arr[i + 1]:
            rightMin = arr[i + 1]
        if leftMax[i] < arr[i] and rightMin > arr[i]:
            print(arr[i])


arr = list(map(int, input('숫자를 입력하세요').split()))
n = len(arr)
findElement(arr, n)
