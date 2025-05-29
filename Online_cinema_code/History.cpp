#include "History.h"
#include <fstream>
#include <sstream>
#include <iostream>

int History::lastId = 0;
std::vector<History> History::allHistory;

History::History(int userId, int contentId, const std::string& contentName)
    : id(++lastId), userId(userId), contentId(contentId), contentName(contentName) {}

void History::addToHistory(int userId, int contentId, const std::string& contentName) {
    allHistory.emplace_back(userId, contentId, contentName);
    saveAll();
}

void History::deleteHistory(int userId, int contentId) {
    allHistory.erase(std::remove_if(allHistory.begin(), allHistory.end(),
        [userId, contentId](const History& history) {
            return history.userId == userId && history.contentId == contentId;
        }), allHistory.end());
    saveAll();
    std::cout << "History entry deleted successfully!\n";
}

void History::loadAll() {
    std::ifstream file("data/history.txt");
    if (!file) return;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string idStr, userIdStr, contentIdStr, contentName;

        if (!std::getline(iss, idStr, '|') ||
            !std::getline(iss, userIdStr, '|') ||
            !std::getline(iss, contentIdStr, '|') ||
            !std::getline(iss, contentName, '|')) {
            std::cerr << "Error: Invalid history entry format: " << line << "\n";
            continue;
        }

        try {
            History history(std::stoi(userIdStr), std::stoi(contentIdStr), contentName);
            history.id = std::stoi(idStr);
            if (history.id > lastId) lastId = history.id;
            allHistory.push_back(history);
        }
        catch (...) {
            std::cerr << "Error: Invalid history data: " << line << "\n";
        }
    }
}

void History::saveAll() {
    std::ofstream file("data/history.txt");
    if (!file) {
        std::cerr << "Error: Could not save history data!\n";
        return;
    }
    for (const auto& entry : allHistory) {
        file << entry.id << "|" << entry.userId << "|"
            << entry.contentId << "|" << entry.contentName << "\n";
    }
}

std::vector<History> History::getHistoryByUserId(int userId) {
    std::vector<History> userHistory;
    for (const auto& entry : allHistory) {
        if (entry.userId == userId) {
            userHistory.push_back(entry);
        }
    }
    return userHistory;
}