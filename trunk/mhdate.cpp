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

#include "mhdate.h"

mHdate::mHdate()
{
    //Find month length:
    month_length = 0;

    Hdate tmpday;
    tmpday.set_hdate(1, get_hmonth(), get_hyear());
    int jd = tmpday.get_julian();

    while( tmpday.get_hmonth() == get_hmonth() )
    {
        month_length++;

        jd++;
        tmpday.set_jd(jd);
    }
}

/*
mHdate::mHdate(Hdate *d)
{
    set_jd(d->get_julian());
}
*/

void mHdate::set_hd(int hd, int hm, int hy)
{
    //Actually set the date
    set_hdate(hd, hm, hy);


    //Find month length:
    month_length = 0;

    Hdate tmpday;
    tmpday.set_hdate(1, hm, hy);
    int jd = tmpday.get_julian();

    while( tmpday.get_hmonth() == get_hmonth() )
    {
        month_length++;

        jd++;
        tmpday.set_jd(jd);
    }


    if ( get_hday() > month_length) set_hdate(month_length, hm, hy);
}

void mHdate::removeMonth()
{
    //Leap year:
    // Go to adar a of meoberet
    if (get_hmonth() == 7 && get_size_of_year() > 365)
    {
        set_hd(get_hday(), 14 , get_hyear());
    }
    // Go to adar b of meoberet
    else if (get_hmonth() == 14)
    {
        set_hd(get_hday(), 13 , get_hyear());
    }
    // Go back to nissan
    else if (get_hmonth() == 13)
    {
        set_hd(get_hday(), 5 , get_hyear());
    }

    //Normall year
    else
    {
        if (get_hmonth() > 1) set_hd(get_hday(), get_hmonth()-1 , get_hyear());
        else
        {
            set_hd(get_hday(), 12 , get_hyear() - 1);
        }
    }

    emit month_changed();
}

void mHdate::addMonth()
{
    //Leap year:
    // Go to adar a of meoberet
    if (get_hmonth() == 5 && get_size_of_year() > 365)
    {
        set_hd(get_hday(), 13, get_hyear());
    }
    // Go to adar b of meoberet
    else if (get_hmonth() == 13)
    {
        set_hd(get_hday(), 14, get_hyear());
    }
    // Go back to nissan
    else if (get_hmonth() == 14)
    {
        set_hd(get_hday(), 7, get_hyear());
    }

    //Normall year
    else
    {
        if (get_hmonth() < 12)
        {
            set_hd(get_hday(), get_hmonth() + 1, get_hyear());
        }
        else
        {
            set_hd(get_hday(), 1 , get_hyear() + 1);
        }
    }

    emit month_changed();
}

void mHdate::removeYear(int i)
{
    set_hd(get_hday(), get_hmonth() , get_hyear() - i);

    if (get_size_of_year() > 365)
    {
        if (get_hmonth() == 6)  set_hd(get_hday(), 13, get_hyear());
    }
    else
        if (get_hmonth() == 14 || get_hmonth() == 13) set_hd(get_hday(), 6, get_hyear());

    emit month_changed();
}

void mHdate::addYear(int i)
{
    set_hd(get_hday(), get_hmonth() , get_hyear() + i);

    //Fix leap year months
    if (get_size_of_year() > 365)
    {
        if (get_hmonth() == 6)  set_hd(get_hday(), 13, get_hyear());
    }
    else
        if (get_hmonth() == 14 || get_hmonth() == 13) set_hd(get_hday(), 6, get_hyear());

    emit month_changed();
}

void mHdate::removeDay()
{
    if (get_hday() > 1) set_hd(get_hday() - 1, get_hmonth(), get_hyear());
    else
    {
        removeMonth();
        set_hd(month_length, get_hmonth(), get_hyear());
    }
}

void mHdate::addDay()
{
    if (get_hday() < month_length) set_hd(get_hday() + 1, get_hmonth(), get_hyear());
    else
    {
        set_hd(1, get_hmonth(), get_hyear());
        addMonth();

    }
}

//Return The day in the omer, starting from 1
int mHdate::getOmerDay()
{
   hdate::Hdate sixteen_nissan;
   sixteen_nissan.set_hdate(16, 7, get_hyear());

   int d = get_julian() - sixteen_nissan.get_julian() + 1;

   if ((d > 49) || (d<0))  d=0;

   return d;
}


bool mHdate::isYomTov(bool hool)
{
    hdate::Hdate todayclone;
    todayclone.set_jd(get_julian());

    if (hool) todayclone.set_diaspora();

    if (todayclone.get_holyday_type() == 1) return true;
    return false;
}

bool mHdate::isErevYomTov(bool hool)
{

    hdate::Hdate tomorrow;
    tomorrow.set_jd(get_julian() + 1);
    if (hool) tomorrow.set_diaspora();

    if (tomorrow.get_holyday_type() == 1) return true;

    return false;

    /*
    int mon = get_hmonth();
    int day = get_hday();
    if (( mon == 1 && ( day == 1 || day == 9 || day == 14 || day == 21) ) || (mon==7 && (day==14 || day==20)) || (mon==9 && day==5))
    {
        return true;
    }

    //
    if (hool)
    {
        if (( mon == 1 && ( day == 1 || day == 10 || day == 15 || day == 22) ) || (mon==7 && (day==15 || day==21)) || (mon==9 && day==6))
        {
            return true;
        }
    }

    return false;
    */
}

int mHdate::getMonthLength() { return month_length; }
