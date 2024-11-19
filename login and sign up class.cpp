#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdbool.h>
#include<string>

using namespace std;

class SignUp_In{
//    signUpInform s;
	char role;
	string pass;
	string email;
    
	public:
    string getPass(){
    	return pass;
	}
	string getEmail(){
		return email;
	}

void checkPass(){
		SignUp_In s;
		ifstream fptr;
		fptr.open("user.txt" , ios::in | ios::binary);
	if(!fptr){
		cout << "This file is not exist..\n\n";
		return;
	}
		string em , tempPass;
		int flag = 0;
		
		while(fptr){
		
		cout << "Enter your email:"; cin >> em;
		
//		fptr.read((char*)&s , sizeof(s));
		fptr >> s.email;
		fptr >> s.pass;		
		if(em==s.email){
		cout << "Enter your password:"; cin >> tempPass;
			do{
			if(tempPass == s.pass){
				cout << "Successfully Login..\n\n";
				flag = 1;
			}
			else{
				cout << "Please enter correct Password:";
			}
			}while(flag!=1);
			fptr.close();	
		}
	}
		if(flag == 0){
			cout << "No such email in  record..\n\n";
		}

}
    
string vemail(){
	bool ver = false;
	int counter, alpha = 0, dot = 0;
	cout << "\t\t\nEnter your e-mail id : " ;
	fflush(stdin);
	cin >> email ;
		do
		{
			for (counter = 0; email[counter] != '\0'; counter++)
			{
				if (email[counter] == '@')
					alpha = counter;
				if (email[counter] == '.')
					dot = counter;
				if(email[alpha + 1] == '\0'){
					cout << "\nInvalid E-mail\n" ;
				cout << "\t\t\nEnter your e-mail id : ";
				cin >> email;
				}
				else{
					ver = true;
				}
			}
			if (alpha > 2 && (dot - alpha) > 3 && ver)
			{
				cout << "\ne-mail Verified..\n";

				return email;
			}

			else
			{
				cout << "\nInvalid E-mail\n" ;
				cout << "\t\t\nEnter your e-mail id : ";
				cin >> email;
			}
		} while (alpha < 2 && (dot - alpha) < 3 && ver);
//	}
}



void password(){
	bool hasUpper = false ;
    bool hasLower = false ;
    bool hasDigit = false ;
    bool hasSpecial = false ;
	
	while(1){
    cout << "Create password(Atleast 8 digit and has lower case, upper case , digit and special character):\n";
    cin >> pass ;
    int len = pass.length();
    for(int i=0 ; i < len ; i++){
        if(isupper(pass[i]))
        hasUpper = true; 
        else if(islower(pass[i]))
        hasLower = true;
        else if(isdigit(pass[i]))
        hasDigit = true;
        else if(ispunct(pass[i]))
        hasSpecial = true;
    }
        if(!hasUpper){
            cout << "please enter password as per requirement..\n";
            continue;
        }
        if(!hasLower){
            cout << "please enter password as per requirement..\n";
            continue;
        }
        if(!hasDigit){
            cout << "please enter password as per requirement..\n";
            continue;
        }
        if(!hasSpecial){
            cout << "please enter password as per requirement..\n";
            continue;
        }
        else{
            cout << "Password was successfully added.\n\n";
            cout << "\n Your account is successfully created..\n\n";
            ofstream fout;
			fout.open("user.txt" , ios::app | ios::binary);
            fout.write((char*)this , sizeof(*this));
			fout.close();
            break;
        }
        }
	}
    
};
class Role{
    bool login ;
    bool signup ;
    char role , ch;

    public:
    int ask(){
        while(1){
        cout << "Enter your role..\npress 'P' for Property Manager.\n'T' for Tenent.\n'O' for Owner.\n:" ;
        cin >> role ;
        if(role == 'p' || role == 'P' || role == 't' || role == 'T' ||  role == 'o' || role == 'O'){
        cout << "What you want to do.\nLogin or SignUp\nPress 'l' for login and 's' for signup:\n";
        cin >> ch ;
        if(ch == 'l' || ch == 'L'){
            return 1;
        }
        else if(ch == 's' || ch == 'S'){
            return 0;
        }
		}
		else{
		cout << "Enter correct choice..\n\n";
		continue;}
		}	
    }
};
int main()
{
    Role r ;
    int flag;
    
    flag = r.ask();
    if(flag == 0){
    	SignUp_In s;
    	s.vemail();
        s.password();
	}
	else if(flag == 1){
    	SignUp_In s1;
    	s1.checkPass();
	}
}
