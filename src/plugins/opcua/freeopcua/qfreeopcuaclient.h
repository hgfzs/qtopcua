/****************************************************************************
**
** Copyright (C) 2015 basysKom GmbH, opensource@basyskom.com
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtOpcUa module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QFREEOPCUACLIENT_H
#define QFREEOPCUACLIENT_H

#include <QtOpcUa/qopcuaclient.h>

#include <opc/ua/client/client.h>
#include <QtCore/QUrl>

QT_BEGIN_NAMESPACE

class QFreeOpcUaClient : public QOpcUaClient, public OpcUa::UaClient
{
    Q_OBJECT

public:
    explicit QFreeOpcUaClient(QObject *parent = 0);
    ~QFreeOpcUaClient() Q_DECL_OVERRIDE;

    bool connectToEndpoint(const QUrl &url) Q_DECL_OVERRIDE;
    bool secureConnectToEndpoint(const QUrl &url) Q_DECL_OVERRIDE;
    bool disconnectFromEndpoint() Q_DECL_OVERRIDE;
    QVariant read(const QString &xmlNodeId) Q_DECL_OVERRIDE;
    bool write(const QString &xmlNodeId, const QVariant &value, QOpcUa::Types type) Q_DECL_OVERRIDE;
    bool call(const QString &xmlObjectNodeId, const QString &xmlMethodNodeId,
              QVector<QOpcUaTypedVariant> *args = 0, QVector<QVariant>  *ret = 0) Q_DECL_OVERRIDE;
    QPair<QString, QString> readEui(const QString &xmlNodeId) Q_DECL_OVERRIDE;
    QPair<double, double> readEuRange(const QString &xmlNodeId) Q_DECL_OVERRIDE;

    QOpcUaMonitoredItem *dataMonitor(double interval, const QString &xmlNodeId) Q_DECL_OVERRIDE;
    QOpcUaMonitoredItem *eventMonitor(const QString &xmlEventNodeId) Q_DECL_OVERRIDE;

    QOpcUaNode *node(const QString &xmlNodeId) Q_DECL_OVERRIDE;

    QList<QPair<QVariant, QDateTime> > readHistorical(const QString &node, int maxCount,
            const QDateTime &begin, const QDateTime &end) Q_DECL_OVERRIDE;

protected:
    QOpcUaSubscription *createSubscription(double interval) Q_DECL_OVERRIDE;
};

QT_END_NAMESPACE

#endif // QFREEOPCUACLIENT_H
