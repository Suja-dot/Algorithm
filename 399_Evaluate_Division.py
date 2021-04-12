class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        graph = {}
        ans = []
        for equation, value in zip(equations,values):
            src, dest = equation[0], equation[1]
            if src not in graph:
                graph[src] = {}
            if dest not in graph:
                graph[dest] = {}
            graph[src][dest] = value
            graph[src][src] = 1.0
            graph[dest][dest] = 1.0
            graph[dest][src] = float(1.0)/value
        
        for src in graph.keys():
            visited = {src}
            q = [src]
            while len(q) > 0:
                cur = q[0]
                q.pop(0)
                for nextNode in graph[cur].keys():
                    if nextNode not in visited:
                        visited.add(nextNode)
                        q.append(nextNode)
                        graph[src][nextNode] = graph[src][cur] * graph[cur][nextNode]
                    
        #print(graph)
        for query in queries:
            src, dest = query[0],query[1]
            if src not in graph or dest not in graph[src]:
                ans.append(-1.0)
            else:
                ans.append(graph[src][dest])
                                    
        return ans
                
        
