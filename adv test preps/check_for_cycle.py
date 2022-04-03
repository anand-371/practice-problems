    def isCyclic(self, V, adj):
        indegree=[0 for i in range(V)]
       # print(adj)
        q=[]
        for i in range(len(adj)):
            for j in adj[i]:
                indegree[j]+=1
        for  i in range(len(indegree)):
            if(indegree[i]==0):
                q.append(i)
        result=[]
        while(q):
            temp=q.pop()
            result.append(temp)
            for j in adj[temp]:
                indegree[j]-=1
                if(indegree[j]==0):
                    q.append(j)

        if(len(result)==V):
            return False
        return True
