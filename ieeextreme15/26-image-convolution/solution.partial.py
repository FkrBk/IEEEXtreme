import numpy as np
import scipy.signal as sc

def similarity_count(matrix1,matrix2):
    a=sc.convolve2d(matrix1, matrix2[::-1,::-1], mode='valid')
    target=np.count_nonzero(matrix2)    
    condition = a == target
    return np.count_nonzero(condition)
    # return dict(zip(unique, counts))[matrix2.shape[0]*matrix2.shape[1]]

t=int(input())
for i in range (t):
    r1,c1 = map(int,input().split())
    matrix1= np.zeros(shape=(r1,c1))
    for i in range(0,r1):
        colvalues= input()
        for j in range(0,c1):
            if(colvalues[j]=='.'):
                matrix1[i][j]=1
            else:
                matrix1[i][j]=-1

    r2,c2 = map(int,input().split())
    matrix2= np.zeros(shape=(r2,c2))
    for i in range(0,r2):
        colvalues= input()
        for j in range(0,c2):
            if(colvalues[j]=='.'):
                matrix2[i][j]=1
            elif(colvalues[j]=='?'):
                matrix2[i][j]=0
            else:
                matrix2[i][j]=-1
    
    count=similarity_count(matrix1,matrix2)
                    

        

    print(int(count))
