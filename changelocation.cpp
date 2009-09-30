#include "changelocation.h"
#include "ui_changelocation.h"

#include <QProcess>

QProcess *tzproc;

ChangeLocation::ChangeLocation(QWidget *parent, QString *locationName, double *latitude, double *longitude, QString *timeZone, double *elavation)
        : QDialog(parent),  m_ui(new Ui::ChangeLocation)
{
    m_ui->setupUi(this);


    //m_ui->comboBox->addItem("Israel");

    tzproc = new QProcess(this);

    QStringList args;
    args << "-jar" << "/usr/bin/ZmanimCLI.jar" << "-tzl";
    tzproc->start("java", args);
    connect(tzproc, SIGNAL(readyReadStandardOutput()), this, SLOT(gotTZ()));


    locationNameptr = locationName;
    m_ui->locationLine->setText(*locationName);

    latitudeptr = latitude;
    m_ui->latitudeLine->setValue(*latitude);

    longitudeptr = longitude;
    m_ui->longitudeLine->setValue(*longitude);

    timeZoneptr = timeZone;

    elavationeptr = elavation;
    m_ui->elavationLine->setValue(*elavationeptr);
}


void ChangeLocation::gotTZ()
{
    QString str = tzproc->readAllStandardOutput();
    //TODO: fix empty lines that still get through
    if ( str != "" && str != "\n" && str != " " && str != " \n")
    {
        QStringList tz = str.split('\n');
        for( int i=0; i<tz.size(); i++)
        {
            if (tz[i] != "List of valid TimeZones:") m_ui->comboBox->addItem(tz[i]);
        }
    }

    m_ui->comboBox->setCurrentIndex(m_ui->comboBox->findText(*timeZoneptr));
}

ChangeLocation::~ChangeLocation()
{
    delete m_ui;
}

void ChangeLocation::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void ChangeLocation::on_exitBTN_clicked()
{
    close();
}

void ChangeLocation::on_okBTN_clicked()
{

    *locationNameptr = m_ui->locationLine->text();

    *latitudeptr = m_ui->latitudeLine->value();
    *longitudeptr = m_ui->longitudeLine->value();
    *elavationeptr = m_ui->elavationLine->value();

    *timeZoneptr = m_ui->comboBox->currentText();

    emit changed();

    close();
}