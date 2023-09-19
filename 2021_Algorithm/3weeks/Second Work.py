data = raw_input()
result = int(data[0])

for i in range(1, len(data)):
    num = int(data[i])
    if num<=1 or result<=1:
        result = result+num
    else:
        result = result*num
        
print(result)
