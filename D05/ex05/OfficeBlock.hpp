#ifndef __OFFICE_BLOCK__
#define __OFFICE_BLOCK__
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

class OfficeBlock
{
  public:
    OfficeBlock();
    OfficeBlock(Intern &intern, Bureaucrat &signOfficer, Bureaucrat &execOfficer);
    ~OfficeBlock();
    void doBureaucracy(std::string name, std::string target);

    void setSigner(Bureaucrat &b);
    void setExecutor(Bureaucrat &b);
    void setIntern();

    Bureaucrat *getSigner();
    Bureaucrat *getExecutor();
    Intern *getIntern();

    class InvalidOfficeBlockException : public std::exception
    {
      public:
        virtual const char *what() const throw()
        {
            return ("office miss some people to work properly");
        }
    };

    class InternFault : public std::exception
    {
      public:
        virtual const char *what() const throw()
        {
            return ("intern doesn't know what you're talking about, again.");
        }
    };

  private:
    Intern *intern;
    Bureaucrat *signOfficer;
    Bureaucrat *execOfficer;
};

#endif
