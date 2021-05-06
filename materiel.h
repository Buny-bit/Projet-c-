#ifndef MATERIEL_H
#define MATERIEL_H

#include <QSqlQuery>
#include <QSqlQueryModel>

class materiel
{
public:
    materiel();

    materiel(QString,QString,QString,int);

    bool ajouter();
    bool modifier(QString);
     QSqlQueryModel * afficher();
      bool supprimer(QString);
      bool archiver(QString,QString);


    QString id,type,nom;
    int quantite;
};

#endif // MATERIEL_H
