# -*- coding: cp949 -*-
print 'what to do?',
sign = raw_input() # � ����Ұ��� ��ȣ �޴� ��
print 'first operand',
first = input() # ����� ù��° ����
print 'second operand',
second = input() # ����� �ι�° ����
if sign == '+' or sign == 'add' : # ���࿡ �����̸�
    print 'result is',
    result = first + second # ���ϰ�
    print '%0.2f'%result # ��� ���
elif sign == '-' or sign == 'sub' : # ���࿡ �����̸�
    print 'first - second or second - first? (f-s or s-f)',
    order = raw_input() # ù ��° ���ڸ� ���� �� ��° ���ڸ� ���� �Է� �ް�
    if order == 'f-s' : # �� ��° ���ڸ� ���ٸ�
        print 'result is',
        result = first - second # ����
        print '%0.2f'%result # ��� ���
    elif order == 's-f' : # ù ��° ���ڸ� ���ٸ�
        print 'result is',
        result = second - first # ����
        print '%0.2f'%result # ��� ���
    else : # �ٸ��� �Է��Ѵٸ�
        print '�߸� �Է��ϼ̳׿�Ф�'
elif sign == '*' or sign == 'mul' : # ���࿡ �����̸�
    print 'result is',
    result = first * second # ���ϰ�
    print '%0.2f'%result # ��� ���
elif sign == '/' or sign == 'div' : # ���࿡ �������̸�
    print 'first / second or second / first? (f/s or s/f)',
    order = raw_input() # ù ��° ���ڸ� ������ �� ��° ���ڸ� ������ �Է� �ް�
    if order == 'f/s': # �� ��° ���ڷ� �����ٸ�
        if second != 0 : # �� ��° ���ڰ� 0�� �ƴ��� Ȯ���ϰ�
            print 'result is',
            result = float(first) / float(second) # ������
            print '%0.2f'%result # ��� ���
        else : # �� ��° ���ڰ� 0�̸�
            print '0���δ� ���� �� ����!!'
    elif order == 's/f': # ù ��° ���ڷ� �����ٸ�
        if first != 0 : # ù ��° ���ڰ� 0�� �ƴ��� Ȯ���ϰ�
            print 'result is',
            result = float(second) / float(first) # ������
            print '%0.2f'%result # ��� ���
        else : # ù ��° ���ڰ� 0�̸�
            print '0���δ� ���� �� ����!!'
    else : # �ٸ��� �Է��Ѵٸ�
        print '�߸� �Է��ϼ̳׿�Ф�'
else : # ��ȣ ���� �ٸ��� �Է����� ��
    print '�߸� �Է��ϼ̳׿�Ф�'
