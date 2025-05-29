#pragma once
#include "User.h"
#include "Content.h"
#include "Comment.h"

class ContentMaker : public User {
public:
    ContentMaker(const std::string& username, const std::string& password);
    void showMenu() override;

    void addContent();
    void deleteContent(int contentId);
    void viewMyContents();
    void manageCategories();
    void viewCommentsForMyContent();
};