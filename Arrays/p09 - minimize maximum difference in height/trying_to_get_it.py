# i don't understand this yet
def getMinDiff(arr, n, k):
    arr = sorted(arr)
    ans = arr[-1]-arr[0] # this case occurs when either we subtract k or add k to all elements of the array
    for i in range(n):
        # after sorting, arr[0] is minimum. 
        # so adding k pushes it towards maximum. 
        # We subtract k from arr[i] to get any other worse (smaller) minimum. worse means increasing the diff b/w mn and mx
        mn=min(arr[0]+k, arr[i]-k) 
        mx=max(arr[n-1]-k, arr[i]+k) # after sorting, arr[n-1] is maximum. so subtracting k pushes it towards minimum. We add k to arr[i] to get any other worse (bigger) maximum. worse means increasing the diff b/w mn and mx
        ans = min(ans, mx-mn)
    return ans
