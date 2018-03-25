#include "../inc/logger.hpp"

Logger::Logger(std::string fileName) : logsPath(fs::current_path() / "logs" / fileName) {

    fs::path tempPath(fs::current_path() / "logs");
    if(!fs::is_directory(tempPath)){
        fs::create_directory(tempPath);
    }

    fs::ofstream out(logsPath, std::ios::out | std::ios::app);
    out << "Logger initiated \n\n";

}

bool Logger::setNewLogFile(std::string fileName){

    if(fileName.empty())
        return false;

    fs::path tempPath(fs::current_path() / "logs" / fileName);
    logsPath = tempPath;
    return true;

}

bool Logger::logToFile(std::string msg){

    if(msg.empty())
        return false;

    fs::ofstream out(logsPath, std::ios::out | std::ios::app);
    out << "Log message: " << msg << std::endl;
    return true;

}