#include <iostream>
#include <limits>
#include "manager.h"
#include "StorageHandler.h"

using namespace std;

void menu(){
    cout << "Password manager\n";
    cout << "\n";
    cout << "1. Add Password\n";
    cout << "2. Search\n";
    cout << "3. Delete Password\n";
    cout << "4. List all entries\n";
    cout << "5. Save & exit\n";
    cout << "\n";
    cout << "Enter your choice!\n";

}

int main(){
    manager mgr;
    StorageHandler storage;

    //trying to load existing json file, rename if u want to
    auto loadjson = storage.loadFile("data.json");
    for(auto &e : loadjson){
        mgr.addEntry(e);
    }


    while (true){
        menu();
        int choice;

        //input validation - https://www.geeksforgeeks.org/how-to-validate-user-input-in-cpp/
        while (!(cin >> choice)){
            cout << "invalid input\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        //ignore leftover inputs
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

        switch(choice){
            case 1: {
                // Add password
                string title, user, pass;
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter username: ";
                getline(cin, user);
                cout << "Enter password: ";
                getline(cin, pass);
                mgr.addEntry(entry(title, user, pass));
                cout << "Entry added.\n\n";
            } break;

            case 2:{
                // search
                string title;
                cout << "enter title to search: ";
                getline(cin, title);

                if(auto* found = mgr.searchEntry(title)){
                    cout << "Title: " << found->getTitleName() << "\n"
                         << "Username: " << found->getUsername() << "\n"
                         << "Password: " << found->getPassword() << "\n\n";
                } else {
                    cout << "Entry not found.\n\n";
                }


            } break;

            case 3:{
                //delete
                string title;
                cout << "Enter title to delete: ";
                getline(cin, title);
                mgr.deleteEntry(title);
                cout << "Title deleted!\n\n";

            } break;

            case 4:{
                //list all entries
                const auto& all = mgr.getAllEntries();
                if(all.empty()){
                    cout << "No entries available.\n";
                    break;
                }
                for(const auto&e : all){
                    cout << "Title: " << e.getTitleName() << "\n"
                         << "Username: " << e.getUsername() << "\n"
                         << "Password: " << e.getPassword() << "\n\n";
                }
            } break;

            case 5:
                //save & exit
                storage.saveToFile("data.json", mgr.getAllEntries());
                cout << "exiting...\n";
                return 0;

            default:
                cin.clear();
                break;


        }
    }
    return 0;
}
