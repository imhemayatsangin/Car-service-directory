#include<iostream>
#include <cstring>
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
//function to search for a car by car id
void search_car_by_id() {
    if (directory.count == 0) {
        cout << "Directory is empty. Cannot search for a car." << endl;
        return;
    }

    int carID;
    cout << "Enter car ID to search: ";
    cin >> carID;

    bool found = false;
    for (int i = 0; i < directory.count; i++) {
        if (directory.entries[i].ID == carID) {
            cout << "Car found:" << endl;
              cout<<"********************************************"<<endl;
            cout << "Car ID: " << directory.entries[i].ID << endl;
            cout << "Owner: " << directory.entries[i].owner_name << " " << directory.entries[i].owner_surname << endl;
            cout << "Model: " << directory.entries[i].model << endl;
            cout << "Registration Date: " << directory.entries[i].reg_date.day << "/"
                 << directory.entries[i].reg_date.month << "/" << directory.entries[i].reg_date.year << endl;
            cout << "Next Service Date: " << directory.entries[i].service_date.day << "/"
                 << directory.entries[i].service_date.month << "/" << directory.entries[i].service_date.year << endl;
            cout << "Phone Number: " << directory.entries[i].phone_no << endl;
            cout << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Car not found in the directory." << endl;
    }
}
//function to search for a car by owner name.
void search_car_by_owner_name() {
    if (directory.count == 0) {
        cout << "Directory is empty. Cannot search for a car." << endl;
        return;
    }

    char ownerName[20];
    cout << "Enter owner's name to search: ";
    cin >> ownerName;

    bool found = false;
    for (int i = 0; i < directory.count; i++) {
        if (strcmp(directory.entries[i].owner_name, ownerName) == 0) {
            cout << "Car found:" << endl;
              cout<<"********************************************"<<endl;
            cout << "Car ID: " << directory.entries[i].ID << endl;
            cout << "Owner: " << directory.entries[i].owner_name << " " << directory.entries[i].owner_surname << endl;
            cout << "Model: " << directory.entries[i].model << endl;
            cout << "Registration Date: " << directory.entries[i].reg_date.day << "/"
                 << directory.entries[i].reg_date.month << "/" << directory.entries[i].reg_date.year << endl;
            cout << "Next Service Date: " << directory.entries[i].service_date.day << "/"
                 << directory.entries[i].service_date.month << "/" << directory.entries[i].service_date.year << endl;
            cout << "Phone Number: " << directory.entries[i].phone_no << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No cars found for the given owner's name." << endl;
    }
}

 // we are using bubble sort for these 2 sorting functions.
void sort_cars_by_id() {
    if (directory.count == 0) {
        cout << "Directory is empty. Cannot sort cars." << endl;
        return;
    }

    for (int i = 0; i < directory.count - 1; i++) {
        for (int j = 0; j < directory.count - i - 1; j++) {
            if (directory.entries[j].ID > directory.entries[j + 1].ID) {
                car temp = directory.entries[j];
                directory.entries[j] = directory.entries[j + 1];
                directory.entries[j + 1] = temp;
            }
        }
    }

    cout << "Cars sorted by ID in ascending order." << endl;
}

void sort_cars_by_name() {
    if (directory.count == 0) {
        cout << "Directory is empty. Cannot sort the cars." << endl;
        return;
    }

    for (int i = 0; i < directory.count - 1; i++) {
        for (int j = 0; j < directory.count - i - 1; j++) {
            if (strcmp(directory.entries[j].owner_name, directory.entries[j + 1].owner_name) > 0) {
                car temp = directory.entries[j];
                directory.entries[j] = directory.entries[j + 1];
                directory.entries[j + 1] = temp;
            }
        }
    }

    cout << "Cars sorted by owner's name in ascending order." << endl;
}


// function to list all cars and display.
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

//functin for updating car info.
void update_car_info() {
    if (directory.count == 0) {
        cout << "Directory is empty. Cannot update car information." << endl;
        return;
    }

    int car_id;
    cout << "Enter car ID to update information: ";
    cin >> car_id;

    bool id_found = false;
    for (int i = 0; i < directory.count; i++) {
        if (directory.entries[i].ID == car_id) {
            cout << "Enter new owner's name: ";
            cin >> directory.entries[i].owner_name;

            cout << "Enter new owner's surname: ";
            cin >> directory.entries[i].owner_surname;

            cout << "Enter new car model: ";
            cin >> directory.entries[i].model;

            cout << "Enter new registration date (day month year): ";
            cin >> directory.entries[i].reg_date.day >> directory.entries[i].reg_date.month >> directory.entries[i].reg_date.year;

            cout << "Enter new next service date (day month year): ";
            cin >> directory.entries[i].service_date.day >> directory.entries[i].service_date.month >> directory.entries[i].service_date.year;

            cout << "Enter new owner's phone number: ";
            cin >> directory.entries[i].phone_no;

            cout << "Car information updated successfully." << endl;
            id_found = true;
            break;
        }
    }

    if (!id_found) {
        cout << "Car not found in the directory." << endl;
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
                	 search_car_by_id();
				}
                   
                else if (search_choice == 'B')
                {
                	 search_car_by_owner_name();
				}
                  
                else
                    cout << "Invalid search type.Try again" << endl;
                break;
            case 5:
               update_car_info();
                break;
            case 6:
                sort_cars_by_Id();
                break;
            case 7:
               sort_cars_by_name();
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
