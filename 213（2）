# https://www.nowcoder.com/questionTerminal/af709ab9ca57430886632022e543d4c6
try:
    while(True):
        N=int(input().strip())
        if(N==''):
            break
        A=[]
        while(len(A)<N):
            AA=input().strip().split()
            AA=[int(a) for a in AA]
            A.extend(AA)
        nummax=0
        nummin=0
        A.sort()
        B=[]
        C={}
        for i in range(1,N):
            t=A[i]-A[i-1]
            B.append(t)
        B.sort()
        for a in A:
            C[a]=A.count(a)
        D=list(C.values())
        if(len(set(A))==1):
            t=N*(N-1)/2
            nummin=t
            nummax=t
        else:
            if B[0]==0:
                for d in D:
                    if d>1:
                        nummin=nummin+d*(d-1)/2
            else:
                for b in B:
                    if b==B[0]:
                        nummin=nummin+1
                    else:
                        break
            a=0
            b=0
            for t in A:
                if t==A[0]:
                    a=a+1
                if t==A[-1]:
                    b=b+1
            nummax=a*b
            print(int(nummin),' ',int(nummax))
except:
    pass
