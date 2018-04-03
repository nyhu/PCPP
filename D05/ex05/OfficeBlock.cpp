#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() : intern(NULL), signOfficer(NULL), execOfficer(NULL) {}
OfficeBlock::OfficeBlock(Intern &i, Bureaucrat &signOfficer, Bureaucrat &execOfficer)
    : intern(&i), signOfficer(&signOfficer), execOfficer(&execOfficer) {}
OfficeBlock::~OfficeBlock() {
    if (signOfficer)
        delete signOfficer;
    if (intern)
        delete intern;
    if (execOfficer)
        delete execOfficer;
}

void OfficeBlock::setExecutor(Bureaucrat &b)
{
    execOfficer = new Bureaucrat(b);
}
void OfficeBlock::setSigner(Bureaucrat &b)
{
    signOfficer = new Bureaucrat(b);
}
void OfficeBlock::setIntern()
{
    intern = new Intern();
}

Bureaucrat *OfficeBlock::getSigner()
{
    return signOfficer;
}
Bureaucrat *OfficeBlock::getExecutor()
{
    return execOfficer;
}
Intern *OfficeBlock::getIntern()
{
    return intern;
}

void OfficeBlock::doBureaucracy(std::string name, std::string target)
{
    Form *f;
    if (!intern || !signOfficer || !execOfficer)
        throw OfficeBlock::InvalidOfficeBlockException();
    f = intern->makeForm(name, target);
    if (!f)
        throw OfficeBlock::InternFault();
    try
    {
        f->beSigned(*signOfficer);
        f->execute(*signOfficer);
    }
    catch (std::exception &e)
    {
        delete f;
        throw e;
    }
    delete f;
}
