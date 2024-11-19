#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <sstream>
#include <vector>

using namespace std;
class Login {
private:
	string name , CNIC , phone;
    string email, Password;
    string role;

public:
    Login() : email(""), Password("") , role(""), name(""), CNIC(""), phone("") {}

    void setEmail(string em) {
        email = em;
    }
    void setPhone(string ph){
    	phone = ph;
	}
	void setName(string n){
		name = n;
	}
	void setCNIC(string cnic){
		CNIC = cnic;
	}
    void setPW(string pw) {
        Password = pw;
    }
    void setRole(string r){
    	role = r;
	}
	string getRole(){
		return role;
	}
    string getEmail() const {
        return email;
    }
	string getName(){
		return name;
	}
	string getCNIC(){
		return CNIC;
	}
	string getPhone(){
		return phone;
	}
    string getPW() const {
        return Password;
    }
};

class Property{

private :
	
	string owner_id;
	string p_name;
	string unit_no;
	bool is_sale;
	bool is_rented;
	bool request;
	bool accept;
	bool agreement;
    float rent_value;
	float sale_value;
	float deposit;
	
public:
	//default
	Property(){
		
	}
	//parametrized constructor 
	
	Property (string o_id,string property,string unit, bool sale, bool rented , float sale_value, float rent_value , float deposit , bool req , bool acc , bool ag)
    {
    	owner_id = o_id;
    	p_name   = property;
    	unit_no  = unit;
    	is_sale  = sale;
    	is_rented   = rented;
		request = req;
		accept = acc;
		agreement = ag;
		this-> rent_value = rent_value;
    	this->sale_value = sale_value;
    	this->deposit = deposit;
    	
    }
    
    // getters and setters 
    
    void setownerid (string id ){
    	owner_id = id;
	}
	void set_property_name (string n){
		p_name = n;
	}
	void set_unit_no (string no){
		unit_no = no;
	}
	void set_is_sale (bool s){
		is_sale = s ;
	}
	void set_is_rented (bool r){
		is_rented = r;
	}
	void set_sale_value (float v){
		sale_value = v;
		
	}
	void set_deposit (float d){
		deposit = d;
	}
	
	string getowner_id (){
		return owner_id;
	}
	string get_unit_no(){
		return unit_no;
		
	}
	
	string get_property_name (){
		return p_name ;
	}
	
	bool get_is_sale (){
		return is_sale ;
	}
	bool get_is_rented (){
		return is_rented;
	}
	float get_sale_value (){
		return sale_value;
	}
	
	float get_deposit (){
		return deposit;
	}

//function for taking details as input

void add_property(){
	
	char ch;
	fstream fout; 
  
    // opens an existing csv file or creates a new file. 
    fout.open("properties.csv", ios::out | ios::app); 
    
    if (!fout){
    	cout << "Error occured while opening file " << endl;
	}

start:
    system("cls");
    

	int c;
			request = false;
			accept = false;
			agreement = false;
			cout << "Enter the owner id " << endl;
			cin >> owner_id;
            cout << "Enter the property name " <<endl;
            fflush(stdin);
            getline(cin , p_name);
            cout << " Enter the unit no  " << endl;
            cin  >> unit_no;

            cout << "Enter 1 do you want to sale property \n or  2 for rent the property" <<endl;
            cin>> c;

            if (c == 1){
                 is_sale = true ;
                 is_rented = false;
                 cout << "enter the deposit you want " <<endl ;
                 cin >> deposit ;
                 cout << " enter the sale value " << endl;
                 cin >> sale_value;
                 rent_value = 0;


            }
            else if (c == 2 ){
                is_rented = true;
                is_sale = false ;

                 cout << "enter the deposit  " <<endl ;
                 cin >> deposit ;
                 cout << " enter the rent  value " << endl;
                 cin >> rent_value;
                 sale_value = 0;


            }
            fout << owner_id << ", "
             << p_name << ", "
             << unit_no << ", "
             << is_sale << ", "
             << is_rented << ", "
             << request << ", "
             << accept << ", "
             << agreement << ", "
             << deposit << ", " << sale_value <<", " << rent_value << "\n"; 
}

//  function to view properties 

