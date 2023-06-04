#include "../Headers/Logs.h"

void logError(const std::string& errorMessage) {
    std::ofstream logfile;
    logfile.open("error.log", std::ios::app | std::ios::out);
    if (logfile.is_open()) {
        std::time_t currentTime = std::time(nullptr);
        std::string timestamp = std::asctime(std::localtime(&currentTime));
        timestamp = timestamp.substr(0, timestamp.length() - 1);

        logfile << "[" << timestamp << "] " << errorMessage << std::endl;

        logfile.close();
    }
}

