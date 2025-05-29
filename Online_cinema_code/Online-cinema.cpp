#include "User.h"
#include "Admin.h"
#include "Content.h"
#include "Category.h"
#include "History.h"
#include "Library.h"
#include "Rating.h"
#include "Comment.h"
#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

void initSystem() {
    User::loadUsers();
    Admin::ensureAdminExists();
    Content::loadAll();
    Category::loadAll();
    History::loadAll();
    Library::loadAll();
    Rating::loadAll();
    Comment::loadAll();
}

void saveSystem() {
    User::saveUsers();
    Content::saveAll();
    Category::saveAll();
    History::saveAll();
    Library::saveAll();
    Rating::saveAll();
    Comment::saveAll();
}

int main() {
    initSystem();

    while (true) {
        cout << "\n=== ONLINE CINEMA ===\n"
            << "1. Login\n"
            << "2. Register\n"
            << "3. Exit\n"
            << "Choice: ";

        int choice;
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        unique_ptr<User> currentUser;

        switch (choice) {
        case 1:
            currentUser = User::login();
            if (currentUser) currentUser->showMenu();
            break;
        case 2:
            currentUser = User::registerUser();
            if (currentUser) cout << "Registration successful!\n";
            break;
        case 3:
            saveSystem();
            cout << "Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}