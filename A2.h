#ifndef A2_H
#define A2_H
#include <iostream>
#include <string> 
#include <cstdlib>
#include <fstream>
using namespace std;

#define DEFAULT_INGREDIENTS_NUM 10


struct employee{
	int id;
	string password;
	string first_name;
	string last_name;
};
struct hours{
	string day;
	string open_hour;
	string close_hour;
};

class Pizza{
	private:
		string name;
		int small_cost;
		int medium_cost;
		int large_cost;
		string *ingredients;
		int num_ingredients;
	public:
		Pizza(); //constructor 
		Pizza(int); //alternate constructor
		~Pizza(); // destructor 
		Pizza(const Pizza&); // copy constructor
		Pizza& operator=(const Pizza&);// assingment operator
		void set_name(string name); //setter for string name
		string get_name() const; // getter for string name
		void set_ingredients(string* ingredients); //setter for string ingredients
		string get_ingredients() const; // getter for string ingredients
		void set_from_file();
		//void display_pizza_ingredients() const;
	
};
class Menu {
	private:
		int num_pizzas;
		Pizza* pizzas;
	public:
		Menu search_pizza_by_cost(int upper_bound, string size);
		Menu search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients);
		Menu search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients);
		void add_to_menu(Pizza pizza_to_add);
		void remove_from_menu(int index_of_pizza_on_menu);
	
};
class Restaurant{
	private:
		Menu menu;
		struct::employee* employeees;
		hours* week;
		string name;
		string phone;
		string address;
	public:
		void load_data();
		bool login(string id, string password);
		void view_menu();
		void view_hours();
		void view_address();
		void view_phone();
		void search_menu_by_price();
		void search_by_ingredients();
		void place_order(Pizza* selection, int selection_size, int* num_ordered);
		void change_hours();
		void add_to_menu();
		void remove_from_menu();
		void view_orders();
		void remove_orders();
};
employee* employee_info();
employee* login_process(employee employee_info[]);
employee* login_process_two(employee employee_info[]);
#endif
	
