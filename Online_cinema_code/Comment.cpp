#include "Comment.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>

int Comment::lastId = 0;
std::vector<Comment> Comment::allComments;

Comment::Comment(int userId, int contentId, const std::string& text, const std::string& username)
    : id(++lastId), userId(userId), contentId(contentId), text(text), username(username) {}

void Comment::addComment(int userId, int contentId, const std::string& text, const std::string& username) {
    allComments.emplace_back(userId, contentId, text, username);
    saveAll();
}

void Comment::deleteComment(int userId, int commentId) {
    allComments.erase(
        std::remove_if(allComments.begin(), allComments.end(),
            [userId, commentId](const Comment& comment) {
                return comment.getId() == commentId && comment.getUserId() == userId;
            }),
        allComments.end());
    saveAll();
}

std::vector<Comment> Comment::getCommentsByContentId(int contentId) {
    std::vector<Comment> contentComments;
    for (const auto& comment : allComments) {
        if (comment.getContentId() == contentId) {
            contentComments.push_back(comment);
        }
    }
    return contentComments;
}

void Comment::loadAll() {
    std::ifstream file("data/comments.txt");
    if (!file) {
        std::cout << "Warning: Could not open comments.txt. Starting with empty comments list.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string idStr, userIdStr, contentIdStr, text, username;

        if (!std::getline(iss, idStr, '|') ||
            !std::getline(iss, userIdStr, '|') ||
            !std::getline(iss, contentIdStr, '|') ||
            !std::getline(iss, text, '|') ||
            !std::getline(iss, username, '|')) {
            std::cerr << "Error: Invalid comment entry format: " << line << "\n";
            continue;
        }

        try {
            int id = std::stoi(idStr);
            Comment comment(std::stoi(userIdStr), std::stoi(contentIdStr), text, username);
            comment.id = id;
            if (id > lastId) lastId = id;
            allComments.push_back(comment);
            std::cout << "Loaded comment: ID " << id << ", Content ID: " << comment.getContentId() << "\n";
        }
        catch (...) {
            std::cerr << "Error: Invalid comment data: " << line << "\n";
        }
    }
    std::cout << "Total comments loaded: " << allComments.size() << ", Last ID: " << lastId << "\n";
}

void Comment::saveAll() {
    std::ofstream file("data/comments.txt");
    if (!file) {
        std::cerr << "Error: Could not save comments data! Check file permissions.\n";
        return;
    }

    for (const auto& comment : allComments) {
        file << comment.id << "|"
            << comment.userId << "|"
            << comment.contentId << "|"
            << comment.text << "|"
            << comment.username << "\n";
    }
    std::cout << "Saved " << allComments.size() << " comments to file.\n";
}