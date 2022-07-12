/*
** EPITECH PROJECT, 2022
** B-CCP-400-RUN-4-1-theplazza-team.bodzen
** File description:
** Parser
*/

#include "Parser.hpp"
#include "Utils.hpp"

void CheckLogFile(Parser *parser, Reception *reception, char *tmp)
{
    LogFile fl = LogFile();
    static std::mutex mtx;

    (void)reception;
    for (;;) {
        std::lock_guard<std::mutex> lock(mtx);
        std::size_t nb = fl.read("logs");
        std::string command = fl.getCommand("logs");

        if (command.find("next") != std::string::npos) {
            std::vector<std::string> tab = Utils::split(command, " ");

            reception->createKitchen(*parser, tab[0] + " " + tab[1], tmp);
            fl.clear("logs");
            fl.write("logs", std::to_string(parser->_kitchenIdx - 1) + " " + tab[1] + " " + tab[2] + " " + tab[3]);
        }
        if (nb >= parser->_kitchenIdx && parser->_kitchenIdx > 0) {
            std::vector<std::string> tab = Utils::split(command, " ");

            reception->createKitchen(*parser, tab[1] + " " + tab[2], tmp);
        }
    }
}

Parser::Parser()
{
}

Parser::~Parser()
{
}

static unsigned countWords(char const *str)
{
    bool state = false;
    unsigned wc = 0;

    while (*str) {
        if (*str == ' ' || *str == '\n' || *str == '\t')
            state = false;
        else if (state == false) {
            state = true;
            ++wc;
        }
        ++str;
    }
    return wc;
}

void Parser::ErrorHandling(std::string input)
{
    if (input.find("exit") != std::string::npos || input.find("status") != std::string::npos)
        return;
    std::size_t n = 0;
    for (int i = 0; input[i] != '\0'; i++)
        if (input[i] == 'x' && std::isdigit(input[i + 1]))
            n++;
    auto words = countWords(input.c_str());
    if (words % 3 != 0 || (n * 3) != words)
        throw std::invalid_argument("Excuse me, your command is incorrect...");
}

void Parser::Treatment(std::string input)
{
    static std::vector<std::string> typeObj = {{"regina"},{"margarita"},{"americana"},{"fantasia"}};
    static std::vector<std::string> sizeObj = {{"S"},{"M"},{"L"},{"XL"}, {"XXL"}};
    std::stringstream ss(input);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    std::vector<std::string> token(begin, end);

    for (size_t i = 0, j = 1; i != token.size() && j != token.size(); i += 3, j += 3) {
        for (auto &c: token[i]) c = tolower(c);
        for (auto &h: token[j]) h = toupper(h);
        for (char const &ch : token[j + 1]) {
            if (ch == 'x')
                continue;
            if (std::isdigit(ch) == 0)
                throw std::invalid_argument("Error: we expect a number!");
        }
        if (!(find(typeObj.begin(), typeObj.end(), token[i]) != typeObj.end()))
            throw std::invalid_argument("Sorry Sir, we don't have <" + token[i] + "> in our menu.");
        if (!(find(sizeObj.begin(), sizeObj.end(), token[j]) != sizeObj.end()))
            throw std::invalid_argument("Sorry Sir, we don't have <" + token[j] + "> size in our menu.");
    }
    this->Serialize(token);
}

void Parser::Serialize(std::vector<std::string> token)
{
    static std::map<std::string, std::string> typeObj = {
        {"regina", "1"},{"margarita", "2"}, {"americana", "4"}, {"fantasia", "8"}
    };
    static std::map<std::string, std::string> sizeObj ={
        {"S", "1"}, {"M", "2"}, {"L", "4"}, {"XL", "8"}, {"XXL", "16"}
    };
    for (size_t i = 0; i != token.size(); i += 3) {
        token[i + 2].erase(0, 1);
        this->_objSerialized += typeObj[token[i]] + sizeObj[token[i + 1]] + token[i + 2];
        this->_queue.push_back(this->_objSerialized);
        this->_objSerialized.clear();
    }
}

