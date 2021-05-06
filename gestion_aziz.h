#ifndef GESTION_AZIZ_H
#define GESTION_AZIZ_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QPrintDialog>
#include <QTextStream>

#include "materiel.h"
#include "add_materiel.h"
#include "vehicule.h"
#include "add_vehicule.h"

namespace Ui {
class gestion_aziz;
}

class gestion_aziz : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion_aziz(QWidget *parent = nullptr);
    ~gestion_aziz();

    vehicule tmp_vehicule;
    materiel tmp_materiel;
    QSortFilterProxyModel *proxy_vehicule,*proxy_materiel;
    void show_materiel();
    void show_vehicule();
    void show_tables();
    void clear_form();

    //materiel

    int quantite() const ; //int
    QString type2() const ; //combo
    QString nom() const; //line
    QString id() const ; //line

    void fill_form(QString);

    //vehicule

    double consomation() const ; //text
    QString couleur() const ; //line
    QString type() const; //line
    QString matricule() const ; //line

    void fill_form_2(QString);

private slots:

    void on_actionadd_vehicule_clicked();

    void on_table_vehicule_clicked(const QModelIndex &index);

    void on_table_vehicule_doubleClicked(const QModelIndex &index);

    void on_actiondelete_vehicule_clicked();

    void on_vehicule_sel_col_currentIndexChanged(const QString &arg1);

    void on_rech_vehicule_textChanged(const QString &arg1);


    void on_actionadd_materiel_clicked();

    void on_table_materiel_clicked(const QModelIndex &index);

    void on_table_materiel_doubleClicked(const QModelIndex &index);

    void on_actiondelete_materiel_clicked();

    void on_materiel_sel_col_currentIndexChanged(const QString &arg1);

    void on_rech_materiel_textChanged(const QString &arg1);

    void on_pushButton_5_clicked();




    void on_actionedit_vehicule_clicked();

    void on_actionedit_materiel_clicked();

private:
    Ui::gestion_aziz *ui;
    QString selected_vehicule="",selected_materiel="";
    int sel_col_vehicule=-1,sel_col_materiel=-1;

};

#endif // GESTION_AZIZ_H
