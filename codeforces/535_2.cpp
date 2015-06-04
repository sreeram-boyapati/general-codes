#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;

int str2int (const string &str) {
  stringstream ss(str);
  int num;
  if((ss >> num).fail())
  {
      //ERROR
  }
  return num;
}
int get_previous_values(int length){
    int in_order = 0;
    for(int i=1; i<=length-1; i++){
        in_order += pow(2, i);
    }
    return in_order;
}

int main(){
    string n;
    cin>>n;
    int string_length = n.length();
    int index = get_previous_values(string_length);
    int k=1;
    string number = "";

    for(int i=0; i<n.length(); i++){
        char c = n[i];
        if(c == '7'){
            number += "1";
        }
        else if(c == '4'){
            number += "0";
        }
    }
    int to_convert = str2int(number);
    cout<<to_convert<<endl;
    return 0;
}
