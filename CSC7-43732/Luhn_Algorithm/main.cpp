/* Carey, Bradd
 * 24 February 2014
 *
 * Purpose:  Perform Luhn Algorithm Checksums in order to validate an account number 
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>

//No Global Constants

using namespace std;

//Function Prototypes
string input();
bool isNum(string);
bool luhnChk(string);

int main(int argc, char** argv) {
    //Initialize account number string
    string acctNum;
    
    //Repeat until a valid account number is input
    do{
        //Get Input and validate number
        acctNum = input();    
    }while(!luhnChk(acctNum));

    cout<<endl<<"Account number is valid.";
    //Stay Execution
    return 0;
}
string input(){
    //Get User input and output as string
    string acct;
    do{
        cout<<"Please enter the account number:  ";
        getline(cin,acct);
    }while(!isNum(acct));
    return acct;
}
bool isNum(string a){
    //Check to make sure that the account number is 11 digits
    if(a.length()!=11){
        cout<<"**********************************************"<<endl
            <<"Error:  Account Number should be 11 Digits."<<endl
            <<"**********************************************"<<endl<<endl;
        return false;
    }
    
    //Check each element of the string to make sure they are numbers
    for(int i=0; i<a.length();i++){
        if(((a[i]-'0')<0)||((a[i]-'0')>9)){
            cout<<"**********************************************"<<endl
                <<"Error:  Please input only numbers."<<endl
                <<"**********************************************"<<endl<<endl;
            return false;
        }    
    }
    return true;
}
bool luhnChk(string a){
    //Variables
    int sum=0;
    int temp=0;
    
//STEP ONE: GET THE SUM OF ACCOUNT NUMBERS
    for(int i=0;i<(a.length()-1);i++){
        //If Odd then double that element
        if(i%2)
            temp = (a[i]-'0')*2;
        //if Even then don't double that element
        else
            temp = (a[i]-'0');
        //If the doubling puts the element over 9 add the two digits together
        if(temp>=10)
            temp = 1+(temp%10);
        //Add result to sum
        sum += temp;
    }
    
//STEP TWO: CHECK (SUM*9)%10 AGAINST THE 11TH DIGIT
    if((a[a.length()-1]-'0')==(sum*9)%10)
        return true;
    else{
        cout<<"**********************************************"<<endl
            <<"Error:  Account number failed check sum."<<endl
            <<"**********************************************"<<endl<<endl;
        return false;
    }
}