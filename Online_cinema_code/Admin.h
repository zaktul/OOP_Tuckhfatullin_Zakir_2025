#pragma once
#include "User.h"

class Admin : public User {
public:
    Admin(const std::string& username, const std::string& password);
    void showMenu() override;

    void createContentMaker();
    void viewContentMakers();
    void createRegularUser();
    void viewRegularUsers();
    void deleteUser(int userId);
    static void ensureAdminExists();
};