   void view_properties() {
        system("cls");

       ifstream fin("D:\\3rd semester stuff\\oop project\\haris code\\properties.csv");


        if (!fin) {
            cout << "Error: Unable to open file 'properties.csv'" << endl;
            return;
        }

        string line;
        while (getline(fin, line)) {
            vector<string> tokens;
            stringstream ss(line);
            string token;

            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }

            cout << "Owner ID: " << tokens[0] << endl;
            cout << "Property Name: " << tokens[1] << endl;
            cout << "Unit Number: " << tokens[2] << endl;
            cout << "For Sale: " << (tokens[3] == "0" ? "No" : "Yes") << endl;
            cout << "For Rent: " << (tokens[4] == "0" ? "No" : "Yes") << endl;
            cout << "Request By tenant: " << (tokens[5] == "1" ? "Yes" : "No")<< endl;
            cout << "Request Accept By Owner: " << (tokens[6] == "1" ? "Yes" : "No")<< endl;
            cout << "Agreement created by admin: " << (tokens[7] == "1" ? "Yes" : "No")<< endl;
            cout << "Deposit: " << tokens[8] << endl;
            cout << "Sale Value: " << tokens[9] << endl;
            cout << "Rent Value: " << tokens[10] << endl;
            cout << "---------------------------" << endl;
        }

        fin.close();
    }
    
       // function to delete a property based on owner or tenant ID
    void delete_property() {
        system("cls");

        cout << "Enter the ID of owner to delete the property:";
        string id_to_delete;
        cin >> id_to_delete;

        ifstream fin("properties.csv");
        ofstream temp("temp.csv", ios::app);

        if (!fin || !temp) {
            cout << "Error: Unable to open files" << endl;
            return;
        }

        string line;
        bool property_deleted = false;

        while (getline(fin, line)) {
            stringstream ss(line);
            vector<string> tokens;

            while (getline(ss, line, ',')) {
                tokens.push_back(line);
            }

            if (tokens.size() > 1 && (tokens[0] == id_to_delete || tokens[1] == id_to_delete)) {
                property_deleted = true;
                continue; 
            }

            temp << line << endl;
        }

        fin.close();
        temp.close();

        // Remove the existing properties.csv file
        remove("properties.csv");
        // Rename temp.csv to properties.csv
        rename("temp.csv", "properties.csv");

        if (property_deleted) {
            cout << "Property with ID " << id_to_delete << " deleted successfully!" << endl;
        } else {
            cout << "Property with ID " << id_to_delete << " not found." << endl;
        }
    }
    
      // function to delete a property based on owner or tenant ID
   
void updateProperty(string r , string id , string unit , string n , string sale , string rent , string req , string acc , string agg , string deposite , string sv , string rv){
      	
      		ifstream fin("properties.csv");
        ofstream temp("temp.csv", ios::app);

        if (!fin || !temp) {
            cout << "Error: Unable to open files" << endl;
            return;
        }

        string line;
        bool property_update = false;

        while (getline(fin, line)) {
            stringstream ss(line);
            vector<string> tokens;

            while (getline(ss, line, ',')) {
                tokens.push_back(line);
            }

            if (tokens.size() > 1 && tokens[0] == id) {
                property_update = true;
               temp << id << ", "
             << n << ", "
             << unit << ", "
             << sale << ", "
             << rent << ", "
             << req << ", "
             << acc << ", "
             << agg << ", "
             << deposite << ", " << sv <<", " << rv << endl; 

            }

            temp << line << endl;
        }

        fin.close();
        temp.close();

        // Remove the existing properties.csv file
        remove("properties.csv");
        // Rename temp.csv to properties.csv
        rename("temp.csv", "properties.csv");

        if (property_update) {
            cout << "request for this property sent successfully!" << endl;
        }
	}
	


};

class Agreemant : public Property{
	public:
		Agreemant (){
			
		}
		
