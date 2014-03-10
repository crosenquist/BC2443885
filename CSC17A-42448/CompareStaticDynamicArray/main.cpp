/* Carey, Bradd
 * 10 March 2014
 * 
 */
//Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

//Global constants

//Function Prototypes
void fillStat(int[],int);
void prntStat(int[],int,int);
int* fillDyna(int);
void prntDyna(int*,int,int);
void fillVect(vector<int>&,int);
void prntVect(vector<int>,int);

int main(int argc, char** argv) {
    srand(time(0));
    
    const int SIZE = 100;
    int arr[SIZE];
    float begin;
    
    
    cout<<"Random Static Array:  ";
    fillStat(arr,SIZE);
    prntStat(arr,SIZE,10);
    
    cout<<endl<<"Random Dynamic Array:  ";
    int* dyna = fillDyna(SIZE);
    prntDyna(dyna,SIZE,10);
    
    cout<<endl<<"Random Vector:  ";
    vector<int> vect; 
    fillVect(vect,SIZE);
    prntVect(vect,10);
    
    delete [] dyna;
    
    return 0;
}
void fillStat(int a[],int n){
    for(int i=0;i<n;i++)
        a[i]=rand()%90+10;
}
void prntStat(int a[],int n, int l){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%l==(l-1))
            cout<<endl;
    }
}
int* fillDyna(int n){
    if(n<2)
        n=2;
    int* a = new int[n];
    
    for(int i=0;i<n;i++)
        a[i]=rand()%90+10;
    
    return a;
}
void prntDyna(int*a,int n,int l){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%l==(l-1))
            cout<<endl;
    }
}
void fillVect(vector<int>& a, int n){
    for(int i=0;i<n;i++)
        a.push_back(rand()%90+10);
}
void prntVect(vector<int>a, int l){
    cout<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
        if(i%l==(l-1))
            cout<<endl;
    }
}