def Radix_Sort(a):
 
    A = a.copy()                          # копия входных данных
    _a = ['' for i in range(len(A))]       # будущий готовый упорядоченный набор
 
    for j in range(k):
        b = m - j - 1
        abc = [0 for i in range(26)]     # алфавит
        letter = 0                            # буква
        count = 0
 
        for i in range(len(A)):
            letter = ord(A[i][b]) - ord('a')
            abc[letter] += 1       
 
        for i in range(26):
            p = abc[i]
            abc[i] = count
            count += p
 
        for i in range(len(A)):
            letter = ord(A[i][b]) - ord('a')
            _a[abc[letter]] = A[i]
            abc[letter] += 1
 
        A = _a.copy()             # упорядочили
 
    return A
  
 
with open('radixsort.in', 'r') as f:              # открываем файл на чтение
    n, m, k = [int(i) for i in f.readline().split()]
    A = []
    for i in range(n):
        A.append(f.readline().replace('\n',''))
 
A = Radix_Sort(A)
 
with open('radixsort.out', 'w') as out:     # открываем файл на запись
    for i in A:
        out.write(i + '\n')
