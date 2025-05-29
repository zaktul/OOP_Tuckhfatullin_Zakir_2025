#pragma once
#include <string>
#include <vector>

class Comment {
private:
    static int lastId;
    int id;
    int userId;
    int contentId;
    std::string text;
    std::string username;

public:
    Comment(int userId, int contentId, const std::string& text, const std::string& username);

    int getId() const { return id; }
    int getUserId() const { return userId; }
    int getContentId() const { return contentId; }
    std::string getText() const { return text; }
    std::string getUsername() const { return username; }

    static void addComment(int userId, int contentId, const std::string& text, const std::string& username);
    static void deleteComment(int userId, int commentId);
    static std::vector<Comment> getCommentsByContentId(int contentId);
    static void loadAll();
    static void saveAll();

    static std::vector<Comment> allComments;
};