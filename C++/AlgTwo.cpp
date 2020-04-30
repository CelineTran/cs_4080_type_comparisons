#include <iostream>
#include <vector>
#include<cstdlib>
#include<math.h> 

using namespace std;

vector<int> one(10); 
vector<int> two(50); 
vector<int> three(100); 

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

  vector<int> sumIntOne = intSum(one, dblA, dblD); 
  vector<int> sumIntTwo = intSum(two, dblB, dblE);
  vector<int> sumInThree = intSum(three, dblC, dblF); 

  vector<double> sumDblOne = doubleSum(one, dblA, dblD); 
  vector<double> sumDblTwo = doubleSum(two, dblB, dblE); 
  vector<double> sumDblThree = doubleSum(three, dblC, dblF); 

}

void populateVectors(){
  for(int index = 0; index < 10; ++index){
    one.at(index) = random(); 
    dblA.at(index) = ((double)random()/RAND_MAX)* 1000000; 
    dblD.at(index) = ((double)random()/RAND_MAX)* 1000000; 
  }

  for(int index = 0; index < 50; ++index){
    two.at(index) = random(); 
    dblB.at(index) = ((double)random()/RAND_MAX)* 1000000; 
    dblE.at(index) = ((double)random()/RAND_MAX)* 1000000; 
  }

  for(int index = 0; index < 100; ++index){
    three.at(index) = random(); 
    dblC.at(index) = ((double)random()/RAND_MAX)* 1000000; 
    dblF.at(index) = ((double)random()/RAND_MAX)* 1000000; 
  }
}

vector<int> intSum(vector<int> a, vector<double> b, vector<double> c){

  vector<int> finalSum(a.size()); 
  vector<double> d(a.size()); 
  vector<double> e(a.size()); 

  for(int index = 0; index < a.size(); ++index){
    d.at(index) = (int)b.at(index); 
    e.at(index) = (int)c.at(index); 
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

  for(int index = 0; index < a.size(); ++index)
    d.at(index) = (double)a.at(index); 

  for(int i = 0; i < a.size(); ++i){
    //-a^2 + (b^2+c^2-4ac)/(2ac + cab)
    //d = new a
    finalSum.at(i) = -(d.at(i) * d.at(i)) + (b.at(i)*b.at(i) + c.at(i)*c.at(i) - 4 * d.at(i) * c.at(i))/(2 * d.at(i) * c.at(i) + c.at(i) * d.at(i) * b.at(i)); 
  }
    
  return finalSum; 
}

