#ifndef ADD_MATERIEL_H
#define ADD_MATERIEL_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class add_materiel;
}

class add_materiel : public QDialog
{
    Q_OBJECT

public:
    explicit add_materiel(QWidget *parent = nullptr);
    ~add_materiel();


    int quantite() const ; //int
    QString type() const ; //combo
    QString nom() const; //line
    QString id() const ; //line

    void fill_form(QString);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::add_materiel *ui;
};

#endif // ADD_MATERIEL_H
