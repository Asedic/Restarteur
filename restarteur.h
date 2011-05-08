#ifndef RESTARTEUR_H
#define RESTARTEUR_H

#include <QMainWindow>
#include "QFileDialog"
#include "QFile"
#include "qfile.h"
#include "QLabel"
#include "QUrl"
#include "QString"
#include "QProcess"

namespace Ui {
    class Restarteur;
}

class Restarteur : public QMainWindow
{
    Q_OBJECT

public:
    explicit Restarteur(QWidget *parent = 0);
    ~Restarteur();

public slots:
    void on_BoutonCheminAccesRealmd_clicked();
    void on_BoutonCheminAccesRealmd_2_clicked();
    void on_BoutonCheminAccesWorld_clicked();
    void on_BoutonCheminAccesWorld_2_clicked();

    void on_BoutonLancerServeur1_clicked();
    void on_BoutonLancerServeur2_clicked();

    void on_BoutonMajServeur1_clicked();
    void on_BoutonMajServeur2_clicked();

    void updateStatutRealmd();
    void updateStatutWorld();


private:
    Ui::Restarteur *ui;
    QProcess *RealmdProcess;
    QProcess *WorldProcess;
    QTimer *timer;
    bool realmdbool;
    bool worldbool;
};

#endif // RESTARTEUR_H
