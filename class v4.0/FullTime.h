/* Author: Michael Trinh
** CS256-01, Winter 2018
** Project #4
** Description:
**     Reads student data from the data record, which can be listed or searched.
*/

// @file FullTime.h
#ifndef FULLTIME_H
#define FULLTIME_H

#include "student.h"

class FullTime : public Student{

    public:
        FullTime();
        FullTime(string firstName, string lastName, int id, char grade);
        virtual ~FullTime();
        virtual string getStatus() const;
};

#endif //FULLTIME_H
