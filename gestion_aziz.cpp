#include "gestion_aziz.h"
#include "ui_gestion_aziz.h"

gestion_aziz::gestion_aziz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_aziz)
{
    ui->setupUi(this);

    show_tables();
}

gestion_aziz::~gestion_aziz()
{
    delete ui;
}

void gestion_aziz::show_tables()
{
    show_materiel();
    show_vehicule();
}

void gestion_aziz::clear_form()
{
ui->id->clear();
ui->nom->clear();
ui->matricule->clear();

ui->type->setCurrentIndex(0);
ui->type_2->setCurrentIndex(0);
ui->couleur->setCurrentIndex(0);

ui->quantite->setValue(0);
ui->consomation->setValue(0);
}

/*********************************** materiel ****************************/

//form
//get form content
int gestion_aziz::quantite() const { //combo box

    return ui->quantite->value();
}

QString gestion_aziz::nom() const { //combo box

    return ui->nom->text();
}

QString gestion_aziz::type2() const { //combo box

    return ui->type_2->currentText();
}


QString gestion_aziz::id() const { //line edit

    return ui->id->text();
}

//remplissage des champs du formulaire a partir de la base

void gestion_aziz::fill_form(QString selected ) {
    QSqlQuery query;
    query.prepare("select * from MATERIEL where ID= :id");
    query.bindValue(":id", selected);
    query.exec();
    while(query.next()){
  ui->id->setText(query.value(0).toString()); //line edit
   ui->quantite->setValue(query.value(3).toInt()); //INT edit
   ui->type_2->setCurrentText(query.value(2).toString()); //combobox
   ui->nom->setText(query.value(1).toString()); //line edit

    }

}





//************************ crud

//ajout
void gestion_aziz::on_actionadd_materiel_clicked()
{
      //recuperation des donnees
        QString s1=id();
        QString s2=type2();
        QString s3=nom();
        int x=quantite();


        //ajout
        materiel mc(s1,s2,s3,x);
        mc.ajouter();

        //refresh du tableau (affichage)
          show_materiel();

          //vider le form
          clear_form();
}

//selection
void gestion_aziz::on_table_materiel_clicked(const QModelIndex &index)
{
    selected_materiel=ui->table_materiel->model()->data(index).toString();
}

//modification
void gestion_aziz::on_table_materiel_doubleClicked(const QModelIndex &index)
{

 fill_form(selected_materiel);



}

void gestion_aziz::on_actionedit_materiel_clicked()
{

    //recuperation des donnees
    QString s2=type2();
    QString s3=nom();
    int x=quantite();


      //mofication
      materiel mc(selected_materiel,s2,s3,x);
      mc.modifier(selected_materiel);

      //refresh du tableau (affichage)
        show_materiel();

        //vider le form
        clear_form();
}


//suppression
void gestion_aziz::on_actiondelete_materiel_clicked()
{
    materiel mc;
  mc.supprimer(selected_materiel);

 //refresh du tableau (affichage)
   show_materiel();
}

//affichage
void gestion_aziz::show_materiel()
{
    //creation model (masque du tableau) : permet recherche et tri
        proxy_materiel = new QSortFilterProxyModel();

     //definir la source (tableau original)
        proxy_materiel->setSourceModel(tmp_materiel.afficher());

     //pour la recherche
        proxy_materiel->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)

        //remplissage tableau avec le masque
        ui->table_materiel->setModel(proxy_materiel);
}

//************************ metiers


//recherche dynamique
void gestion_aziz::on_materiel_sel_col_currentIndexChanged(const QString &arg1)
{
    sel_col_materiel=ui->materiel_sel_col->currentIndex()-1;
    proxy_materiel->setFilterKeyColumn(sel_col_materiel); // chercher dans tout le tableau (-1) ou donner le numero de la colone
}
void gestion_aziz::on_rech_materiel_textChanged(const QString &arg1)
{
    proxy_materiel->setFilterFixedString(arg1);
}

