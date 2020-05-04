import time
import random

def algorithmTwoInt(list1, list2, list3, listFinInt, listFinOrig):
# Take in 4 arrays of same length and apply formula after 
# converting to int at each index. Then fill listFin
    for idx in range(len(list1)):
        a = int(list1[idx])
        b = int(list2[idx])
        c = int(list3[idx])
        a2 = list1[idx]
        b2 = list2[idx]
        c2 = list3[idx]
        listFinOrig[idx] = -1*(a2**2)+(b2**2+c**2-4*a*c2)/(2*a2*c2+c2*a2*b2)
        listFinInt[idx] = int(-1*(a**2)+(b**2+c**2-4*a*c)/(2*a*c+c*a*b))
        diff = abs(listFinOrig[idx]-listFinInt[idx])
        print(f"Original Value: {listFinOrig[idx]}")
        print(f"Pre-Typecasted Value: {listFinInt[idx]}")
        print(f"Difference: {diff}\n")


def main():
    listSize = 100
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
    listFinInt = []
    for i in range(0, listSize):
        listFinInt.append(1)
    listFinOrig = []
    for i in range(0, listSize):
        listFinOrig.append(1)
    algorithmTwoInt(list1, list2, list3, listFinInt, listFinOrig)

main()