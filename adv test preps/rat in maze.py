class Solution:
    def findPath(self, m, n):
        store=[]
        start=(0,0)
        end=(n-1,n-1)
        dfs(m,n,0,0,"",store)
        return store
def isvalid(grid,n,i,j):
    if(i<0 or j<0 or i>=n or j>=n or grid[i][j]==0):
        return False
    return True
        
def dfs(grid,n,i,j,path,store):
    
    if(not isvalid(grid,n,i,j)):
        return
    if(i==n-1 and j==n-1):
        store.append(path)
        return
    grid[i][j]=0
    dfs(grid,n,i+1,j,path+'D',store)
    dfs(grid,n,i,j+1,path+'R',store)
    dfs(grid,n,i-1,j,path+'U',store)
    dfs(grid,n,i,j-1,path+'L',store)
    grid[i][j]=1
