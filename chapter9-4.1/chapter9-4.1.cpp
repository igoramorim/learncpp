#include <iostream>

struct Advertising
{
    int adsShown{};
    double adsClickedPercentage{};
    double earnedByClick{};
    double earnedTotal{};
};

void printAdvertising(Advertising ad)
{
    std::cout << '\n';
    std::cout << "Ads Shown: " << ad.adsShown << '\n';
    std::cout << "Percentage of ads clicked: " << ad.adsClickedPercentage << '\n';
    std::cout << "Earned by each ad clicked: " << ad.earnedByClick << '\n';
    std::cout << "Earned total in a day: " << ad.earnedTotal << '\n';
}

Advertising calculateTotalEarnings(Advertising ad)
{
    ad.earnedTotal = (ad.adsShown * ad.adsClickedPercentage / 100 * ad.earnedByClick);
    return ad;
}

Advertising getAdvertising()
{
    Advertising ad{};

    std::cout << "How many ads were shown: ";
    std::cin >> ad.adsShown;

    std::cout << "What percentage of ads were clicked on by users: ";
    std::cin >> ad.adsClickedPercentage;

    std::cout << "How much you earned on average from each ad that was clicked: ";
    std::cin >> ad.earnedByClick;

    return ad;
}

int main()
{
    Advertising ad{ getAdvertising() };

    ad = calculateTotalEarnings(ad);

    printAdvertising(ad);

    return 0;
}

