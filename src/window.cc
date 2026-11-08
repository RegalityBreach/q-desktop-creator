#include "window.h"
#include <iostream>

MainWindow::MainWindow() {
	set_default_size(300, 200);
	set_resizable(false);
	set_child(m_content);

	m_folder_entry.set_hexpand(true);
	m_folder_entry.set_vexpand(true);
	m_folder_entry.set_text(data->GetFolderPath());
	m_folder_box.append(m_folder_entry);

	m_folder_select.signal_clicked().connect([this] {
		data->Select(m_folder_select, m_folder_entry);
	});
	m_folder_box.append(m_folder_select);

	m_content.append(m_folder_box);
}