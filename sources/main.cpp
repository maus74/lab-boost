#include <iostream>

#include "BrokerResolver.h"

int main(int argc, char *argv[])
{
    boost::filesystem::path path = "/home/maus/homeworks/iu10/lab4/lab-04-boost-filesystem/tests/data";
    if (argc > 1) {
        path = argv[1];
    }

    BrokerResolver resolver{};
    resolver.resolve(path);

    std::cout << "FILES: \n";
    for (const BrokerFile &file: resolver.getFileCollection()) {
        std::cout << file.directoriesToString() << " " << file.filename << std::endl;
    }

    std::cout << "\nDATA: \n";
    for (const auto &pair: resolver.getDataCollection()) {
        std::cout << "broker:" << pair.first.broker
                  << " account:" << pair.first.account
                  << " files:" << pair.second.files
                  << " lastdate:" << pair.second.lastDate
                  << std::endl;
    }

    return 0;
}