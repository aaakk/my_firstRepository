while(True):
    try:
        M=input()
        M=list(M)
        n=len(M)
        i=n1
        while(i>0 or i==0):
            loc=-1
            for j in range(i+1):
                if(M[j].isupper()):
                    loc=j
            if(loc>0 or loc==0):
                for k in range(loc,i):
                    t=M[k]
                    M[k]=M[k+1]
                    M[k+1]=t
                i=i-1
            else:
                break
        print(''.join(M))
    except:
        break
