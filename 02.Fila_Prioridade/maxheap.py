#!/usr/bin/python3
#
# Max heap
#

class MaxHeap:

    def __init__(self, *args):
        self.heap = [ ' ' ]
        if len(args) > 0:
            self.heap += args[0]

    def add(self, x):
        self.heap.append(x)
        self.swim(len(self.heap)-1)

    def swim(self, k):
        while k > 1 and self.heap[k//2] < self.heap[k]:
            print("swap",self.heap[k],"and",self.heap[k//2])
            self.heap[k], self.heap[k//2] = self.heap[k//2], self.heap[k]
            k = k // 2

    def sink(self, k):
      N = len(self.heap)-1
      while 2*k <= N:
        j = 2*k
        if j < N and self.heap[j]<self.heap[j+1]:
          j += 1
        if self.heap[k] >= self.heap[j]:
          break
        print("swap",self.heap[k],"and",self.heap[j])
        self.heap[k], self.heap[j] = self.heap[j], self.heap[k]
        k = j
 
    def get(self):
        res = self.heap[1]
        print("move",self.heap[len(self.heap)-1],"to top")
        self.heap[1] = self.heap[len(self.heap)-1]
        self.heap.pop()
        self.sink(1)
        return res

    def printh(self, sp=32):
        b = 1
        elem = 1
        print(self.heap[1:])
        while True:
            print(" "*(sp//2),end="")
            for i in range(b,b+elem):
                if i == len(self.heap):
                    print()
                    return
                print(self.heap[i]," "*(sp-1),end="")
            print()
            b += elem
            elem *= 2
            sp //= 2

    def getData(self): # retorna o conteúdo do heap como uma lista - exceto a posição 0
        return self.heap[1:]

    def sort(self, data):
        # Implemente heapsort!
        pass

def main():

    myheap = MaxHeap()
    el = "A"
    print("Digite um número/string ou 'get' para retirar o maior elemento, 'quit' para sair")
    while el != "quit":
        el = input("Element: ")
        if el == "get":
            print("get: ",myheap.get())
        else:
            myheap.add(el)
        myheap.printh()
  

if __name__ == "__main__":
    main()

