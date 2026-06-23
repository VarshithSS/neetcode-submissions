class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        myMap = {}
        pointerL = 0

        for pointerR in range(len(nums)):
            if nums[pointerR] not in myMap:
                myMap[nums[pointerR]] = 1
            else:
                return True

            if (abs(pointerR - pointerL) >= k):
                myMap.pop(nums[pointerL])
                pointerL += 1

        return False
        