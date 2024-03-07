#ifndef IU_FUNC_WTLSCRIPTDIALOGPROVIDER_H
#define IU_FUNC_WTLSCRIPTDIALOGPROVIDER_H

#include "Core/Scripting/DialogProvider.h"

class ConsoleScriptDialogProvider : public IDialogProvider {
public:
    std::string askUserCaptcha(NetworkClient *nm, const std::string& url) override;
    std::string inputDialog(const std::string& text, const std::string& defaultValue) override;
    std::string ConsoleScriptDialogProvider::messageBox(const std::string& message, const std::string& title, const std::string& buttons, const std::string& type) override;
};
#endif
