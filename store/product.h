#pragma once

#include <iostream>

//
// Описание продукта
//

namespace product 
{
	class IElectronics
	{
	public:
		/*
		IElectronics() {
			std::cout << "IElectronics()" << std::endl;
		}
		virtual ~IElectronics() {
			std::cout << "~IElectronics()" << std::endl;
		}
		*/
		virtual ~IElectronics() = default;
	public:
		virtual void ShowSpec() const = 0;
	};

	class Device : virtual public IElectronics
	{
	public:
		Device(size_t batteryLife)
			: batteryLife_(batteryLife)
		{}
		virtual ~Device() = 0;
	public:
		virtual void ShowSpec() const override
		{
			std::cout << "Battery Life: " << batteryLife_ << std::endl;
		}

	private:
		size_t batteryLife_;
	};
	Device::~Device() = default;

	class Appliences : virtual public IElectronics
	{
	public:
		Appliences(size_t weight)
			: weight_(weight)
		{}
		virtual ~Appliences() = 0;
	public:
		virtual void ShowSpec() const override
		{
			std::cout << "Weight: " << weight_ << std::endl;
		}
	private:
		size_t weight_;
	};
	Appliences::~Appliences() = default;

	class Player : public Device
	{
	public:
		Player(size_t batteryLife, size_t maxTracks)
			: Device(batteryLife)
			, maxTracks_(maxTracks)
		{}
		virtual ~Player() = 0;
	public:
		virtual void ShowSpec() const override
		{
			Device::ShowSpec();
			std::cout << "Max tracks: " << maxTracks_ << std::endl;
		}
	private:
		size_t maxTracks_;
	};
	Player::~Player() = default;


	class Smartphone : public Device
	{
	public:
		Smartphone(size_t batteryLife, const std::string& osName)
			: Device(batteryLife)
			, osName_(osName)
		{}
		virtual ~Smartphone() = 0;
	public:
		virtual void ShowSpec() const override
		{
			Device::ShowSpec();
			std::cout << "OS: " << osName_ << std::endl;
		}
	private:
		std::string osName_;
	};
	Smartphone::~Smartphone() = default;

	class VacumCleaner : public Appliences
	{
	public:
		VacumCleaner(size_t weight, size_t sakeVolume, size_t maxPower)
			: Appliences(weight)
			, sakeVolume_(sakeVolume)
			, maxPower_(maxPower)
		{}
		virtual ~VacumCleaner() = 0;
	public:
		virtual void ShowSpec() const override
		{
			Appliences::ShowSpec();
			std::cout << "Volume: " << sakeVolume_  << std::endl
				<< "Power: " << maxPower_ << std::endl;
		}
	private:
		size_t sakeVolume_;
		size_t maxPower_;
	};
	VacumCleaner::~VacumCleaner() = default;

	class WashingMachine : public Appliences
	{
	public:
		WashingMachine(size_t weight, size_t volume, size_t maxSpeed)
			: Appliences(weight)
			, volume_(volume)
			, maxSpeed_(maxSpeed)
		{}
		virtual ~WashingMachine() = 0;
	public:
		virtual void ShowSpec() const override
		{
			Appliences::ShowSpec();
			std::cout << "Volume: " << volume_ << std::endl
				<< "Speed: " << maxSpeed_  << std::endl;
		}
	private:
		size_t volume_;
		size_t maxSpeed_;
	};
	WashingMachine::~WashingMachine() = default;

	class Drone : public Device, public Appliences
	{
	public:
		Drone(size_t batteryLife, size_t weight, size_t maxDistance)
			: Device(batteryLife)
			, Appliences(weight)
			, maxDistance_(maxDistance)
		{}
		virtual ~Drone() = 0; 
	public:
		virtual void ShowSpec() const override
		{
			Device::ShowSpec();
			Appliences::ShowSpec();
			std::cout << "Distance: " << maxDistance_ << std::endl;
		}
	private:
		size_t maxDistance_;
	};
	Drone::~Drone() = default;
}

