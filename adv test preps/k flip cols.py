import copy
def backtrack(nums, path,store):
    dt = {}
    if not nums:
        store.append(path.copy())
        return
    for i in range(len(nums)):
        if nums[i] not in dt:
            backtrack(nums[:i] + nums[i + 1:], path + [nums[i]],store)
            dt[nums[i]] = 1

def flip_count(arr,grid):
    temp_grid=copy.deepcopy(grid)
    for j in range(len(arr)):
        if(arr[j]==1):
            for i in range(len(grid)):
                temp_grid[i][j]=1-temp_grid[i][j]
    final_row_count=0
    for i in range(len(temp_grid)):
        count=0
        for j in range(len(temp_grid[0])):
            if(temp_grid[i][j]==1):
                count+=1
        if(count==len(temp_grid[0])):
            final_row_count+=1
    return final_row_count
n,m,k=list(map(int,input().split()))
grid=[]
for _ in range(n):
    temp=list(map(int,input().split()))
    grid.append(temp)
max_val=0
while(k>0):
    nums=[0 for i in range(len(grid[0]))]
    for j in range(k):
        nums[j]=1
    store = []
    nums=sorted(nums)
    backtrack(sorted(nums), [], store)
    for perm in store:
        t=flip_count(perm,grid)
        max_val=max(max_val,t)
    k-=2
print(max_val)
