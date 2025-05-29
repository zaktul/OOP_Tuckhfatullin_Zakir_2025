#include "Admin.h"
#include "ContentMaker.h"
#include "RegularUser.h"
#include "User.h"
#include "Content.h"
#include <iostream>
#include <fstream>
#include <limits>

Admin::Admin(const std::string& username, const std::string& password)
    : User(username, password, "admin") {}

void Admin::ensureAdminExists() {
    const std::string adminUsername = "admin";
    const std::string adminPassword = "admin";

    bool adminExists = false;
    for (const auto& user : User::userList) {
        if (user->getUsername() == adminUsername && user->getRole() == "admin") {
            adminExists = true;
            break;
        }
    }

    if (!adminExists) {
        User::userList.push_back(std::make_unique<Admin>(adminUsername, adminPassword));
        std::ofstream outFile("data/users.txt", std::ios::app);
        if (outFile) {
            outFile << User::userList.back()->getId() << "|"
                << adminUsername << "|" << adminPassword << "|admin\n";
        }
        else {
            std::cerr << "Error: Cannot open users.txt!\n";
        }
    }
}

void Admin::showMenu() {
    while (true) {
        std::cout << "\n=== ADMIN MENU ===\n"
            << "1. Create Content Maker\n"
            << "2. View Content Makers\n"
            << "3. Create Regular User\n"
            << "4. View Regular Users\n"
            << "5. Delete User\n"
            << "6. Logout\n"
            << "Choice: ";

        int choice;
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input! Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1: createContentMaker(); break;
        case 2: viewContentMakers(); break;
        case 3: createRegularUser(); break;
        case 4: viewRegularUsers(); break;
        case 5: {
            int userId;
            std::cout << "Enter User ID to delete: ";
            if (!(std::cin >> userId)) {
                std::cout << "Invalid ID!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            deleteUser(userId);
            break;
        }
        case 6: return;
        default: std::cout << "Invalid choice!\n";
        }
    }
}

void Admin::createContentMaker() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::getline(std::cin, username);
    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    if (User::usernameExists(username)) {
        std::cout << "Username already exists!\n";
        return;
    }

    User::userList.push_back(std::make_unique<ContentMaker>(username, password));
    std::ofstream outFile("data/users.txt", std::ios::app);
    if (!outFile) {
        std::cerr << "Error: Cannot open users.txt!\n";
        return;
    }
    outFile << User::userList.back()->getId() << "|"
        << username << "|" << password << "|contentmaker\n";
    std::cout << "Content Maker created successfully!\n";
}

void Admin::viewContentMakers() {
    std::cout << "\n=== CONTENT MAKERS ===\n";
    bool found = false;
    for (const auto& user : User::userList) {
        if (user->getRole() == "contentmaker") {
            std::cout << "ID: " << user->getId()
                << " | Username: " << user->getUsername() << "\n";
            found = true;
        }
    }
    if (!found) std::cout << "No content makers found.\n";
}

void Admin::createRegularUser() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::getline(std::cin, username);
    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    if (User::usernameExists(username)) {
        std::cout << "Username already exists!\n";
        return;
    }

    User::userList.push_back(std::make_unique<RegularUser>(username, password));
    std::ofstream outFile("data/users.txt", std::ios::app);
    if (!outFile) {
        std::cerr << "Error: Cannot open users.txt!\n";
        return;
    }
    outFile << User::userList.back()->getId() << "|"
        << username << "|" << password << "|user\n";
    std::cout << "Regular User created successfully!\n";
}

void Admin::viewRegularUsers() {
    std::cout << "\n=== REGULAR USERS ===\n";
    bool found = false;
    for (const auto& user : User::userList) {
        if (user->getRole() == "user") {
            std::cout << "ID: " << user->getId()
                << " | Username: " << user->getUsername() << "\n";
            found = true;
        }
    }
    if (!found) std::cout << "No regular users found.\n";
}

void Admin::deleteUser(int userId) {
    if (this->getId() == userId) {
        std::cout << "Cannot delete yourself!\n";
        return;
    }

    auto it = std::find_if(User::userList.begin(), User::userList.end(),
        [userId](const auto& user) { return user->getId() == userId; });
    if (it != User::userList.end()) {
        if ((*it)->getRole() == "contentmaker") {
            // Удаление всех фильмов контент-мейкера
            Content::allContents.erase(
                std::remove_if(Content::allContents.begin(), Content::allContents.end(),
                    [userId](const Content& content) { return content.getMakerId() == userId; }),
                Content::allContents.end());
            Content::saveAll();

            // Удаление связанных рейтингов
            Rating::allRatings.erase(
                std::remove_if(Rating::allRatings.begin(), Rating::allRatings.end(),
                    [userId](const Rating& rating) {
                        for (const auto& content : Content::allContents) {
                            if (content.getId() == rating.contentId && content.getMakerId() == userId) {
                                return true;
                            }
                        }
                        return false;
                    }),
                Rating::allRatings.end());
            Rating::saveAll();
        }
        User::userList.erase(it);
        User::saveUsers();
        std::cout << "User deleted successfully!\n";
    }
    else {
        std::cout << "User not found!\n";
    }
}