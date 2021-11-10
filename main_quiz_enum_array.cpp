#include <iostream>
#include <array>
#include <numeric> // std::reduce

// As we want to use Item to idex an array, use enum rather than enum class
enum Item
{
	item_healthPotion, // 0
	item_torche,       // 1
	item_arrow,        // 2
	max_items          // 3
};

unsigned int countTotalItems(const std::array<int, Item::max_items>& items)
{
	return std::reduce(items.begin(), items.end());
}

int main()
{
	std::array inventory = { 2, 5, 10 };
	std::cout << "Player has " << countTotalItems(inventory) << " item(s) in total" << std::endl;
	std::cout << "Payer has " << inventory[Item::item_torche] << " torch(es)" << std::endl;

	return 0;
}