def Heap_IFY(n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2
    l_r = l
    if l < n:
        if r < n:
            if(A[r] < A[l]):
                l_r = r
        if A[i] > A[l_r]:
            largest = l_r
    if largest != i:
        change = A[i]
        A[i] = A[largest]  
        A[largest] = change
        Heap_IFY(n, largest)
 
def push(x):
    A.append(x)
    i = len(A) - 1
    parent = (i - 1) // 2
    while i > 0 and A[parent] > A[i]:
        change = A[i]
        A[i] = A[parent]  
        A[parent] = change
        i = parent
        parent = (i - 1) // 2
    Heap_IFY(len(A), 0)
 
def extract_min(a):
    if len(A) < 1:
        return '*'
    if len(A) == 1:
        return A.pop()
    x = A[0]
    A[0] = A.pop()
    Heap_IFY(len(A), 0)
    return x
 
def Decr_key(s, e):
    x = A.index(s)
    A[x] = e
    for i in range(x, -1, -1):
        Heap_IFY(len(A), i)
  
with open('priorityqueue.in', 'r') as f:
    with open('priorityqueue.out', 'w') as out:
        lines = [i.split() for i in f.readlines()]
        A = []
        for in_ in lines:
            command_ = in_[0]
            if command_[0] == 'p':
                data = int(in_[1])
                push(data)
            elif command_[0] == 'e':
                out.write(str(extract_min(A))+'\n')                
            else:
                s = int(in_[1]) - 1
                Decr_key(int(lines[s][1]), int(in_[2]))
                lines[s][1] = in_[2]
