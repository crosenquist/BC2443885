/* Carey, Bradd
 * 02 March 2014
 *  
 * Purpose:  Demonstrate usefulness of Luhn Algorithm
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

//Global Constants
enum CrdCard{AMEX, VISA, MASTER, DISC, ALL};  //Required to declare here to use in functions

//Functions
char* genCC(CrdCard);
char* genVisa();
char* genMstr();
char* genDisc();
char* genAmex();
char* genNum(int,int);
char getLuhn(char[],int); 
void prntCard(char[],int); 

int main(int argc, char** argv) {
    srand(time(0));
    int length;
    char* card = genCC(MASTER);
    return 0;
}

char* genCC(CrdCard c){
    /*Information for CCs obtained from http://en.wikipedia.org/wiki/Bank_card_number
     *| Type    |  Prefix                          |  Lengths     
     *| Visa    |    4                             |  13,16
     *| Master  |  50-55                           |  16
     *| Disc    |  6011,622, 644-649, 65           |  16
     *| Amex    |  34,37                           |  15
     */
    if(c==VISA)
        return genVisa();
    else if(c==MASTER)
        return genMstr();
    else if(c==DISC)
        return genDisc();
    else if(c==AMEX)
        return genAmex();
   
}
char* genVisa(){
    //Declare Variables
    int foo;
    int prefix;
    int length;
    //Find Length
    foo = rand()%2;
    if(foo) length=16;
    else length=13;
    
    //Find Prefix
    prefix=4;
    
    return genNum(length,prefix);
}
char* genMstr(){
    //Declare Variables
    int foo;
    int prefix;
    int length;
    //Find Length
    length=16;
    
    //Find Prefix
    foo = rand()%6+50;
    prefix=foo;

    return genNum(length,prefix);
}
char* genDisc(){
 //Declare Variables
    int foo;
    int prefix;
    int length;
 //Find Length
    length=16;
    
 //Find Prefix
    do{ //Find First Digit (cannot = 3)
        foo = rand()%6+60;
    }while(foo==63||foo==61);
    prefix=foo;
        //Generate the rest of the prefix digits
    if(prefix==60)
        prefix=6011;
    else if(prefix==62)
        prefix=622;
    else if(prefix==64){
        foo = rand()%6+4; //Generate 4-9
        prefix = (prefix*10)+foo;
    }
    
    return genNum(length,prefix);
}
char* genAmex(){
    //Declare Variables
    int foo;
    int prefix;
    int length;
    //Find Length
    length=15;
    
    //Find Prefix
    foo = rand()%2;
    if(foo)prefix=34;
    else prefix=37;
    
    return genNum(length,prefix);
}
char* genNum(int length, int prefix){
  //Declare
    char num[length];
    int digit;
  //Get the size of the prefix-1
    if(prefix/1000)digit=3;
    else if(prefix/100)digit=2;
    else if(prefix/10)digit=1;
    else digit=0;
  //Store the prefix as the first digits of char array
    for(int i=digit;i>=0;i--){
        num[i]=prefix%10+'0';
        prefix/=10;
    }
  //Randomly generate the rest of the digits except the check sum
    for(int i=digit;i<length-1;i++)
        num[i]=rand()%10+'0';
  //Use Luhn Algorithm to generate the last digit
    num[length-1] = getLuhn(num,length);
    
    prntCard(num,length);
    
  //Return the array
    return num;
    
    
}
char getLuhn(char *num, int length){
    //Declare
    char reverse[length];
    int temp;
    int sum=0;
    
    //STEP ONE: REVERSE THE ARRAY
    for(int i=0,j=length-2;i<length;i++){
        reverse[i]=num[j];
        j--;
    }
    //STEP TWO: GET THE SUM OF CARD NUMBERS
    for(int i=0;i<(length-1);i++){
        //If Odd then double that element
        if(!(i%2))
            temp = (reverse[i]-'0')*2;
        //if Even then don't double that element
        else
            temp = (reverse[i]-'0');
        //THIS WAS TO MAKE SURE DOUBLING IS HAPPENING CORRECTLY  cout<<temp<<endl;
        if(temp>=10)
            temp-=9;
        //Add result to sum
        sum += temp;
        
    }
    return (sum*9)%10+'0';
}
void prntCard(char *num,int length){
    for(int i=0;i<length;i++)
        cout<<num[i];
} 