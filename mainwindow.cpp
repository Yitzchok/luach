/* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2
* as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* Author: Moshe Wagner. <moshe.wagner@gmail.com>
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

/*

  Kaluach clone:

  Should have some day:

    - Basic "calandar" like interface ( custom widget )
        - Hebrew / English date
        - Change date, location, timezone
        - Events?
    - Connection to "ZmanimCLI"
    - Daf yomi (shiftan?), eventually add other "yomi" stuff
    - Print snapshots?

    - Other cool features of course

*/

//TODO: Make g_date smaller
//TODO: Add no g_date option
//TODO: Align holidays to center
//TODO: Sfirat Hoomer
//TODO: Days of חנוכה וחול המועד



//TODO: OK, clean all this mess up...
//TODO: Comments! comments, comments comments!

//List of all day button shown
QList <dayButton *> dayList;
//Points to the selected button
dayButton * lastselected;

QStringList weekdays;
QStringList engmonths;

QProcess *zmanimproc;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set all QString to work with unicode
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));

    connect( &current, SIGNAL(month_changed()), this, SLOT(redraw()));


    weekdays << "ראשון" << "שני" << "שלישי" << "רביעי" << "חמישי" << "שישי" << "שבת";

    engmonths << "ינואר" << "פברואר" << "מרס" << "אפריל" << "מאי" << "יוני" << "יולי" << "אוגוסט" << "ספטמבר" << "אוקטובר" << "נובמבר" << "דצמבר";
    
    lastselected = NULL;


    //Force the locale to hebrew, so Hdate will give Hebrew strings. Yup, I don't like this either.
    // TODO: test on windows
    setlocale (LC_ALL, "he_IL.UTF-8");
    
    //Add weekday labels
    for (int i=0; i<7; i++)
    {
        QLabel *lbl = new QLabel(weekdays[i]);
        lbl->setLayoutDirection(Qt::RightToLeft);
        lbl->setAlignment(Qt::AlignCenter);
        ui->gridLayout->addWidget(lbl, 0, i);

        QFont q; q.setBold(true); q.setPixelSize(20);
        lbl->setFont(q);
        //lbl->setStyleSheet("QLabel { background-color: blue }");
        //lbl->setBackgroundRole(QPalette::Highlight);
    }

    //A defualt Hdate class has today's date
    Hdate today, d;

    current.set_hd(today.get_hday(), today.get_hmonth(), today.get_hyear());

    d.set_hdate(1, today.get_hmonth(), today.get_hyear());
    showMonth(&d);

    //Current time (do something with this):
    QTime t;
    print (t.currentTime ().toString());


}


//Rebuild the calendar from the given first day of the month
void MainWindow::showMonth(Hdate *firstday)
{
    //Clear last month
    clearMonth();

    updateLabels(&current);

    //A defualt Hdate class has today's date
    Hdate today;

    Hdate tmpday;
    tmpday.set_hdate(firstday->get_hday(), firstday->get_hmonth(), firstday->get_hyear());

    int jd = tmpday.get_julian();
    int firstweekday = tmpday.get_day_of_the_week()-1;

    QSize widest(0,0);

    for (int i = firstweekday; tmpday.get_hmonth() == firstday->get_hmonth(); i++)
    {
        //
        //print (tmpday.get_format_date(0));

        dayButton *d = new dayButton(this, jd);
        dayList << d;

        ui->gridLayout->addWidget(d, 1+(i/7), (i%7));

        connect(d, SIGNAL(clicked(dayButton*)), this, SLOT(dayClicked(dayButton*)));

        jd++;
        tmpday.set_jd(jd);

        //Find the biggest button's minimum size
        if (d->sizeHint().width() > widest.width()) widest = d->sizeHint();

    }

    if (lastselected != NULL) lastselected->Unselect();

    //Force all buttons to the size of the biggest one
    for (int i = 0; i<dayList.size(); i++)
    {
        dayList[i]->setMinimumSize(widest);
    }

    if (current.get_julian() - firstday->get_julian() >= 0 && current.get_julian() - firstday->get_julian() < dayList.size())
    {
        dayList[current.get_julian() - firstday->get_julian()]->Select();
        lastselected = dayList[current.get_julian() - firstday->get_julian()];
    }

    if (firstday->get_hmonth() == today.get_hmonth() && firstday->get_hyear() == today.get_hyear()) dayList[today.get_julian() - firstday->get_julian()]->setToday();
}

