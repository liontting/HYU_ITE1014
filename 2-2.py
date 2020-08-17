# -*- coding: cp949 -*-
a = input()
if type(a) is float:
    print '그건 실수야!'
else :
    if a<0 :
        print '그건 음수야!'
    elif a==0 :
        print '그건 0이야!'
    else :
        if a%2!=0 :
            print '그건 홀수야!'
        else :
            print '그건 짝수야!'
