/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the Qt Assistant of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

#include "helpwindow.h"

QT_BEGIN_NAMESPACE

HelpWindow::HelpWindow(QWidget *parent)
    : QWidget(parent, 0)
{
    setAutoFillBackground(true);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    QFrame *frame = new QFrame(this);
    QPalette p = palette();
    p.setColor(QPalette::Background, Qt::white);
    setPalette(p);
    frame->setFrameStyle(QFrame::Box | QFrame::Plain);
    layout->addWidget(frame);

    layout = new QVBoxLayout(frame);
    layout->setMargin(2);
    QLabel *l = new QLabel(tr("<center><b>Wizard Assistant</b></center>"));
    layout->addWidget(l);
    m_textEdit = new QTextEdit();
    m_textEdit->setFrameStyle(QFrame::NoFrame);
    m_textEdit->setReadOnly(true);
    layout->addWidget(m_textEdit);
}

void HelpWindow::setHelp(const QString &topic)
{
    QLatin1String fileStr(":/trolltech/qhelpconverter/doc/%1.html");
    QFile f(QString(fileStr).arg(topic.toLower()));
    f.open(QIODevice::ReadOnly);
    QTextStream s(&f);
    m_textEdit->setText(s.readAll());
}

QT_END_NAMESPACE
