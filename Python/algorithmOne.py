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

def algorithmOneIntOrig(list):
# Take in an array of double, convert to integer (widening) and use bubble sort, which is o(n^2)
    for iter_num in range(len(list)-1,0,-1):
        for idx in range(iter_num):
            temp = list[idx] 
            if list[idx]>list[idx+1]:
                temp = list[idx]
                list[idx] = list[idx+1]
                list[idx+1] = temp

def coercion1():
    global avgTime
    initTime = time.perf_counter()
    listSize = 250
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

def coercion2():
    global avgTime
    initTime = time.perf_counter()
    listSize = 500
    # change list size as necessary
    list = []
    for i in range(0, listSize):
        list.append(random.random()*1000)
        #print(list[i])
    algorithmOneIntOrig(list)
    #print(list)
    finTime = time.perf_counter()
    temp = finTime-initTime
    avgTime += temp

def coercion3():
    global avgTime
    initTime = time.perf_counter()
    listSize = 750
    # change list size as necessary
    list = []
    for i in range(0, listSize):
        list.append(random.random()*1000)
        #print(list[i])
    algorithmOneIntOrig(list)
    #print(list)
    finTime = time.perf_counter()
    temp = finTime-initTime
    avgTime += temp

def coercion4():
    global avgTime
    initTime = time.perf_counter()
    listSize = 1000
    # change list size as necessary
    list = []
    for i in range(0, listSize):
        list.append(random.random()*1000)
        #print(list[i])
    algorithmOneIntOrig(list)
    #print(list)
    finTime = time.perf_counter()
    temp = finTime-initTime
    avgTime += temp

def orig1():
    global avgTime
    initTime = time.perf_counter()
    listSize = 250
    # change list size as necessary
    list = []
    for i in range(0, listSize):
        list.append(random.random()*1000)
        #print(list[i])
    algorithmOneIntOrig(list)
    #print(list)
    finTime = time.perf_counter()
    temp = finTime-initTime
    avgTime += temp
    #print(f"Completed in {temp:0.5f} seconds")

def orig2():
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

def orig3():
    global avgTime
    initTime = time.perf_counter()
    listSize = 750
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

def orig4():
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

avgTime = 0.0
print("With Type Coercion -- ")
for i in range(0,10): # Run trial 100 times
    coercion1()
avgTime = avgTime/10.0
print(f"Average time of 10 trials of size 250 is {avgTime:0.5f} seconds")
avgTime = 0.0
for i in range(0,10): # Run trial 100 times
    coercion2()
avgTime = avgTime/10.0
print(f"Average time of 10 trials of size 500 is {avgTime:0.5f} seconds")
avgTime = 0.0
for i in range(0,10): # Run trial 100 times
    coercion3()
avgTime = avgTime/10.0
print(f"Average time of 10 trials of size 750 is {avgTime:0.5f} seconds")
avgTime = 0.0
for i in range(0,10): # Run trial 100 times
    coercion4()
avgTime = avgTime/10.0
print(f"Average time of 10 trials of size 1000 is {avgTime:0.5f} seconds")

print("Without Type Coercion (Original List) -- ")
avgTime = 0.0
for i in range(0,10): # Run trial 100 times
    orig1()
avgTime = avgTime/10.0
print(f"Average time of 10 trials of size 250 is {avgTime:0.5f} seconds")
avgTime = 0.0
for i in range(0,10): # Run trial 100 times
    orig2()
avgTime = avgTime/10.0
print(f"Average time of 10 trials of size 500 is {avgTime:0.5f} seconds")
avgTime = 0.0
for i in range(0,10): # Run trial 100 times
    orig3()
avgTime = avgTime/10.0
print(f"Average time of 10 trials of size 750 is {avgTime:0.5f} seconds")
avgTime = 0.0
for i in range(0,10): # Run trial 100 times
    orig4()
avgTime = avgTime/10.0
print(f"Average time of 10 trials of size 1000 is {avgTime:0.5f} seconds")