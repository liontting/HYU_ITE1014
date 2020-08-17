while True:
    print 'Menu'
    print '1. 99dan   2. exit'
    dan = input ()
    if dan == 1 :
        print 'input dan : ',
        num = input()
        for i in range(1, 10) :
            print num,' * ', i,' = ', num*i    
    elif dan == 2 :
        break
    
