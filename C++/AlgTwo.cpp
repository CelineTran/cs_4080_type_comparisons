#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> intA(10); 
vector<int> intB(50); 
vector<int> intC(100); 

vector<double> dblA(10); 
vector<double> dblB(50); 
vector<double> dblC(100); 

vector<double> dblD(10); 
vector<double> dblE(50); 
vector<double> dblF(100); 

vector<int> intSum(vector<int> a, vector<double> b, vector<double> c); 
vector<double> doubleSum(vector<int> a, vector<double> b, vector<double> c); 
void populateVectors(); 

int main(){
  int random = rand(); 

  populateVectors(); 

  vector<int> sumIntA = intSum(intA, dblA, dblD); 
  vector<int> sumIntB = intSum(intB, dblB, dblE);
  vector<int> sumIntC = intSum(intC, dblC, dblF); 

  vector<double> sumDblA = doubleSum(intA, dblA, dblD); 
  vector<double> sumDblB = doubleSum(intB, dblB, dblE); 
  vector<double> sumDblC = doubleSum(intC, dblC, dblF); 

}

void populateVectors(){
  for(int i = 0; i < 10; ++i){
    intA.at(i) = random(); 
    dblA.at(i) = ((double)random()/RAND_MAX)* 1000000; 
    dblD.at(i) = ((double)random()/RAND_MAX)* 1000000; 
  }

  for(int i = 0; i < 50; ++i){
    intB.at(i) = random(); 
    dblB.at(i) = ((double)random()/RAND_MAX)* 1000000; 
    dblE.at(i) = ((double)random()/RAND_MAX)* 1000000; 
  }

  for(int i = 0; i < 100; ++i){
    intC.at(i) = random(); 
    dblC.at(i) = ((double)random()/RAND_MAX)* 1000000; 
    dblF.at(i) = ((double)random()/RAND_MAX)* 1000000; 
  }
}

vector<int> intSum(vector<int> a, vector<double> b, vector<double> c){

  vector<int> finalSum(a.size()); 
  vector<double> d(a.size()); 
  vector<double> e(a.size()); 

  for(int i = 0; i < a.size(); ++i){
    d.at(i) = (int)b.at(i); 
    e.at(i) = (int)c.at(i); 
  }

  for(int i = 0; i < a.size(); ++i){
    //-a^2 + (b^2+c^2-4ac)/(2ac + cab)
    // d = new b, e = new c
    finalSum.at(i) = -(a.at(i) * a.at(i)) + (d.at(i)*d.at(i) + e.at(i)*e.at(i) - 4 * a.at(i) * e.at(i))/(2 * a.at(i) * e.at(i) + e.at(i) * a.at(i) * d.at(i)); 
  }
    
  return finalSum; 
}

vector<double> doubleSum(vector<int> a, vector<double> b, vector<double> c){

  vector<double> finalSum(a.size()); 
  vector<int> d(a.size()); 

  for(int i = 0; i < a.size(); ++i)
    d.at(i) = (double)a.at(i); 

  for(int i = 0; i < a.size(); ++i){
    //-a^2 + (b^2+c^2-4ac)/(2ac + cab)
    //d = new a
    finalSum.at(i) = -(d.at(i) * d.at(i)) + (b.at(i)*b.at(i) + c.at(i)*c.at(i) - 4 * d.at(i) * c.at(i))/(2 * d.at(i) * c.at(i) + c.at(i) * d.at(i) * b.at(i)); 
  }
    
  return finalSum; 
}

