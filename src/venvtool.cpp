#include <iostream>
#include <fstream>
#include <iomanip>
#include <filesystem>
#include <string>
#include "venvtool.hpp"

VenvTool::VenvTool(std::string venvPath) {
    venvPath_ = venvPath;
}

VenvTool::~VenvTool() {}

void VenvTool::venvCreate(std::string venvName) {
    std::string createCMD = "python3 -m venv ";
    createCMD += (venvPath_ + "/" + venvName);
    std::system(createCMD.c_str());
}


void VenvTool::venvList() {
    std::cout << "# Python venvs:" << std::endl;
    std::cout << "#" << std::endl;

    // creat venv path if it not exist
    if (!std::filesystem::exists(venvPath_)) {
        std::filesystem::create_directory(venvPath_);
    }

    for (auto const& entry : std::filesystem::directory_iterator(venvPath_))
    {
        // print venv name and path
        std::cout << std::setw(24) << std::left << entry.path().filename()\
                    << entry.path() << std::endl;
    }
    std::cout << std::endl;
}

void VenvTool::venvActivate(std::string venvName) {
    #if defined(_WIN32) || defined(__MINGW32__)
    std::string activatePath = venvPath_ + "/" + venvName + "/Scripts/Activate.ps1";
    #else
    std::string activatePath = venvPath_ + "/" + venvName + "/bin/activate";
    #endif

    std::cout << activatePath << std::endl;
}

void VenvTool::venvDeactive() {
    std::system("deactivate");
}

void VenvTool::venvRemove(std::string venvName) {
    std::filesystem::path venvPathToBeRemoved(venvPath_ + "/" + venvName);
    std::filesystem::remove_all(venvPathToBeRemoved);
}
