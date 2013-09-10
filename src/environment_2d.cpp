#include <gabgui/environment_2d.hpp>
#include <ui_environment_2d.h>

gab::gui::environment_2d::environment_2d(QWidget *parent)
  : QWidget(parent)
  , _ui(new Ui::environment_2d)
  , _model(0)
  , _types_hash(gab::environment_2d::hash_type())
{
  _ui->setupUi(this);
}

gab::gui::environment_2d::~environment_2d()
{
  delete _ui;
}

void gab::gui::environment_2d::model(gab::environment_2d *const model)
{
  _model = model;
  refresh();
}

gab::environment_2d *gab::gui::environment_2d::model() const
{
  return _model;
}

void gab::gui::environment_2d::refresh()
{
  refresh_types();
  if(!_model) return;
  // ...
}

void gab::gui::environment_2d::refresh_types()
{
  if(!_model && _types_hash == gab::environment_2d::hash_type()) {
    // Model is null
    return;
  }
  
  if(!_model && _types_hash != gab::environment_2d::hash_type()) {
    // Model just became null
    _types_hash = gab::environment_2d::hash_type();
    _ui->types->clear();
  }
  
  if(_types_hash == _model->types_hash()) {
    // No changes necessary.
    return;
  }
  
  
}