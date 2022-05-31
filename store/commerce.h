#pragma once

#include <string>

namespace commerce {
	class Label
	{
	public:
		Label(const std::string& type, const std::string& name)
			: type_(type)
			, name_(name)
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

	private:
		std::string type_;
		std::string name_;
	};
}


