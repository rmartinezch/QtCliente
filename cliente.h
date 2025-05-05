#ifndef CLIENTE_H
#define CLIENTE_H

#include <QWidget>

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

private:
    Ui::Cliente *ui;
};
#endif // CLIENTE_H
