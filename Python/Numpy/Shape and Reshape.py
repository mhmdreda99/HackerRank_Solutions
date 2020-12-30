
import numpy as np

# get input and split it 
array = np.array(list(map(int, input().split())))
print(array.reshape(3, 3))
