#include <gabgui/simulation.hpp>
#include <ui_simulation.h>

using namespace gab::gui;

gab::gui::simulation::simulation(QWidget *parent)
  : QMainWindow(parent)
  , _ui(new Ui::simulation)
{
  _ui->setupUi(this);
}

gab::gui::simulation::~simulation()
{
  delete _ui;
}

void gab::gui::simulation::model(gab::simulation *const model)
{
  _model = model;
}

gab::simulation *gab::gui::simulation::model() const
{
  return _model;
}