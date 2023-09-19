def solution(num):
    num = list(map(str, num.split()))
    num.sort(key=lambda x : x*2, reverse=True)

    return num

a = solution('10 68 75 7 21 12')
print(a)