	//other functions
		void  create_agreement (){
	
	string  o_id,t_id , name;
	
			cout << "Enter Owner email:";
			cin >> o_id;
			
			ifstream fow((o_id + ".csv") , ios::in);
			if(!fow){
			cout <<  "Error: Unable to open file..\n\n";
			return;
			}
			
			cout << "Enter tenant email:" <<endl;
			cin >> t_id ;
			
			ifstream fte((t_id + ".csv") , ios::in);
			if(!fte){
			cout <<  "Error: Unable to open file..\n\n";
			return;
			}
			
			cout << "Enter name of property:";
			getline(cin , name);
			
        ofstream fout("Agreement.csv", ios :: app);
        
        if (!fout ){
        	cout <<"Error occured while opening file "  << endl;
        	return;
		}
			
			
        ifstream fin("properties.csv");

        if (!fin) {
            cout << "Error: Unable to open file 'properties.csv'" << endl;
            return;
        }


		
		//owner 
		 string oline;
        while (getline(fow, oline)) {
            vector<string> otokens;
            stringstream ss(oline);
            string otoken;

            while (getline(ss, otoken, ',')) {
                otokens.push_back(otoken);
            }
            
            if (otokens [2] != "O"){
            	cout << "This id " << o_id << " is not owner id..." << endl;
            	getch();
            	return ;
			}
		fout << otokens[0] << "," << otokens[2] << ", " << otokens[4] << ", " << otokens[5] << ", " << otokens[6] << ", ";
			fow.close();
	}
            
            //teanant vector
        	string t_line;
        	 
        while (getline(fte, t_line)) {
            vector<string> t_tokens;
            stringstream ss(t_line);
            string t_token;

            while (getline(ss, t_token, ',')) {
                t_tokens.push_back(t_token);
                
            }
             if (t_tokens [2] != "T"){
            	cout << "This id " << t_id << " is not tenant  id " << endl;
            	getch();
            	return ;
			}
		
			 fout << t_tokens[0] << ", " << t_tokens[2] << ", " << t_tokens[4] << ", " << t_tokens[5] << t_tokens[6] << ", ";
			fte.close();
     	}
            
        string line;
        while (getline(fin, line)) {
            vector<string> tokens;
            stringstream ss(line);
            string token;

            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }
			 if(tokens[1] == name){
		fout << tokens[1] << ", " << tokens[2] << ", " << tokens[3] << ", " << tokens[4] << tokens[8] << ", "
			  
		     << tokens[9] << ", " << tokens[10] << "\n" ;
		     fout.close();
			 }
		     else{
		     	cout << "This property is not present..\n";
		     	getch();
		     	system("cls");
		     	fin.close();
		     	return;
			 }
    }
    
		
}
	  
 void view_agreement(){
 	fstream fin;
 	fin.open("agreement.csv" , ios::in);
 	
 	string name , unit;
 	cout << "Enter property name:";
 	getline(cin , name);
 	cout << "Enter unit number:";
 	cin >> unit;
 	
 	string line;
        while (getline(fin, line)) {
            vector<string> tokens;
            stringstream ss(line);
            string token;

            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }
			 if(tokens[8] == name){
			 	cout << "Owner Details:" << endl;
			 cout << "Owner Email:" << tokens[0] << endl; 
			 cout << "Owner Name:" << tokens[1] << endl; 
			 cout << "Owner Phone Number:" << tokens[2] << endl; 
			 cout << "Owner CNIC:" << tokens[3] << endl;
			 cout << "Tenent Details:" << endl; 
			 cout << "Tenent Email:" << tokens[4] << endl; 
			 cout << "Tenent Name:" << tokens[5] << endl; 
			 cout << "Tenent Phone Number:" << tokens[6] << endl; 
			 cout << "Tenent CNIC:" << tokens[7] << endl;
			 cout << "Property name :"<< tokens[8] << endl;
			cout << "For Sale: " << (tokens[9] == "0" ? "No" : "Yes") << endl;
            cout << "For Rent: " << (tokens[10] == "0" ? "No" : "Yes") << endl;
            cout << "Deposit amount :" << tokens [11] <<endl;
            cout << "sold amount :" << tokens[12] << endl;
            cout << "Rent amount :" << tokens [13] << endl;
			 }
		     else{
		     	cout << "This property is not present..\n";
		     	getch();
		     	system("cls");
		     	fin.close();
		     	return;
			 }
 	
	
       }
       
    }

};
//property class end here


vector<string> split(const string& str, char delimiter)
 {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
	 {
        tokens.push_back(token);
    }
    return tokens;
}


