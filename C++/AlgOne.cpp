#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h> 

using namespace std;

vector<int> intA(125); 
vector<int> intB(250); 
vector<int> intC(375); 
vector<int> intD(500);

vector<double> dblA(125); 
vector<double> dblB(250); 
vector<double> dblC(375); 
vector<double> dblD(500); 

vector<double> dbl1(250); 
vector<double> dbl2(500); 
vector<double> dbl3(750); 
vector<double> dbl4(1000); 

void populateVectors(); 
void intSort(vector<double> a); //widening
void doubleSort(vector<double> a); 
void mixedSort(vector<int> a, vector<double> b); 
double intTimeTrial(vector<double> a);
double dblTimeTrial(vector<double> a);
double mixedTimeTrial(vector<int> a, vector <double> b);

int main(){
  int random = rand();    

  populateVectors(); 

  
  cout << "With Type Coercion -- " << endl; 
  cout << "Average time of 10 trials of size 250 is " << intTimeTrial(dbl1)/CLOCKS_PER_SEC << " seconds" << endl; 
  cout << "Average time of 10 trials of size 500 is " << intTimeTrial(dbl2)/CLOCKS_PER_SEC << " seconds" << endl; 
  cout << "Average time of 10 trials of size 750 is " << intTimeTrial(dbl3)/CLOCKS_PER_SEC << " seconds" << endl; 
  cout << "Average time of 10 trials of size 1000 is " << intTimeTrial(dbl4)/CLOCKS_PER_SEC << " seconds" << endl;
  cout << "Without Type Coercion -- " << endl; 
  cout << "Average time of 10 trials of size 250 is " << dblTimeTrial(dbl1)/CLOCKS_PER_SEC << " seconds" << endl; 
  cout << "Average time of 10 trials of size 500 is " << dblTimeTrial(dbl2)/CLOCKS_PER_SEC << " seconds" << endl; 
  cout << "Average time of 10 trials of size 750 is " << dblTimeTrial(dbl3)/CLOCKS_PER_SEC << " seconds" << endl; 
  cout << "Average time of 10 trials of size 1000 is " << dblTimeTrial(dbl4)/CLOCKS_PER_SEC << " seconds" << endl; 
  cout << "With Mixed Types -- " << endl; 
  cout << "Average time of 10 trials of size 250 is " << mixedTimeTrial(intA, dblA)/CLOCKS_PER_SEC << " seconds" << endl; 
  cout << "Average time of 10 trials of size 500 is " << mixedTimeTrial(intB, dblB)/CLOCKS_PER_SEC << " seconds" << endl; 
  cout << "Average time of 10 trials of size 750 is " << mixedTimeTrial(intC, dblC)/CLOCKS_PER_SEC << " seconds" << endl; 
  cout << "Average time of 10 trials of size 1000 is " << mixedTimeTrial(intD, dblD)/CLOCKS_PER_SEC << " seconds" << endl; 
  

  //mixedSort(intA, dblA); 
  
}

void populateVectors(){
  for(int i = 0; i < 125; ++i){
    intA.at(i) = random()%1001; 
    dblA.at(i) = 1001 * ((double)random()/(double)RAND_MAX);
  }

  for(int i = 0; i < 250; ++i){
    intB.at(i) = random()%1001; 
    dblB.at(i) = 1001 * ((double)random()/(double)RAND_MAX); 
    dbl1.at(i) = 1001 * ((double)random()/(double)RAND_MAX); 
  }

  for(int i = 0; i < 375; ++i){
    intC.at(i) = random()%1001; 
    dblC.at(i) = 1001 * ((double)random()/(double)RAND_MAX); 
  }

  for(int i = 0; i < 500; ++i){
    intD.at(i) = random()%1001; 
    dblD.at(i) = 1001 * ((double)random()/(double)RAND_MAX); 
    dbl2.at(i) = 1001 * ((double)random()/(double)RAND_MAX); 
  }

  for(int i = 0; i < 750; ++i)
    dbl3.at(i) = 1001 * ((double)random()/(double)RAND_MAX); 

  for(int i = 0; i < 1000; ++i)
    dbl4.at(i) = 1001 * ((double)random()/(double)RAND_MAX); 
}

void intSort(vector<double> a){
  
  vector<int> tempVect(a.size()); 
  
  for(int i = 0; i < a.size(); ++i)
    tempVect.at(i) = (int)a.at(i); 

  for(int i = 0; i < tempVect.size()-1; ++i){
    for(int j = 0; j < tempVect.size() - i - 1; ++j){
      if(tempVect.at(j) > tempVect.at(j+1)){
        int temp = tempVect.at(j); 
        tempVect.at(j) = tempVect.at(j+1); 
        tempVect.at(j+1) = temp; 
      }
    }
  }
}

void doubleSort(vector<double> a){ 
  for(int i = 0; i < a.size()-1; ++i){
    for(int j = 0; j < a.size() - i - 1; ++j){
      if(a.at(j) > a.at(j+1)){
        double temp = a.at(j); 
        a.at(j) = a.at(j+1); 
        a.at(j+1) = temp; 
      }
    }
  }
}

void mixedSort(vector<int> a, vector<double> b){
  vector<double> tempVect(a.size()*2); 

  for(int i = 0; i < a.size(); ++i)
    tempVect.at(i) = a.at(i); 

  int k = a.size(); 
  for(int i = 0; i < b.size(); ++i){
    tempVect.at(k) = b.at(i); 
    k++; 
  }

  for(int i = 0; i < tempVect.size()-1; ++i){
    for(int j = 0; j < tempVect.size() - i - 1; ++j){
      if(tempVect.at(j) > tempVect.at(j+1)){
        double temp = tempVect.at(j); 
        tempVect.at(j) = tempVect.at(j+1); 
        tempVect.at(j+1) = temp; 
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

double mixedTimeTrial(vector<int> a, vector <double> b){
  double avgTime = 0.0; 
  clock_t start; 
  clock_t end; 
  for(int i = 0; i < 10; ++i){
    start = clock(); 
    mixedSort(a,b); 
    end = clock(); 
    avgTime += (end-start); 
  }

  return avgTime/10.0; 
}

