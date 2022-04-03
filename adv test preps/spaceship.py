def backtrack(grid,i,j,bomb_used,curr_coins,max_coins):
    if(i<0 or i >len(grid) or j<0 or j>=len(grid[0])):
        return
    if(i==len(grid)):
        if (curr_coins > max_coins[0]):
            max_coins[0] = curr_coins
        return
    store_enemy=[]
    flag=0
    if(grid[i][j]==2):
        if(bomb_used==True):
            if(curr_coins>max_coins[0]):
                max_coins[0]=curr_coins
        else:
            bomb_used=True
            flag=1
            for k in range(min((i+5,len(grid)))):
                for j in range(len(grid[0])):
                    if(grid[i][j]==2):
                        store_enemy.append((i,j))
                        grid[i][j]=0
    elif(grid[i][j]==1):
        curr_coins+=1
    backtrack(grid,i+1,j+1,bomb_used,curr_coins,max_coins)
    backtrack(grid, i + 1, j, bomb_used, curr_coins, max_coins)
    backtrack(grid, i + 1, j - 1, bomb_used, curr_coins, max_coins)

    if(flag==1):
        for x,y in store_enemy:
            grid[x][y]=2
    return

num_input=int(input())
grid=[]
for i in range(num_input):
    temp=list(map(int,input().split()))
    grid.append(temp)
grid=grid[::-1]
max_coins=[0]
backtrack(grid,0,2,False,0,max_coins)
backtrack(grid,0,1,False,0,max_coins)
backtrack(grid,0,3,False,0,max_coins)
print(max_coins[0])
