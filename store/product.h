#pragma once

#include <iostream>

//
// ����������� �������� ��������
//

// IELectronics
//	Device
//		Player, Smartphone
//	Appliences
//		VacuumCleaner, Washing Machine
//	Device, Appliences
//		Drone

namespace product 
{
	//
	// ��������� ���������
	//

	class IElectronics
	{
	public:
		virtual ~IElectronics() = default;
	public:
		virtual void ShowSpec() const = 0;
	};

	// ��������������� ������������
	class Device : virtual public IElectronics
	{
	public:
		Device(size_t batteryLife)
			: batteryLife_(batteryLife)
		{}
		virtual ~Device() = 0;
	public:
		virtual void ShowSpec() const override;
	private:
		size_t batteryLife_; // �� ������� ������� ������������ � �������
	};

	// �������� ��������������
	class Appliences : virtual public IElectronics
	{
	public:
		Appliences(size_t weight)
			: weight_(weight)
		{}
		virtual ~Appliences() = 0;
	public:
		virtual void ShowSpec() const override;
	private:
		size_t weight_; // ��� � �������
	};


	//
	// �������� ��������������� ������������ � �������� ��������������
	//

	class Player : public Device
	{
	public:
		Player(size_t batteryLife, size_t maxTracks)
			: Device(batteryLife)
			, maxTracks_(maxTracks)
		{}
		virtual ~Player() = 0;
	public:
		virtual void ShowSpec() const override;
	private:
		size_t maxTracks_; // ������������ ���������� ������������
	};

	class Smartphone : public Device
	{
	public:
		Smartphone(size_t batteryLife, const std::string& osName)
			: Device(batteryLife)
			, osName_(osName)
		{}
		virtual ~Smartphone() = 0;
	public:
		virtual void ShowSpec() const override;
	private:
		std::string osName_; // �������� ��
	};

	class VacuumCleaner : public Appliences
	{
	public:
		VacuumCleaner(size_t weight, size_t sakeVolume, size_t maxPower)
			: Appliences(weight)
			, sakeVolume_(sakeVolume)
			, maxPower_(maxPower)
		{}
		virtual ~VacuumCleaner() = 0;
	public:
		virtual void ShowSpec() const override;
	private:
		size_t sakeVolume_; // ����� ����� ��� ���� � ���������� �����������
		size_t maxPower_;	// ��������
	};

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
		virtual void ShowSpec() const override;
	private:
		size_t volume_;		// ����� ����
		size_t maxSpeed_;	// �������� � �������� � ������
	};

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
		virtual void ShowSpec() const override;
	private:
		size_t maxDistance_;	// ������������ ��������� ����� � ������
	};

}

