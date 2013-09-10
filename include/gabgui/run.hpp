#ifndef _GABGUI_APPLICATION_HPP_
#define _GABGUI_APPLICATION_HPP_

namespace gab
{
  class simulation;
  
  namespace gui
  {
    int run(int argc, char *argv[], simulation *const model);
  }
}

#endif
