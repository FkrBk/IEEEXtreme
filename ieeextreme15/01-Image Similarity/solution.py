import numpy as np
import scipy.signal as sc

def similarity_count(matrix1,matrix2):
    return np.amax(sc.convolve2d(matrix1, matrix2[::-1,::-1], mode='full', boundary='fill', fillvalue=0))

t=int(input())
for i in range (t):
    r1,c1 = map(int,input().split())
    matrix1= np.zeros(shape=(r1,c1))
    for i in range(0,r1):
        colvalues= input()
        for j in range(0,c1):
            if(colvalues[j]=='.'):
                matrix1[i][j]=0
            else:
                matrix1[i][j]=1

    r2,c2 = map(int,input().split())
    matrix2= np.zeros(shape=(r2,c2))
    for i in range(0,r2):
        colvalues= input()
        for j in range(0,c2):
            if(colvalues[j]=='.'):
                matrix2[i][j]=0
            else:
                matrix2[i][j]=1
    count=0
    # count= max(count, similarity_count(matrix1,matrix2))
    matrix1_rotation=[]
    for i in range(0,5):
        matrix1_rotation.append(np.rot90(matrix1,k=i))
    
 

    for rotation in matrix1_rotation:
        matrix1_flips=[]
        matrix1_flips.append(rotation)
        matrix1_flips.append(np.fliplr(rotation))
        matrix1_flips.append(np.flipud(rotation))
        matrix2_flips=[]
        matrix2_flips.append(matrix2)
        matrix2_flips.append(np.fliplr(matrix2))
        matrix2_flips.append(np.flipud(matrix2))

        for matrix1_flip in matrix1_flips:
            for matrix2_flip in matrix2_flips:                
                count= max(count, similarity_count(matrix1_flip,matrix2_flip))
                    

        

    print(int(count))
