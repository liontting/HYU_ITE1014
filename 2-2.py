# -*- coding: cp949 -*-
a = input()
if type(a) is float:
    print '�װ� �Ǽ���!'
else :
    if a<0 :
        print '�װ� ������!'
    elif a==0 :
        print '�װ� 0�̾�!'
    else :
        if a%2!=0 :
            print '�װ� Ȧ����!'
        else :
            print '�װ� ¦����!'
