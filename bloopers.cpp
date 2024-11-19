#include<iostream>

using namespace std;

int main(){
	string tokens[4] = {"1" , "0" , "1" , "1"};
	cout << "For Rent: " << (tokens[3] == "1" ? "Yes" : "No") << endl;
	if(tokens[3] == "1"){
		cout << "yes";
	}
}