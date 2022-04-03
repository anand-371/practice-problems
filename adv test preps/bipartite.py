class Solution:
	def isBipartite(self, V, adj):
		colour=[-1 for i in range(V)]
		for i in range(V):
		    if(colour[i]==-1):
		        if(util(V,adj,colour,i)==False):
		            return False
		return True

def util(V,adj,colour,source):
    	q=[source]
    	colour[source]=0
		while(q):
		    temp=q.pop()
		    for j in adj[temp]:
		            if(colour[j]==-1):
                        colour[j]=1-colour[temp]
                        q.append(j)
                    elif(temp!=j and colour[j]==colour[temp]):
                        return False
                    else:
                        pass
        return True
