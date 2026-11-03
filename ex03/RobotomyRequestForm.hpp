#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
        static int numOp;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();

        void executeFinal() const;

};
