import time
import random

def algorithmTwoInt(list1, list2, list3, listFin):
# Take in 4 arrays of same length and apply formula after 
# converting to int at each index. Then fill listFin
    for idx in range(len(list1)):
        a = int(list1[idx])
        b = int(list2[idx])
        c = int(list3[idx])
        listFin[idx] = -1*(a**2)+(b**2+c**2-4*a*c)/(2*a*c+c*a*b)


def main():
    initTime = time.perf_counter()
    listSize = 1000
    # change list size as necessary
    list1 = []
    for i in range(0, listSize):
        list1.append(random.random()*1000+1)
    list2 = []
    for i in range(0, listSize):
        list2.append(random.random()*1000+1)
    list3 = []
    for i in range(0, listSize):
        list3.append(random.random()*1000+1)
    listFin = []
    for i in range(0, listSize):
        listFin.append(1)
    algorithmTwoInt(list1, list2, list3, listFin)
    #print(list)
    finTime = time.perf_counter()
    print(f"Completed in {finTime - initTime:0.5f} seconds")

main()