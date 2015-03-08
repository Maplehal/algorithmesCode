2.2-2	选择排序
		for i=1 to n-1
			key=A[i]
			j=n-i
			while j>0
				if key >A[j]
					key = A[j]
					X = j
				j = j-1
			exch A[i] and A[j]

		第一部用n-1是因为最后一个数已经是最大的了

		选择排序最好与最坏的情况都是 O[n^2]

		