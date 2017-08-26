#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <string.h>

#include <QTimer>

QTimer *mTimer = new QTimer();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    connect( mTimer,
        SIGNAL(timeout()),
        this,
        SLOT(mIncrement())
        );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mIncrement() {

    int aux;
    int countDown;

    aux = ui->progressBar->value();
    aux--;
    countDown = ui->progressBar->value();
    countDown--;
    ui->progressBar->setValue(aux);
    ui->label->setText("seconds left: " + QString::number(countDown));

}

void MainWindow::on_pushButton_clicked()
{
    if(mTimer->isActive()) {
      mTimer->stop();
      ui->pushButton->setText("Go");



    } else {
    mTimer->start(1000);
    ui->pushButton->setText("Stop");


    int i=0;
    int diceRoll;

    srand(time(NULL));
    for(i=1; i<2; i++){
        diceRoll = ( rand()%6 ) + i;
        printf("%d \n", diceRoll);
        //printf(time(NULL));

        ui->label_2->setText("return "  + QString::number(diceRoll));

        if(diceRoll==1){QPixmap pix(":/Graphics/graphics/one.png");
     ui->label_3->setPixmap(pix);
        }
        else if(diceRoll==2){QPixmap pix(":/Graphics/graphics/two.png");
     ui->label_3->setPixmap(pix);
        }
        else if(diceRoll==3){QPixmap pix(":/Graphics/graphics/three.png");
     ui->label_3->setPixmap(pix);
        }
        else if(diceRoll==4){QPixmap pix(":/Graphics/graphics/four.png");
     ui->label_3->setPixmap(pix);
        }
        else if(diceRoll==5){QPixmap pix(":/Graphics/graphics/five.png");
     ui->label_3->setPixmap(pix);
        }
        else if(diceRoll==6){QPixmap pix(":/Graphics/graphics/six.png");
     ui->label_3->setPixmap(pix);
        }
        else if(diceRoll==7){QPixmap pix(":/Graphics/graphics/seven.png");
     ui->label_3->setPixmap(pix);
        }
    }


    }


}
