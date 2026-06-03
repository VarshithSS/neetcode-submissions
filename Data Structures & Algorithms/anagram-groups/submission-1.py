class Solution:
    def help(self, st):
        l = [0]*26
        for i in st:
            l[ord(i) - 97] += 1
        return tuple(l)
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = dict()

        for i in range(len(strs)):
            l1 = self.help(strs[i])
            if l1 not in mp:
                mp[l1] = []
            mp[l1].append(strs[i])
        l = []
        for x,y in mp.items():
            l.append(list(y))
        
        return l