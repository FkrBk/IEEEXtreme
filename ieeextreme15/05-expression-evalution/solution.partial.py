allowed = ['+','-','*','(',')','1','2','3','4','5','6','7','8','9','0']
ops = ['+','-','*']
numbers = list(map(str,list(range(10))))

def validate(exp):
    exp = exp.strip("(")
    if exp[0] in ['+','-','*',')'] or exp[-1] in ['+','-','*','(']:
        raise ValueError('invalid')

    for i in range(len(exp)-1):
        if exp[i] not in allowed:
            raise ValueError('invalid')
        if exp[i] in ops and exp[i+1] in ops:
            raise ValueError('invalid')
        elif exp[i]=="(" and exp[i+1] in ['+','-','*',')']:
            raise ValueError('invalid')
        elif exp[i+1]=="(" and exp[i] in numbers:
            raise ValueError('invalid') 
    return True


t=int(input())

for i in range (t):
    try:
        str = input()
        if validate(str):
            print(eval(str)% (10**9 + 7))
    except:
        print('invalid')
