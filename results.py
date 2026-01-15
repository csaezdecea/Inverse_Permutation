import numpy as np
import matplotlib.pyplot as plt

Narr = float('nan')* np.ones(4)
nN = 13
nF = 5
nRep = 4
data = np.zeros([nN,nF,nRep])
data[0][:][:] = np.array ([ [0.04,0.03,0.03,0.03], [0.02,0.02,0.02,0.02],Narr,[0.02,0.01,0.02,0.02],[1.32,1.27,1.27,1.27] ]) #N=1E16
data[1][:][:] = np.array ([ [0.06,0.06,0.06,0.06],Narr,Narr,Narr,[5.15,5.17,5.02,5.06] ]) #N=1E17
data[2][:][:] = np.array ([ [0.13,0.13,0.13,0.13],[0.08,0.08,0.08,0.09],[0.08,0.08,0.07,0.07],Narr,[21.26,20.86,20.51,20.23] ]) #N=1E18
data[3][:][:] = np.array ([ [0.28,0.28,0.29,0.28],Narr,Narr,Narr,[81.96,83.25,82.43,81.84] ]) #N=1E19
data[4][:][:] = np.array ([ [0.56,0.57,0.59,0.58],[0.34,0.37,0.33,0.36],Narr,[0.3,0.3,0.27,0.27],[329.43,325.22,323.88,324.82] ]) #N=1E20
data[5][:][:] = np.array ([ [1.18,1.1,1.16,1.18],Narr,[0.67,0.66,0.61,0.67],Narr,Narr ]) #N=1E21
data[6][:][:] = np.array ([ [2.5,2.28,2.31,2.3],[1.62,1.48,1.63,1.62],Narr,Narr,Narr ]) #N=1E22
data[7][:][:] = np.array ([ [4.88,4.8,4.93,5.2],Narr,Narr,Narr,Narr ]) #N=1E23
data[8][:][:] = np.array ([ [10.08,9.84,10.86,10.9],[6.5,6.41,6.67,6.67],[5.53,5.9,5.45,5.32],[5.61,5.6,5.09,5.65],Narr ]) #N=1E24
data[9][:][:] = np.array ([ [21.8,21.18,22.56,21.61],Narr,Narr,Narr,Narr ]) #N=1E25
data[10][:][:] = np.array ([ [43.39,43.73,43.81,45.41],[29.71,27.44,29.44,27.82],Narr,Narr,Narr ]) #N=1E26
data[11][:][:] = np.array ([ [92.81,92.16,92.74,91.18],Narr,[48.34,50.59,49.43,50.32],Narr,Narr ]) #N=1E27
data[12][:][:] = np.array ([ [187.46,187.59,188.96,184.86],[115.49,117.88,118.55,119.14],Narr,[94.76,92.93,95.3,94.72],Narr ]) #N=1E28
#print(data[0][:][:])
#print(data)
meanval= np.zeros([nN,nF])
stdval= np.zeros([nN,nF])
for i in range(nN):
    for j in range(nF):
        meanval[i][j]=np.mean(data[i,j,:])
        stdval[i][j]=np.sqrt(np.var(data[i,j,:]))
        mn=meanval[i][j]; SEM=stdval[i][j]/np.sqrt(nRep)
        if j==0: 
            if (not np.isnan(mn)):
                print('%d & %.2f$\pm$%.2f ' % (16+i,mn,SEM), end=" ")
            else: print('%d & $\cdots$ ' % 16+i, end=" ")
        elif j<nF-1: 
            if (not np.isnan(mn)):
                print('& %.2f$\pm$%.2f ' %(mn,SEM),end=" ")
            else: print('& $\cdots$ ',end=" ")
        else: 
            if (not np.isnan(mn)):
                print('& %.2f$\pm$%.2f \\\\' %(mn,SEM))
            else: print('& $\cdots$ \\\\')
#print(meanval)
#print(stdval)
pow2arr = np.linspace(16,28,nN)
#print(pow2arr)
#fig, ax = plt.subplots(figsize=(16, 12))]]
labels = ['k = 2', 'k = 4', 'k = 8', 'k = 16', 'O(N2)']
for j in range(nF):
    sel= np.where(np.logical_not(np.isnan(meanval[:,j])))
    plt.plot(pow2arr[sel[0]],np.log10(meanval[sel[0],j]),label=labels[j], marker = 'o')
    #print(meanval[:,j])
plt.legend()
funarr = np.log10(np.power(2,pow2arr)*pow2arr)
pow2arrCut = np.linspace(16,20,5)
ON2arr = np.log10(np.power(2,pow2arrCut)**2)
#print(funarr)
plt.plot(pow2arr,funarr-7.68,linestyle='dashed',color='b')
plt.plot(pow2arrCut,ON2arr-9.7,linestyle='dashed',color='black')
plt.xlabel("log2 N")
plt.ylabel("log10 (tiempo/segundo)")
plt.savefig('tiempos.png',bbox_inches='tight')
#N= pow(2.,24)
#foo = lambda N,k : N*np.log(k)*np.log(N)/np.log(k)
#perc = (foo(N,2)-foo(N,4))/foo(N,2)
#print(foo(N,2),foo(N,4))