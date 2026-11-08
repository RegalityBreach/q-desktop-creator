#pragma once

#include "data.h"
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>

class MainWindow : public Gtk::Window
{
public:
	MainWindow();
	~MainWindow() override = default;
private:
	// Main content
	Gtk::Box m_content{Gtk::Orientation::VERTICAL};
	Data* data = new Data;

	// Folder selector.
	Gtk::Box m_folder_box{Gtk::Orientation::HORIZONTAL};
	Gtk::Entry m_folder_entry;
	Gtk::Button m_folder_select{"Select"};
};