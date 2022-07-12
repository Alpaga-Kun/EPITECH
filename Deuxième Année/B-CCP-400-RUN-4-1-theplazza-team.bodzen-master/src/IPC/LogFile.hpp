/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** LogFile
*/

#pragma once
#include <string>

class LogFile {
    public:
        LogFile();
        ~LogFile();

        void write(std::string const &filename, std::string const &content);
        std::size_t read(std::string const &filename);
        void clear(std::string const &filename);
        std::size_t getOccurence(std::string const &filename, std::string const &occurence);
        std::string getCommand(std::string const &filename);

    protected:
    private:
};
