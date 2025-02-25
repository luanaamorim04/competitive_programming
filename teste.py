arr = 11*[16] + 12*[17] + 15*[18] + 10*[19] + 7*[20] 
arr.sort()
print(len(arr))
print(arr[len(arr)//2])
soma = 0
for x in arr:
	soma += x

soma /= len(arr) 
print(soma)

des = 0
for x in arr:
	des += (x - soma)**2

print((des/len(arr))**0.5)
