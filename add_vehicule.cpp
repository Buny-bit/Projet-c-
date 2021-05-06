#include "add_vehicule.h"
#include "ui_add_vehicule.h"

add_vehicule::add_vehicule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_vehicule)
{
    ui->setupUi(this);
}

add_vehicule::~add_vehicule()
{
    delete ui;
}

//configurer ok et cancel
void add_vehicule::on_buttonBox_accepted()
{
    accept();
}

void add_vehicule::on_buttonBox_rejected()
{
    reject();
}

//get form content
double add_vehicule::consomation() const { //combo box

    return ui->consomation->value();
}

QString add_vehicule::couleur() const { //combo box

    return ui->couleur->currentText();
}

QString add_vehicule::type() const { //combo box

    return ui->type->currentText();
}


QString add_vehicule::matricule() const { //line edit

    return ui->matricule->text();
}

//remplissage des champs du formulaire a partir de la base

void add_vehicule::fill_form(QString selected ) {
    QSqlQuery query;
    query.prepare("select * from VEHICULE where MATRICULE= :id");
    query.bindValue(":id", selected);
    query.exec();
    while(query.next()){
  ui->matricule->setText(query.value(0).toString()); //line edit
   ui->type->setCurrentText(query.value(1).toString()); //combobox
   ui->couleur->setCurrentText(query.value(2).toString()); //combobox
 ui->consomation->setValue(query.value(3).toReal()); // reel
    }

}
