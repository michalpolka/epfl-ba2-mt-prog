//

#include "examplewindow.h"
#include <iostream>


ExampleWindow::ExampleWindow():
	m_Box(Gtk::Orientation::VERTICAL),
	m_Button_Open("Open File"),
	m_Button_Save("Save File")
{
	set_title("");
	
	set_child(m_Box);
	
	m_Box.append(m_Button_Open);
    m_Button_Open.set_expand(true);
	m_Box.append(m_Button_Save);
    m_Button_Save.set_expand(true);


	m_Button_Open.signal_clicked().connect(sigc::mem_fun(*this,
			  &ExampleWindow::on_button_open_clicked) );

	m_Button_Save.signal_clicked().connect(sigc::mem_fun(*this,
			  &ExampleWindow::on_button_save_clicked) );
}

void ExampleWindow::on_button_open_clicked()
{
	auto dialog = new Gtk::FileChooserDialog("Please choose a file",
		  Gtk::FileChooser::Action::OPEN);
	dialog->set_transient_for(*this);
	dialog->set_modal(true);
	dialog->signal_response().connect(sigc::bind(
	sigc::mem_fun(*this, &ExampleWindow::on_file_dialog_response), dialog));
	
	//Add response buttons to the dialog:
	dialog->add_button("_Cancel", Gtk::ResponseType::CANCEL);
	dialog->add_button("_Open", Gtk::ResponseType::OK);
	
	//Add filters, so that only certain file types can be selected:
	
	auto filter_text = Gtk::FileFilter::create();
	filter_text->set_name("Text files");
	filter_text->add_mime_type("text/plain");
	dialog->add_filter(filter_text);
	
	auto filter_cpp = Gtk::FileFilter::create();
	filter_cpp->set_name("C/C++ files");
	filter_cpp->add_mime_type("text/x-c");
	filter_cpp->add_mime_type("text/x-c++");
	filter_cpp->add_mime_type("text/x-c-header");
	dialog->add_filter(filter_cpp);
	
	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog->add_filter(filter_any);
	
	//Show the dialog and wait for a user response:
	dialog->show();
}

void ExampleWindow::on_button_save_clicked()
{
	auto dialog = new Gtk::FileChooserDialog("Please choose a file",
		  Gtk::FileChooser::Action::SAVE);
	dialog->set_transient_for(*this);
	dialog->set_modal(true);
	dialog->signal_response().connect(sigc::bind(
	sigc::mem_fun(*this, &ExampleWindow::on_file_dialog_response), dialog));
	
	//Add response buttons to the dialog:
	dialog->add_button("_Cancel", Gtk::ResponseType::CANCEL);
	dialog->add_button("_Save", Gtk::ResponseType::OK);
	
	//Add filters, so that only certain file types can be selected:
	
	auto filter_text = Gtk::FileFilter::create();
	filter_text->set_name("Text files");
	filter_text->add_mime_type("text/plain");
	dialog->add_filter(filter_text);
	
	auto filter_cpp = Gtk::FileFilter::create();
	filter_cpp->set_name("C/C++ files");
	filter_cpp->add_mime_type("text/x-c");
	filter_cpp->add_mime_type("text/x-c++");
	filter_cpp->add_mime_type("text/x-c-header");
	dialog->add_filter(filter_cpp);
	
	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog->add_filter(filter_any);
	
	//Show the dialog and wait for a user response:
	dialog->show();
}


void ExampleWindow::on_file_dialog_response(int response_id, 
										    Gtk::FileChooserDialog* dialog)
{
	//Handle the response:
	switch (response_id)
	{
		case Gtk::ResponseType::OK:
		{
		    std::cout << "Open or Save clicked." << std::endl;
		
		    //Notice that this is a std::string, not a Glib::ustring.
		    filename = dialog->get_file()->get_path();
		    std::cout << "File selected: " <<  filename << std::endl;
		    break;
		}
		case Gtk::ResponseType::CANCEL:
		{
		    std::cout << "Cancel clicked." << std::endl;
		    break;
		}
		default:
		{
		    std::cout << "Unexpected button clicked." << std::endl;
		    break;
		}
	}
	delete dialog;
}

