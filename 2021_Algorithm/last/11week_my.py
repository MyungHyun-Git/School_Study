arr = list(map(int, input('숫자를 입력하시오: ').split()))
idx = 0

for i in range(len(arr)):
    count1 = 0
    count2 = 0
    for j in range(i):
        if arr[i] > arr[j]:
            count1 = 1
        elif arr[i] < arr[j]:
            count1 = 0
            break

    for k in range(i, len(arr)):
        if arr[i] > arr[k]:
            count2 = 0
            break
        elif arr[i] < arr[k]:
            count2 = 1


    if count1==1 and count2==1:
        idx = i
        print(arr[idx])

if idx == 0:
    print('-1')
