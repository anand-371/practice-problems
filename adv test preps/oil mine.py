def backtrack(i,mines,visited,minV,maxV,curr_sum,nodes,ANS,n):
    if(visited[i]==1):
        newmin=min(curr_sum,minV)
        newmax=max(curr_sum,maxV)
        if(nodes==n-1):
            ANS[0]=min(ANS[0],newmax-newmin)
        return
    visited[i]=1
    j=(i+1)%len(mines)
    backtrack(j,mines,visited,minV,maxV,curr_sum+mines[i],nodes,ANS,n)
    newmin=min(curr_sum,minV)
    newmax=max(curr_sum,maxV)
    backtrack(j,mines,visited,newmin,newmax,mines[i],nodes+1,ANS,n)
    visited[i]=0
    return

n,m=list(map(int,input().split()))
mines=list(map(int,input().split()))
visited=[0 for i in range(m+1)]
INT_MAX=float('inf')
INT_MIN=-float('inf')
ANS=[INT_MAX]
for i in range(len(mines)):
    backtrack(i,mines,visited,INT_MAX,INT_MIN,0,0,ANS,n)
print(ANS)
