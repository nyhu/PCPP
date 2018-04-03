#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "OfficeBlock.hpp"

int main(void)
{
	{
		Intern idiotOne;
		Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
		Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
		OfficeBlock ob;
		ob.setIntern(idiotOne);
		ob.setSigner(bob);
		ob.setExecutor(hermes);
		try
		{
			ob.doBureaucracy("mutant pig termination", "Pigley");
		}
		catch (OfficeBlock::InvalidOfficeBlockException &e)
		{
			std::cout << "It's not a porchery here" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Error doing bureaucracy: " << e.what() << std::endl;
		}
	}
	{
		Intern i;
		Bureaucrat l("Leon", 149);
		Bureaucrat m("Macron", 1);

		OfficeBlock incomplete;
		OfficeBlock completeLow(i, l, l);
		OfficeBlock completeHigh(i, m, m);

		try
		{
			incomplete.doBureaucracy("robot", "olag");
		}
		catch (std::exception &e)
		{
			std::cout << "Error doing bureaucracy: " << e.what() << std::endl;
		}

		incomplete.setSigner(m);
		incomplete.setExecutor(m);
		incomplete.setIntern(i);
		incomplete.doBureaucracy("presidential", "olag");

		try
		{
			completeLow.doBureaucracy("robot", "olag");
		}
		catch (std::exception &e)
		{
			std::cout << "Error doing bureaucracy: " << e.what() << std::endl;
		}

		try
		{
			completeHigh.doBureaucracy("robot", "olag");
			completeHigh.doBureaucracy("tree", "adam");
			completeHigh.doBureaucracy("president", "osef");
			completeHigh.doBureaucracy("unkown", "jojo");
		}
		catch (OfficeBlock::InternFault &e)
		{
			std::cout << "Error doing bureaucracy: " << e.what()
					  << " But he deserve a royal pardon" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Error doing bureaucracy: " << e.what() << std::endl;
		}
	}
	return 0;
}
