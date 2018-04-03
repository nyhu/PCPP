#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy() {
    initQueue();
	srand(std::time(NULL));
    
}
CentralBureaucracy::CentralBureaucracy(CentralBureaucracy &c)
{
    initQueue();
	srand(std::time(NULL));    
    *this = c;
}
CentralBureaucracy::~CentralBureaucracy()
{
}
void CentralBureaucracy::initQueue()
{
    for (int i = 0; i < MAX_REQUESTER; i++)
        queue[i] = "";
}

CentralBureaucracy &CentralBureaucracy::operator=(CentralBureaucracy &b)
{
    for (int i = 0; i < OFFICES_NB; i++) {
        offices[i].setExecutor(*b.offices[i].getExecutor());
        offices[i].setSigner(*b.offices[i].getSigner());
    }
    for (int i = 0; i < MAX_REQUESTER; i++)
    {
        queue[i] = b.queue[i];
    }
    return *this;
}

void CentralBureaucracy::feed(Bureaucrat &b)
{
    for (int i = 0; i < OFFICES_NB; i++)
    {
        if (!offices[i].getIntern())
            offices[i].setIntern();
        if (!offices[i].getSigner())
        {
            offices[i].setSigner(b);
            return;
        }
        if (!offices[i].getExecutor())
        {
            offices[i].setExecutor(b);
            return;
        }
    }
    throw CentralFullOfBureaucratException();
}

void CentralBureaucracy::queueUp(std::string name)
{
    for (int i = 0; i < MAX_REQUESTER; i++)
    {
        if (queue[i] == "")
        {
            queue[i] = name;
            return;
        }
    }
    throw CentralFullPeopleException();
}

void CentralBureaucracy::doBureaucracy()
{
    for (int i = 0; i < MAX_REQUESTER; i++)
    {
        if (queue[i] == "")
            return;
        for (int j = 0; j < OFFICES_NB; j++)
        {
            try
            {
                offices[i].doBureaucracy(getRandomBureaucracyRequest(), queue[i]);
            }
            catch (std::exception &e)
            {
                std::cout << "Central Bureaucraty error while bureaucracyning: " << e.what() << std::endl;
                if (j == OFFICES_NB - 1)
                {
                    std::cout << queue[i] << " request to Central Bureaucraty could not be satisfied " << e.what() << std::endl;
                }
                else
                    continue;
            }
            break;
        }
        queue[i] = "";
    }
}

std::string CentralBureaucracy::getRandomBureaucracyRequest() {
    static const std::string possibilities [6] = {
        "robot",
        "president",
        "tree",
        "pipe",
        "pardon",
        "shrubbery"
    };
    return possibilities[rand()%6];
}