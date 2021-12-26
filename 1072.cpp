n = (int)(input())
for i in range (1,n+1):
    if i == 1:
        print(0)
    elif i == 2:
        print(6)
    elif i == 3:
        print(28)
    elif i == 4:
        print(96)
    else:
        two = 4
        three = 8
        four = (i - 4) * 4 + 4
        six = (i - 4) * 4
        eight = (i - 4) * (i - 4)
        print(( (i * i) * (i * i - 1) - (two * 2 + three * 3 + four * 4 + six * 6 + eight * 8) ) // 2)