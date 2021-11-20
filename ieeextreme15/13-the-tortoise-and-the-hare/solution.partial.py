from collections import defaultdict

def dijsktra(graph, initial, end,skip=None):

    short_pth = {initial: (None, 0)}
    cur_node = initial
    visited = set()

    while cur_node != end:
        visited.add(cur_node)
        dests = graph.edges[cur_node]
        if(cur_node==skip):
            dests=[]
        wgt_to_cur_node = short_pth[cur_node][1]

        for next_node in dests:
            wgt = graph.wgts[(cur_node, next_node)] + wgt_to_cur_node
            if(next_node)==skip:
                wgt=float('inf')
            if next_node not in short_pth:
                short_pth[next_node] = (cur_node, wgt)
            else:
                cur_short_wgt = short_pth[next_node][1]
                if cur_short_wgt > wgt:
                    short_pth[next_node] = (cur_node, wgt)
        
        nxt_des = {node: short_pth[node] for node in short_pth if node not in visited}
        if not nxt_des:
            return -1,-1

        cur_node = min(nxt_des, key=lambda k: nxt_des[k][1])    

    path = []
    cost=0
    while cur_node is not None:
        path.append(cur_node)
        next_node = short_pth[cur_node][0]
        if next_node is not None:
            cost += graph.wgts[(cur_node, next_node)]
        cur_node = next_node
    path = path[::-1]
    return cost, path

    
class Graph():
    def __init__(self):
        self.edges = defaultdict(list)
        self.wgts = {}
    
    def add_edge(self, from_node, to_node, wgt):
        self.edges[from_node].append(to_node)
        self.edges[to_node].append(from_node)
        self.wgts[(from_node, to_node)] = wgt
        self.wgts[(to_node, from_node)] = wgt

graph = Graph()

n,m,s,t = map(int,input().split())
for i in range(m):
    a,b,d= input().split()
    graph.add_edge(a,b,int(d))

cost,path=dijsktra(graph, str(s),str(t))
ans=-1
max_cost=0
skip_flag=False
if(cost>-1):
    for node in path[1:-1]:
        if skip_flag:
            skip_flag=False
            continue
        c2,p2=dijsktra(graph, str(s), str(t), node)
        if(len(graph.edges[node])==2):
            skip_flag=True
        if c2>max_cost:
            max_cost=c2
            ans=node
    print(ans)
   
else:
    print(-1)


