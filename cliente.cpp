#include "cliente.h"
#include "ui_cliente.h"

Cliente::Cliente(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cliente)
{
    ui->setupUi(this);
    // inicialización del socket
    clientSocket = new QTcpSocket(this);
    // Establecemos cual es el dispositivo de entrada
    in.setDevice(clientSocket);
    // conexiones
    connect(ui->pb_cerrar, &QAbstractButton::clicked,
            this, &QWidget::close);
    connect(ui->pb_connect, &QAbstractButton::clicked,
            this, &Cliente::requestMessage);
    connect(clientSocket, &QIODevice::readyRead, this, &Cliente::readRandomMessage);;
}

Cliente::~Cliente()
{
    delete ui;
}

void Cliente::readRandomMessage()
{
    qDebug() << "readRandomMessage() !!!";
    in.startTransaction();
    QString msg;
    in >> msg;
    if (!in.commitTransaction()) {
        qDebug() << "error en el flujo de datos recibido";
        return;
    }
    qDebug() << "msg: " + msg;
    ui->lbl_random_msg->setText(msg);
}

void Cliente::requestMessage()
{
    qDebug() << "requestMessage() !!!";
    // conectar al servidor
    QString ipAddress = ui->le_ip->text();
    QString port = ui->le_port->text();
    qDebug() << "ip: " + ipAddress + ", puerto: " + port;
    clientSocket->connectToHost(ipAddress, port.toInt());
}
