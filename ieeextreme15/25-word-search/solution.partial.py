directions = [[-1, 0], [1, 0], [1, 1], [1, -1], [-1, -1], [-1, 1], [0, 1], [0, -1]]

def search2D(grid, row, col, word, R, C):
    if grid[row][col] != word[0]:
        return(False, 0, 0)

    for x, y in directions:
        rd, cd = row + x, col + y
        flag = True

        for k in range(1, len(word)):
            if (0 <= rd < R and 0 <= cd < C and word[k] == grid[rd][cd]):
                rd += x
                cd += y
            else:
                flag = False
                break
        if flag:
            return(True, x, y)
    return(False, 0, 0)


def patternSearch(grid, word, R, C):
    found = False
    for row in range(R):
        if found==True:
            break
        for col in range(C):
            found, dirx, diry = search2D(grid, row, col, word, R, C)
            if found==True:
                print(str(row)+' '+str(col)+' '+str(row+(len(word)-1)*dirx)+' '+str(col+(len(word)-1)*diry))
                break
    if found==False:
        print(-1)


r, c, q = [int(x) for x in input().split()]
grid = []
for i in range(r):
    temp = input().strip().lower()
    grid.append(temp)
    
for i in range(q):
    word = input().strip().lower()
    patternSearch(grid, word, r, c)