#include "employeeinfo.h"
#include "ui_employeeinfo.h"
#include "employee.h"
#include "address.h"
#include "phonenumber.h"
#include "bankinformation.h"
#include "editemployeeinfocontrol.h"

#include "addroledialog.h"
#include "addroledialog.h"
#include "salary.h"
#include "status.h"
#include "role.h"

employeeInfo::employeeInfo(QWidget *parent,Employee* tempE):
    QDialog(parent),
    ui(new Ui::employeeInfo)
{
    ui->setupUi(this);
    this->employee = tempE;

}

employeeInfo::~employeeInfo()
{
    delete ui;
    delete employee;
}

void employeeInfo::displayEmployeeInfo()
{
 qDebug() << "called" << endl;





    // GET USER INFO
    QString Fname = this->employee->getFName();
    QString Lname = this->employee->getLName();

    Address* address = this->employee->getAddress();
         QString street     = address->getStreet();
         int streetNum  = address->getStreetNumber();
         QString city       = address->getCity();
         QString province   = address->getProvince();
         QString country    = address->getCountry();
         QString postalCode = address->getPostalCode();

    PhoneNumber* phoneNum = this->employee->getPhoneNumber();
        QString localNum    = phoneNum->getLocalNumber();
        QString countryCode = phoneNum->getCountryCode();
        QString extension   = phoneNum->getExtension();
        QString localCode   = phoneNum->getLocalCode();

   BankInformation* bankInfo = this->employee->getBankInformation();
        int     accountNum = bankInfo->getAccountNumber();
        int     bankNum    = bankInfo->getBankNumber();
        int     branchNum  = bankInfo->getBranchNumber();
        QString bankName   = bankInfo->getBankName();


    int eID = this->employee->getEmployeeNumber();
    int sin = this->employee->getSIN();




    //Salary* salaryInfo = this->employee->get
    //float salaryDeduct;

    // SET LABEL INFO
//SetEmployeeID
    ui->label_eID->setText(QString::number(eID));

// SetFirstName LastName
    ui->label_Fname->setText(Fname);
    ui->label_Lname->setText(Lname);

//SetPhoneNumber
    ui->label_localNum->setText(localNum);
    ui->label_countryCode->setText(countryCode);
    ui->label_extension->setText(extension);
    ui->label_localCode->setText(localCode);

// SetAddress
    ui->label_street->setText(street);
    ui->label_streetNum->setText(QString::number(streetNum));
    ui->label_city->setText(city);
    ui->label_province->setText(province);
    ui->label_country->setText(country);
    ui->label_postalCode->setText(postalCode);

//Set BankInformation
    ui->label_accountNum->setText(QString::number(accountNum));
    ui->label_bankNum->setText(QString::number(bankNum));
    ui->label_branchNum->setText(QString::number(branchNum));
    ui->label_bankName->setText(bankName);

//Set DeductionPercenatge
    ui->label_deductionPerc->setText(QString::number(accountNum));

//Set SIN
    ui->label_sin->setText(QString::number(sin));

//Set Roles
    int roles = this->employee->getNumRoles();
     qDebug() << roles;

     for(int i =0; i < roles; i++){
        Role* tempRole = this->employee->getRoleAtIndex(i);
        Status* status = tempRole->getStatus();
        QString roleType = tempRole->getRole();
        QString employmentType =  status->getEmploymentType();
        QString employmenStatus= status->getEmploymentStatus();
        qDebug() << roleType;
        qDebug() << employmentType;
        qDebug() << employmenStatus;
        const int currentRow2 =  ui->rolesTable->rowCount();
        ui->rolesTable->setRowCount(currentRow2 + 1);
        ui->rolesTable->setItem(currentRow2, 0, new QTableWidgetItem(roleType));
        ui->rolesTable->setItem(currentRow2, 1, new QTableWidgetItem(employmentType));
        ui->rolesTable->setItem(currentRow2, 2, new QTableWidgetItem(employmenStatus));

    }

     //SetTotalSalary
     double totalSalary = computeTotalSalary(this->employee);
     ui->label_salary->setText(QString::number(totalSalary));



}

