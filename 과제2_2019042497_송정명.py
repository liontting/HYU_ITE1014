# -*- coding: cp949 -*-
def menu() : # 메뉴 출력 함수
    print '------------------------------'
    print 'Calculator'
    print '------------------------------'
    print 'What to do?'
    print '------------------------------'
    print '1. add'
    print '2. sub'
    print '3. mul'
    print '4. div'
    print '0. quit'
    print '------------------------------'
    
def add(arg) : # 더하기 함수
    result = 0 # 더하기이기 때문에 기본이 0으로 시작
    for i in arg : # 리스트 안에 있는 데이터들을 더하기 위한 for문
        result += i # 데이터 다 더하기
    return result # 결과 값 리턴

def sub(a,b) : # 빼기 함수
    result = a-b # 뺀 값 결과에 넣기
    return result # 결과 값 리턴

def mul(arg) : # 곱하기 함수
    result = 1 # 곱하기이기 때문에 기본이 1로 시작
    for i in arg : # 리스트 안에 있는 데이터들을 곱하기 위한 for문
        result *= i # 데이터 다 곱하기
    return result # 결과 값 리턴

def div(a,b) : # 나누기 함수
    result = a/b # 나눈 값 결과에 넣기
    return result # 결과 값 리턴
        
while True : # while을 활용한 무한 루프
    menu() # 메뉴 출력 함수 사용
    sign = raw_input() # raw_input()을 활용해 어떤 동작을 할 지 입력 받음
    if sign == '0' : # 0 입력할 시
        print 'bye!'
        break # break로 무한루프 탈출
    
    elif sign == '1' : # 1 입력할 시
        print 'Input ad many as you want (input result to quit)'
        a = [] # 더할 값들 받아 놓는 리스트
        while True : # 더할 값 받는 while을 활용한 무한 루프
            b = raw_input() # raw_input()을 활용해 값 입력 받음
            if b == 'result' : # result 입력 시
                break # break로 무한루프 탈출
            else : 
                a.append(float(b)) # 입력 받은 값을 리스트에 float형으로 저장
        print ('%d numbers added. result is %0.2f' % (len(a), add(a))) # 더하는 숫자의 개수와 더한 결과 값 출력
        
    elif sign == '2' : # 2 입력할 시
        print 'first operand:',
        first = raw_input() # raw_input()을 활용해 첫 번째 숫자 입력 (나중에 입력 받은 숫자 그대로 출력하기 위해서 raw_input() 활용)
        print 'second operand:',
        second = raw_input() # raw_input()을 활용해 두 번째 숫자 입력 (나중에 입력 받은 숫자 그대로 출력하기 위해서 raw_input() 활용)
        print ('%s - %s = %0.2f' % (first, second, sub(float(first), float(second)))) # 첫 번째 숫자, 두 번째 숫자, sub() 함수 사용해 뺀 값(float로 형변환 후 진행) 출력
        
    elif sign == '3' : # 3 입력할 시
        print 'Input ad many as you want (input result to quit)'
        a = [] # 곱할 값들 받아 놓는 리스트
        while True : # 곱할 값 받는 while을 활용한 무한 루프
            b = raw_input() # raw_input()을 활용해 값 입력 받음
            if b == 'result' : # result 입력 시
                break # break로 무한루프 탈출
            else :
                a.append(float(b)) # 입력 받은 값을 리스트에 float형으로 저장
        print ('%d numbers multiplied. result is %0.2f' % (len(a), mul(a))) # 곱하는 숫자의 개수와 곱한 결과 값 출력
        
    elif sign == '4' : # 4 입력할 시
        print 'first operand:',
        first = raw_input() # raw_input()을 활용해 첫 번째 숫자 입력 (나중에 입력 받은 숫자 그대로 출력하기 위해서 raw_input() 활용)
        print 'second operand:',
        second = raw_input() # raw_input()을 활용해 두 번째 숫자 입력 (나중에 입력 받은 숫자 그대로 출력하기 위해서 raw_input() 활용)
        if second != '0' :
            print ('%s / %s = %0.2f' % (first, second, div(float(first), float(second)))) # 첫 번째 숫자, 두 번째 숫자, div() 함수 사용해 나눈 값(float로 형변환 후 진행) 출력
        else : # 두 번째 숫자(나누는 숫자)가 0일 때
            print "Can't divide by zero!!!"
            
    else : # 잘못 입력할 시
        print 'Wrong command!'
