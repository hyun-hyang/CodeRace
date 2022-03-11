n = int(input())

def hanoi(n, rod1, rod3, rod2):

    if n == 1: 
        print(rod1, rod3)
    
    else:
        hanoi(n-1, rod1, rod2, rod3)
        print(rod1, rod3)
        hanoi(n-1, rod2, rod3, rod1)
print(n**2 -1)
hanoi(n, 1, 3, 2)