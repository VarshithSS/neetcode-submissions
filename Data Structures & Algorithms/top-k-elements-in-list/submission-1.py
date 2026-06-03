class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        l = [0]*2001

        for i in nums:
            l[i+1000] += 1
        ls = []
        for i in range(len(l)):
            if l[i] != 0:
                ls.append([l[i], i])
        
        ls.sort(reverse = True)

        res = []

        for i in range(k):
            res.append(ls[i][1] - 1000)

        return res