coin_num, value = raw_input().split()
coin_num = int(coin_num)
value = int(value)

check = 0
count = 0
minus = 0
coin = []

while check<coin_num:
    coin.append(raw_input())
    check = check+1

coin = list(map(int, coin))

#동전갯수와 금액을 입력받고 list를 int형으로 변환

while True:
    for i in coin:
        if value>=i:
            minus = i
    if value==0:
        break
    count = count + 1
    value = value - minus

print count
