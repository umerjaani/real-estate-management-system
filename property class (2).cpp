#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<windows.h>


using namespace std;
class Agreement {
	protected:
	
	string p_name;
	string tenant_id;
	string owner_id;
	string agreement_text;
	
	public:
		
	Agreement (){
		
	}
	
	Agreement (string n,string tenant , string owner , string text){
		this -> p_name = n;
		this -> tenant_id = tenant;
		this -> owner_id = owner;
		this -> agreement_text = text;
		
	}
		
	//setters and getters 
	
    void setownerid (string id ){
    	owner_id = id;
	}
	void set_tenant_id (string id ){
		tenant_id = id ;
	}
	void set_property_name (string n){
		p_name = n;
	}
	
	void set_agreement_text(string t){
		agreement_text = t;
	}
	
	string getowner_id (){
		return owner_id;
	}
	string gettenant_id (){
		return  tenant_id ;
	}
	string get_property_name (){
		return p_name ;
	}
	string get_text (){
		return agreement_text ;
	}
	
	void create_Agreement (){
	system ("cls");
	
	   cout<<"enter property name  "<<endl;
	   cin>> p_name;
	   cout<< "Enter owner id "  << endl;
	   cin >> owner_id;
	   cout << "Enter tenant id " << endl;
	   cin >> tenant_id ;
	   
	   
	   ofstream fout("Agreement.csv",ios :: app);
	   if(!fout ){
	   	cout << "File not oppened successfully " << endl;
	   	
	   }
	   
	   else {
	   	
	   	fout << owner_id << ", "
             << p_name << ", " << tenant_id <<", " << agreement_text << endl;
             
             cout << "Agreement created successfully!" << endl;
	   }
	   
	   fout.close();
	   
	 }
	 
	 void view_all_agreements(){
	 	system ("cls");
	 	
	    fin("Agreement.csv", ios::in);
	 	
	 	(!fin){
	 		cout << "Error opening file " << endl;
		 }
	 	
	 	string line ;
	
	while (getline (fin,line )){
		cout << line << endl;
	}
	
	fin.close();
	 	
	 }
};

class Property : public Agreement {

private :
	

	string unit_no;
    float rent_value;
	bool is_sale;
	bool is_rented;
	float sale_value;
	float deposit;
	
public:
	//default
	Property(){
		
	}
	//parametrized constructor 
	
	Property(const string& property, const string& tenant, const string& owner, string unit, const string& text,bool sale, bool rented,float sale_value , 
	float deposit  )
        : Agreement(property, tenant, owner, text){
		
		
    	p_name   = property;
    	tenant_id = tenant ;
    	owner_id = owner ;
    	unit_no  = unit;
    	is_sale  = sale;

    	this->is_rented   = rented;
    	this->sale_value = sale_value;
    	this->deposit = deposit;
    	
    }
    
    // getters and setters 
    
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
	
	string get_unit_no(){
		return unit_no;
		
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
    
	cout << "enter O for tenant and enter O for owner " << endl;
    cin >> ch;

	int c;
	switch (ch ){
		case 'O':
		{
			cout << "Enter the owner id " << endl;
			cin >> owner_id;
            cout << "Enter the property name " <<endl;
            cin >> p_name;
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


            }
            else if (c == 2 ){
                is_rented = true;
                is_sale = false ;

                 cout << "enter the deposit  " <<endl ;
                 cin >> deposit ;
                 cout << " enter the rent  value " << endl;
                 cin >> rent_value;


            }
            fout << owner_id << ", "
             << p_name << ", "
             << unit_no << ", "
             << is_sale << ", "
             << is_rented << ", "
             << deposit << ", " << sale_value <<", " << rent_value; 

	break;		
		}
		case 'T':
        {
            cout << "Enter the tenant id " << endl;
			cin >> tenant_id;
            cout << "Enter the property name " <<endl;
            cin >> p_name;
            cout << " Enter the unit no  " << endl;
            cin  >> unit_no;

            cout << "Enter 1 do you want to purchase  property \n or  2 for rent " <<endl;
            cin >> c;

            if (c == 1){
                 is_sale = true ;
                 is_rented = false;
                 cout << "enter the deposit  " <<endl ;
                 cin >> deposit ;
                 cout << "enter the sale value " << endl;
                 cin >> sale_value;


            }
            else if (c == 2 ){
                is_rented = true;
                is_sale = false ;

                 cout << "enter the deposit you want " <<endl ;
                 cin >> deposit ;
                 cout << "enter the rent " << endl;
                 cin >> sale_value;
	}
     fout << tenant_id << ", "
             << p_name << ", "
             << unit_no << ", "
             << is_sale << ", "
             << is_rented << ", "
             << deposit << ", " << sale_value <<", " << rent_value;
    fout.close();
    break;

	}
    default :{
        cout << "Invalid input " <<endl;
        goto start;
    }
    
 }
 
}

//  function to view properties 

   void view_properties() {
        system("cls");

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

            cout << "Owner ID: " << tokens[0] << endl;
            cout << "Property Name: " << tokens[1] << endl;
            cout << "Unit Number: " << tokens[2] << endl;
            cout << "For Sale: " << (tokens[3] == "1" ? "Yes" : "No") << endl;
            cout << "For Rent: " << (tokens[4] == "1" ? "Yes" : "No") << endl;
            cout << "Deposit: " << tokens[5] << endl;
            cout << "Sale Value: " << tokens[6] << endl;
            cout << "Rent Value: " << tokens[7] << endl;
            cout << "---------------------------" << endl;
        }

        fin.close();
    }
    
       // function to delete a property based on owner or tenant ID
    void delete_property() {
        system("cls");

        cout << "Enter the ID (owner or tenant) to delete the property: ";
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
   


};




int main ()
{
	
    
	 while (!exit) {
        system("cls");
        int val;
        cout << "Welcome To Properties" << endl;
        cout << "************************************" << endl;
        cout << "1.do you want property for rent " << endl;
        cout << "2.do you want property for purchase" << endl;
        cout << "3.do you want property for " << endl;
        cout << "3.Exit." << endl;
        cout << "Enter Choice: ";
        cin >> val;

    

    Property  a;

    a.add_property();
    
    a.delete_property();
	
return 0;
}

