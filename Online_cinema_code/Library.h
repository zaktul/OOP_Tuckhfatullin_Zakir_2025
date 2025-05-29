#pragma once
#include <string>
#include <vector>

class Library {
private:
    static int lastId;
    int id;
    int contentId;
    std::string contentName;

public:
    int userId;
    Library(int userId, int contentId, const std::string& contentName);

    static void addToLibrary(int userId, int contentId, const std::string& contentName);
    static void removeFromLibrary(int userId, int contentId);
    static void loadAll();
    static void saveAll();
    static std::vector<Library> getLibraryByUserId(int userId);

    int getContentId() const { return contentId; }
    std::string getContentName() const { return contentName; }

    static std::vector<Library> allLibrary;
};