class Admin {
	public :
		//default 
		Admin (){
			
		}
		
string vemail(){

	bool ver = false;
	string email;
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
}


bool isValidPhoneNumber(string phoneNumber) {
    if (phoneNumber.length() != 11) {
        return false;
    }

    if (phoneNumber[0] != '0' && phoneNumber[0] != '9' && phoneNumber[0] != '1') {
        return false;
    }

    for (int i = 1; i < phoneNumber.length(); i++) {
        if (!isdigit(phoneNumber[i])) {
            return false;
        }
    }

    return true;
}

bool isValidCNICNumber(string cnic) {
    if (cnic.length() != 13) {
        return false;
    }

    if (cnic[0] != '4') {
        return false;
    }

    for (int i = 1; i < cnic.length(); i++) {
        if (!isdigit(cnic[i])) {
            return false;
        }
    }

    return true;
}

void registration(Login log) 
{
    system("cls");
    string email, pw , name , cnic , phone;
    string role;
    int i;
    
    cout << "Enter your name:";
    fflush(stdin);
    getline(cin , name);
    log.setName(name);
    
    while(1){
    cout << "Enter a phone number: ";
    cin >> phone;

    if (isValidPhoneNumber(phone)) {
        cout << "Valid phone number" << endl;
        log.setPhone(phone);
        break;
    } else {
        cout << "Invalid phone number" << endl;
    }
	}
	
	while(1){
    cout << "Enter a CNIC number: ";
    cin >> cnic;

    if (isValidCNICNumber(cnic)) {
        cout << "Valid CNIC number" << endl;
        log.setCNIC(cnic);
        break;
    } else {
        cout << "Invalid CNIC number" << endl;
    }
		}
	
	
	
    while(1){	
    cout << "Enter Role ('T' for tenant & 'O' for Owner):";
    cin >> role;
    if(role == "T" || role == "O"){
    	log.setRole(role);
    	break;
	}
	else{
		cout << "Enter valid character..\n\n";
		continue;
	}
}
	email = vemail();
    log.setEmail(email);

    start:
    cout << "Enter A Strong Password: ";
    cin >> pw;
    if (pw.length() >= 8) {
        log.setPW(pw);
    } else {
        cout <<"Enter Minimum 8 Characters!" << endl;
        goto start;
    }

    ofstream outfile((email + ".csv") , ios::app);
    if (!outfile) {
        cout <<"Error: File Can't Open!" << endl;
    } else {
        outfile <<log.getEmail() << "," <<log.getPW() << "," << log.getRole() << "," << log.getName() << "," << log.getPhone() << "," << log.getCNIC() <<"\n";   
        cout <<"User Registered Successfully!" <<endl;
    }
    outfile.close();
    Sleep(3000);
}
		
void admin(Property &p, Agreemant &a){
	int ch;
	while(1){
	cout << "\n\nWhat you want to do:\n";
	cout  << "1.Add Property.\n2.View Properties.\n3.Delete Property.\n";
	cout << "4.Create Agreement.\n5.Delete Agreement.\n0.Back.\n";
	cin >> ch;
	if(ch == 1){
		p.add_property();
	}
	else if(ch == 2){
		p.view_properties();
	}
	else if(ch == 3){
		p.delete_property();
	}
	else if(ch == 4){
	    a.create_agreement ();
	}
	else if(ch == 5){

	}
	else if(ch == 0){
		break;
	}
	else{
		cout << "Invalid choice..\n";
		sleep(3000);
		system("cls");
		continue;
	    }
	}
}
};

