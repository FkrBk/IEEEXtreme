import numpy as np

t = int(input())
for i in range(t):
    rc = input().split()
    r1 = int(rc[0])
    c1 = int(rc[1])
    img1 = []
    for j in range(r1):
        img1.append(list(input()))
    
    rc = input().split()
    r2 = int(rc[0])
    c2 = int(rc[1])
    img2 = []
    for j in range(r2):
        img2.append(list(input()))
    
    img1 = np.array(img1)
    img2 = np.array(img2)
    if (r1*c1) < (r2*c2):
        changer = img1
        fixed = img2
        changerC = c1
        changerR = r1
        fixedC = c2
        fixedR = r2
    else:
        changer = img2
        fixed = img1
        changerC = c2
        changerR = r2
        fixedC = c1
        fixedR = r1
    
    changer2 = np.flip(changer, 0)
    changer11 = np.rot90(changer)
    changer12 = np.rot90(changer11)
    changer13 = np.rot90(changer12)
    changer21 = np.rot90(changer2)
    changer22 = np.rot90(changer21)
    changer23 = np.rot90(changer22)
    changes1 = [changer,changer12,changer2,changer22]
    changes2 = [changer11, changer13, changer21, changer23]
    
    fixed1 = fixed
    for j in range(changerR-1):
        fixed1 = np.vstack([['.']*fixedC, fixed1])
        fixed1 = np.vstack([fixed1, ['.']*fixedC])
    for j in range(changerC-1):
        fixed1 = np.insert(fixed1, 0, '.', axis=1)
        fixed1 = np.insert(fixed1, fixedC+1+j, '.', axis=1)
        
    answer = 0
    for j in range(fixedR+changerR-1):
        for k in range(fixedC+changerC-1):
            for z in changes1:
                slidedWindow = fixed1[j:j+changerR,  k:k+changerC]
                temp = np.sum((slidedWindow=='#') & (z=='#'))
                if temp>answer:
                    answer=temp
    
    fixed2 = fixed
    for j in range(changerC-1):
        fixed2 = np.vstack([['.']*fixedC, fixed2])
        fixed2 = np.vstack([fixed2, ['.']*fixedC])
    for j in range(changerR-1):
        fixed2 = np.insert(fixed2, 0, '.', axis=1)
        fixed2 = np.insert(fixed2, fixedC+1+j, '.', axis=1)
    for j in range(fixedR+changerC-1):
        for k in range(fixedC+changerR-1):
            for z in changes2:
                slidedWindow = fixed2[j:j+changerC,  k:k+changerR]
                temp = np.sum((slidedWindow=='#') & (z=='#'))
                if temp>answer:
                    answer=temp
            
    print(answer)