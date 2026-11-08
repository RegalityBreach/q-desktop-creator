#include "window.h"
#include <gtkmm/cssprovider.h>
#include <iostream>

MainWindow::MainWindow() {
	set_default_size(300, 200);
	set_resizable(false);
	set_child(m_content);

	const auto css_provider = Gtk::CssProvider::create();
	SetCssTheme(css_provider);

	// Folder info
	m_folder_entry.set_name("folder-entry");
	m_folder_entry.set_hexpand(true);
	m_folder_entry.set_vexpand(true);
	m_folder_entry.set_text(data->GetFolderPath());
	m_folder_box.append(m_folder_entry);

	m_folder_select.set_name("folder-button");
	m_folder_select.signal_clicked().connect([this] {
		data->Select(m_folder_select, m_folder_entry);
	});
	m_folder_box.append(m_folder_select);

	m_folder_box.add_css_class("container");
	m_content.append(m_folder_box);

	// Info paned 1

	// Name info
	m_name.set_spacing(4);
	m_name.append(m_name_label);

	m_name_entry.set_hexpand(true);
	m_name.append(m_name_entry);

	m_info_paned_1.set_start_child(m_name);

	// Description info
	m_desc.set_spacing(4);
	m_desc.append(m_desc_label);

	m_desc_entry.set_hexpand(true);
	m_desc.append(m_desc_entry);

	m_info_paned_1.set_end_child(m_desc);

	m_info_paned_1.set_position(135);
	m_info_paned_1.add_css_class("container");
	m_content.append(m_info_paned_1);

	// Info paned 2

	// Path info
	m_path.set_spacing(4);
	m_path.append(m_path_label);

	m_path_entry.set_hexpand(true);
	m_path.append(m_path_entry);

	m_info_paned_2.set_start_child(m_path);

	// Exec info
	m_exec.set_spacing(4);
	m_exec.append(m_exec_label);

	m_exec_entry.set_hexpand(true);
	m_exec.append(m_exec_entry);

	m_info_paned_2.set_end_child(m_exec);

	m_info_paned_2.set_position(135);
	m_info_paned_2.add_css_class("container");
	m_content.append(m_info_paned_2);

	// Create
	m_button_create.set_name("create-button");
	m_button_create.set_hexpand(true);
	m_content.append(m_button_create);
}

void MainWindow::SetCssTheme(const Glib::RefPtr<Gtk::CssProvider>& css_provider) {
    std::string css_path = "css/style.css";

    css_provider->load_from_path(css_path);

    Glib::RefPtr<Gtk::StyleProvider> style_provider = css_provider;
    Gtk::StyleProvider::add_provider_for_display(
        get_display(),
        style_provider,
        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
    );
}