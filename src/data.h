#pragma once

#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <map>

class Data
{
public:
    Data();
    void Select(Gtk::Button& button, Gtk::Entry& entry);
    void SaveConfig() const;
	void LoadConfig();

    void SetFolderPath(std::string path);
    std::string GetFolderPath() const;
private:
    std::map<std::string, std::string> m_config = {
        {"FolderPath", ""},
    };
    const std::string m_config_file;
};