class Queue:
    def __init__(self):
        self.queue = []
    
    def push(self,item):
        self.queue.append(item)
    
    def pop(self) -> int:
        res = self.queue[0]
        del self.queue[0]
        return res

    def size(self) -> int:
        return len(self.queue)

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # 0...n-1 course
        # return order if impossible to finish all course return empty array
        ans = []
        inCount = []
        node = []
        queue = Queue()
        for i in range(numCourses):
            inCount.append(0)
            node.append([])
        
        for i in range(len(prerequisites)):
            node[prerequisites[i][1]].append(prerequisites[i][0])
            inCount[prerequisites[i][0]] += 1
        
        for i in range(len(inCount)):
            if inCount[i] == 0:
                queue.push(i)
        
        while queue.size() != 0:
            curItem = queue.pop()
            ans.append(curItem)
            for nItem in node[curItem]:
                inCount[nItem] -= 1
                if inCount[nItem] == 0:
                    queue.push(nItem)
        
        if len(ans) != numCourses:
            ans = []
        return ans
