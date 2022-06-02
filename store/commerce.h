#pragma once

#include <string>

//
// ������������ �������� ��������
//

namespace commerce {

	using money_t = size_t;

	class Label
	{
	public:
		Label(const std::string& type, const std::string& name, money_t price)
			: type_(type)
			, name_(name)
			, price_(price)
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
		std::string getType() const
		{
			return type_;
		}
		std::string setType(const std::string& type)
		{
			type_ = type;
		}
		money_t getPrice() const
		{
			return price_;
		}
		void setPrice(money_t price)
		{
			price_ = price;
		}
	private:
		std::string type_;	// ��������, �������������, ������� � �.�.
		std::string name_;	// �������� ������
		money_t price_;		// ����		
	};

}


