/**
    This file is part of program Lenna
    Copyright (C) 2013-2016  FalseCAM

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PCPLUGINWIDGET_H
#define PCPLUGINWIDGET_H

#include <lenna/plugins/plugin.h>

#include <QtWidgets/QWidget>

namespace Ui {
class PCPluginWidget;
}

namespace lenna {
namespace plugin {

class PCPluginWidget : public QWidget {
  Q_OBJECT

 public:
  PCPluginWidget(Plugin *plugin);
  ~PCPluginWidget();
  Plugin *getPlugin();

 signals:
  void pluginActivated(QString uid);

 private:
  Ui::PCPluginWidget *ui;
  Plugin *plugin;

 private slots:
  void checkBoxChanged();
  void on_addButton_clicked();
};
}
}

#endif  // PCPLUGINWIDGET_H
