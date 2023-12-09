#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include "cxxopts.hpp"
#include "venvtool.hpp"

// path of venv dictory
#if defined(_WIN32) || defined(__MINGW32__)
std::string venvPathDefault = std::string(std::getenv("LOCALAPPDATA")) + "/venvtool";
#else
std::string venvPathDefault = std::string(std::getenv("HOME")) + "/.venvtool";
#endif

// path of venvtool
#if defined(_WIN32) || defined(__MINGW32__)
std::string venvtoolPath = std::string(std::getenv("appdata")) + "/venvtool";
#else
std::string venvtoolPath = std::string(std::getenv("HOME")) + "/.local/bin/venvtool";
#endif

std::string getVenvPath() {
    std::string venvPath;
    
    // if already initiated, there will be conf file
    // so read venv path from conf file
    if (std::filesystem::exists(venvtoolPath + "/.conf")) {
        std::ifstream confFile(venvtoolPath + "/.conf");
        std::getline(confFile, venvPath);
    // else use the default path
    } else {
        venvPath = venvPathDefault;
        // init whith default path
        VenvTool::venvInit(venvPath);
    }

    return venvPath;
}

int main(int argc, char** argv) {
    cxxopts::Options options("venvtool", "a tool to manage venvs like conda");

    // set options
    options.add_options()
        ("h, help", "Print usage")
        ("i, init",
         "initiate venvtool with a path where all venvs will be stored",
         cxxopts::value<std::string>())
        ("l, list", "List all existing venvs")
        ("c, create", "Create a new venv", cxxopts::value<std::string>())
        ("r, remove", "Remove an venv", cxxopts::value<std::string>())
        ("a, activate", "Activate an venv", cxxopts::value<std::string>())
        ("d, deactivate", "Deactivate an venv")
    ;

    // parse options
    auto result = options.parse(argc, argv);

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
    }

    // init venvtool, set root dir for venvs
    if (result.count("init")) {
        std::string venvPath = result["init"].as<std::string>();
        VenvTool::venvInit(venvPath);
    }
    
    if (result.count("create")) {
        std::string venvName = result["create"].as<std::string>();
        // read venvPath from conf file
        std::string venvPath = getVenvPath();
        
        VenvTool venvTool(venvPath);
        venvTool.venvCreate(venvName);
    }
    if (result.count("list")) {
        std::string venvPath = getVenvPath();
        
        VenvTool venvTool(venvPath);
        venvTool.venvList();
    }
    if (result.count("activate")) {
        std::string venvName = result["activate"].as<std::string>();
        std::string venvPath = getVenvPath();
        
        VenvTool venvTool(venvPath);
        venvTool.venvActivate(venvName);
    }
    if (result.count("deactivate")) {
        std::string venvPath = getVenvPath();
        
        VenvTool venvTool(venvPath);
        venvTool.venvDeactive();
    }
    if (result.count("remove")) {
        std::string venvName = result["remove"].as<std::string>();
        std::string venvPath = getVenvPath();
        
        VenvTool venvTool(venvPath);
        venvTool.venvRemove(venvName);
    }

    return 0;
}
