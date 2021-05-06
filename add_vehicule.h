#ifndef ADD_VEHICULE_H
#define ADD_VEHICULE_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class add_vehicule;
}

class add_vehicule : public QDialog
{
    Q_OBJECT

public:
    explicit add_vehicule(QWidget *parent = nullptr);
    ~add_vehicule();


    double consomation() const ; //text
    QString couleur() const ; //line
    QString type() const; //line
    QString matricule() const ; //line

    void fill_form(QString);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::add_vehicule *ui;
};

#endif // ADD_VEHICULE_H