void Parser::attributionType(int type, int size)
{
    switch (type) {
        case Regina: switch(size) {
                        case S : this->_listCommand.insert(std::pair<std::string, std::string>("regina", "S")); break;
                        case M : this->_listCommand.insert(std::pair<std::string, std::string>("regina", "M")); break;
                        case L : this->_listCommand.insert(std::pair<std::string, std::string>("regina", "L")); break;
                        case XL: this->_listCommand.insert(std::pair<std::string, std::string>("regina", "XL")); break;
                    } break;
        case Margarita: switch(size) {
                        case S : this->_listCommand.insert(std::pair<std::string, std::string>("margarita", "S")); break;
                        case M : this->_listCommand.insert(std::pair<std::string, std::string>("margarita", "M")); break;
                        case L : this->_listCommand.insert(std::pair<std::string, std::string>("margarita", "L")); break;
                        case XL: this->_listCommand.insert(std::pair<std::string, std::string>("margarita", "XL")); break;
                    } break;
        case Americana: switch(size) {
                        case S : this->_listCommand.insert(std::pair<std::string, std::string>("americana", "S")); break;
                        case M : this->_listCommand.insert(std::pair<std::string, std::string>("americana", "M")); break;
                        case L : this->_listCommand.insert(std::pair<std::string, std::string>("americana", "L")); break;
                        case XL: this->_listCommand.insert(std::pair<std::string, std::string>("americana", "XL")); break;
                    } break;
        case Fantasia: switch(size) {
                        case S : this->_listCommand.insert(std::pair<std::string, std::string>("fantasia", "S")); break;
                        case M : this->_listCommand.insert(std::pair<std::string, std::string>("fantasia", "M")); break;
                        case L : this->_listCommand.insert(std::pair<std::string, std::string>("fantasia", "L")); break;
                        case XL: this->_listCommand.insert(std::pair<std::string, std::string>("fantasia", "XL")); break;
                    } break;
        default: break;
    }
}

void Parser::scanObject(size_t size)
{
    if (size == 3) {
        for (size_t i = 0; i < this->_objDeserialized.size() - 1; i += 2) {
            this->attributionType(this->_objDeserialized[i] - '0', this->_objDeserialized[i + 1] - '0');
            this->_objDeserialized.erase(0, 2);
            this->_numberOfPizzas.push_back(atoi(this->_objDeserialized.c_str()));
        }
    } else {
        if (this->_objDeserialized[1] == '1' && this->_objDeserialized[2] == '6') {
            switch (this->_objDeserialized[0] - '0') {
                case Regina   : this->_listCommand.insert(std::pair<std::string, std::string>("regina", "XXL")); break;
                case Margarita: this->_listCommand.insert(std::pair<std::string, std::string>("margarita", "XXL")); break;
                case Americana: this->_listCommand.insert(std::pair<std::string, std::string>("americana", "XXL")); break;
                case Fantasia : this->_listCommand.insert(std::pair<std::string, std::string>("fantasia", "XXL")); break;
                default: break;
            }
            this->_objDeserialized.erase(0, 3);
            this->_numberOfPizzas.push_back(atoi(this->_objDeserialized.c_str()));
        } else {
            this->attributionType(this->_objDeserialized[0] - '0', this->_objDeserialized[1] - '0');
            this->_objDeserialized.erase(0, 2);
            this->_numberOfPizzas.push_back(atoi(this->_objDeserialized.c_str()));
        }
    }
}

void Parser::Deserialize(std::string str)
{
    this->_objDeserialized = std::string(str.c_str());
    this->scanObject(_objDeserialized.size());
    this->_objDeserialized.clear();
}

void Parser::update(Reception *reception)
{
    std::string input;
    LogFile fl = LogFile();
    SharedMem mem = SharedMem();

    char *tmp = (char *)mem.setMemShared();
    strcpy(tmp, "");
    reception->createKitchen(*this, mem, tmp);
    this->_checkLogs = std::thread(CheckLogFile, this, std::ref(reception), tmp);
    while (std::getline(std::cin, input)) {
        try {
            if (input.size() == 0)
                continue;
            if (input.find("exit") != std::string::npos) {
                strcpy(tmp, "exit");
                exit(0);
            }
            if (input.find("status") != std::string::npos) {
                std::string str = "status 0 " + std::to_string(this->_kitchenIdx - 1);
                strcpy(tmp, str.c_str());
            } else {
                input.erase(std::remove(input.begin(), input.end(), ';'), input.end());
                this->ErrorHandling(input);
                this->Treatment(input);
                for (std::string &s : this->_queue) {
                    strcpy(tmp, s.c_str());
                    this->pop();
                    sleep(1);
                }
                input.clear();
            }
        } catch (std::invalid_argument &e) {
            std::cerr << e.what() << std::endl;
            input.clear();
            continue;
        }
    }
    this->_checkLogs.join();
}

void Parser::pop()
{
    if (!this->_queue.empty())
        this->_queue.pop_back();
}

std::vector<std::string> &Parser::getQueue()
{
    return this->_queue;
}

std::vector<std::string> Parser::getQueueR()
{
    std::vector<std::string> tmp;

    for (int i = this->_queue.size() - 1; i >= 0; i--) {
        tmp.push_back(this->_queue[i]);
    }
    return tmp;
}

void Parser::sendMessage(std::string const &msg)
{
    (void)msg;
    return;
}

void Parser::clear()
{
    if (!this->_queue.empty())
        this->_queue.clear();
}