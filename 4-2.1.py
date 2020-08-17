while True :
    try :
        print '\n        Calcultator'
        print 'First operand :',
        first = input() 
        print 'Second operand :',
        second = input()
        result1 = first + second
        print ('%s + %s = %0.2f'%(str(first),str(second),result1))
        result2 = first - second
        print ('%s - %s = %0.2f'%(str(first),str(second),result2))
        result3 = first * second
        print ('%s * %s = %0.2f'%(str(first),str(second),result3))
        result4 = first / second
        print ('%s / %s = %0.2f'%(str(first),str(second),result4))
    except NameError:
        print '<ERROR> Please input numbers'
        print 'Do you want to terminater program? (y or n)',
        end = raw_input()
        if end == 'y':
            break
    except ZeroDivisionError:
        print "<ERROR> Can't divide number by zero"
        
