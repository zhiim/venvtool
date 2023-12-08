#include <iostream>
#include <iomanip>
#include <filesystem>
#include "venvtool.hpp"

VenvTool::VenvTool(std::string venvPath) {
    venvPath_ = venvPath;
}

VenvTool::~VenvTool() {}

void VenvTool::venvCreate(std::string venvName) {
    std::string createCMD = "python -m venv ";
    createCMD += (venvPath_ + "/" + venvName);
    std::system(createCMD.c_str());
}


void VenvTool::venvList() {
    std::cout << "# Python venvs:" << std::endl;
    std::cout << "#" << std::endl;

    std::filesystem::path venvRootPath(venvPath_);
    for (auto const& entry : std::filesystem::directory_iterator(venvRootPath))
    {
        // print venv name and path
        std::cout << std::setw(24) << std::left << entry.path().filename()\
                    << entry.path() << std::endl;
    }
}

void VenvTool::venvActivate(std::string venvName) {
    #if defined(_WIN32) || defined(__MINGW32__)
    std::string activateCMD = venvPath_ + "\\" + venvName + "\\Scripts\\activate";
    #else
    std::string activateCMD = "source " + venvPath_ + "/" + venvName +\
                            "/bin/activate";
    #endif

    std::cout << activateCMD << std::endl;
    std::system(activateCMD.c_str());
}

void VenvTool::venvDeactive() {
    std::system("deactivate");
}

void VenvTool::venvRemove(std::string venvName) {
    std::filesystem::path venvPathToBeRemoved(venvPath_ + "/" + venvName);
    std::filesystem::remove_all(venvPathToBeRemoved);
}
