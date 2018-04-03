#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock() : intern(NULL), signOfficer(NULL), execOfficer(NULL) {}
OfficeBlock::OfficeBlock(Intern &i, Bureaucrat &signOfficer, Bureaucrat &execOfficer)
    : intern(&i), signOfficer(&signOfficer), execOfficer(&execOfficer) {}
OfficeBlock::~OfficeBlock(){}

void OfficeBlock::setExecutor(Bureaucrat &b)
{
    execOfficer = &b;
}
void OfficeBlock::setSigner(Bureaucrat &b)
{
    signOfficer = &b;
}
void OfficeBlock::setIntern(Intern &i)
{
    intern = &i;
}

void OfficeBlock::doBureaucracy(std::string name, std::string target)
{
    Form *f;
    if (!intern || !signOfficer || !execOfficer)
        throw OfficeBlock::InvalidOfficeBlockException();
    f = intern->makeForm(name, target);
    if (!f)
        throw OfficeBlock::InternFault();
    f->beSigned(*signOfficer);
    f->execute(*signOfficer);
}
