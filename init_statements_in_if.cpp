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

    const auto& [it, inserted] = address_book.insert({hans, hans_address});
    const auto& [name, address] = *it;

    std::cout << "inserted = " << inserted << std::endl;
    std::cout << "name = " << name << std::endl;
    std::cout << "address = " << address.street << ", "
              << address.plz << ", "
              << address.city << std::endl;

    if (const auto it = address_book.find(hans); it != address_book.end()) {
        const auto& [name, address] = *it;
        std::cout << name << " is in address book living in " << address.city << std::endl;
    } else {
        std::cout << hans << " is not in address book\n";
    }
    const auto peter = "Peter Müller"s;

    if (const auto it = address_book.find(peter); it != address_book.end()) {
        const auto& [name, address] = *it;
        std::cout << name << " is in address book living in " << address.city << std::endl;
    } else {
        std::cout << peter << " is not in address book\n";
    }

    const auto peter_address = address_t{"Langstrasse 49"s, 8000u, "Zürich"s};

    if (const auto& [it, inserted] = address_book.insert({peter, peter_address}); inserted) {
        std::cout << "Inserted " << it->first << std::endl;;
    } else {
        std::cout << "Did not insert " << it->first << std::endl;;
    }

    if (const auto& [it, inserted] = address_book.insert({peter, peter_address}); inserted) {
        std::cout << "Inserted " << it->first << std::endl;;
    } else {
        std::cout << "Did not insert " << it->first << std::endl;;
    }

    for(const auto& [name, address] : address_book)
    {
        std::cout << "\n name = " << name << std::endl;
        std::cout << " address = " << address.street << ", "
                  << address.plz << ", "
                  << address.city << std::endl;
    }
}