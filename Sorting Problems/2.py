a=[2,1,3,2,1,4,5,9,6,8,7]
a.sort()
i=0
while(i<len(a)):
	l=0
	r=len(a)-1
	while(l<r):
		if(a[l]+a[r]==a[i]):
			print(a[l],a[r],a[i])
			l+=1
			r-=1
		elif(a[l]+a[r]<a[i]):
			l+=1
		else:
			r-=1