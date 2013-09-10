#ifndef _GABGUI_SIMULATION_HPP_
#define _GABGUI_SIMULATION_HPP_

#include <QMainWindow>

namespace Ui
{
  class simulation;
}

namespace gab
{
  class simulation;
  
  namespace gui
  {
    class simulation : public QMainWindow
    {
    Q_OBJECT
    public:
      simulation(QWidget *parent = 0);
      ~simulation();
      
      void model(gab::simulation *const model);
      gab::simulation *model() const;
      
    protected:
      Ui::simulation *_ui;
      
    private:
      gab::simulation *_model;
    };
  }
}

#endif
