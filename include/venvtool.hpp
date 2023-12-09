#pragma once
#include <string>

class VenvTool {
    private:
        std::string venvPath_;
    public:
        VenvTool(std::string venvPath); 
        ~VenvTool();
        /**
         * @brief init venvtool, create a dictoty to store all venvs, and save
         * this path into a config file
         *
         * @param venvPath path where all venvs will be stored 
         */
        void venvInit(std::string venvPath);
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
};
