l = [10, 15, 3, 7, 19, 5, 4, 8]
k = 66

def isKPossible(l, k):
	l.sort()
	print(l)
	for i in range(len(l)):
		sInd = 0
		eInd = len(l) - 1
		currNum = l[i]
		target = k - currNum
		while(sInd <= eInd):
			mid = (sInd + eInd)//2
			if (l[mid] == target):
				print("Possible. First with: {} and {}".format(currNum, target));
				return True
			elif (l[mid] > target):	#search in the left sublist
				eInd = mid - 1
			else:					#search in the right sublist
				sInd = mid + 1
	print("Condition not met, returning false")
	return False

print(isKPossible(l, k))