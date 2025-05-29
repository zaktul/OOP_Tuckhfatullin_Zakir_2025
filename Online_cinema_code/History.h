#pragma once
#include <string>
#include <vector>

class History {
private:
    static int lastId;
    int id;
    int userId;
    int contentId;
    std::string contentName;

public:
    History(int userId, int contentId, const std::string& contentName);

    static void addToHistory(int userId, int contentId, const std::string& contentName);
    static void deleteHistory(int userId, int contentId);
    static void loadAll();
    static void saveAll();
    static std::vector<History> getHistoryByUserId(int userId);

    int getContentId() const { return contentId; }
    std::string getContentName() const { return contentName; }

    static std::vector<History> allHistory;
};