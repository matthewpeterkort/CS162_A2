#include <iostream>
#include "A2.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <limits>

using namespace std;
//constructor 
Pizza::Pizza(): num_ingredients(DEFAULT_INGREDIENTS_NUM){
		cout<<"Default constructor called!"<<endl;
		ingredients = new string[num_ingredients];
		num_ingredients=0;
}

//alternate constructor
Pizza::Pizza(int cap): num_ingredients(cap){
	cout<<"Constructor Called."<<endl;
	ingredients= new string[num_ingredients];
	num_ingredients=0;
}


// destructor
Pizza::~Pizza(){
	cout<<" Destructor called!"<<endl;
	delete [] ingredients;
}
//define copy constructor
Pizza::Pizza(const Pizza& old_obj){
	cout<<"Copy constructor called!"<<endl;
	num_ingredients=old_obj.num_ingredients;
	name=old_obj.name;
	small_cost=old_obj.small_cost;
	medium_cost=old_obj.medium_cost;
	large_cost=old_obj.large_cost;
	
	ingredients=new string[num_ingredients];
	for (int i=0; i<num_ingredients; i++){
		ingredients[i] = old_obj.ingredients[i];
	}
}

//define an assignment operator overload
Pizza& Pizza::operator=(const Pizza& old_obj){
	cout<<"Assignment operator invoked!"<<endl;
	if (this != &old_obj){
		delete [] ingredients;
		num_ingredients=old_obj.num_ingredients;
		name=old_obj.name;
        	small_cost=old_obj.small_cost;
        	medium_cost=old_obj.medium_cost;
        	large_cost=old_obj.large_cost;
		ingredients = new string[num_ingredients];
		for (int i=0; i<num_ingredients; i++){
			ingredients[i] = old_obj.ingredients[i];
		}
	}
	return *this;
}


void Pizza::set_name(string name){
	this->name=name;
}
void Pizza::set_from_file(){


}
void Pizza::set_ingredients(string* ingredients){
	this->ingredients=ingredients;
}
	
string Pizza::get_name() const{
	return name;
}
employee* employee_info(){
        fstream loginInfo;   // declare the fstream name
        loginInfo.open("employee.txt");
       	employee* employee_info=new struct::employee[10];
        for  (int i=0; !loginInfo.eof(); i++){
                loginInfo>>employee_info[i].id;
                loginInfo>>employee_info[i].password;         // this block of code reads in the information from the wizards file into the array
                loginInfo>>employee_info[i].first_name;
                loginInfo>>employee_info[i].last_name;
        //        cout<<employee_info[i].id<<" ";
	//	cout<<employee_info[i].password<<" ";
	///	cout<<employee_info[i].first_name<<" ";
	//	cout<<employee_info[i].last_name<<" "<<endl;
        }
	loginInfo.close();
	return employee_info;
}
employee* login_process_two(employee employee_info[]){
        int ID;
        cout<<"please enter your ID"<<endl;
        cin>>ID;
        while (cin.fail()){  // this !cin idea was taken from http://www.cplusplus.com/forum/beginner/198057/
                cout<<"Invalid Integer input please try again"<<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> ID; }
        return 0;
}
employee* login_process(employee employee_info[]){
	string User_Input;
	cout<<"Welcome to Matthew's Pizza!"<<endl;	
	cout<<"Are you a customer (C) or employee (E) or would you like to quit (Q)?"<<endl;
	getline(cin,User_Input);
	if (User_Input=="C"){
		//function callto Menu screen
		cout<<"Menu Screen activated"<<endl;
		return 0;}
	if (User_Input=="Q"){
		exit(0);}
	if(User_Input=="E"){
		cout<<"Please enter you ID number"<<endl;
		login_process_two(employee_info);}

	cout<<"User input is this "<<User_Input<<endl;
	while((User_Input.compare("E")!=0)&&(User_Input.compare("Q")!=0)&&(User_Input.compare("C")!=0)){
		cin.clear();
		cout<<"Invalid Input please try again"<<endl;
		getline(cin,User_Input);
	}
}