void MainWindow::clearMonth()
{
    for (int i = 0; i<dayList.size(); i++)
    {
        if (dayList[i] != NULL) delete dayList[i];
    }
    dayList.clear();
}

void MainWindow::redraw()
{
    lastselected = NULL;

    Hdate d;
    d.set_hdate(1, current.get_hmonth(),  current.get_hyear());
    showMonth(&d);
}

void MainWindow::dayClicked(dayButton * day)
{
    if (lastselected != NULL) lastselected->Unselect();

    day->Select();
    lastselected = day;

    current.set_jd(day->getHDate()->get_julian());

    updateLabels(&current);
}

void MainWindow::readFromStdout()
{
    //print( QString(proc->readAllStandardOutput()) );
}

MainWindow::~MainWindow()
{
    clearMonth();

    delete ui;
}

//TODO:
void MainWindow::changeDay(int i)
{
    if (i < 0)
    {
        for (int j=0; j > i; j--) current.removeDay();
    }
    else
    {
        for (int j=0; j < i; j++) current.addDay();
    }

    if (lastselected != NULL) lastselected->Unselect();

    dayList[current.get_julian() - dayList[0]->getHDate()->get_julian()]->Select();
    lastselected = dayList[current.get_julian() - dayList[0]->getHDate()->get_julian()];

    updateLabels(&current);
}

void MainWindow::on_backMonthBTN_clicked()
{
    current.removeMonth();
}

void MainWindow::on_nextMonthBTN_clicked()
{
    current.addMonth();
}

void MainWindow::on_backYearBTN_clicked()
{
    current.removeYear();
}

void MainWindow::on_nextYearBTN_clicked()
{
    current.addYear();
}

void MainWindow::on_backDayBTN_clicked()
{
    changeDay(-1);
}

void MainWindow::on_nextDayBTN_clicked()
{
    changeDay(1);
}

void MainWindow::on_doublenextYearBTN_clicked()
{
    current.addYear(10);
}

void MainWindow::on_doublebackYearBTN_clicked()
{
    current.removeYear(10);
}

void MainWindow::updateLabels(mHdate *date)
{
    ui->monthlabel->setText(date->get_hebrew_month_string(0));
    ui->yearlabel->setText(date->get_hebrew_year_string());
    ui->engyearlbl->setText(stringify(date->get_gyear()));
    ui->hmonthlbl->setText(date->get_hebrew_month_string(0));


    ui->daylabel->setText(current.get_hebrew_day_string());
    ui->engdaylbl->setText(stringify(current.get_gday()));
    ui->engmonthlbl->setText(engmonths[current.get_gmonth() - 1]);

    Hdate e;

    e.set_hdate(1, date->get_hmonth(), date->get_hyear());
    QString gmonths = engmonths[e.get_gmonth() - 1];

    e.set_hdate(date->getMonthLength(), date->get_hmonth(), date->get_hyear());
    if (engmonths[e.get_gmonth()-1] != gmonths) gmonths += " - " + engmonths[e.get_gmonth()-1];
    ui->gmonthlbl->setText(gmonths);



    //Show times:

    delete zmanimproc;
    zmanimproc = new QProcess(this);

    QStringList args;

    QString dstr = stringify(date->get_gyear()) + "/" + stringify(date->get_gmonth()) + "/" + stringify(date->get_gday());

    args << "-jar" << "/usr/bin/ZmanimCLI.jar" << "-d" << dstr;
    zmanimproc->start("java", args);

    connect(zmanimproc, SIGNAL(readyReadStandardOutput()), this, SLOT(gotTimes()));
}

