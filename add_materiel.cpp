#include "add_materiel.h"
#include "ui_add_materiel.h"

add_materiel::add_materiel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_materiel)
{
    ui->setupUi(this);
}

add_materiel::~add_materiel()
{
    delete ui;
}

//configurer ok et cancel
void add_materiel::on_buttonBox_accepted()
{
    accept();
}

void add_materiel::on_buttonBox_rejected()
{
    reject();
}

//get form content
int add_materiel::quantite() const { //combo box

    return ui->quantite->value();
}

QString add_materiel::nom() const { //combo box

    return ui->nom->text();
}

QString add_materiel::type() const { //combo box

    return ui->type->currentText();
}


QString add_materiel::id() const { //line edit

    return ui->id->text();
}

//remplissage des champs du formulaire a partir de la base

void add_materiel::fill_form(QString selected ) {
    QSqlQuery query;
    query.prepare("select * from MATERIEL where ID= :id");
    query.bindValue(":id", selected);
    query.exec();
    while(query.next()){
  ui->id->setText(query.value(0).toString()); //line edit
   ui->quantite->setValue(query.value(3).toInt()); //INT edit
   ui->type->setCurrentText(query.value(2).toString()); //combobox
   ui->nom->setText(query.value(1).toString()); //line edit

    }

}
