#include "restarteur.h"
#include "ui_restarteur.h"
#include "QFileDialog"
#include "QMessageBox"
#include "QProcess"
#include "QTimer"

Restarteur::Restarteur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Restarteur)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    RealmdProcess = new QProcess(this);
    WorldProcess = new QProcess(this);

    /*connect(timer, SIGNAL(timeout()), this, SLOT(updateStatut()));
    timer->setInterval(1000);
    timer->start();*/

    connect(RealmdProcess, SIGNAL(finished(int)), this, SLOT(updateStatutRealmd()));
    connect(WorldProcess, SIGNAL(finished(int)), this, SLOT(updateStatutWorld()));



}

Restarteur::~Restarteur()
{
    delete ui;
}

/*========Boutons Parcourir Chemin d'accès=========*/
void Restarteur::on_BoutonCheminAccesRealmd_clicked()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Sélectionner le realmdServer", QString(), "Programmes executable (*.exe)");
    ui->lineEditChemAcces->setText(fichier);
}

void Restarteur::on_BoutonCheminAccesRealmd_2_clicked()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Sélectionner le realmdServer", QString(), "Programmes executable (*.exe)");
    ui->lineEditChemAcces_3->setText(fichier);
}

void Restarteur::on_BoutonCheminAccesWorld_clicked()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Sélectionner le realmdServer", QString(), "Programmes executable (*.exe)");
    ui->lineEditChemAcces_2->setText(fichier);
}
void Restarteur::on_BoutonCheminAccesWorld_2_clicked()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Sélectionner le realmdServer", QString(), "Programmes executable (*.exe)");
    ui->lineEditChemAcces_4->setText(fichier);
}
/*==================================================*/

/*========Boutons Lancer Appli=========*/

void Restarteur::on_BoutonLancerServeur1_clicked()
{
    QString Program = QString(ui->lineEditChemAcces->text());
    RealmdProcess->start(Program);
    ui->LabelEtatRealmd->setText("On");
}
void Restarteur::on_BoutonLancerServeur2_clicked()
{
    QString Program = QString(ui->lineEditChemAcces_2->text());
    WorldProcess->start(Program);
    ui->LabelEtatWorld->setText("On");
}

/*=======Boutons MAJ Serveur==========*/
void Restarteur::on_BoutonMajServeur1_clicked()
{
    QMessageBox::information(this , "Désolé , c'est pas possible" , "Désolé , cette fonction n'est pas encore implantée");
}
void Restarteur::on_BoutonMajServeur2_clicked()
{
    QMessageBox::information(this , "Désolé , c'est pas possible" , "Désolé , cette fonction n'est pas encore implantée");
}

void Restarteur::updateStatutRealmd()
{
       ui->LabelEtatRealmd->setText("Off");
       if(ui->checkBoxRACRealmd->isChecked())
       {
           QString Program = QString(ui->lineEditChemAcces->text());
           RealmdProcess->start(Program);
           ui->LabelEtatRealmd->setText("On");
       }

}
void Restarteur::updateStatutWorld()
{
       ui->LabelEtatWorld->setText("Off");
       if(ui->checkBoxRACWorld->isChecked())
       {
           QString Program = QString(ui->lineEditChemAcces_2->text());
           WorldProcess->start(Program);
           ui->LabelEtatWorld->setText("On");
       }
}

