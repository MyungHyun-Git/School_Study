n, k = raw_input().split()
result=0
n=int(n)
k=int(k)

while True:
    if n%k==0:
        n = n/k
    else:
        n = n -1
    
    result = result+1
    if n<k:
        break

result = result+(n-1)
print(result)

