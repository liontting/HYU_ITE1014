for i in range(1,10) :
    if i < 5 :
        print ' ' * (4-i),
        print '*' * (2*i-1)
    elif i == 5 :
        print '*' * (2*i-1)
    else :
        print ' ' * (i-6),
        print '*' * (19-2*i)
