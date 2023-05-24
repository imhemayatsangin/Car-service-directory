#include<iostream>

using namespace std;

struct date {
    int day, month, year;
};

struct car {
    int ID;
    char owner_name[20], owner_surname[20], model[20];
    struct date reg_date, service_date;
    char phone_no[20];
};

struct car_directory {
    car entries[100];
    int count;
} directory;

//function for adding car into the directory...
void add_car() {
    if (directory.count == 100) {
        cout << "Directory is full. Cannot add more cars." << endl;
        return;
    }

    car newCar;

    cout << "Enter car ID: ";
    cin >> newCar.ID;

    cout << "Enter owner's name: ";
    cin >> newCar.owner_name;

    cout << "Enter owner's surname: ";
    cin >> newCar.owner_surname;

    cout << "Enter car model: ";
    cin >> newCar.model;

    cout << "Enter registration date (day month year): ";
    cin >> newCar.reg_date.day >> newCar.reg_date.month >> newCar.reg_date.year;

    cout << "Enter next service date (day month year): ";
    cin >> newCar.service_date.day >> newCar.service_date.month >> newCar.service_date.year;

    cout << "Enter owner's phone number: ";
    cin >> newCar.phone_no;

    directory.entries[directory.count] = newCar;
    directory.count++;

    cout << "Car added successfully." << endl;
    cout<<"************************************"<<endl;
    
}
//function to delete a car from directory
void delete_car() {
    if (directory.count == 0) {
        cout << "Directory is empty. You Can not delete a car." << endl;
        return;
    }

    int car_id;
    cout << "Enter a car ID to delete: ";
    cin >> car_id;

    int foundIndex = -1;
    for (int i = 0; i < directory.count; i++) {
        if (directory.entries[i].ID == car_id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        cout << "Car not found in the directory." << endl;
    } else {
        for (int i = foundIndex; i < directory.count - 1; i++) {
            directory.entries[i] = directory.entries[i + 1];
        }
        directory.count--;

        cout << "Car deleted successfully." << endl;
    }
}

void list_cars() {
    if (directory.count == 0) {
        cout << "Car directory is empty." << endl;
        return;
    }

    cout << "Car Directory list:" << endl;
     cout<<"********************************************"<<endl;
    for (int i = 0; i < directory.count; i++) {
        cout << "Car ID: " << directory.entries[i].ID << endl;
        cout << "Owner: " << directory.entries[i].owner_name << " " << directory.entries[i].owner_surname << endl;
        cout << "Model: " << directory.entries[i].model << endl;
        cout << "Registration Date: " << directory.entries[i].reg_date.day << "/"
             << directory.entries[i].reg_date.month << "/" << directory.entries[i].reg_date.year << endl;
        cout << "Next Service Date: " << directory.entries[i].service_date.day << "/"
             << directory.entries[i].service_date.month << "/" << directory.entries[i].service_date.year << endl;
        cout << "Phone Number: " << directory.entries[i].phone_no << endl;
        cout << endl;
    }
}
int main(){
	

	cout<<"Car Service Directory!"<<endl;
  cout<<"********************************************"<<endl;
	cout<<endl;
	
	directory.count = 0;
    int choice;

    do {
    	
        cout << "Menu:" << endl;
          cout<<"********************************************"<<endl;
        cout << "1- Add a new car to directory" << endl;
        cout << "2- Delete a car from the directory" << endl;
        cout << "3- List available cars in the directory" << endl;
        cout << "4- Search a car:" << endl;
        cout << "   A - Search according to car ID" << endl;
        cout << "   B - Search according to owner's name" << endl;
        cout << "5- Update car information" << endl;
        cout << "6- Sort according to car ID" << endl;
        cout << "7- Sort according to owner's name" << endl;
        cout << "8- Quit" << endl;
        cout<<"********************************************"<<endl;
        cout<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_car();
                break;
            case 2:
                delete_car();
                break;
            case 3:
                list_cars();
                break;
            case 4:
                char search_choice;
                cout << "Enter search type (A or B): ";
                cin >> search_choice;
                if (search_choice == 'A'){
				}
//                    search_car_by_id();
                else if (search_choice == 'B')
                {
				}
//                    search_car_by_name();
                else
                    cout << "Invalid search type.Try again" << endl;
                break;
            case 5:
//                update_car_info();
                break;
            case 6:
//                sort_cars_by_Id();
                break;
            case 7:
//                sort_cars_by_name();
                break;
            case 8:
                cout << "Quit the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid menu option." << endl;
                break;
        }

        cout << endl;
    } while (choice != 8);

	
	
	return 0;
}
