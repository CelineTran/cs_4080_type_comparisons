#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<double> dblA(100); 
vector<double> dblB(100); 
vector<double> dblC(100); 

void sum(vector<double> a, vector<double> b, vector<double> c); 
void populateVectors(); 

int main(){
  int random = rand(); 

  populateVectors(); 

  sum(dblA, dblB, dblC); 
}

void populateVectors(){
  for(int i = 0; i < 100; ++i){
    dblA.at(i) = 1001 * ((double)random()/(double)RAND_MAX);  
    dblB.at(i) = 1001 * ((double)random()/(double)RAND_MAX); 
    dblC.at(i) = 1001 * ((double)random()/(double)RAND_MAX); 
  }
}

void sum(vector<double> vectA, vector<double> vectB, vector<double> vectC){

  vector<int> intSum(vectA.size()); 
  vector<double> dblSum(vectA.size()); 

  for(int i = 0; i < vectA.size(); ++i){
    //-a^2 + (b^2+c^2-4ac)/(2ac + cab)
    // d = new a, e = new b, f = new c
    double a = vectA.at(i); 
    double b = vectB.at(i); 
    double c = vectC.at(i); 
    int d = (int)vectA.at(i); 
    int e = (int)vectB.at(i); 
    int f = (int)vectC.at(i);
 
    dblSum.at(i) = (-1 * (a * a) + ((b * b) + (c * c) - 4 * a * c)/(2 * a * c + c * a * b));
    intSum.at(i) = int((-1 *(d * d)) + (e * e + f * f - 4 * d * f)/(2 * d * f + f * d * e)); 
    
    cout << "Original Value: " << dblSum.at(i) << endl; 
    cout << "Pre-Typecasted Value: " << intSum.at(i) << endl;
    cout << "Difference: " << abs(dblSum.at(i) - intSum.at(i)) << endl << endl; 
  }
}

