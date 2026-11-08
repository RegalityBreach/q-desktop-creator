#pragma once

#include "data.h"
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/paned.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include <gtkmm/cssprovider.h>

class MainWindow : public Gtk::Window
{
public:
	MainWindow();
	~MainWindow() override = default;

	void SetCssTheme(const Glib::RefPtr<Gtk::CssProvider>& css_provider);
private:
	// Main content
	Gtk::Box m_content{Gtk::Orientation::VERTICAL};
	Data* data = new Data;

	// Folder selector.
	Gtk::Box m_folder_box{Gtk::Orientation::HORIZONTAL};
	Gtk::Entry m_folder_entry;
	Gtk::Button m_folder_select{"Select"};

	// Info
	Gtk::Paned m_info_paned_1{Gtk::Orientation::HORIZONTAL};
	Gtk::Box m_name{Gtk::Orientation::VERTICAL};
	Gtk::Label m_name_label{"Name:"};
	Gtk::Entry m_name_entry;

	Gtk::Box m_desc{Gtk::Orientation::VERTICAL};
	Gtk::Label m_desc_label{"Description:"};
	Gtk::Entry m_desc_entry;

	Gtk::Paned m_info_paned_2{Gtk::Orientation::HORIZONTAL};
	Gtk::Box m_path{Gtk::Orientation::VERTICAL};
	Gtk::Label m_path_label{"Path:"};
	Gtk::Entry m_path_entry;

	Gtk::Box m_exec{Gtk::Orientation::VERTICAL};
	Gtk::Label m_exec_label{"Exec:"};
	Gtk::Entry m_exec_entry;

	// Create
	Gtk::Button m_button_create{"Create"};
};