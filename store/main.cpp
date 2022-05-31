#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <random>

#include "store.h"

class Store final
{
public:
	Store(size_t maxProducts)
		: maxProducts_(maxProducts)
		, nproducts_(0)
		, products_(new product::IElectronics* [maxProducts_])
	{}
	~Store()
	{
		cleanProducts();
		delete[] products_;
	}
public:
	bool AddProduct(product::IElectronics* electronics)
	{
		if (nproducts_ >= maxProducts_) {
			return false;
		}

		products_[nproducts_++] = electronics;

		return true;
	}

	void rmProduct(size_t index)
	{
		if (index >= nproducts_) {
			return;
		}
		delete products_[index];
		products_[index] = products_[nproducts_ - 1];
		products_[nproducts_ - 1] = nullptr;
	}

	void cleanProducts()
	{
		for (size_t i = 0; i < nproducts_; ++i) {
			delete products_[i];
		}
		nproducts_ = 0;
	}

	size_t nproducts() const
	{
		return nproducts_;
	}

	const product::IElectronics* getItem(size_t index) const
	{
		if (index < nproducts_) {
			return products_[index];
		}

		return nullptr;
	}

	void ShowProducts()
	{
		using namespace std;

		map<string, map<string, size_t>> report;

		for (size_t i = 0; i < nproducts_; ++i) {
			commerce::Label* label = dynamic_cast<commerce::Label*>(products_[i]);
			++report[label->getType()][label->getName()];
		}


		size_t totalProducts = 0;
		for (const auto& [type, names] : report) {
			cout << type << endl;
			size_t total = 0;
			for (const auto& [name, n] : names) {
				std::cout << " " <<name << ": " << n << std::endl;
				total += n;
			}
			std::cout << " Total: " << total << std::endl;
			totalProducts += total;
		}

		std::cout << "Total: " << totalProducts << std::endl;
	}

private:
	size_t maxProducts_;
	size_t nproducts_;
	product::IElectronics** products_;
};

int main()
{
	setlocale(LC_ALL, "");

	Store store(150);

	for (size_t i = 0; i < 5; ++i) {
		store.AddProduct(new store::Player("Walkman", 500, 15, 500));
	}

	for (size_t i = 0; i < 5; ++i) {
		store.AddProduct(new store::Player("Xiamoi", 1500, 1000, 500));
	}

	for (size_t i = 0; i < 5; ++i) {
		store.AddProduct(new store::Smartphone("Galaxy", 1500, "Android", 1024, 500));
	}

	for (size_t i = 0; i < 5; ++i) {
		store.AddProduct(new store::Smartphone("Huawey", 2000, "Android", 1024, 500));
	}

	for (size_t i = 0; i < 5; ++i) {
		store.AddProduct(new store::VacumCleaner("Фиолент", 5, 1000, 1500, 500));
	}

	for (size_t i = 0; i < 5; ++i) {
		store.AddProduct(new store::VacumCleaner("Дастпром", 5, 1000, 1500, 500));
	}

	for (size_t i = 0; i < 5; ++i) {
		store.AddProduct(new store::VacumCleaner("Умница", 5, 1000, 1500, 500));
	}


	for (size_t i = 0; i < 5; ++i) {
		store.AddProduct(new store::WashingMachine("Атлант", 5, 1000, 1500, 500));
	}

	for (size_t i = 0; i < 5; ++i) {
		store.AddProduct(new store::WashingMachine("Вятка", 5, 1000, 1500, 500));
	}

	for (size_t i = 0; i < 5; ++i) {
		store.AddProduct(new store::Drone("MJX", 1500, 1, 1500, 500));
	}

	for (size_t i = 0; i < 5; ++i) {
		store.AddProduct(new store::Drone("R16", 1500, 1, 1500, 500));
	}


	store.ShowProducts();

	std::srand(time(NULL));
	std::cout << "Item specifications" << std::endl;
	const product::IElectronics* item = store.getItem(std::rand() % store.nproducts());
	item->ShowSpec();
	
	
}