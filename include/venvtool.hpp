#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

class VenvTool {
    private:
        std::string venvPath_;
    public:
        VenvTool(std::string venvPath); 
        ~VenvTool();
        /**
         * @brief create a new venv
        */
        void venvCreate(std::string venvName);
        /**
         * @brief list all existing venvs
        */
        void venvList();
        /**
         * @brief activate an venv
        */
        void venvActivate(std::string venvName);
        /**
         * @brief deactivate an venv
        */
        void venvDeactive();
        /**
         * @brief deactivate an venv
        */
        void venvRemove(std::string venvName);

        /**
         * @brief init venvtool, create a dictoty to store all venvs, and save
         * this path into a config file
         *
         * @param venvPath path where all venvs will be stored 
         */
        static void venvInit(std::string venvPath) {
            // path of venv dictory
            #if defined(_WIN32) || defined(__MINGW32__)
            std::string venvtoolPath = std::string(std::getenv("appdata")) + "/venvtool";
            #else
            std::string venvtoolPath = std::string(std::getenv("HOME")) + "/.local/bin/venvtool";
            #endif

            std::filesystem::path rootPath(venvPath);
            
            if (std::filesystem::exists(rootPath)) {
                std::cout << "Directory already exists" << std::endl;
                return;
            }
            
            std::filesystem::create_directory(rootPath);
            
            // save venv root path into config file
            std::ofstream pathOut(venvtoolPath + "/.conf");
            pathOut << venvPath;
            pathOut.close();
        };
};
