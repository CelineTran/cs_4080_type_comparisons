#include <iostream>
#include <vector>
#include<cstdlib>
using namespace std;

void populateArrays(vector<int> vect); 

int main(){
  int random = rand(); 
  vector<int> one(100); 
  vector<int> two(500); 
  vector<int> three(1000); 

}

void populateArrays(vector<int> vect){
  int half = vect.size()/2; 
  for(int index = 0; index < half; ++index)
    vect.at(index) = random(); 

  for(int index = half; index < vect.size(); ++index)
    vect.at(index) = (int)(((double)random()/RAND_MAX)* 1000000); 
}

