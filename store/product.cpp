#include "product.h"

namespace product {

	Device::~Device() = default;

	void Device::ShowSpec() const
	{
		std::cout << "Battery Life: " << batteryLife_ << std::endl;
	}

	Appliences::~Appliences() = default;

	void Appliences::ShowSpec() const
	{
		std::cout << "Weight: " << weight_ << std::endl;
	}

	Player::~Player() = default;

	void Player::ShowSpec() const
	{
		Device::ShowSpec();
		std::cout << "Max tracks: " << maxTracks_ << std::endl;
	}

	Smartphone::~Smartphone() = default;

	void Smartphone::ShowSpec() const
	{
		Device::ShowSpec();
		std::cout << "OS: " << osName_ << std::endl;
	}

	VacuumCleaner::~VacuumCleaner() = default;

	void VacuumCleaner::ShowSpec() const
	{
		Appliences::ShowSpec();
		std::cout << "Volume: " << sakeVolume_ << std::endl
			<< "Power: " << maxPower_ << std::endl;
	}

	WashingMachine::~WashingMachine() = default;

	void WashingMachine::ShowSpec() const
	{
		Appliences::ShowSpec();
		std::cout << "Volume: " << volume_ << std::endl
			<< "Speed: " << maxSpeed_ << std::endl;
	}

	Drone::~Drone() = default;

	void Drone::ShowSpec() const
	{
		Device::ShowSpec();
		Appliences::ShowSpec();
		std::cout << "Distance: " << maxDistance_ << std::endl;
	}

}