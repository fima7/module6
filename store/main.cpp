#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <random>

#include "store.h"

//
// В магазин добавляються и убираються описания товаров, так же может быть продемострирована витрина.
// 1. Описанием товара являеться коммерческое и техническое описание изделия, store.h, store.cpp 
// 2. Комерческое описание изделия содержит название, тип изделия и его стоимость, commerce.h
// 3. Техническим описанием изделия является техническое описание электронного устройства либо домашней электротехники,
//    а так же оно содержит спецификаю характерную для конкретного типа изделия, product.h, product.cpp
// 4. Техническое описание электронного устройства содержит спецификацию общую для всех электронных уствройств, 
//    с интерфейсом IElectronics
// 5. Техническое описание домашней электротехники содержит спецификацию общую для всех изделий домашней электротехники,
//    с интерфейсом IElectronics
//


// Описание магазина
// Внимание, магазин являеться владельцем товаров 
// удалает добавленные продукты самостоятельно
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
	// Добавление товара 
	bool AddProduct(product::IElectronics* electronics)
	{
		if (nproducts_ >= maxProducts_) {
			return false;
		}

		products_[nproducts_++] = electronics;

		return true;
	}

	// Удаление товара 
	void rmProduct(size_t index)
	{
		if (index >= nproducts_) {
			return;
		}
		if (products_[index]) {
			delete products_[index];
			products_[index] = products_[nproducts_ - 1];
			products_[nproducts_ - 1] = nullptr;
		}
	}

	// Удаление всех товаров
	void cleanProducts()
	{
		for (size_t i = 0; i < nproducts_; ++i) {
			if (products_[i]) {
				delete products_[i];
			}
		}
		nproducts_ = 0;
	}

	// Количество добавленных товаров
	size_t nproducts() const
	{
		return nproducts_;
	}

	// Доступ к продукту
	const product::IElectronics* getItem(size_t index) const
	{
		if (index < nproducts_) {
			return products_[index];
		}

		return nullptr;
	}

	// Демонстрация витрины
	void ShowProducts()
	{
		using namespace std;

		// Отчёт в форме
		//  Телефоны 
		//   Galaxy   5 штук
		//   Huawey   10 штук
		map<string, map<string, size_t>> report;

		for (size_t i = 0; i < nproducts_; ++i) {
			commerce::Label* label = dynamic_cast<commerce::Label*>(products_[i]);
			++report[label->getType()][label->getName()];
		}

		size_t totalProducts = 0;
		// for (const auto& [type, names] : report) { // Если можно C++17 то лучше вот так
		for (const auto& item : report) {
			const auto& type = item.first;
			const auto& names = item.second;
			cout << type << endl;
			size_t total = 0;
			// for (const auto& [name, n] : names) {
			for (const auto& nm : names) {
				const auto& name = nm.first;
				auto n = nm.second;
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

// Привер работы с магазином
int main()
{
	setlocale(LC_ALL, "");

	Store store(150);

	// Добавляем продукты в магазин
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
		store.AddProduct(new store::VacuumCleaner("Фиолент", 5, 1000, 1500, 500));
	}

	for (size_t i = 0; i < 5; ++i) {
		store.AddProduct(new store::VacuumCleaner("Дастпром", 5, 1000, 1500, 500));
	}

	for (size_t i = 0; i < 5; ++i) {
		store.AddProduct(new store::VacuumCleaner("Умница", 5, 1000, 1500, 500));
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

	// Показываем витрину
	store.ShowProducts();

	// Случайный запрос на спецификацию продукта и цену
	std::srand(static_cast<unsigned int>(time(NULL)));

	std::cout << "Item specifications" << std::endl;

	const product::IElectronics* item = store.getItem(std::rand() % store.nproducts());
	item->ShowSpec();

}