int employeeInfo::updateEmployeeInfo(){

    // GET USER INFO

    // SetFirstName LastName
    QString Fname       =  ui->label_Fname->text();
    QString Lname       =  ui->label_Lname->text();

    //SetEmployeeID
    int eID             = ui->label_eID->text().toInt();

    // Address
    QString street      =  ui->label_street->text();
    int streetNum       = (ui->label_streetNum->text()).toInt();
    QString city        = ui->label_city->text();
    QString province    = ui->label_province->text();
    QString country     = ui->label_country->text();
    QString postalCode  = ui->label_postalCode->text();



    //PhoneNumber
    QString countryCode = ui->label_countryCode->text();
    QString localCode   = ui->label_localCode->text();
    QString localNum    = ui->label_localNum->text();
    QString extension   = ui->label_extension->text();

           //BankInformation
    int     accountNum  =  ui->label_accountNum->text().toInt();
    int     bankNum     =  ui->label_bankNum->text().toInt();
    int     branchNum   =  ui->label_branchNum->text().toInt();
    QString bankName    =  ui->label_bankName->text();

    //SIN
    int sin             = ui->label_sin->text().toInt();

    PhoneNumber* phoneNum     = new PhoneNumber(countryCode,localCode,localNum,extension);
    Address* address          = new Address(street,streetNum,city,province,country,postalCode);
    BankInformation* bankInfo = new BankInformation(accountNum,bankNum,branchNum,bankName,Fname,Lname);

    int numRoles =  ui->rolesTable->rowCount();
    for(int i =0; i < numRoles; i++){
       Role* tempRole = this->employee->getRoleAtIndex(i);
       Status* status = tempRole->getStatus();
       QString roleType = tempRole->getRole();
       QString employmentType =  status->getEmploymentType();
       QString employmenStatus= status->getEmploymentStatus();
       qDebug() << roleType;
       qDebug() << employmentType;
       qDebug() << employmenStatus;
       const int currentRow2 =  ui->rolesTable->rowCount();
       ui->rolesTable->setRowCount(currentRow2 + 1);
       ui->rolesTable->setItem(currentRow2, 0, new QTableWidgetItem(roleType));
       ui->rolesTable->setItem(currentRow2, 1, new QTableWidgetItem(employmentType));
       ui->rolesTable->setItem(currentRow2, 2, new QTableWidgetItem(employmenStatus));

   }



    //create new Employee with Updated Info
    qDebug() << Fname;
    qDebug() << Lname;

    Employee* eTemp = new Employee(Fname,Lname,eID,phoneNum,address,bankInfo,sin);
    EditEmployeeInfoControl* eControl = new EditEmployeeInfoControl();
    eControl->updateFunctionCaller(eTemp);

    return 1;


}





void employeeInfo::on_updateButton_clicked()
{

    if(this->updateEmployeeInfo())
        close();
}

QString employeeInfo::getRolesString(Employee* emp) {

    int numRoles=0;
        numRoles= emp->getNumRoles();
    qDebug() << "NumRoles " +numRoles;
    QString roles = "";
    for(int i=0; i< numRoles; i++){
        Role* role = emp->getRoleAtIndex(i);
        roles += role->getRole()+",";

    }
    return roles;

}

double employeeInfo::computeTotalSalary(Employee* employee){

    int numberOfRole = employee->getNumRoles();
    double totalSalary = 0.0;
    for(int i= 0; i< numberOfRole ; i++){
        Role* role = employee->getRoleAtIndex(i);
        totalSalary += role->getSalary()->getSalaryAfterDeduction();
    }

    return totalSalary;
}

void employeeInfo::on_addButton_clicked()
{
    addRoleDialog* addRoleD = new addRoleDialog(this,newRole);
    addRoleD->setModal(true);
    addRoleD->exec();
    qDebug()<< "NewRole" +newRole->getRole();
    EditEmployeeInfoControl* eControl = new EditEmployeeInfoControl();
    eControl->updateEmployeeRole(newRole,employee->getEmployeeNumber());
}

void employeeInfo::on_deleteButton_clicked()
{
    int currentrow =  ui->rolesTable->currentRow();
    QTableWidgetItem *itab =  ui->rolesTable->item(currentrow,0);
    QString itabtext = itab->text();

    //this->employee->removeRole(itabtext);
    ui->rolesTable->removeRow(currentrow);

}