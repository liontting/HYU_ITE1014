# -*- coding: cp949 -*-
print 'what to do?',
sign = raw_input() # 어떤 계산할건지 부호 받는 것
print 'first operand',
first = input() # 계산할 첫번째 숫자
print 'second operand',
second = input() # 계산할 두번째 숫자
if sign == '+' or sign == 'add' : # 만약에 덧셈이면
    print 'result is',
    result = first + second # 더하고
    print '%0.2f'%result # 결과 출력
elif sign == '-' or sign == 'sub' : # 만약에 뺄셈이면
    print 'first - second or second - first? (f-s or s-f)',
    order = raw_input() # 첫 번째 숫자를 뺄지 두 번째 숫자를 뺄지 입력 받고
    if order == 'f-s' : # 두 번째 숫자를 뺀다면
        print 'result is',
        result = first - second # 빼고
        print '%0.2f'%result # 결과 출력
    elif order == 's-f' : # 첫 번째 숫자를 뺀다면
        print 'result is',
        result = second - first # 빼고
        print '%0.2f'%result # 결과 출력
    else : # 다른거 입력한다면
        print '잘못 입력하셨네요ㅠㅠ'
elif sign == '*' or sign == 'mul' : # 만약에 곱셈이면
    print 'result is',
    result = first * second # 곱하고
    print '%0.2f'%result # 결과 출력
elif sign == '/' or sign == 'div' : # 만약에 나눗셈이면
    print 'first / second or second / first? (f/s or s/f)',
    order = raw_input() # 첫 번째 숫자를 나눌지 두 번째 숫자를 나눌지 입력 받고
    if order == 'f/s': # 두 번째 숫자로 나눈다면
        if second != 0 : # 두 번째 숫자가 0이 아닌지 확인하고
            print 'result is',
            result = float(first) / float(second) # 나누고
            print '%0.2f'%result # 결과 출력
        else : # 두 번째 숫자가 0이면
            print '0으로는 나눌 수 없어!!'
    elif order == 's/f': # 첫 번째 숫자로 나눈다면
        if first != 0 : # 첫 번째 숫자가 0이 아닌지 확인하고
            print 'result is',
            result = float(second) / float(first) # 나누고
            print '%0.2f'%result # 결과 출력
        else : # 첫 번째 숫자가 0이면
            print '0으로는 나눌 수 없어!!'
    else : # 다른거 입력한다면
        print '잘못 입력하셨네요ㅠㅠ'
else : # 부호 말고 다른거 입력했을 때
    print '잘못 입력하셨네요ㅠㅠ'
