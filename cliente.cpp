#include "cliente.h"
#include "ui_cliente.h"

Cliente::Cliente(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cliente)
{
    ui->setupUi(this);
}

Cliente::~Cliente()
{
    delete ui;
}
