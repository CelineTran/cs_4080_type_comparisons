import time
import random

def algorithmOneInt(list):
# Take in an array of double, convert to integer (widening) and use bubble sort, which is o(n^2)
    for iter_num in range(len(list)-1,0,-1):
        for idx in range(iter_num):
            temp = list[idx] 
            list[idx] = int(temp) # Comment out for original performance
            if list[idx]>list[idx+1]:
                temp = list[idx]
                list[idx] = list[idx+1]
                list[idx+1] = temp

def main():
    global avgTime
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
    temp = finTime-initTime
    avgTime += temp
    #print(f"Completed in {temp:0.5f} seconds")

def main2():
    global avgTime
    initTime = time.perf_counter()
    listSize = 500
    # change list size as necessary
    list = []
    for i in range(0, listSize):
        list.append(random.random()*1000)
        #print(list[i])
    algorithmOneInt(list)
    #print(list)
    finTime = time.perf_counter()
    temp = finTime-initTime
    avgTime += temp

def main3():
    global avgTime
    initTime = time.perf_counter()
    listSize = 100
    # change list size as necessary
    list = []
    for i in range(0, listSize):
        list.append(random.random()*1000)
        #print(list[i])
    algorithmOneInt(list)
    #print(list)
    finTime = time.perf_counter()
    temp = finTime-initTime
    avgTime += temp

avgTime = 0.0
for i in range(0,10): # Run trial 100 times
    main()
avgTime = avgTime/10.0
print(f"Average time of 10 trials of size 1000 is {avgTime:0.5f} seconds")
avgTime = 0.0
for i in range(0,10): # Run trial 100 times
    main2()
avgTime = avgTime/10.0
print(f"Average time of 10 trials of size 500 is {avgTime:0.5f} seconds")
avgTime = 0.0
for i in range(0,10): # Run trial 100 times
    main3()
avgTime = avgTime/10.0
print(f"Average time of 10 trials of size 100 is {avgTime:0.5f} seconds")