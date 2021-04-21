class Stack(): 
  
    def cleaning(x):
        x.tail = 0
         
    def empty(x):
        if x.tail == 0:
            return True
        return False
  
    def push(x, numb):
        x.data[x.tail] = numb
        x.tail += 1
  
    def pop(x):
        x.tail -= 1
        return x.data[x.tail]
  
    def __init__(x, len_):
        x.data = [0] * len_
        x.tail = 0
        x.len_ = len_                  
            
stack_ = Stack(1000001)
  
f = open("brackets.in", "r")
out = open("brackets.out", "w")
  
for string in f:
    yes_or_no = 1
    stack_.cleaning()
    
    for x in string:
    
        if x == "\n":
            continue
              
        if x == "(" or x == "[":
            stack_.push(x)
              
        elif not stack_.empty():
  
            if x == ")" and stack_.data[stack_.tail - 1] == "(":
                stack_.pop()
  
            elif x == "]" and stack_.data[stack_.tail - 1] == "[":
                stack_.pop()
  
            else:
                yes_or_no = 0
                break;
  
        else:
            yes_or_no = 0
            break;
  
    if not stack_.empty():
        yes_or_no = 0
  
    out.write("YES" + "\n" if yes_or_no else "NO" + "\n")
