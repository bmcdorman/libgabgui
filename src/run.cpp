#include <gabgui/run.hpp>
#include <gabgui/simulation.hpp>

#include <QApplication>

int gab::gui::run(int argc, char *argv[], gab::simulation *const model)
{
  QApplication app(argc, argv);
  gab::gui::simulation sim_window;
  sim_window.model(model);
  sim_window.show();
  sim_window.raise();
  return app.exec();
}