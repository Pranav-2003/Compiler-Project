# Python3 code to linearly search x in arr[].

def search(arr, N, x):
	i=0
	while i<N:
		if (arr[i] == x):
			return i
	return -1

arr = [2, 3, 4, 10, 40]
x = 10
N = len(arr)
result = search(arr, N, x)
if result == -1:
	print("Element is not present in array")
else:
	print("Element is present at index", result)