/*********************************** vehicule ****************************/

//get form content
double gestion_aziz::consomation() const { //combo box

    return ui->consomation->value();
}

QString gestion_aziz::couleur() const { //combo box

    return ui->couleur->currentText();
}

QString gestion_aziz::type() const { //combo box

    return ui->type->currentText();
}


QString gestion_aziz::matricule() const { //line edit

    return ui->matricule->text();
}

//remplissage des champs du formulaire a partir de la base

void gestion_aziz::fill_form_2(QString selected ) {
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


//************************ crud

//ajout

void gestion_aziz::on_actionadd_vehicule_clicked()
{

      //recuperation des donnees
        QString s1=matricule();
        double x=consomation();
        QString s2=type();
        QString s3=couleur();


        //ajout
        vehicule mc(s1,s2,s3,x);
        mc.ajouter();

        //refresh du tableau (affichage)
          show_vehicule();

          //vider le form
          clear_form();
}

//selection
void gestion_aziz::on_table_vehicule_clicked(const QModelIndex &index)
{
    selected_vehicule=ui->table_vehicule->model()->data(index).toString();
}

//modification
void gestion_aziz::on_table_vehicule_doubleClicked(const QModelIndex &index)
{


  fill_form_2(selected_vehicule);




}

void gestion_aziz::on_actionedit_vehicule_clicked()
{
    //recuperation des donnees
    double x=consomation();
    QString s2=type();
    QString s3=couleur();



      //mofication
      vehicule mc(selected_vehicule,s2,s3,x);
      mc.modifier(selected_vehicule);

      //refresh du tableau (affichage)
        show_vehicule();

        //vider le form
        clear_form();
}



//suppression
void gestion_aziz::on_actiondelete_vehicule_clicked()
{
    vehicule mc;
  mc.supprimer(selected_vehicule);


 //refresh du tableau (affichage)
   show_vehicule();
}

//affichage
void gestion_aziz::show_vehicule()
{
    //creation model (masque du tableau) : permet recherche et tri
        proxy_vehicule = new QSortFilterProxyModel();

     //definir la source (tableau original)
        proxy_vehicule->setSourceModel(tmp_vehicule.afficher());

     //pour la recherche
        proxy_vehicule->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)

        //remplissage tableau avec le masque
        ui->table_vehicule->setModel(proxy_vehicule);
}

//************************ metiers

//recherche dynamique
void gestion_aziz::on_vehicule_sel_col_currentIndexChanged(const QString &arg1)
{
    sel_col_vehicule=ui->vehicule_sel_col->currentIndex()-1;
    proxy_vehicule->setFilterKeyColumn(sel_col_vehicule); // chercher dans tout le tableau (-1) ou donner le numero de la colone

}
void gestion_aziz::on_rech_vehicule_textChanged(const QString &arg1)
{
    proxy_vehicule->setFilterFixedString(arg1);
}

//imprimer
void gestion_aziz::on_pushButton_5_clicked()
{
vehicule v;
    double tot=v.calcul_consomation();


    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->table_vehicule->model()->rowCount();
    const int columnCount =ui->table_vehicule->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("strTitle")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"
        "<table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0>";
    for (int column = 0; column < columnCount; column++)
      //  if (ui->table_journaliste->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->table_vehicule->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->table_vehicule->isColumnHidden(column)) {
                QString data = ui->table_vehicule->model()->data(ui->table_vehicule->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }


    out <<  "</table>\n";
          out <<  "<table border=1 cellspacing=0 cellpadding=2>\n";
            out << "<tr><th  bgcolor=#f0f0f0>Consomation Totale</th> ";

              out << "<td bkcolor=0>";
              out << tot;
               out << "</td></tr>\n";
                out <<  "</table>\n";
     out <<   "</body>\n"
        "</html>\n";

    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
    if (dialog->exec() == QDialog::Accepted) {
        document->print(&printer);
    }

    delete document;
}


