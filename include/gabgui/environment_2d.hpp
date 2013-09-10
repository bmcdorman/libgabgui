#ifndef _GABGUI_ENVIRONMENT_2D_HPP_
#define _GABGUI_ENVIRONMENT_2D_HPP_

#include <QWidget>
#include <gab/environment_2d.hpp>

namespace Ui
{
  class environment_2d;
}

namespace gab
{
  class environment_2d;
  
  namespace gui
  {
    class environment_2d : public QWidget
    {
    Q_OBJECT
    public:
      environment_2d(QWidget *parent = 0);
      ~environment_2d();
      
      void model(gab::environment_2d *const model);
      gab::environment_2d *model() const;
      void refresh();
      
    private:
      void refresh_types();
      
      Ui::environment_2d *_ui;
      gab::environment_2d *_model;
      gab::environment_2d::hash_type _types_hash;
    };
  }
}

#endif
