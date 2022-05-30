#include <iostream>
#include <string>

namespace product 
{
	class IElectronics
	{
	public:
		IElectronics() {
			std::cout << "IElectronics()" << std::endl;
		}
		virtual ~IElectronics() {
			std::cout << "~IElectronics()" << std::endl;
		}
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

	class Accessories : virtual public IElectronics
	{
	public:
		Accessories(IElectronics& compatible)
			: compatible_(compatible)
		{}
		virtual ~Accessories() = default;
	private:
		const IElectronics& compatible_;
	};

	class Player : public Device
	{
	public:
		Player(size_t batteryLife, size_t maxTracks)
			: Device(batteryLife)
			, maxTracks_(maxTracks)
		{}
	public:
		virtual void ShowSpec() const override
		{
			Device::ShowSpec();
			std::cout << "Max tracks: " << maxTracks_ << std::endl;
		}
	private:
		size_t maxTracks_;
	};

	class Smartphone : public Device
	{
	public:
		Smartphone(size_t batteryLife, const std::string& osName)
			: Device(batteryLife)
			, osName_(osName)
		{}
		virtual ~Smartphone() = default;
	public:
		virtual void ShowSpec() const override
		{
			Device::ShowSpec();
			std::cout << "OS: " << osName_ << std::endl;
		}
	private:
		std::string osName_;
	};

	class VacumCleaner : public Appliences
	{
	public:
		VacumCleaner(size_t weight, size_t sakeVolume, size_t maxPower)
			: Appliences(weight)
			, sakeVolume_(sakeVolume)
			, maxPower_(maxPower)
		{}
		virtual ~VacumCleaner() = default;
	public:
		virtual void ShowSpec() const override
		{
			Appliences::ShowSpec();
			std::cout << "Volume: " << sakeVolume_ 
				<< "Power: " << maxPower_
				<< std::endl;
		}
	private:
		size_t sakeVolume_;
		size_t maxPower_;
	};

	class WashingMachine : public Appliences
	{
	public:
		WashingMachine(size_t weight, size_t volume, size_t maxSpeed)
			: Appliences(weight)
			, volume_(volume)
			, maxSpeed_(maxSpeed)
		{}
		virtual ~WashingMachine() = default;
	public:
		virtual void ShowSpec() const override
		{
			Appliences::ShowSpec();
			std::cout << "Volume: " << volume_ 
				<< "Speed: " << maxSpeed_ 
				<< std::endl;
		}
	private:
		size_t volume_;
		size_t maxSpeed_;
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

namespace commerce {
	class Label
	{
	public:
		Label(const std::string& name)
			: name_(name)
		{}
	public:
		std::string getName() const
		{
			return name_;
		}
		std::string setName(const std::string& name)
		{
			name_ = name;
		}
	private:
		std::string name_;
	};
}

namespace store
{
	class Player final: public commerce::Label, public product::Player
	{
	public:
		Player(const std::string& name, size_t batteryLife, size_t maxTracks)
			: commerce::Label(name)
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
			: commerce::Label(name)
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
			: commerce::Label(name)
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
			: commerce::Label(name)
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
			: commerce::Label(name)
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

int main()
{
	/*
	store::Player walkman("Walkman", 10, 15);
	walkman.ShowSpec();
	*/

	// store::Drone drone("Drone name", 10, 15, 100);
	store::Smartphone GalaxyA10("Galaxy A10", 10, "Android", 1024);
	const uint8_t fw[]{0xB, 0xA, 0xB, 0xE, 0xF, 0xA, 0xC, 0xE};
	GalaxyA10.fwLoad(fw, 8);
	GalaxyA10.fwShow();


	
	
	
}