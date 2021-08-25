'''
	2021.08.25
	BOJ : 1068 트리 (https://www.acmicpc.net/problem/1068)
	Algorithm : 그래프 탐색
'''
class Node :
    def __init__(self, num) :
        self.num = num
        self.child = []
    def isLeaf(self, erase) :
        if not self.child : return True
        if len(self.child) == 1 and self.child[0].num == erase :
            return True
        else : return False
    def appendChild(self, node) :
        self.child.append(node)

def getLeaf(root, erase) :
    if not root or root.num == erase:
        return 0
    elif root.isLeaf(erase) :
        return 1
    else : 
        cnt = 0
        for childNode in root.child :
            cnt += getLeaf(childNode, erase)
        return cnt

N = int(input())
tree = list(map(int, input().split()))
erase = int(input())
pointer = [Node(i) for i in range(N)]
root_idx = -1
for i, n in enumerate(tree) :
    node = pointer[i]
    if n != -1 :
        parentNode = pointer[n]
        parentNode.appendChild(node)
    else : 
        root_idx = i
pointer[erase] = 0
root = pointer[root_idx]
print(getLeaf(root, erase))