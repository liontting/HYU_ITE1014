def ave(arg):
    total = 0;
    num = len(arg)
    for i in arg :
        total += float(i)
    return float(total/num)

a = []
print 'input numbers (input result to stop)'
while True :
    b = raw_input ()
    if b == 'result' :
        break
    else :
        a.append(float(b))
print ('average value is %0.4f' % ave(a))
    

