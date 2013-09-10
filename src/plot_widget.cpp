#include <gabgui/plot_widget.hpp>

#include <QDebug>
#include <QPainter>
#include <QMouseEvent>

#define GOLDEN_RATIO 2.39996

using namespace gab::gui;

namespace gab
{
  namespace gui
  {
    struct plot
    {
      plot(const quint32 &res, const QColor &color)
        : values(new double[res])
        , color(color)
      {
      }

      ~plot()
      {
        delete[] values;
      }

      double *values;
      QColor color;
    };
  }
}

plot_widget::plot_widget(QWidget *parent)
  : QWidget(parent)
  , _resolution(120)
  , _location(0)
{
}

plot_widget::~plot_widget()
{
  while(!_plots.isEmpty()) delete _plots.takeFirst();
}

plot_handle plot_widget::add_plot(const QColor &color)
{
  _plots.append(new plot(_resolution, color));
  return _plots.size() - 1;
}

void plot_widget::remove_plot(const plot_handle &handle)
{
  delete _plots[handle];
  _plots.replace(handle, 0);
}

void plot_widget::push(const plot_handle &handle, const double value)
{
  double safeValue = value;
  if(safeValue > 1.0) safeValue = 1.0;
  else if(safeValue < -1.0) safeValue = -1.0;
  _plots[handle]->values[_location] = safeValue;
}

void plot_widget::inc()
{
  ++_location;
  _location %= _resolution;
  update();
}

#define MOUSE_TO_ASD ((height() - event->pos().y()) / (double)height() * 2.0 - 1.0)

void plot_widget::mousePressEvent(QMouseEvent *event)
{
  emit mouseEvent(MOUSE_TO_ASD);
}

void plot_widget::mouseMoveEvent(QMouseEvent *event)
{
  emit mouseEvent(MOUSE_TO_ASD);
}

void plot_widget::mouseReleaseEvent(QMouseEvent *event)
{
  emit mouseEvent(MOUSE_TO_ASD);
}

void plot_widget::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.fillRect(0, 0, width() - 1, height() - 1, Qt::transparent);
  const double max = (double)height() / 2.1;
  const double widthRatio = (double)width() / (double)_resolution;
  foreach(plot *p, _plots) {
    painter.setPen(QPen(p->color, 2));
    painter.setBrush(p->color);
    double oldX = 0.0;
    double oldY = max - p->values[0] * max;
    for(quint32 i = 0; i < _resolution - 1; ++i) {
      const int off = (i + _location) % _resolution;
      double newX = i * widthRatio;
      double newY = height() / 2.0 - p->values[off] * max;
      painter.drawLine(oldX, oldY, newX, newY);
      oldX = newX;
      oldY = newY;
    }
  }
}
