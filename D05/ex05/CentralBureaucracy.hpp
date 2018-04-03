#ifndef __CENTRAL_BUREAUCRACY__
#define __CENTRAL_BUREAUCRACY__

#include "OfficeBlock.hpp"

#define MAX_REQUESTER 100
#define OFFICES_NB 20

class CentralBureaucracy
{
  public:
    CentralBureaucracy();
    CentralBureaucracy(CentralBureaucracy &c);
    ~CentralBureaucracy();

    CentralBureaucracy &operator=(CentralBureaucracy &c);

    void feed(Bureaucrat &b);
    void queueUp(std::string name);
    void doBureaucracy();

    class CentralFullOfBureaucratException : public std::exception
    {
      public:
        virtual const char *what() const throw()
        {
            return ("Central is totally full of Bureaucrate and cannot take any more workers");
        }
    };

    class CentralFullPeopleException : public std::exception
    {
      public:
        virtual const char *what() const throw()
        {
            return ("Central is totally full of People waiting and cannot take anymore requester");
        }
    };

  private:
    void initQueue();
    std::string getRandomBureaucracyRequest();

    OfficeBlock offices[OFFICES_NB];
    std::string queue[MAX_REQUESTER];
};

#endif