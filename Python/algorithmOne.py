import time
import random

def algorithmOneInt(list):
# Take in an array of half double/int, convert to integer (widening) and use bubble sort, which is o(n^2)
    for iter_num in range(len(list)-1,0,-1):
        for idx in range(iter_num):
            temp = list[idx]
            list[idx] = int(temp)
            if list[idx]>list[idx+1]:
                temp = list[idx]
                list[idx] = list[idx+1]
                list[idx+1] = temp

def main():
    initTime = time.perf_counter()
    listSize = 1000
    # change list size as necessary
    list = []
    for i in range(0, listSize):
        list.append(random.random()*1000)
        #print(list[i])
    algorithmOneInt(list)
    #print(list)
    finTime = time.perf_counter()
    print(f"Completed in {finTime - initTime:0.5f} seconds")

main()