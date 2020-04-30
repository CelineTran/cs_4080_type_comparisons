#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> intA(50); 
vector<int> intB(250); 
vector<int> intC(500); 

vector<double> dblA(50); 
vector<double> dblB(250); 
vector<double> dblC(500); 


vector<int> intSort(vector<int> a, vector<double> b); 
vector<double> doubleSort(vector<int> a, vector<double> b); 
void populateVectors(); 

int main(){
  int random = rand(); 

  populateVectors(); 

  vector<int> sortedIntA = intSort(intA, dblA); 
  vector<int> sortedIntB = intSort(intB, dblB);
  vector<int> sortedIntC = intSort(intC, dblC); 

  vector<double> sortedDblA = doubleSort(intA, dblA); 
  vector<double> sortedDblB = doubleSort(intB, dblB); 
  vector<double> sortedDblC = doubleSort(intC, dblC); 
  
}

void populateVectors(){
  for(int index = 0; index < 50; ++index){
    intA.at(index) = random(); 
    dblA.at(index) = ((double)random()/RAND_MAX)* 1000000; 
  
  }

  for(int index = 0; index < 250; ++index){
    intB.at(index) = random(); 
    dblB.at(index) = ((double)random()/RAND_MAX)* 1000000; 
  }

  for(int index = 0; index < 500; ++index){
    intC.at(index) = random(); 
    dblC.at(index) = ((double)random()/RAND_MAX)* 1000000; 
  }
}

vector<int> intSort(vector<int> a, vector<double> b){
  
  vector<int> sortedVect(a.size()*2); 
  vector<double> tempDblVect(b.size()); 
  int k = 0;

  for(int i = 0; i < b.size(); i++){
    int temp = (int)b.at(i); 
    tempDblVect.at(i) = temp;
  }

  for (int i = 0; i < a.size(); ++i)
    sortedVect.at(i) = a.at(i); 

  for(int i = b.size(); i < b.size()*2 -1; ++i)
    sortedVect.at(i) = tempDblVect[k++]; 

  for(int i = 0; i < sortedVect.size()-1; ++i){
    for(int j = 0; j < sortedVect.size() - i - 1; ++j){
      if(sortedVect.at(j) > sortedVect.at(j+1)){
        int temp = sortedVect.at(j); 
        sortedVect.at(j) = sortedVect.at(j+1); 
        sortedVect.at(j+1) = temp; 
      }
    }
  }

  return sortedVect; 
}

vector<double> doubleSort(vector<int> a, vector<double> b){

  vector<double> sortedVect(a.size()*2); 
  vector<int> tempIntVect(b.size()); 
  int k = 0;

  for(int i = 0; i < a.size(); ++i){
    double temp = (double)a.at(i); 
    tempIntVect.at(i) = temp; 
  }

  for (int i = 0; i < b.size(); ++i)
    sortedVect.at(i) = b.at(i); 
 

  for(int i = a.size(); i < a.size()*2 -1; ++i)
    sortedVect.at(i) = tempIntVect[k++]; 

  for(int i = 0; i < sortedVect.size()-1; ++i){
    for(int j = 0; j < sortedVect.size() - i - 1; ++j){
      if(sortedVect.at(j) > sortedVect.at(j+1)){
        double temp = sortedVect.at(j); 
        sortedVect.at(j) = sortedVect.at(j+1); 
        sortedVect.at(j+1) = temp; 
      }
    }
  }

  return sortedVect; 
}

