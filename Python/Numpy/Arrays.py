
#reverse input array
import numpy

def arrays(arr):
    # complete this function
    # use numpy.array
    return numpy.array(arr,float)[::-1] #reverse array indexes

arr = input().strip().split(' ')
result = arrays(arr)
print(result)