class Tenant {
	public:
		Tenant (){
			
		}
		
//other functions 

void tenant (Property &p){
	int ch;
	string id , unit;
	while(1){
		cout << "What you want to do:\n";
		cout << "1.View Properties.\n2.Left Request.\n0.Back.\n";
		cin >> ch;
		if(ch == 1){
			p.view_properties();
		}
		else if(ch == 2){	
			bool flag = false; 
			cout << "Enter Owner id:";
			cin >> id;
			cout << "Enter Unit Number:";
			cin >> unit;
			
        ifstream fin("properties.csv");

        if (!fin) {
            cout << "Error: Unable to open file 'properties.csv'" << endl;
            return;
        }

        string line;
        while (getline(fin, line)) {
            vector<string> tokens;
            stringstream ss(line);
            string token;

            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }
            if(tokens[0] == id && tokens[2] == unit){
	        cout << "Owner ID: " << tokens[0] << endl;
            cout << "Property Name: " << tokens[1] << endl;
            cout << "Unit Number: " << tokens[2] << endl;
            cout << "For Sale: " << (tokens[3] == "1" ? "Yes" : "No") << endl;
            cout << "For Rent: " << (tokens[4] == "1" ? "Yes" : "No") << endl;
            cout << "Deposit: " << tokens[5] << endl;
            cout << "Request By tenant: " << (tokens[6] == "1" ? "Yes" : "No")<< endl;
            cout << "Request Accept By Owner: " << (tokens[7] == "1" ? "Yes" : "No")<< endl;
            cout << "Agreement created by admin: " << (tokens[8] == "1" ? "Yes" : "No")<< endl;
            cout << "Sale Value: " << tokens[9] << endl;
            cout << "Rent Value: " << tokens[10] << endl;
            cout << "---------------------------" << endl;
	            
	            if(tokens[3]=="0" && tokens[4]=="0"){
	            	cout << "This property is not available yet..\n\n";
	            	sleep(3000);
	            	system("cls");
	            	break;
				}
				else if(tokens[6] == "1"){
					cout << "Some one already sent request for this Property..\n\n";
					system("cls");
					break;
				}
				else{
					char c;
					ten:
					cout << "Do you want to send request for this property.\n('Y' for yes and 'N' for no):";
					if(c == 'Y'){
						tokens[6] == "1";
						p.updateProperty("T" , id , unit , tokens[1] , tokens[3] , tokens[4] , tokens[5] , tokens[6] , tokens[7] , tokens[8] , tokens[9] , tokens[10]);
					}
					else if(c == 'N'){
						system("cls");
						break;
					}
					else{
						goto ten;
					}
			}
		}
	}
			
			}else if(ch == 0){
				system("cls");
				break;
			}
       }
   }
};

class Owner {

	public:
	Owner (){
		
	}
	
		
   void owner(Property& p){
	
	
	int ch;
	string id , unit;
	while(1){
		cout << "What you want to do:\n";
		cout << "1.View Properties.\n2.Accept Request.\n0.Back.\n";
		cin >> ch;
		if(ch == 1){
		bool flag = false; 
			cout << "Enter Owner id:";
			cin >> id;
			cout << "Enter Unit Number:";
			cin >> unit;
			
        ifstream fin("properties.csv");

        if (!fin) {
            cout << "Error: Unable to open file 'properties.csv'" << endl;
            return;
        }

        string line;
        while (getline(fin, line)) {
            vector<string> tokens;
            stringstream ss(line);
            string token;

            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }
            if(tokens[0] == id && tokens[2] == unit){
	        cout << "Owner ID: " << tokens[0] << endl;
            cout << "Property Name: " << tokens[1] << endl;
            cout << "Unit Number: " << tokens[2] << endl;
            cout << "For Sale: " << (tokens[3] == "1" ? "Yes" : "No") << endl;
            cout << "For Rent: " << (tokens[4] == "1" ? "Yes" : "No") << endl;
            cout << "Deposit: " << tokens[5] << endl;
            cout << "Request By tenant: " << (tokens[6] == "1" ? "Yes" : "No")<< endl;
            cout << "Request Accept By Owner: " << (tokens[7] == "1" ? "Yes" : "No")<< endl;
            cout << "Agreement created by admin: " << (tokens[8] == "1" ? "Yes" : "No")<< endl;
            cout << "Sale Value: " << tokens[9] << endl;
            cout << "Rent Value: " << tokens[10] << endl;
            cout << "---------------------------" << endl;
	        
		}
		else if(ch == 2){	
			    
					char c;
					if(tokens[6] == "1"){
					ten:
					cout << "Do you want to Accept request for this property.\n('Y' for yes and 'N' for no):";
					if(c == 'Y'){
						tokens[7] == "1";
						p.updateProperty("O" , id , unit , tokens[1] , tokens[3] , tokens[4] , tokens[5] , tokens[6] , tokens[7] , tokens[8] , tokens[9] , tokens[10]);
					}
					else if(c == 'N'){
						system("cls");
						break;
					}
					else{
						goto ten;
					}
				}
			}
			else if(ch == 0){
				system("cls");
				break;
		}
	}
			
			}
			}
}
	
};
/*
void  create_agreement (){
	
	string  o_id,t_id;
	
			cout << "Enter Owner email:";
			cin >> o_id;
			cout << "Enter tenant email:" <<endl;
			cin >> t_id ;
			
        ofstream fout("Agreement.csv", ios :: app);
        
        if (!fout ){
        	cout <<"Eroor occured while opening file "  << endl;
        	return;
		}
			ifstream fow((o_id + ".csv") , ios::in);
			if(!fow){
			cout <<  "Error: Unable to open file..\n\n";
			return;
			}
			
			ifstream fte((o_id + ".csv") , ios::in);
			if(!fte){
			cout <<  "Error: Unable to open file..\n\n";
			return;
			}
			
        ifstream fin("properties.csv");

        if (!fin) {
            cout << "Error: Unable to open file 'properties.csv'" << endl;
            return;
        }

        string line;
        while (getline(fin, line)) {
            vector<string> tokens;
            stringstream ss(line);
            string token;

            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }
			 
		fout << tokens[1] << ", " << tokens[2] << ", " << tokens[3] << ", " << tokens[4] << tokens[8] << ", "
			  
		     << tokens[9] << ", " << tokens[10] << "\n" ;
		     
    }
		
		//owner tenant 
		 string oline;
        while (getline(fow, oline)) {
            vector<string> otokens;
            stringstream ss(oline);
            string otoken;

            while (getline(ss, otoken, ',')) {
                otokens.push_back(otoken);
            }
            
            if (otokens [3] != "O"){
            	cout << "This is not owner id " << endl;
            	getch();
            	return ;
			}
		fout << otokens[0] << "," << otokens[2] << ", " << otokens[4] << ", " << otokens[5] << ", " << otokens[6] << ", ";
			
	}
            
            //teanant vector
        	string t_line;
        	 
        while (getline(fow, t_line)) {
            vector<string> t_tokens;
            stringstream ss(t_line);
            string t_token;

            while (getline(ss, t_token, ',')) {
                t_tokens.push_back(t_token);
                
            }
             if (t_tokens [3] != "T"){
            	cout << "This is not tenant  id " << endl;
            	getch();
            	return ;
			}
		
			 fout << t_tokens[0] << ", " << t_tokens[2] << ", " << t_tokens[4] << ", " << t_tokens[5] << t_tokens[6] << ", ";
			
     	}
            
		
		
}
*/

