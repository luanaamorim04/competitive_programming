import sys
sys.setrecursionlimit(2*10**6) # como vamos percorrer uma matriz 1000x1000, precisamos de no max 10**6 operações

def flood(i, j, vis): #dfs flood fill
	if vis[i][j] == 1: #se é uma posição visitada ou inválida eu paro a recursão
		return

	vis[i][j] = 1 #marco como visitada
	#visitando os visinhos
	flood(i+1, j, vis)
	flood(i-1, j, vis)
	flood(i, j+1, vis)
	flood(i, j-1, vis)

vis = [] #visitados
n, m = input().split()
n = int(n)
m = int(m)

#inicializando a matriz de visitados e colocando as bordas como inválidas
for i in range(0, n+2):
	linha = []
	for j in range(0, m+2):
		if i == 0 or j == 0 or i == n+1 or j == m+1:
			linha.append(1)
		else:
			linha.append(0)
	vis.append(linha)

#descomente abaixo para ver como fica a matriz visitadas 
#for i in range(n+2):
#	print(vis[i])

#lendo a entrada e marcando tudo que não é mancha como posição inválida
for i in range(0, n):
	linha = input().split()
	for j in range(0, m):
		if linha[j] == '0':
			vis[i+1][j+1] = 1

#contando quantas manchas tem
resp = 0
for i in range(1, n+1):
	for j in range(1, m+1):
		if vis[i][j] == 0: #se é uma mancha
			flood(i, j, vis)
			resp += 1

print(resp)
