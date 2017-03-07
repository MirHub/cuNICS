#include "status.h"
#include <stdio.h>

Status::Status()
{
    Status(false, NO_STATUS, NO_TYPE, NULL, NULL);
}

Status::Status(bool               currentlyEmployed,
               EmploymentStatus   employmentStatus,
               EmploymentType     employmentType,
               Date               *startDate,
               Date               *endDate)
{
    this->currentlyEmployed     = currentlyEmployed;
    this->employmentStatus      = employmentStatus;
    this->employmentType        = employmentType;
    this->startDate             = startDate;
    this->endDate               = endDate;
}

Status::Status(bool               currentlyEmployed,
               QString            employmentStatus,
               QString            employmentType,
               Date               *startDate,
               Date               *endDate)
{
    this->currentlyEmployed     = currentlyEmployed;

    if (employmentType == "Term")
            this->employmentType = TERM;
    else
            this->employmentType = CONTINUING;

    if (employmentStatus == "Full-Time")
            this->employmentStatus = FULL_TIME;
    else
            this->employmentStatus = PART_TIME;

    this->startDate             = startDate;
    this->endDate               = endDate;
}

Status::~Status()
{
    if (startDate != NULL) {
        delete startDate;
    }
    if (endDate != NULL) {
        delete startDate;
    }
}

//----- Getters -----
bool Status::isEmployed()
{
    return currentlyEmployed;
}

QString Status::getEmploymentType()
{
    switch(employmentType)
    {
        case TERM:
            return "Term";
        case CONTINUING:
            return "Continuing";

        default:
        return NULL;
    }
}

QString Status::getEmploymentStatus()
{
    switch(employmentStatus)
    {
        case FULL_TIME:
            return "Full-Time";
        case PART_TIME:
            return "Part-Time";

        default:
        return NULL;
    }
}

Date* Status::getStartDate()
{
    return startDate;
}

Date* Status::getEndDate()
{
    return endDate;
}

//----- Setters -----
bool Status::setCurrentlyEmployed(bool isEmployed)
{
    currentlyEmployed = isEmployed;
    return true;
}

bool Status::setTermPartTimeStatus(Date *startDate, Date *endDate)
{
    if (*endDate < *startDate) {
        return false;
    }

    this->currentlyEmployed = true;
    this->employmentStatus  = PART_TIME;
    this->employmentType    = TERM;
    this->startDate         = startDate;
    this->endDate           = endDate;
    return true;
}

bool Status::setTermFullTimeStatus(Date *startDate, Date *endDate)
{
    if (endDate < startDate) {
        return false;
    }

    this->currentlyEmployed = true;
    this->employmentStatus  = FULL_TIME;
    this->employmentType    = TERM;
    this->startDate         = startDate;
    this->endDate           = endDate;
    return true;
}

bool Status::setContinuingFullTimeStatus(Date *startDate)
{
    this->currentlyEmployed = true;
    this->employmentStatus  = FULL_TIME;
    this->employmentType    = CONTINUING;
    this->startDate         = startDate;
    this->endDate           = NULL;
    return true;
}

bool Status::setContinuingPartTimeStatus(Date *startDate)
{
    this->currentlyEmployed = true;
    this->employmentStatus  = PART_TIME;
    this->employmentType    = CONTINUING;
    this->startDate         = startDate;
    this->endDate           = NULL;
    return true;
}
