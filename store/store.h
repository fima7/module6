#pragma once

#include <istream>

#include "product.h"
#include "commerce.h"

// Описание товара
// Коммерческое и техническое описание продукта

namespace store
{

	class Player final: public commerce::Label, public product::Player
	{
	public:
		Player(const std::string& name, size_t batteryLife, size_t maxTracks, commerce::money_t price)
			: commerce::Label("Player", name, price)
			, product::Player(batteryLife, maxTracks)
		{}
	public:
		void ShowSpec() const final;
	};

	class Smartphone final: public commerce::Label, public product::Smartphone
	{
	public:
		Smartphone(const std::string& name, size_t batteryLife, const std::string& osName, size_t fwMaxSize, commerce::money_t price)
			: commerce::Label("Smartphone", name, price)
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
		void ShowSpec() const final;
		bool fwLoad(const uint8_t* fw, size_t fwSize);
		void fwShow();
	private:
		size_t fwMaxSize_;	// Максимальный размер памяти для ПО в байтах
		size_t fwSize_;		// Размер загруженного ПО в байтах
		uint8_t* firmware_;	// Исполняемый код ПО
	};

	class VacuumCleaner final: public commerce::Label, public product::VacuumCleaner
	{
	public:
		VacuumCleaner(const std::string& name, size_t weight, size_t sakeVolume, size_t maxPower, commerce::money_t price)
			: commerce::Label("Vacum Cleaner", name, price)
			, product::VacuumCleaner(weight, sakeVolume, maxPower)
		{}
	public:
		void ShowSpec() const final;
	};

	class WashingMachine final: public commerce::Label, public product::WashingMachine
	{
	public:
		WashingMachine(const std::string& name, size_t weight, size_t volume, size_t maxSpeed, commerce::money_t price)
			: commerce::Label("Washing Machine", name, price)
			, product::WashingMachine(weight, volume, maxSpeed)
		{}
	public:
		void ShowSpec() const final;
	};

	class Drone final: public commerce::Label, public product::Drone
	{
	public:
		Drone(const std::string& name, size_t batteryLife, size_t weight, size_t maxDistance, commerce::money_t price)
			: commerce::Label("Drone", name, price)
			, product::Drone(batteryLife, weight, maxDistance)
		{}
	public:
		void ShowSpec() const final;
	};

}

