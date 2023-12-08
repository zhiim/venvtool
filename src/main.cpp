#include <cstdlib>
#include <iostream>
#include <string>
#include "cxxopts.hpp"
#include "venvtool.hpp"

// path of venv dictory
#if defined(_WIN32) || defined(__MINGW32__)
std::string venvPath = std::string(std::getenv("UserProfile")) + "/.venvtool";
#else
std::string venvPath = std::string(std::getenv("HOME")) + "/.venvtool";
#endif

int main(int argc, char** argv) {
    cxxopts::Options options("venvtool", "a tool to manage venvs like conda");

    options.add_options()
        ("h, help", "Print usage")
        ("l, list", "List all existing venvs")
        ("c, create", "Create a new venv", cxxopts::value<std::string>())
        ("r, remove", "Remove an venv", cxxopts::value<std::string>())
        ("a, activate", "Activate an venv", cxxopts::value<std::string>())
        ("d, deactivate", "Deactivate an venv")
    ;

    // parse options
    auto result = options.parse(argc, argv);

    std::string venvName;
    VenvTool venvTool(venvPath);
    
    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        exit(0);
    }
    if (result.count("create")) {
        venvName = result["create"].as<std::string>();
        venvTool.venvCreate(venvName);
    }
    if (result.count("list")) {
        venvTool.venvList();
    }
    if (result.count("activate")) {
        venvName = result["activate"].as<std::string>();
        venvTool.venvActivate(venvName);
    }
    if (result.count("deactivate")) {
        venvTool.venvDeactive();
    }
    if (result.count("remove")) {
        venvName = result["remove"].as<std::string>();
        venvTool.venvRemove(venvName);
    }

    return 0;
}
