#ifndef _PLOT_WIDGET_HPP_
#define _PLOT_WIDGET_HPP_

#include <QWidget>
#include <QColor>

namespace gab
{
  namespace gui
  {
    typedef unsigned int plot_handle;

    struct plot;

    class plot_widget : public QWidget
    {
    Q_OBJECT
    public:
      plot_widget(QWidget *parent = 0);
      ~plot_widget();

      plot_handle add_plot(const QColor &color);
      void remove_plot(const plot_handle &handle);

      void push(const plot_handle &handle, const double value);
      void inc();

    signals:
      void mouseEvent(const double y);

    protected:
      void mousePressEvent(QMouseEvent *event);
      void mouseMoveEvent(QMouseEvent *event);
      void mouseReleaseEvent(QMouseEvent *event);
      void paintEvent(QPaintEvent *event);

    private:
      const quint32 _resolution;
      QList<plot *> _plots;
      quint32 _location;
    };
  }
}


#endif
