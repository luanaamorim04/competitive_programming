n, m = [int (x) for x in input().split()]
arr = [int(x) for x in input().split()]
dici = {} #dict (tipo um array porém qualquer coisa pode ser índice)
resp = 0
psa = [0]*(n+1)
suff = [0]*(n+1)

for i in range(len(arr)): #calculo soma de prefixo e soma de sufixo 
	psa[i+1] = psa[i] + arr[i]
	suff[n-i-1] = suff[n-i] + arr[n-i-1]

#vejo quantos intervalos não ciclicos tem soma m
for val in psa:
	if val-m in dici:
		resp += dici[val-m] #achei intervalo(s) com soma m
	if val not in dici: 
		dici[val] = 0
	dici[val] += 1 #adiciono valor no dict

#intervalos ciclicos
soma_total = psa[-1] #calculo a soma do vetor todo 
dici = {} #inicializo o dict
for val in psa:
	if val not in dici:
		dici[val] = 0
	dici[val] += 1
	if m-soma_total+val in dici and val: #achei um intervalo ciclico com soma m
		resp += dici[m-soma_total+val]

# somas de prefixo e sufixo com soma m são a interseção entre os ciclicos e não ciclicos     
for x in psa: 
	if x == m:
		resp -= 1

for x in suff: 
	if x == m:
		resp -= 1

#se prefixo e sufixo sao iguais eu devolvo um
if m == soma_total: 
	resp += 1
print(resp)


