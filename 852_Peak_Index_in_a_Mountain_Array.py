class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        ans = 0
        l = 0
        r = len(arr)-1
        mid = math.ceil((l+r)/2)
        while True:
            if arr[mid-1] < arr[mid] < arr[mid+1]:
                l = mid+1
                mid = math.ceil((l+r)/2)
            else:
                if arr[mid-1] > arr[mid] > arr[mid+1]:
                    r = mid-1
                    mid = math.ceil((l+r)/2)
                else:
                    ans = mid
                    break
        return ans
