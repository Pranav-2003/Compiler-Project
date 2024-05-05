# Python3 implementation of QuickSort
# Function to find the partition position
def partition(array, low, high):
	pivot = array[high]
	i = low - 1
	j = low
	while(j<high):
		if array[j] <= pivot:
			i = i + 1
			temp=array[i]
			array[j]=array[i]
			array[i]=temp
		j = j + 1
	temp=array[i+1]
	array[i+1]=array[high]
	array[high]=temp
	return i + 1
# Function to perform quicksort
def quicksort(array, low, high):
	if low < high:
		pi = partition(array, low, high)
		quicksort(array, low, pi - 1)
		quicksort(array, pi + 1, high)

array=[1,2,3,4,5,6]
N = len(array)
quicksort(array, 0, N-1)
print('Sorted array:')
x=0
while x<N:
	print(array[x])
	x=x+1

