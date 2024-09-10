from queue import Queue
from sys import stdin, stdout
input, print = stdin.readline, stdout.write

def main():
	while True:
		o, d, k = map(int, input().split())
		if o == 0 and d == 0 and k == 0:
			break
		
		achou = 0
		proibidos = set(map(int, input().split()))
		vis = {} 
		for canal in proibidos:
			vis[canal] = 1
		
		fila = Queue()
		fila.put((o, 0))
		
		while not fila.empty():
			num, dist = fila.get()
			
			if num <= 0 or num > 10**5 or num in vis:
				continue
			
			if num == d:
				achou = 1
				print(str(dist) + '\n')
			
			vis[num] = 1
			
			if not vis[num + 1]:
				vis[num + 1] = 1
				fila.put((num + 1, dist + 1))
			if not vis[num - 1]:
				vis[num - 1] = 1
				fila.put((num - 1, dist + 1))
			if not vis[num*2]:
				vis[num*2] = 1
				fila.put((num * 2, dist + 1))
			if not vis[num*3]:
				vis[num*3] = 1
				fila.put((num * 3, dist + 1))
			if num % 2 == 0 and not vis[num//2]:
				vis[num//2] = 1
				fila.put((num // 2, dist + 1))
		

		if not achou:
			print("-1" + '\n')

if __name__ == "__main__":
    main()
