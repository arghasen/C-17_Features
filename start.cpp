
#include <map>
#include <string>
#include <iostream>

using namespace std::string_literals;

struct address_t {
    std::string street;
    unsigned plz;
    std::string city;
};

int main() {

    std::map<std::string, address_t> address_book;

    const auto hans = "Hans Meister"s;
    const auto hans_address = address_t{"Maihofstrasse 49"s, 6000u, "Luzern"s};

    auto it = address_book.begin();
    auto inserted = false;

    std::tie(it, inserted)  = address_book.insert({hans, hans_address});

    std::cout << "inserted = " << inserted << std::endl;
    std::cout << "name = " << it->first << std::endl;
    std::cout << "address = " << it->second.street << ", "
              << it->second.plz << ", "
              << it->second.city << std::endl;

    it = address_book.find(hans);
    if (it != address_book.end()) {
        std::cout << hans << " is in address book living in " << it->second.city << std::endl;
    } else {
        std::cout << hans << " is not in address book\n";
    }

    const auto peter = "Peter Müller"s;
    it = address_book.find(peter);
    if (it != address_book.end()) {
        std::cout << peter << " is in address book living in " << it->second.city << std::endl;
    } else {
        std::cout << peter << " is not in address book\n";
    }

    const auto peter_address = address_t{"Langstrasse 49"s, 8000u, "Zürich"s};
    auto result = address_book.insert({peter, peter_address});

    if (result.second) {
        std::cout << "Inserted " << result.first->first << std::endl;;
    } else {
        std::cout << "Did not insert " << result.first->first << std::endl;;
    }

    result = address_book.insert({peter, peter_address});

    if (result.second) {
        std::cout << "Inserted " << result.first->first << std::endl;;
    } else {
        std::cout << "Did not insert " << result.first->first << std::endl;;
    }

    for(const auto& entry : address_book)
    {
        std::cout << "\n name = " << entry.first << std::endl;
        std::cout << " address = " << entry.second.street << ", "
                  << entry.second.plz << ", "
                  << entry.second.city << std::endl;
    }
}