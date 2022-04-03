def dist(x1,y1,x2,y2):
    return abs(x1-x2) + abs(y1-y2)
def backtrack(source,destination,temp,visited,curr_sum,min_sum,end):
    curr_sum += dist(temp[source][0], temp[source][1], temp[destination][0], temp[destination][1])
    if(curr_sum>min_sum[0]):
        return
    if(destination==end):
        if(sum(visited)==len(visited)):
            if(curr_sum<min_sum[0]):
                min_sum[0]=curr_sum
        return

    for k in range(1,len(temp)):
        if(visited[k]==0):
            visited[k]=1
            backtrack(destination,k,temp, visited, curr_sum, min_sum,end)
            visited[k]=0
    return
n=int(input())
nums=list(map(int,input().split()))
start=(nums[0],nums[1])
end=(nums[2],nums[3])
i=4
temp=[]
temp.append(start)
while(i<len(nums)-1):
    temp.append((nums[i],nums[i+1]))
    i+=2
temp.append(end)

n=len(temp)
min_sum=[float('inf')]
visited=[0 for i in range(n)]
visited[0]=1
backtrack(0,0,temp,visited,0,min_sum,len(temp)-1)
print(min_sum[0])

