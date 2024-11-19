//#include <iostream>
//
//#include<stdio.h>
//#include<httplib.h>
//
//int main() {
//    // Create an instance of the httplib::Client
//    httplib::Client cli("smtp://your-smtp-server.com");
//
//    // Replace the following placeholders with your actual email and password
//    std::string email = "your-email@example.com";
//    std::string password = "your-email-password";
//
//    // Compose the email content
//    std::string from = "k224515@nu.edu.pk";
//    std::string to =   "k224185@nu.edu.pk";
//    std::string subject = "Test Email";
//    std::string body = "This is a test email sent from a C++ program.";
//
//    // Compose the POST data for the SMTP server
//    std::string data = "From=" + from + "&To=" + to + "&Subject=" + subject + "&Body=" + body;
//
//    // Set up authentication
//    cli.set_basic_auth(email.c_str(), password.c_str());
//
//    // Send the POST request to the SMTP server
//    auto res = cli.Post("/send", data.c_str(), "application/x-www-form-urlencoded");
//
//    // Check the response
//    if (res && res->status == 200) {
//        std::cout << "Email sent successfully!\n";
//    } else {
//        std::cerr << "Failed to send email. Error: " << (res ? res->status : -1) << std::endl;
//    }
//
//    return 0;
//}


#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdbool.h>
#include<string>
#include<sstream>
#include<vector>

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
		string em , tempPass;
		int flag = 0;
		cout << "Enter your email:"; cin >> em;
		fstream fin;
		fin.open((em + ".csv") , ios::in);
		
		if(!fin){
		cout << "This file is not exist..\n\n";
		}
		
		string temp , line , word;
		vector<string> row; 
    while (fin >> temp) { 
  		cout << "Enter your password:";
		cin >> tempPass;
        row.clear(); 
  
        // read an entire row and 
        // store it in a string variable 'line' 
        getline(fin, line); 
  
        // used for breaking words 
        stringstream s(line); 
  
        // read every column data of a row and 
        // store it in a string variable, 'word' 
        while (getline(s, word, ',')) { 
  
            // add all the column data 
            // of a row to a vector 
            row.push_back(word); 
        } 
  
			if(tempPass == row[1]){
				cout << "Successfully Login..\n\n";
				flag = 1;
				fin.close();
				break;
			}
			else{
				cout << "Please enter correct Password:";
			}
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



void password(char r){
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
			string str;
            fstream fout;
        	fout.open((email + ".csv") , ios::out);
            fout << email << "," << pass << "\n";
			fout.close();
            break;
        }
        }
	}
};
    
class Role{
    //object of signup class
    SignUp_In  s;

    bool login ;
    bool signup ;
    char role , ch;

    public:
     ask(){
        while(1){
        cout << "Enter your role..\npress 'P' for Property Manager.\n'T' for Tenent.\n'O' for Owner.\n:" ;
        cin >> role ;
        if(role == 'p' || role == 'P' || role == 't' || role == 'T' ||  role == 'o' || role == 'O'){
        cout << "What you want to do.\nLogin or SignUp\nPress 'l' for login and 's' for signup:\n";
        cin >> ch ;
        if(ch == 'l' || ch == 'L'){
            s.checkPass();
   
        }
        else if(ch == 's' || ch == 'S'){
        s.vemail();
        s.password(role);
        }
		}
		else{
		cout << "Enter correct choice..\n\n";
		continue;}
		}	
    }
};
int main(){
    Role r ;
    r.ask();
    
}
