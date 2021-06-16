#include <cstdint>
#include <iostream>

int main()
{
    constexpr std::uint_fast8_t mask0{ 0b0000'0001 }; // represents bit 0
	constexpr std::uint_fast8_t mask1{ 0b0000'0010 }; // represents bit 1
	constexpr std::uint_fast8_t mask2{ 0b0000'0100 }; // represents bit 2 
	constexpr std::uint_fast8_t mask3{ 0b0000'1000 }; // represents bit 3
	constexpr std::uint_fast8_t mask4{ 0b0001'0000 }; // represents bit 4
	constexpr std::uint_fast8_t mask5{ 0b0010'0000 }; // represents bit 5
	constexpr std::uint_fast8_t mask6{ 0b0100'0000 }; // represents bit 6
	constexpr std::uint_fast8_t mask7{ 0b1000'0000 }; // represents bit 7
 
	std::uint_fast8_t flags{ 0b0000'0101 }; // 8 bits in size means room for 8 flags
 
    // testing if a bit is on or off
	std::cout << "bit 0 is " << ((flags & mask0) ? "on\n" : "off\n");
	std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n\n");

    // setting a bit (turn on)
    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n");
    flags |= mask1; // turn on bit 1
    std::cout << "bit 1 is " << ((flags & mask1) ? "on\n" : "off\n\n");

    

    return 0;
}