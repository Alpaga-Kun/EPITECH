/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** LogFile
*/

#include "LogFile.hpp"
#include <fstream>
#include <iostream>

LogFile::LogFile()
{
}

LogFile::~LogFile()
{
}

void LogFile::write(std::string const &filename, std::string const &content)
{
    std::ofstream file (filename, std::ofstream::app);

    if (!file)
        return;
    file << content << "\n";
    file.close();
}

std::size_t LogFile::read(std::string const &filename)
{
    std::ifstream file (filename, std::ifstream::out);
    std::size_t line = 0;
    std::string buffer = "";

    if (!file.is_open())
        return -1;
    while (std::getline(file, buffer)) {
        if (buffer != "\n")
            line++;
    }
    file.close();
    return line;
}

void LogFile::clear(std::string const &filename)
{
    std::ofstream file(filename);

    if (!file.is_open())
        return;
    file.close();
}

std::size_t LogFile::getOccurence(std::string const &filename, std::string const &occurence)
{
    std::ifstream file (filename, std::ifstream::out);
    std::size_t occur = 0;
    std::string buffer = "";

    if (!file.is_open())
        return -1;
    while (std::getline(file, buffer)) {
        if (buffer.find(occurence) != std::string::npos)
            occur++;
    }
    file.close();
    return occur;
}

std::string LogFile::getCommand(std::string const &filename)
{
    std::ifstream file (filename, std::ifstream::out);
    std::string buffer = "";

    if (!file.is_open())
        return nullptr;
    while (std::getline(file, buffer))
        break;
    file.close();
    return buffer;
}