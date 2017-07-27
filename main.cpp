/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QApplication>
#include <QProcess>
#include "bvs_wallet.h"
#include <QDebug>
#include <getopt.h>

/**
 * @brief qMain
 * @param argc - number of args
 * @param argv - array of args
 * @return - returns 0 if exit normal, otherwise 1.
 */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv); // ->this process
    QStringList args = app.arguments(); // ->console cmd args
    BVS_Wallet b(args); // ->GUI MainWindow
    QString cmd, blockchain, server, port, path;
    bool multichain = false;


//    qDebug() << "argc = " << argc;
    for(int i = 0; i < argc; i++) {
//        qDebug() << "argv[" << i << "] = " << argv[i] << "\n";
        QString arg = args[i];
        if (arg == "--with-multichain") {
            multichain = true;
        }
        else if (arg.contains("blockchain=") == true) {
            QStringList argBlockchain= arg.split("=");
            blockchain = argBlockchain[1];
        }
        else if (arg.contains("server=") == true) {
            QStringList argBlockchain = arg.split("=");
            server = argBlockchain[1];
        }

        else if (arg.contains("port=") == true) {
            QStringList argBlockchain = arg.split("=");
            port = argBlockchain[1];
        }

        else if (arg.contains("path=") == true) {
            QStringList argBlockchain = arg.split("=");
            path = argBlockchain[1];
        }
    }

    cmd = path + "multichaind";

    QStringList arguments;
    arguments.append(blockchain + "@" + server + ":" + port);
    arguments.append("-daemon");


    if (multichain == true) {
        QProcess process; // ->Multichain daemon process
        process.startDetached(cmd, arguments);
        process.waitForFinished();
        qDebug() << "Getting data from blockchain... Please be patient while daemon starts!";
    }

    b.show();
    return app.exec();
}
