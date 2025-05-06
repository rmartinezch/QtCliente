#ifndef CLIENTE_H
#define CLIENTE_H

#include <QWidget>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {
class Cliente;
}
QT_END_NAMESPACE

class Cliente : public QWidget
{
    Q_OBJECT

public:
    Cliente(QWidget *parent = nullptr);
    ~Cliente();

private slots:
    // leer el mensaje recibido
    void readRandomMessage();
    // solicitar conexión
    void requestMessage();

private:
    Ui::Cliente *ui;
    // Socket
    QTcpSocket *clientSocket = nullptr;
    // Flujo de datos recibido
    QDataStream in;
};
#endif // CLIENTE_H
