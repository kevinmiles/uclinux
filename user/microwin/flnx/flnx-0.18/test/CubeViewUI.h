// generated by Fast Light User Interface Designer (fluid) version 1.00

#ifndef CubeViewUI_h
#define CubeViewUI_h
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Roller.H>
#include <stdio.h>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Box.H>
#include "CubeView.h"
#include <FL/Fl_Value_Slider.H>

class CubeViewUI {
public:
  CubeViewUI();
private:
  Fl_Window *mainWindow;
public:
  Fl_Group *VChange;
  Fl_Roller *vrot;
private:
  inline void cb_vrot_i(Fl_Roller*, void*);
  static void cb_vrot(Fl_Roller*, void*);
public:
  Fl_Slider *ypan;
private:
  inline void cb_ypan_i(Fl_Slider*, void*);
  static void cb_ypan(Fl_Slider*, void*);
public:
  Fl_Group *HChange;
  Fl_Slider *xpan;
private:
  inline void cb_xpan_i(Fl_Slider*, void*);
  static void cb_xpan(Fl_Slider*, void*);
public:
  Fl_Roller *hrot;
private:
  inline void cb_hrot_i(Fl_Roller*, void*);
  static void cb_hrot(Fl_Roller*, void*);
public:
  Fl_Group *MainView;
  Fl_Box *cframe;
  CubeView *cube;
  Fl_Value_Slider *zoom;
private:
  inline void cb_zoom_i(Fl_Value_Slider*, void*);
  static void cb_zoom(Fl_Value_Slider*, void*);
public:
  void show();
};
#endif
