#include "AsteroKreog.hpp"

AsteroBocal::AsteroBocal(void)
	: name("AsteroBocal")
{
}

AsteroBocal::AsteroBocal(AsteroBocal const &src)
	: name(src.getName())
{
}

AsteroBocal::~AsteroBocal()
{
}

AsteroBocal &AsteroBocal::operator=(AsteroBocal const &rhs)
{
	this->name = rhs.getName();
	return *this;
}

std::string AsteroBocal::getName() const
{
	return this->name;
}

std::string AsteroBocal::beMined(DeepCoreMiner *) const
{
	return "Thorite";
}

std::string AsteroBocal::beMined(StripMiner *) const
{
	return "Flavium";
}
