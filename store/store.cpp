#include "store.h"

namespace store {

	void Player::ShowSpec() const
	{
		std::cout << getType() << std::endl;
		std::cout << "Name: " << getName() << std::endl;
		product::Player::ShowSpec();
		std::cout << "Price: " << getPrice() << std::endl;
	}

	void Smartphone::ShowSpec() const
	{
		std::cout << getType() << std::endl;
		std::cout << "Name: " << getName() << std::endl;
		product::Smartphone::ShowSpec();
		std::cout << "Price: " << getPrice() << std::endl;
	}

	bool Smartphone::fwLoad(const uint8_t* fw, size_t fwSize)
	{
		if (fwSize >= fwMaxSize_) {
			return false;
		}

		fwSize_ = fwSize;
		memcpy(firmware_, fw, fwSize_);

		return true;
	}

	void Smartphone::fwShow() {
		for (size_t i = 0; i < fwSize_; ++i) {
			std::cout << std::hex << static_cast<uint32_t>(firmware_[i]);
		}
		std::cout << std::endl;
	}

	void VacuumCleaner::ShowSpec() const
	{
		std::cout << getType() << std::endl;
		std::cout << "Name: " << getName() << std::endl;
		product::VacuumCleaner::ShowSpec();
		std::cout << "Price: " << getPrice() << std::endl;
	}

	void WashingMachine::ShowSpec() const
	{
		std::cout << getType() << std::endl;
		std::cout << "Name: " << getName() << std::endl;
		product::WashingMachine::ShowSpec();
		std::cout << "Price: " << getPrice() << std::endl;
	}

	void Drone::ShowSpec() const
	{
		std::cout << getType() << std::endl;
		std::cout << "Name: " << getName() << std::endl;
		product::Drone::ShowSpec();
		std::cout << "Price: " << getPrice() << std::endl;
	}

}
