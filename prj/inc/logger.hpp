#include <iostream>
#include <fstream>
#include <cstring>


class Logger{

        std::string logFileName;
        std::ofstream logFile;

    public:

        Logger(std::string fileName);

        bool setNewLogFile(std::string fileName);

        bool logToFile(std::string msg);

        bool logToConsole(std::string msg);

};