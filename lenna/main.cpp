/**
    This file is part of program Lenna
    Copyright (C) 2013  FalseCAM

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

#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include "lenna.h"
#include "logger.h"

using namespace lenna;

int main(int argc, char *argv[])
{
    qInstallMessageHandler(Logger::messageHandler);
    qDebug("starting Application");
    QApplication a(argc, argv);
    Lenna::setApplicationName("Lenna");
    Lenna::setApplicationVersion("0.1");
    Lenna::setOrganizationName("FalseCAM");
    a.setWindowIcon(Lenna::applicationIcon());
    MainWindow w;
    w.show();
    
    return a.exec();
}
