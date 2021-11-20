import re

def cusEval(e):
    regexp = re.compile(r'(\+|-|\*)(\+|-|\*)+')
    if regexp.search(e):
        return "invalid"
    if e.find('(+')>=0 or e.find('(-')>=0 or e.find('-)')>=0 or e.find('+)')>=0 or e.find('()')>=0 or e.find('(*')>=0 or e.find('*)')>=0 or e[0]=='+' or e[0]=='-' or e[0]=='*':
        return "invalid"
    try:
        return eval(e)%1000000007
    except:
        return "invalid"

t = int(input())
for i in range(t):
    e = input()
    
    parts = []
    bracketStack = 0
    lastPointer = 0
    for j in range(len(e)):
        if e[j]=='(':
            bracketStack+=1
        elif e[j]==')':
            bracketStack-=1
        elif (e[j]=='+' or e[j]=='-') and bracketStack == 0:
            parts.append(e[lastPointer:j])
            parts.append(e[j])
            lastPointer = j+1
    parts.append(e[lastPointer:])
    
    rest = ''
    for j in range(len(parts)):
        if parts[j]=='':
            continue
        response = cusEval(rest+parts[j])
        if response=='invalid':
            rest = rest+parts[j]
        else:
            rest = str(response)
    
    print(cusEval(rest))