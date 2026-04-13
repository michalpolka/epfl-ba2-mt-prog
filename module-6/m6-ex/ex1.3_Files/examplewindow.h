#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <string>
#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();

private:
  //Child widgets:
  Gtk::Box m_Box;
  Gtk::Button m_Button_Open;
  Gtk::Button m_Button_Save;

  std::string filename;
  
  //Signal handlers:
  void on_button_open_clicked();
  void on_button_save_clicked();
  void on_file_dialog_response(int response_id, Gtk::FileChooserDialog* dialog);
};

#endif //GTKMM_EXAMPLEWINDOW_H
