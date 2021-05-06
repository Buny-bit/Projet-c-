#ifndef VEHICULE_H
#define VEHICULE_H

#include <QSqlQuery>
#include <QSqlQueryModel>

class vehicule
{
public:
    vehicule();
    vehicule(QString,QString,QString,double);

    bool ajouter();
    bool modifier(QString);
     QSqlQueryModel * afficher();
      bool supprimer(QString);
      bool archiver(QString,QString);
double calcul_consomation();

    QString matricule,type,couleur;
    double consomation;
};

#endif // VEHICULE_H
