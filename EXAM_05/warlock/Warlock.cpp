#include "Warlock.hpp"

Warlock::Warlock() {
};

Warlock::Warlock(std::string const name, std::string const title) {
    this->name = name;
    this->title = title;

    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
    std::cout << this->name << "My job here is done!" << std::endl;
}

Warlock::Warlock(const Warlock &obj) {
    *this = obj;
}

Warlock &Warlock::operator=(const Warlock &obj) {
    this->name = obj.name;
    this->title = obj.title;
    return (*this);
}

std::string const &Warlock::getName() const {
    return this->name;
}

std::string const &Warlock::getTitle() const {
    return this->title;
}

void Warlock::setTitle(std::string const &str) {
    this->title = str;
}

void Warlock::introduce() const {
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}