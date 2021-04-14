
import numpy as np
from numpy.core._multiarray_umath import ndarray

a: ndarray = np.array([[7, 71],[99, 322],[80, 102],[50, 600],[300, 400],[360, 1300]])

for i in range(len(a)):
    for j in range(len(a)):
        if (a[i, 1] < a[j, 1]):
            aux1: int= a[i, 0]
            aux2: int= a[i, 1]
            a[i, 0] = a[j, 0]
            a[i, 1] = a[j, 1]
            a[j, 0] = aux1
            a[j, 1] = aux2

print('Primul spectacol incepe la ',(a[0,0]-a[0, 0] % 60)/60 , a[0, 0] % 60)
print('si se termina la ', (a[0, 1]-a[0, 1]%60)/60, a[0, 1]%60)
ultim = 0
for i in range(len(a)):
    if a[i, 0]>= a[ultim, 1]:
        print('Urmatorul spectacol incepe la ', (a[i, 0]-a[i, 0]%60)/60, a[i, 0]%60)
        print('si se termina la ', (a[i, 1]-a[i, 1]%60)/60, a[i, 1]%60)
        ultim = i
print(a)
