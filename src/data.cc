#include "data.h"
#include <gtkmm/filedialog.h>
#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <glibmm.h>
#include <filesystem>
#include <iostream>

Data::Data() 
    : m_config_file(Glib::build_filename(Glib::get_user_config_dir(), "qdesktop-creator", "qdesktop-creator.ini"))
{
    std::filesystem::create_directories(
        std::filesystem::path(m_config_file).parent_path()
    );

    LoadConfig();
}

void Data::Select(Gtk::Button& button, Gtk::Entry& entry) {
    button.set_sensitive(false);

    auto dialog = Gtk::FileDialog::create();
    dialog->set_title("Select Folder");

    dialog->select_folder([this, &button, &entry, dialog](const auto& result) {
        try {
            auto file = dialog->select_folder_finish(result);
            if (file) {
                std::string path = file->get_path();
                SetFolderPath(path);
                entry.set_text(path);
                SaveConfig();
            }
        } catch (const Glib::Error& err) {
            std::cerr << "Cancelled or error: " << err.what() << std::endl;
        }

        button.set_sensitive(true);
    });
}

void Data::SetFolderPath(std::string path) {
    m_config["FolderPath"] = path;
}

std::string Data::GetFolderPath() const {
    return m_config.at("FolderPath");
}

void Data::SaveConfig() const {
    auto key_file = Glib::KeyFile::create();

    for (const auto& [key, value] : m_config) {
        key_file->set_string("Config", key, value);
    }

    try {
        key_file->save_to_file(m_config_file);
    } catch (const Glib::Error& err) {
        std::cerr << "Failed to save config: " << err.what() << std::endl;
    }
}

void Data::LoadConfig() {
    auto key_file = Glib::KeyFile::create();
    try {
        key_file->load_from_file(m_config_file);

        for (const auto& [key, value] : m_config) {
            try {
                std::string path = key_file->get_string("Config", key);
                m_config[key] = path;
            } catch (const Glib::Error& err) {
                std::cerr << "Failed to load " << key << ": " << err.what() << std::endl;
            }
        }
    } catch (const Glib::Error& ex) {
        // File doesn't exist yet, which is fine on first launch
    }
}