void MainWindow::gotTimes()
{
    QString str =  zmanimproc->readAllStandardOutput();

    QStringList times = str.split('\n');

    for (int i=0; i<times.size(); i++)
    {
        QString t = times[i].mid(times[i].lastIndexOf(" "));
        //A time
        if (times[i][0] == '*')
        {
            if (times[i].startsWith("* AlosHashachar:") == true)
            {
                //Clear all labels, as this is the first time:
                // (Maybe unneccesary: )
                ui->sunriselabel->setText("");
                ui->shmamgalbl->setText("");
                ui->shmagralbl->setText("");
                ui->tfilamgalbl->setText("");
                ui->tfilagralbl->setText("");
                ui->hatzotlbl->setText("");
                ui->minchagdolalbl->setText("");
                ui->minchaktanalbl->setText("");
                ui->plaglbl->setText("");
                ui->skialbl->setText("");
                ui->tzitslbl->setText("");
                ui->tzits72lbl->setText("");


                //Show alos
                ui->aloslabel->setText(t);
            }
            if (times[i].startsWith("* sunrise:") == true)
            {
                ui->sunriselabel->setText(t);
            }
            if (times[i].startsWith("* SofZmanShmaMGA:") == true)
            {
                ui->shmamgalbl->setText(t);
            }
            if (times[i].startsWith("* SofZmanShmaGRA:") == true)
            {
                ui->shmagralbl->setText(t);
            }
            if (times[i].startsWith("* SofZmanTfilaMGA:") == true)
            {
                ui->tfilamgalbl->setText(t);
            }
            if (times[i].startsWith("* SofZmanTfilaGRA:") == true)
            {
                ui->tfilagralbl->setText(t);
            }
            if (times[i].startsWith("* Chatzos:") == true)
            {
                ui->hatzotlbl->setText(t);
            }
            if (times[i].startsWith("* MinchaGedola:") == true)
            {
                ui->minchagdolalbl->setText(t);
            }
            if (times[i].startsWith("* MinchaKetana:") == true)
            {
                ui->minchaktanalbl->setText(t);
            }
            if (times[i].startsWith("* PlagHamincha:") == true)
            {
                ui->plaglbl->setText(t);
            }
            if (times[i].startsWith("* Sunset:") == true)
            {
                ui->skialbl->setText(t);
            }
            if (times[i].startsWith("* Tzais:") == true)
            {
                ui->tzitslbl->setText(t);
            }
            if (times[i].startsWith("* Tzais72:") == true)
            {
                ui->tzits72lbl->setText(t);
            }


            ui->dafyomilbl->setText(dafYomi(current.get_julian()));
        }
    }
}


//TODO: fix this!!!
QString MainWindow::dafYomi(int jd)
{
    QStringList masehtot;

    masehtot << "ברכות" << "שבת" << "עירובין" << "פסחים" << "שקלים" << "יומא" << "סוכה" << "ביצה" << "ראש השנה" << "תענית" << "מגילה" << "מועד קטן" << "חגיגה" << "יבמות" << "כתובות" << "נדרים" << "נזיר" << "סוטה" << "גיטין" << "קידושין" << "בבא קמא" << "בבא מציעא" << "בבא בתרא" << "סנהדרין" << "מכות" << "שבועות" << "עבודה זרה" << "הוריות" << "זבחים" << "מנחות" << "חולין" << "בכורות" << "ערכין" << "תמורה" << "כריתות" << "מעילה" << "נידה";

    QList <int> dapim;
    dapim << 64 << 157 << 105 << 121 << 22 << 88 << 56 << 40 << 35 << 31 << 32 << 29 << 27 << /*Yevamot*/122 << 112 << 91 << 66 << 49 << 90 << 82 << /*Bava Kama*/119 << 119 << 176 << 113 << 24 << 49 << 76 << 14 << /*Zevahim*/120 << 110 << 142 << 61 << 34 << 34 << 28 << 37 << 73;

    int numDapim = 0;
    for (int i=0; i<dapim.size(); i++) numDapim += dapim[i] - 1;

    Hdate d; d.set_hdate(26,10,5683);

    int i=(jd - d.get_julian()+1) % numDapim;

    if ( i < 0 ) return "";
    else if (i==0) i = numDapim;

    int masehet=0;

    while (dapim[masehet]-1 < i)
    {
        i-=dapim[masehet++]-1;

    }
    
    return masehtot[masehet] + ' ' + NumberToGematria(i+1, false);

}



void MainWindow::keyPressEvent( QKeyEvent *keyEvent )
{
    if ( keyEvent->key() == Qt::Key_Left)
    {
        changeDay(1);
    }
    else if ( keyEvent->key() == Qt::Key_Right)
    {
        changeDay(-1);
    }
    else if ( keyEvent->key() == Qt::Key_Up)
    {
        //Move week back:
         changeDay(-7);
    }
    else if ( keyEvent->key() == Qt::Key_Down)
    {
        //Move week ahead:
         changeDay(7);
    }
}

