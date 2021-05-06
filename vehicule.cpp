#include "vehicule.h"

vehicule::vehicule()
{

}

vehicule::vehicule(QString s1 ,QString s2,QString s3,double x ){

    matricule=s1;
    type=s2;
    couleur=s3;
    consomation=x;

}


bool vehicule::ajouter(){

    QSqlQuery query;


    query.prepare("INSERT INTO VEHICULE VALUES (:matricule, :type, :couleur,:consomation)");

    query.bindValue(":matricule", matricule);
    query.bindValue(":type",type);
    query.bindValue(":couleur",couleur);
    query.bindValue(":consomation",consomation);

    return    query.exec();

}

bool vehicule::modifier(QString selected){

    QSqlQuery query;


    query.prepare(" UPDATE VEHICULE SET TYPE= :type ,COULEUR= :couleur, CONSOMATION=:consomation where MATRICULE= :matricule");
    query.bindValue(":matricule", selected);
    query.bindValue(":type",type);
    query.bindValue(":couleur",couleur);
    query.bindValue(":consomation",consomation);

    return    query.exec();

}

 QSqlQueryModel * vehicule::afficher(){

     QSqlQueryModel * modal=new QSqlQueryModel();
     modal->setQuery("SELECT * FROM VEHICULE");

     return modal;

 }
  bool vehicule::supprimer(QString selected){

      QSqlQuery query;
      query.prepare("Delete from VEHICULE where MATRICULE = :matricule ");
      query.bindValue(":matricule", selected);
      return    query.exec();


  }

  double vehicule::calcul_consomation(){
double tot=0;
      QSqlQuery query;
      query.prepare("select CONSOMATION from VEHICULE ");
      query.exec();
      while(query.next()){

 tot+=query.value(0).toReal();
      }
      return   tot;


  }
