#pragma once

#include <istream>

#include "product.h"
#include "commerce.h"

namespace store
{
	class Player final: public commerce::Label, public product::Player
	{
	public:
		Player(const std::string& name, size_t batteryLife, size_t maxTracks)
			: commerce::Label("Player", name)
			, product::Player(batteryLife, maxTracks)
		{}
	public:
		void ShowSpec() const final
		{
			std::cout << "Name: " << getName() << std::endl;
			product::Player::ShowSpec();
		}
	};

	class Smartphone final: public commerce::Label, public product::Smartphone
	{
	public:
		Smartphone(const std::string& name, size_t batteryLife, const std::string& osName, size_t fwMaxSize)
			: commerce::Label("Smartphone", name)
			, product::Smartphone(batteryLife, osName)
			, fwMaxSize_(fwMaxSize)
			, fwSize_(0)
			, firmware_(new uint8_t [fwMaxSize_])
		{}
		~Smartphone()
		{
			delete[] firmware_;
		}
	public:
		void ShowSpec() const final
		{
			std::cout << "Name: " << getName() << std::endl;
			product::Smartphone::ShowSpec();
		}
		bool fwLoad(const uint8_t* fw, size_t fwSize)
		{
			if (fwSize >= fwMaxSize_) {
				return false;
			}

			fwSize_ = fwSize;
			memcpy(firmware_, fw, fwSize_);

			return true;
		}
		void fwShow() {
			for (size_t i = 0; i < fwSize_; ++i) {
				std::cout << std::hex << static_cast<uint32_t>(firmware_[i]);
			}
			std::cout << std::endl;
		}
	private:
		size_t fwMaxSize_;
		size_t fwSize_;
		uint8_t* firmware_;
	};
	class VacumCleaner final: public commerce::Label, public product::VacumCleaner
	{
	public:
		VacumCleaner(const std::string& name, size_t weight, size_t sakeVolume, size_t maxPower)
			: commerce::Label("Vacum Cleaner", name)
			, product::VacumCleaner(weight, sakeVolume, maxPower)
		{}
	public:
		void ShowSpec() const final
		{
			std::cout << "Name: " << getName() << std::endl;
			product::VacumCleaner::ShowSpec();
		}
	};
	class WashingMachine final: public commerce::Label, public product::WashingMachine
	{
	public:
		WashingMachine(const std::string& name, size_t weight, size_t volume, size_t maxSpeed)
			: commerce::Label("Washing Machine", name)
			, product::WashingMachine(weight, volume, maxSpeed)
		{}
	public:
		void ShowSpec() const final
		{
			std::cout << "Name: " << getName() << std::endl;
			product::WashingMachine::ShowSpec();
		}
	};

	class Drone final: public commerce::Label, public product::Drone
	{
	public:
		Drone(const std::string& name, size_t batteryLife, size_t weight, size_t maxDistance)
			: commerce::Label("Drone", name)
			, product::Drone(batteryLife, weight, maxDistance)
		{}
	public:
		void ShowSpec() const final
		{
			std::cout << "Name: " << getName() << std::endl;
			product::Drone::ShowSpec();
		}
	};


}

