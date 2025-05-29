#include "User.h"
#include "Admin.h"
#include "ContentMaker.h"
#include "RegularUser.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

int User::lastId = 0;
std::vector<std::unique_ptr<User>> User::userList;

User::User(const std::string& username, const std::string& password, const std::string& role)
    : id(++lastId), username(username), password(password), role(role) {}

void User::loadUsers() {
    std::ifstream file("data/users.txt");
    if (!file) return;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string idStr, username, password, role;

        if (std::getline(iss, idStr, '|') &&
            std::getline(iss, username, '|') &&
            std::getline(iss, password, '|') &&
            std::getline(iss, role, '|')) {
            try {
                int id = std::stoi(idStr);
                if (id > lastId) lastId = id;
                if (role == "admin") {
                    userList.push_back(std::make_unique<Admin>(username, password));
                }
                else if (role == "contentmaker") {
                    userList.push_back(std::make_unique<ContentMaker>(username, password));
                }
                else {
                    userList.push_back(std::make_unique<RegularUser>(username, password));
                }
                userList.back()->id = id;
            }
            catch (...) {
                std::cerr << "Error: Invalid user data in users.txt\n";
            }
        }
    }
}

std::unique_ptr<User> User::login() {
    std::string username, password;
    std::cout << "Username: ";
    std::getline(std::cin, username);
    std::cout << "Password: ";
    std::getline(std::cin, password);

    for (auto& user : userList) {
        if (user->getUsername() == username && user->checkPassword(password)) {
            if (user->getRole() == "admin") {
                return std::make_unique<Admin>(username, password);
            }
            else if (user->getRole() == "contentmaker") {
                return std::make_unique<ContentMaker>(username, password);
            }
            else {
                return std::make_unique<RegularUser>(username, password);
            }
        }
    }
    std::cout << "Invalid credentials!\n";
    return nullptr;
}

std::unique_ptr<User> User::registerUser() {
    std::string username, password;
    std::cout << "Choose username: ";
    std::getline(std::cin, username);

    if (usernameExists(username)) {
        std::cout << "Username already taken!\n";
        return nullptr;
    }

    std::cout << "Choose password: ";
    std::getline(std::cin, password);

    auto newUser = std::make_unique<RegularUser>(username, password);
    userList.push_back(std::move(newUser));

    std::ofstream file("data/users.txt", std::ios::app);
    if (!file) {
        std::cerr << "Error: Cannot open users.txt!\n";
        return nullptr;
    }
    file << userList.back()->getId() << "|" << username << "|" << password << "|user\n";

    return std::make_unique<RegularUser>(username, password);
}

bool User::usernameExists(const std::string& username) {
    for (auto& user : userList) {
        if (user->getUsername() == username) {
            return true;
        }
    }
    return false;
}

void User::saveUsers() {
    std::ofstream file("data/users.txt");
    if (!file) {
        std::cerr << "Error: Cannot save users data!\n";
        return;
    }
    for (auto& user : userList) {
        file << user->getId() << "|"
            << user->getUsername() << "|"
            << user->password << "|"
            << user->getRole() << "\n";
    }
}

void User::deleteUser(int userId) {
    auto it = std::find_if(userList.begin(), userList.end(),
        [userId](const auto& user) { return user->getId() == userId; });
    if (it != userList.end()) {
        if ((*it)->getRole() == "admin") {
            std::cout << "Cannot delete admin account!\n";
            return;
        }
        userList.erase(it);
        saveUsers();
        std::cout << "User deleted successfully!\n";
    }
    else {
        std::cout << "User not found!\n";
    }
}