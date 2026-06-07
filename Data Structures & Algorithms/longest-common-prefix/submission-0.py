class Solution:
    def compare(self, str1, str2):
        res = 0
        for i in range(min(len(str1), len(str2))):
            if str1[i] != str2[i]:
                return res
            res = res + 1
        return res
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort()
        res = self.compare(strs[0], strs[len(strs) - 1])
        return strs[0][:res]