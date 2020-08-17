# -*- coding: cp949 -*-
import random # random 모듈에 있는 함수를 사용하기 위해 random 모듈 import

def Add (arg1, arg2) : # 행렬 합 함수
    result = [[0 for i in range(len(arg1[0]))]for j in range(len(arg1))] # 결과 배열을 0으로 초기화하면서 만듦
    for i in range(len(arg1)): # 결과 행 크기만큼 반복
        for j in range(len(arg1[0])): # 결과 열 크기만큼 반복
            result[i][j] = arg1[i][j] + arg2[i][j] # 결과 배열에 두 행렬의 합을 대입
    return result # 결과 배열 반환

def Sub (arg1, arg2) : # 행렬 뺄셈 함수
    result = [[0 for i in range(len(arg1[0]))]for j in range(len(arg1))] # 결과 배열을 0으로 초기화하면서 만듦
    for i in range(len(arg1)): # 결과 행 크기만큼 반복
        for j in range(len(arg1[0])): # 결과 열 크기만큼 반복
            result[i][j] = arg1[i][j] - arg2[i][j] # 결과 배열에 두 행렬의 뺄셈을 대입
    return result # 결과 배열 반환

def Mul (arg1, arg2) : # 행렬 곱 함수
    result = [[0 for i in range(len(arg2[0]))]for j in range(len(arg1))] # 결과 배열을 0으로 초기화하면서 만듦
    for i in range(len(arg1)): # 결과 행 크기만큼 반복
        for j in range(len(arg2[0])): # 결과 열 크기만큼 반복
            for k in range(len(arg1[0])): # 첫번째 행렬의 열과 두번째 행렬의 행의 크기만큼 반복
                result[i][j] += arg1[i][k] * arg2[k][j] # 행렬 곱을 계산하기 위해 값을 계속 알맞은 행렬 위치에 더해줌
    return result # 결과 배열 반환

while True : # 무한 루프
    try : # 예외 처리 적용되는 부분
        a = input ("Input Your First Matrix's Rows Size : ") # 첫 번째 행렬의 행 크기 입력
        if a<=0 : # 값이 양수가 아닐 때 예외 처리
            raise TypeError()
        b = input ("Input Your First Matrix's Cols Size : ") # 첫 번째 행렬의 열 크기 입력
        if b<=0 : # 값이 양수가 아닐 때 예외 처리
            raise TypeError()
        ar = [[random.randint(0,2) for i in range(b)]for j in range(a)] # 첫 번째 행렬에 0,1,2 중 랜덤으로 숫자를 넣음
        for i in range(a) : # 첫 번째 행렬의 행 크기만큼 반복
            for j in range(b) : # 첫 번째 행렬의 열 크기만큼 반복
                print '  ',
                print ar[i][j], # 행렬 출력
            print ' '
            
        c = input ("Input Your Second Matrix's Rows Size : ") # 두 번째 행렬의 행 크기 입력
        if c<=0 : # 값이 양수가 아닐 때 예외 처리
            raise TypeError()
        d = input ("Input Your Second Matrix's Cols Size : ") # 두 번째 행렬의 열 크기 입력
        if d<=0 : # 값이 양수가 아닐 때 예외 처리
            raise TypeError()
        ar1 = [[random.randint(0,2) for i in range(d)]for j in range(c)] # 두 번째 행렬에 0,1,2 중 랜덤으로 숫자를 넣음
        for i in range(c) : # 두 번째 행렬의 행 크기만큼 반복
            for j in range(d) : # 두 번째 행렬의 열 크기만큼 반복
                print '  ',
                print ar1[i][j], # 행렬 출력
            print ' '
            
        if a==c and b==d and a==b : # 행렬 합, 뺄셈, 곱 계산 가능할 때
            sign = raw_input("Input '+' or '-' or '*': ") # 행렬 합, 뺄셈, 곱 중 수행하고 싶은 것 입력 받음
        elif a==c and b==d : # 행렬 합, 뺄셈 계산 가능할 때
            sign = raw_input("Input '+' or '-': ") # 행렬 합, 뺄셈 중 수행하고 싶은 것 입력 받음
        elif b==c : # 행렬 곱 계산 가능할 때
            sign = raw_input("Input '*': ") # 행렬 곱 입력 받음
        else : # 행렬 합, 뺄셈, 곱 중 계산 가능한 것이 없을 때 
            raise ValueError() # 예외처리

        if sign == '+': # 행렬 합 계산 시
            answer = Add(ar, ar1) # answer 행렬에 행렬 합 함수 적용해서 값 넣음
            for i in range(a) : # 행렬의 행 크기만큼 반복
                for j in range(b) : # 행렬의 열 크기만큼 반복
                    print '  ',
                    print answer[i][j], # 행렬 출력
                print ' '
        elif sign == '-': # 행렬 뺄셈 계산 시
            answer = Sub(ar, ar1) # answer 행렬에 행렬 뺄셈 함수 적용해서 값 넣음
            for i in range(a) : # 행렬의 행 크기만큼 반복
                for j in range(b) : # 행렬의 열 크기만큼 반복
                    print '  ',
                    print answer[i][j], # 행렬 출력
                print ' '
        elif sign == '*': # 행렬 곱 계산 시
            answer = Mul(ar, ar1) # answer 행렬에 행렬 곱 함수 적용해서 값 넣음
            for i in range(a) : # 행렬의 행 크기만큼 반복
                for j in range(d) : # 행렬의 열 크기만큼 반복
                    print '  ',
                    print answer[i][j], # 행렬 출력
                print ' '
        else : # 행렬 합, 뺄셈, 곱말고 다른 값 입력 받았을 시
            raise Exception() # 예외처리

        judge = raw_input('Continue? (o or x) : ') # 무한 루프를 계속 진행할 것인지 질문
        if judge == 'x' : # 진행하지 않을 때
            break
        elif judge == 'o' : # 진행할 때
            continue
        else : # 다른 값 입력 시
            raise Exception() # 예외처리
         
    except (NameError,TypeError,SyntaxError): # input()에 숫자가 아닌 값이 들어 가거나, 정수형인데 실수형을 입력 받았을 시 일어나는 오류에 대한 예외처리
        print '<ERROR> Please input Natural numbers'
        print 'Do you want to terminater program? (y or n)',
        end = raw_input()
        if end == 'y':
            break
        elif end == 'n':
            continue
        else :
            print 'Wrong Input'
            break

    except ValueError: # 입력 받은 두 행렬로 행렬 합, 뺄셈, 곱의 연산이 불가능할 때 예외처리
        print '<ERROR> Please input Computable values'
        print 'Do you want to terminater program? (y or n)',
        end = raw_input()
        if end == 'y':
            break
        elif end == 'n':
            continue
        else :
            print 'Wrong Input'
            break

    except Exception: # 질문에 대한 잘못된 입력과 같은 나머지 오류에 대한 예외 처리
        print '<ERROR>'
        print 'Do you want to terminater program? (y or n)',
        end = raw_input()
        if end == 'y':
            break
        elif end == 'n':
            continue
        else :
            print 'Wrong Input'
            break

