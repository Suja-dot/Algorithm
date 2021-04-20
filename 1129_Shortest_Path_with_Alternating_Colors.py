class Solution:
    def shortestAlternatingPaths(self, n: int, red_edges: List[List[int]], blue_edges: List[List[int]]) -> List[int]:
        cost = [[-1]*n for _ in range(2)]
        nodeDict = {}
        cost[0][0] = 0
        cost[1][0] = 0
        #make red & blue dictionary
        for red_item in red_edges:
            if red_item[0] not in nodeDict.keys():
                nodeDict[red_item[0]] = [(red_item[1],0)]
            else:
                nodeDict[red_item[0]].append((red_item[1],0)) 
        for blue_item in blue_edges:
            if blue_item[0] not in nodeDict.keys():
                nodeDict[blue_item[0]] = [(blue_item[1],1)]
            else:
                nodeDict[blue_item[0]].append((blue_item[1],1))
        #print("Node Dict",nodeDict)
        #find search
        queue = []
        if 0 in nodeDict.keys():
            for item in nodeDict[0]:
                queue.append((item[0],item[1],1))
        #print("Queue",queue)
        while len(queue) != 0:
            curItem = queue[0]
            #print(curItem)
            queue.pop(0)
            if cost[curItem[1]][curItem[0]] != -1:
                continue
            cost[curItem[1]][curItem[0]] = curItem[2]
            if curItem[0] in nodeDict.keys():
                for node in nodeDict[curItem[0]]:
                    if node[1] != curItem[1]:
                        queue.append((node[0],node[1],curItem[2]+1))
        #print("Red Cost",cost[0])
        #print("Blue Cost",cost[1])
        ans = []
        for i in range(n):
            if cost[0][i] != -1:
                if cost[1][i] != -1:
                    ans.append(min(cost[0][i],cost[1][i]))
                else:
                    ans.append(cost[0][i])
            else:
                if cost[1][i] != -1:
                    ans.append(cost[1][i])
                else:
                    ans.append(-1)
            
        return ans