void login() {
	Property p;
    system("cls");
    string email , pw;
    string role;
    cout << "Enter Email ID: ";
    cin >> email;
    
    cout << "Enter Password: ";
    cin >> pw;
    
    cout << "Enter role:";
    cin >> role;

	ifstream infile((email + ".csv") , ios :: in);

    if (!infile)
	{
       cout << "Error: This email is not present!" << endl;
    }
    

	else
	{
        string line;
        bool found = false;
        while (getline(infile, line)) {
            vector<string> tokens = split(line, ',');
            if (tokens.size() == 6 && email == tokens[0] && pw == tokens[1] && role == tokens[2]) {
                found = true;

                cout << "Please Wait";
                for (int i = 0; i < 3; i++) {
                    cout << ".";
                    Sleep(800);
                }
                system("cls");
                cout << "Welcome To This Page!" << endl;
                if(role == "A"){
                	Admin(p);
				}
				else if(role == "T"){
					Tenant(p);
				}
				else if(role == "O"){
					Owner(p);
				}
            }
        }
        if (!found) {
            cout << "Error: Incorrect Login ID Or Password!" << endl;
        }
    }
    infile.close();
    Sleep(800);
}



int main() {
    Login log;
    Admin admin ;
    bool exit = 0;

    while (!exit) {
        system("cls");
        int val;
        cout << "Welcome To Registration & Login Form" << endl;
        cout << "************************************" << endl;
        cout << "1.Register." << endl;
        cout << "2.Login." << endl;
        cout << "3.Exit." << endl;
        cout << "Enter Choice: ";
        cin >> val;

        if (val == 1) {
            admin.registration(log);
        } else if (val == 2) {
            login();
        } else if (val == 3) {
            system("cls");
            exit = true;
            cout << "\tGood Luck!" << endl;
            Sleep(800);
        }
        Sleep(800);
    }

    return 0;
}
