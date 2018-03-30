#include "KoalaSteroid.hpp"

BocalSteroid::BocalSteroid(void)
	: name("BocalSteroid")
{
}

BocalSteroid::BocalSteroid(BocalSteroid const &src)
	: name(src.getName())
{
}

BocalSteroid::~BocalSteroid()
{
}

BocalSteroid &BocalSteroid::operator=(BocalSteroid const &rhs)
{
	this->name = rhs.getName();
	return *this;
}

std::string BocalSteroid::getName() const
{
	return this->name;
}

std::string BocalSteroid::beMined(DeepCoreMiner *) const
{
	return "Zazium";
}

std::string BocalSteroid::beMined(StripMiner *) const
{
	return "Krpite";
}
