#include <cstdint>
#include <exception>
#include <string>

class Bureaucrat : public std::exception
{
    private:
        std::string const name;
        uint8_t grade;
    public:
        Bureaucrat(std::string, uint8_t grade);
        uint8_t getGrade() const;
        uint8_t getName() const;
        void incrementGrade();
        void decrementGrade();
};