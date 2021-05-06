#include "materiel.h"

materiel::materiel()
{

}

materiel::materiel(QString s1 ,QString s2,QString s3,int x ){

    id=s1;
    type=s2;
    nom=s3;
    quantite=x;

}


bool materiel::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO MATERIEL VALUES (:id, :nom, :type,:quantite)");

    query.bindValue(":id", id);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
    query.bindValue(":quantite",quantite);

    return    query.exec();

}

bool materiel::modifier(QString selected){

    QSqlQuery query;


    query.prepare(" UPDATE MATERIEL SET NOM= :nom ,TYPE= :type, QUANTITE=:quantite where ID= :id");
    query.bindValue(":id", selected);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
    query.bindValue(":quantite",quantite);
    return    query.exec();

}

 QSqlQueryModel * materiel::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM MATERIEL");

     return modal;

 }
  bool materiel::supprimer(QString selected){

      QSqlQuery query;
      query.prepare("Delete from MATERIEL where ID = :id ");
      query.bindValue(":id", selected);
      return    query.exec();


  }
