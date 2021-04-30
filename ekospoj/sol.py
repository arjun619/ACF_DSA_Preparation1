def getmax(arr,low,maxs):
    if low==maxs:
        return arr[low]
    elif low==maxs-1:
        if arr[low]>arr[maxs]:
            return arr[low]
        else:
            return arr[maxs]
    else:
        mid=low + (maxs-low)//2
        return max(getmax(arr,low,mid),getmax(arr,mid+1,maxs))

def getmin(arr,low,maxs):
    if low==maxs:
        return arr[low]
    elif low==maxs-1:
        if arr[low]<arr[maxs]:
            return arr[low]
        else:
            return arr[maxs]
    else:
        mid=low + (maxs-low)//2
        return min(getmin(arr,low,mid),getmin(arr,mid+1,maxs))
def getheight(arr,length):
    counts=0
    #print(counts)
    for i in arr:
        if i-length>0:
            counts+=i-length
    #print(counts)
    return counts
#print(getmax([100,4,5,3,1],0,4))
#print(getmin([100,4,5,3,1],0,4))
def treecutting(arr,height):
    high=getmax(arr,0,len(arr)-1)
    low=getmin(arr,0,len(arr)-1)
    #print(high,low)
    ans=-1
    while high>low:
        mid= low + (high-low)//2
        if getheight(arr,mid)>=height:
            ans=mid
            low=mid+1
            print(ans,getheight(arr,mid))
        elif getheight(arr, mid)<height:
            high=mid
            
    return ans

print(treecutting([4,42,40,26,46],20))
        
        
        
    
    
