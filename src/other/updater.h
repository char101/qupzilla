/* ============================================================
* QupZilla - WebKit based browser
* Copyright (C) 2010-2011  nowrep
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#ifndef UPDATER_H
#define UPDATER_H

#if defined(QT_NO_DEBUG) & !defined(QT_NO_DEBUG_OUTPUT)
#define QT_NO_DEBUG_OUTPUT
#endif

#include <QObject>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QNetworkReply>

class QupZilla;
class Updater : public QObject
{
    Q_OBJECT
public:
    explicit Updater(QupZilla* mainClass, QObject *parent = 0);
    ~Updater();

signals:

public slots:
    void downCompleted(QNetworkReply* reply);
    void start();
    void goUpdate();
    void clicked(QSystemTrayIcon::ActivationReason reason);

private:
    void createTrayIcon();
    void startDownloadingUpdateInfo(const QUrl &url);

    QSystemTrayIcon* m_trayIcon;
    QMenu* m_trayIconMenu;

    QupZilla* p_QupZilla;

};

#endif // UPDATER_H
