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

#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include "lenna/plugins/editplugin.h"
#include "lenna/plugins/inputplugin.h"
#include "lenna/plugins/outputplugin.h"

#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QObject>

namespace lenna {
namespace plugin {

class PluginLoader : public QObject {
  Q_OBJECT
 public:
  ~PluginLoader();

  static void destroyInstance();
  static PluginLoader &getInstance();

  void activatePlugin(QString uid, QString name);
  void activatePlugin(Plugin *plugin);
  void activatePlugins(QStringList list);
  void deactivatePlugin(Plugin *plugin);
  void deactivatePlugin(int index);
  bool isActivatedPlugin(Plugin *plugin);
  Plugin *getPlugin(QString name);
  Plugin *getActivePlugin(QString uid);

  // InputPlugin
  QList<InputPlugin *> getInputPlugins();
  QList<InputPlugin *> getActiveInputPlugins();
  void moveInputPlugin(InputPlugin *plugin, int index);

  // EditPlugin
  QList<EditPlugin *> getEditPlugins();
  QList<EditPlugin *> getActiveEditPlugins();
  void moveEditPlugin(EditPlugin *plugin, int index);

  // OutputPlugin
  QList<OutputPlugin *> getOutputPlugins();
  QList<OutputPlugin *> getActiveOutputPlugins();
  void moveOutputPlugin(OutputPlugin *plugin, int index);

 signals:

 public slots:

 private:
  explicit PluginLoader(QObject *parent = 0);
  static PluginLoader *instance;
  void loadPlugins();
  void loadConfig();
  void saveConfig();

  QMap<QString, Plugin *> activatedPlugins;

  // InputPlugin
  QList<InputPlugin *> inputPlugins;
  QList<QString> activeInputPlugins;
  void loadInputPlugins(QString dir);
  void addInputPlugin(InputPlugin *plugin);

  // EditPlugin
  QList<EditPlugin *> editPlugins;
  QList<QString> activeEditPlugins;
  void loadEditPlugins(QString dir);
  void addEditPlugin(EditPlugin *plugin);

  // OutputPlugin
  QList<OutputPlugin *> outputPlugins;
  QList<QString> activeOutputPlugins;
  void loadOutputPlugins(QString dir);
  void addOutputPlugin(OutputPlugin *plugin);
};
}
}

#endif  // PLUGINLOADER_H
