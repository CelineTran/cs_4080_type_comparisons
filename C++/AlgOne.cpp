#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h> 

using namespace std;

vector<double> dblA(250); 
vector<double> dblB(500); 
vector<double> dblC(750); 
vector<double> dblD(1000); 

void populateVectors(); 
void intSort(vector<double> a); //widening
void doubleSort(vector<double> a); 
double intTimeTrial(vector<double> a);
double dblTimeTrial(vector<double> a);

int main(){
  int random = rand();  

  populateVectors(); 

  cout << "With Type Coercion -- " << endl; 
  cout << "Average time of 10 trials of size 250 is " << intTimeTrial(dblA)/CLOCKS_PER_SEC << " seconds" << endl; 
  cout << "Average time of 10 trials of size 500 is " << intTimeTrial(dblB)/CLOCKS_PER_SEC << " seconds" << endl; 
  cout << "Average time of 10 trials of size 750 is " << intTimeTrial(dblC)/CLOCKS_PER_SEC << " seconds" << endl; 
  cout << "Average time of 10 trials of size 1000 is " << intTimeTrial(dblD)/CLOCKS_PER_SEC << " seconds" << endl;
  cout << "Without Type Coercion -- " << endl; 
  cout << "Average time of 10 trials of size 250 is " << intTimeTrial(dblA)/CLOCKS_PER_SEC << " seconds" << endl; 
  cout << "Average time of 10 trials of size 500 is " << intTimeTrial(dblB)/CLOCKS_PER_SEC << " seconds" << endl; 
  cout << "Average time of 10 trials of size 750 is " << intTimeTrial(dblC)/CLOCKS_PER_SEC << " seconds" << endl; 
  cout << "Average time of 10 trials of size 1000 is " << intTimeTrial(dblD)/CLOCKS_PER_SEC << " seconds" << endl;  
  
}

void populateVectors(){
  for(int i = 0; i < 250; ++i)
    dblA.at(i) = 1001 * ((double)random()/(double)RAND_MAX); 

  for(int i = 0; i < 500; ++i)
    dblB.at(i) = 1001 * ((double)random()/(double)RAND_MAX); 

  for(int i = 0; i < 750; ++i)
    dblC.at(i) = 1001 * ((double)random()/(double)RAND_MAX); 

  for(int i = 0; i < 1000; ++i)
    dblD.at(i) = 1001 * ((double)random()/(double)RAND_MAX); 
}

void intSort(vector<double> a){
  
  vector<int> sortedVect(a.size()); 
  vector<int> tempVect(a.size()); 
  
  for(int i = 0; i < a.size(); ++i)
    tempVect.at(i) = (int)a.at(i); 

  for(int i = 0; i < tempVect.size()-1; ++i){
    for(int j = 0; j < tempVect.size() - i - 1; ++j){
      if(tempVect.at(j) > tempVect.at(j+1)){
        int temp = tempVect.at(j); 
        sortedVect.at(j) = tempVect.at(j+1); 
        sortedVect.at(j+1) = temp; 
      }
    }
  }
}

void doubleSort(vector<double> a){ 

  vector<double> sortedVect(a.size()); 

  for(int i = 0; i < a.size()-1; ++i){
    for(int j = 0; j < a.size() - i - 1; ++j){
      if(a.at(j) > a.at(j+1)){
        double temp = a.at(j); 
        sortedVect.at(j) = a.at(j+1); 
        sortedVect.at(j+1) = temp; 
      }
    }
  }
}

double intTimeTrial(vector<double> a){
  double avgTime = 0.0; 
  clock_t start; 
  clock_t end; 
  for(int i = 0; i < 10; ++i){
    start = clock(); 
    intSort(a); 
    end = clock(); 
    avgTime += (end-start); 
  }

  return avgTime/10.0; 
}

double dblTimeTrial(vector<double> a){
  double avgTime = 0.0; 
  clock_t start; 
  clock_t end; 
  for(int i = 0; i < 10; ++i){
    start = clock(); 
    doubleSort(a); 
    end = clock(); 
    avgTime += (end-start); 
  }

  return avgTime/10.0; 
}

