from queue import Queue #importando fila

n = int(input()) 
caminho = input().split() #entrada

adj = [[]]*n #lista de adj 
vis = [0]*n #visitados
for i in range(n):
	curr = [] #visinhos diretos da posicao i 
	if caminho[i] == '0': #se for obstaculo eu ignoro e vou pra proxima iteração do for
		continue
	if i+1 < n and caminho[i+1] == '1': #se i+1 é válido eu adiciono nos meus visinhos
		curr.append(i+1)
	if i+2 < n and caminho[i+2] == '1': #se i+2 ...
		curr.append(i+2)
	adj[i] = curr #adiciono visinhos diretos na minha lista de adj

achou = 0 #para saber se tem caminho
fila = Queue() 
fila.put((0, 0)) #coloco a posição inicial na fila e sua distancia
vis[0] = 1 #marco como visitado

while not fila.empty():
	u, dist = fila.get() #pego o ultimo da fila
	if u == n - 1: #achei a resposta
		achou = 1
		print(str(dist))
		break
	for v in adj[u]: #passo pelos meus visinhos diretos
		if not vis[v]: #se ainda nao visitei eles
			vis[v] = 1 #marco como visitados
			fila.put((v, dist+1)) #boto na fila

if not achou:
	print("-1")
