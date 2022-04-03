def isop(check):
    if(check=='+' or check=='-' or check=='*' or check=='/'):
        return True
    return False

def evaluate(str):
    try:
        return eval(str)
    except:
        return -1
def calculate(digits,operations,max_moves):
    q=[]
    for i in range(len(digits)):
        if(digits[i]==1):
            found[i]=1
            q.append(str(i))
    while(q):
        temp=q.pop(0)
        if(len(temp)==1 and temp=='0'):
            continue
        if(not isop(temp[-1])):
            for i in range(4):
                if(operations[i]==1):
                    if(i==0):
                        q.append(temp+'+')
                    if(i==1):
                        q.append(temp+'-')
                    if(i==2):
                        q.append(temp+'*')
                    if(i==3):
                        q.append(temp+'/')
        for i in range(len(digits)):
            if(digits[i]==1):
                new_temp=temp+str(i)
                if(len(new_temp)>=max_moves):
                    continue
                value=evaluate(new_temp)
                if(value<0):
                    continue
                if(value>1000000):
                    continue
                if(value==desired):
                    print(len(new_temp)+1)
                    return
                q.append(new_temp)



def ispossible(dig,desired):
    for i in str(desired):
        if(int(i) not in dig):
            return False
    return True

n,m,o=list(map(int,input().split()))
dig=list(map(int,input().split()))
ops=list(map(int,input().split()))
desired=int(input())

digits=[0 for i in range(10)]
operations=[0,0,0,0]
found=[0 for i in range(1000000)]
for i in dig:
    digits[i]=1
for i in ops:
    operations[i-1]=1

if(ispossible(dig,desired)):
    print(len(str(desired)))
else:
    calculate(digits,operations,o)
