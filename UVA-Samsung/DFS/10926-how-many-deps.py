

def DFS(adj, vis, s, deps):
    #  import pdb;pdb.set_trace()
    vis[s]=True
    if s not in deps:
        deps[s] = 0
    if not adj[s]:
        return deps[s]
    for x in adj[s]:
        if x not in vis:
            deps[x] = DFS(adj, vis, x, deps)
        deps[s] += deps[x]+1
    return deps[s]


if __name__ == '__main__':
    while True:
        try:
            n = int(input().strip())
        except Exception:
            n = 0
        if n==0:
            break
        adj = dict()
        for curr in range(1, 1+n):
            if curr not in adj:
                adj[curr] = set()
            arr = list(map(int, input().strip().split()))
            for dep in arr[1:]:
                adj[curr].add(dep)
        deps = dict()
        vis = [False]*(n+1)
        for i in range(1, 1+n):
            if not vis[i]:
                deps[i] = 0
                deps[i] = DFS(adj, vis, i, deps)
        deps = sorted(deps.items(), key=lambda x: (x[1], -1 * x[0]), reverse=True)
        print(deps, deps[0][0])
        #  maxv=deps[0][1]
        #  maxi=deps[0][0]
        #  for i in range(1,n):
        #      if deps[i][1] != maxv:
        #          break
        #      maxi = deps[i][0]
        #  print(maxi)
