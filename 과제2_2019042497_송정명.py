# -*- coding: cp949 -*-
def menu() : # �޴� ��� �Լ�
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
    
def add(arg) : # ���ϱ� �Լ�
    result = 0 # ���ϱ��̱� ������ �⺻�� 0���� ����
    for i in arg : # ����Ʈ �ȿ� �ִ� �����͵��� ���ϱ� ���� for��
        result += i # ������ �� ���ϱ�
    return result # ��� �� ����

def sub(a,b) : # ���� �Լ�
    result = a-b # �� �� ����� �ֱ�
    return result # ��� �� ����

def mul(arg) : # ���ϱ� �Լ�
    result = 1 # ���ϱ��̱� ������ �⺻�� 1�� ����
    for i in arg : # ����Ʈ �ȿ� �ִ� �����͵��� ���ϱ� ���� for��
        result *= i # ������ �� ���ϱ�
    return result # ��� �� ����

def div(a,b) : # ������ �Լ�
    result = a/b # ���� �� ����� �ֱ�
    return result # ��� �� ����
        
while True : # while�� Ȱ���� ���� ����
    menu() # �޴� ��� �Լ� ���
    sign = raw_input() # raw_input()�� Ȱ���� � ������ �� �� �Է� ����
    if sign == '0' : # 0 �Է��� ��
        print 'bye!'
        break # break�� ���ѷ��� Ż��
    
    elif sign == '1' : # 1 �Է��� ��
        print 'Input ad many as you want (input result to quit)'
        a = [] # ���� ���� �޾� ���� ����Ʈ
        while True : # ���� �� �޴� while�� Ȱ���� ���� ����
            b = raw_input() # raw_input()�� Ȱ���� �� �Է� ����
            if b == 'result' : # result �Է� ��
                break # break�� ���ѷ��� Ż��
            else : 
                a.append(float(b)) # �Է� ���� ���� ����Ʈ�� float������ ����
        print ('%d numbers added. result is %0.2f' % (len(a), add(a))) # ���ϴ� ������ ������ ���� ��� �� ���
        
    elif sign == '2' : # 2 �Է��� ��
        print 'first operand:',
        first = raw_input() # raw_input()�� Ȱ���� ù ��° ���� �Է� (���߿� �Է� ���� ���� �״�� ����ϱ� ���ؼ� raw_input() Ȱ��)
        print 'second operand:',
        second = raw_input() # raw_input()�� Ȱ���� �� ��° ���� �Է� (���߿� �Է� ���� ���� �״�� ����ϱ� ���ؼ� raw_input() Ȱ��)
        print ('%s - %s = %0.2f' % (first, second, sub(float(first), float(second)))) # ù ��° ����, �� ��° ����, sub() �Լ� ����� �� ��(float�� ����ȯ �� ����) ���
        
    elif sign == '3' : # 3 �Է��� ��
        print 'Input ad many as you want (input result to quit)'
        a = [] # ���� ���� �޾� ���� ����Ʈ
        while True : # ���� �� �޴� while�� Ȱ���� ���� ����
            b = raw_input() # raw_input()�� Ȱ���� �� �Է� ����
            if b == 'result' : # result �Է� ��
                break # break�� ���ѷ��� Ż��
            else :
                a.append(float(b)) # �Է� ���� ���� ����Ʈ�� float������ ����
        print ('%d numbers multiplied. result is %0.2f' % (len(a), mul(a))) # ���ϴ� ������ ������ ���� ��� �� ���
        
    elif sign == '4' : # 4 �Է��� ��
        print 'first operand:',
        first = raw_input() # raw_input()�� Ȱ���� ù ��° ���� �Է� (���߿� �Է� ���� ���� �״�� ����ϱ� ���ؼ� raw_input() Ȱ��)
        print 'second operand:',
        second = raw_input() # raw_input()�� Ȱ���� �� ��° ���� �Է� (���߿� �Է� ���� ���� �״�� ����ϱ� ���ؼ� raw_input() Ȱ��)
        if second != '0' :
            print ('%s / %s = %0.2f' % (first, second, div(float(first), float(second)))) # ù ��° ����, �� ��° ����, div() �Լ� ����� ���� ��(float�� ����ȯ �� ����) ���
        else : # �� ��° ����(������ ����)�� 0�� ��
            print "Can't divide by zero!!!"
            
    else : # �߸� �Է��� ��
        print 'Wrong command!'
