create table employee (
employeeid    integer primary key autoincrement,
firstname     char(20) not null,
lastname      char(20) not null,
sinnumber     integer not null unique check(sinnumber > 99999999 and sinnumber < 1000000000),
phonenumber   char(20) ,
street        char(20),
streetnumber  integer,
city          char(20),
province      char(20), 
country       char(20),
postalcode    char(20),
bankname      char(20),
banknumber    integer,
branchnumber  integer,
accountnumber integer);

create table employmentdetails (
employeeid       integer,
roletype         char(20) check (roletype         in ('TA', 'RA', 'Faculty', 'Staff')),
employmentstatus char(20) check (employmentstatus in ('Full-Time', 'Part-Time')),
employmenttype   char(20) check (employmenttype   in ('Term', 'Continuing')),
startdate        date,
enddate          date,
salary           number check(salary > 0),
primary key (employeeid, roletype),
foreign key (employeeid) references employee(employeeid));

create table paystub(
employeeid          integer,
roletype            char(20) check (roletype in ('TA', 'RA', 'Faculty', 'Staff')),
paydate             date,
grossincome         number   check (grossincome > 0),
netincome           number   check (netincome > 0),
taxdeductions       number   check (taxdeductions >= 0 and taxdeductions < 1),
deductionpercentage number   check (deductionpercentage >= 0 and deductionpercentage < 1),
ytdgrossincome      number   check (ytdgrossincome > 0),
ytdnetincome        number   check (ytdnetincome > 0),
ytdtaxdeductions    number   check (ytdtaxdeductions > 0),
primary key (employeeid, roletype, paydate),
foreign key (employeeid) references employee(employeeid));

insert into employee values (1000, 'Fahad',  'Hayat',    120000345, 6130000000, 'Hunt Club Ave', 11, 'Ottawa', 'Ontario', 'Canada', 'K3D1F3', 'TD Bank',     211, 234, 434343);
insert into employee values (1002, 'Troy',   'Havelock', 140764377, 6131111111, 'Bank St',       21, 'Ottawa', 'Ontario', 'Canada', 'T5A1R7', 'TD Bank',     211, 235, 675543);
insert into employee values (1003, 'Mir',    'Abbas',    839426234, 6132222222, 'Lib Rd',        55, 'Ottawa', 'Ontario', 'Canada', 'R5T6O7', 'Scotia Bank', 213, 678, 328479);
insert into employee values (1004, 'Yunwei', 'Li',       345435433, 6133333333, 'Belle St',      78, 'Ottawa', 'Ontario', 'Canada', 'T3A9R0', 'RBC',         212, 998, 435643);

insert into employmentdetails values(1000, 'TA',      'Part-Time', 'Term',       '2017-01-01', '2017-04-30', 500);
insert into employmentdetails values(1000, 'RA',      'Part-Time', 'Term',       '2017-01-01', '2017-04-30', 700);
insert into employmentdetails values(1002, 'Faculty', 'Full-Time', 'Continuing', '2016-04-01', null,         2000);
insert into employmentdetails values(1003, 'Staff',   'Full-Time', 'Continuing', '2015-01-01', null,         1000);
insert into employmentdetails values(1003, 'RA',      'Part-Time', 'Term',       '2017-02-01', '2017-09-30', 700);
insert into employmentdetails values(1003, 'TA',      'Part-Time', 'Term',       '2016-12-01', '2017-03-30', 500);
insert into employmentdetails values(1004, 'TA',      'Part-Time', 'Term',       '2016-11-01', '2017-08-30', 500);
insert into employmentdetails values(1004, 'Staff',   'Part-Time', 'Continuing', '2016-11-01', null,         1000);