# -*- coding: cp949 -*-
import random # random ��⿡ �ִ� �Լ��� ����ϱ� ���� random ��� import

def Add (arg1, arg2) : # ��� �� �Լ�
    result = [[0 for i in range(len(arg1[0]))]for j in range(len(arg1))] # ��� �迭�� 0���� �ʱ�ȭ�ϸ鼭 ����
    for i in range(len(arg1)): # ��� �� ũ�⸸ŭ �ݺ�
        for j in range(len(arg1[0])): # ��� �� ũ�⸸ŭ �ݺ�
            result[i][j] = arg1[i][j] + arg2[i][j] # ��� �迭�� �� ����� ���� ����
    return result # ��� �迭 ��ȯ

def Sub (arg1, arg2) : # ��� ���� �Լ�
    result = [[0 for i in range(len(arg1[0]))]for j in range(len(arg1))] # ��� �迭�� 0���� �ʱ�ȭ�ϸ鼭 ����
    for i in range(len(arg1)): # ��� �� ũ�⸸ŭ �ݺ�
        for j in range(len(arg1[0])): # ��� �� ũ�⸸ŭ �ݺ�
            result[i][j] = arg1[i][j] - arg2[i][j] # ��� �迭�� �� ����� ������ ����
    return result # ��� �迭 ��ȯ

def Mul (arg1, arg2) : # ��� �� �Լ�
    result = [[0 for i in range(len(arg2[0]))]for j in range(len(arg1))] # ��� �迭�� 0���� �ʱ�ȭ�ϸ鼭 ����
    for i in range(len(arg1)): # ��� �� ũ�⸸ŭ �ݺ�
        for j in range(len(arg2[0])): # ��� �� ũ�⸸ŭ �ݺ�
            for k in range(len(arg1[0])): # ù��° ����� ���� �ι�° ����� ���� ũ�⸸ŭ �ݺ�
                result[i][j] += arg1[i][k] * arg2[k][j] # ��� ���� ����ϱ� ���� ���� ��� �˸��� ��� ��ġ�� ������
    return result # ��� �迭 ��ȯ

while True : # ���� ����
    try : # ���� ó�� ����Ǵ� �κ�
        a = input ("Input Your First Matrix's Rows Size : ") # ù ��° ����� �� ũ�� �Է�
        if a<=0 : # ���� ����� �ƴ� �� ���� ó��
            raise TypeError()
        b = input ("Input Your First Matrix's Cols Size : ") # ù ��° ����� �� ũ�� �Է�
        if b<=0 : # ���� ����� �ƴ� �� ���� ó��
            raise TypeError()
        ar = [[random.randint(0,2) for i in range(b)]for j in range(a)] # ù ��° ��Ŀ� 0,1,2 �� �������� ���ڸ� ����
        for i in range(a) : # ù ��° ����� �� ũ�⸸ŭ �ݺ�
            for j in range(b) : # ù ��° ����� �� ũ�⸸ŭ �ݺ�
                print '  ',
                print ar[i][j], # ��� ���
            print ' '
            
        c = input ("Input Your Second Matrix's Rows Size : ") # �� ��° ����� �� ũ�� �Է�
        if c<=0 : # ���� ����� �ƴ� �� ���� ó��
            raise TypeError()
        d = input ("Input Your Second Matrix's Cols Size : ") # �� ��° ����� �� ũ�� �Է�
        if d<=0 : # ���� ����� �ƴ� �� ���� ó��
            raise TypeError()
        ar1 = [[random.randint(0,2) for i in range(d)]for j in range(c)] # �� ��° ��Ŀ� 0,1,2 �� �������� ���ڸ� ����
        for i in range(c) : # �� ��° ����� �� ũ�⸸ŭ �ݺ�
            for j in range(d) : # �� ��° ����� �� ũ�⸸ŭ �ݺ�
                print '  ',
                print ar1[i][j], # ��� ���
            print ' '
            
        if a==c and b==d and a==b : # ��� ��, ����, �� ��� ������ ��
            sign = raw_input("Input '+' or '-' or '*': ") # ��� ��, ����, �� �� �����ϰ� ���� �� �Է� ����
        elif a==c and b==d : # ��� ��, ���� ��� ������ ��
            sign = raw_input("Input '+' or '-': ") # ��� ��, ���� �� �����ϰ� ���� �� �Է� ����
        elif b==c : # ��� �� ��� ������ ��
            sign = raw_input("Input '*': ") # ��� �� �Է� ����
        else : # ��� ��, ����, �� �� ��� ������ ���� ���� �� 
            raise ValueError() # ����ó��

        if sign == '+': # ��� �� ��� ��
            answer = Add(ar, ar1) # answer ��Ŀ� ��� �� �Լ� �����ؼ� �� ����
            for i in range(a) : # ����� �� ũ�⸸ŭ �ݺ�
                for j in range(b) : # ����� �� ũ�⸸ŭ �ݺ�
                    print '  ',
                    print answer[i][j], # ��� ���
                print ' '
        elif sign == '-': # ��� ���� ��� ��
            answer = Sub(ar, ar1) # answer ��Ŀ� ��� ���� �Լ� �����ؼ� �� ����
            for i in range(a) : # ����� �� ũ�⸸ŭ �ݺ�
                for j in range(b) : # ����� �� ũ�⸸ŭ �ݺ�
                    print '  ',
                    print answer[i][j], # ��� ���
                print ' '
        elif sign == '*': # ��� �� ��� ��
            answer = Mul(ar, ar1) # answer ��Ŀ� ��� �� �Լ� �����ؼ� �� ����
            for i in range(a) : # ����� �� ũ�⸸ŭ �ݺ�
                for j in range(d) : # ����� �� ũ�⸸ŭ �ݺ�
                    print '  ',
                    print answer[i][j], # ��� ���
                print ' '
        else : # ��� ��, ����, ������ �ٸ� �� �Է� �޾��� ��
            raise Exception() # ����ó��

        judge = raw_input('Continue? (o or x) : ') # ���� ������ ��� ������ ������ ����
        if judge == 'x' : # �������� ���� ��
            break
        elif judge == 'o' : # ������ ��
            continue
        else : # �ٸ� �� �Է� ��
            raise Exception() # ����ó��
         
    except (NameError,TypeError,SyntaxError): # input()�� ���ڰ� �ƴ� ���� ��� ���ų�, �������ε� �Ǽ����� �Է� �޾��� �� �Ͼ�� ������ ���� ����ó��
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

    except ValueError: # �Է� ���� �� ��ķ� ��� ��, ����, ���� ������ �Ұ����� �� ����ó��
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

    except Exception: # ������ ���� �߸��� �Է°� ���� ������ ������ ���� ���� ó��
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

