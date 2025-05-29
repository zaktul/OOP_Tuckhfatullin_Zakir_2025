#pragma once
#include "User.h"
#include "Content.h"
#include "History.h"
#include "Library.h"
#include "Rating.h"
#include "Comment.h"

class RegularUser : public User {
public:
    RegularUser(const std::string& username, const std::string& password);
    void showMenu() override;

    void viewContent();
    void watchContent(int contentId);
    void addToLibrary(int contentId);
    void removeFromLibrary(int contentId);
    void viewHistory();
    void deleteHistory(int contentId);
    void viewLibrary();
    void rateContent(int contentId, int rating);
    void addComment(int contentId, const std::string& text);
    void deleteComment(int commentId);
    void viewComments(int contentId);
};