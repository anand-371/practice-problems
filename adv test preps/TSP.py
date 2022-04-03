def total_cost(self, cost):
        nums=[i for i in range(1,len(cost))]
        ans=[]
    #    print(nums)
        recur(nums,[],ans)
    #    print("ans",ans)
        mini_val=float('inf')
        for i in ans:
            final=[0]+i+[0]
            #print(final)
            j=0
            temp=0
            while(j<len(final)-1):
                start=final[j]
                end=final[j+1]
                #print(start,end)
                temp+=cost[start][end]
                j+=1
            mini_val=min(mini_val,temp)
        return mini_val
        
def recur(nums,path,ans):
    
    if len(nums) == len(path):
        ans.append(path[:])
        
        return
    
    for i in nums:
        if i in path:
            continue
        path.append(i)
        recur(nums,path,ans)
        path.pop()
