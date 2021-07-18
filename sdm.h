//
// Created by hashim on 4/30/19.
//

#ifndef SDM_HEADER_TEST_SDM_H
#define SDM_HEADER_TEST_SDM_H

#include <iostream>
#include "sqlite3.h"
#include <string>
#include <vector>
#include "sha256.h"
using namespace std;

typedef vector<vector<vector<string>>> get_data_vec;

class Database{
private:
    sqlite3 *db;
    int exit=0;

public:
    void open_database();
    sqlite3** get_db_pointer();
    int* get_status();
    void close_database();
};

class User{
    struct log_in_details {
        string password;
        bool access;
    };
private:
    static int login_callback(void* data, int argc, char** argv, char** azColName);
public:
    bool login(sqlite3 *db, string user, string pass);
};

class Teacher: public User {
private:
    static int teacher_callback(void* data, int argc, char** argv, char** azColName);
public:
    void view_attendance_section(sqlite3 *db, string course_name, char section, get_data_vec* vector_address);
    void view_marks_for_a_section(sqlite3 *db, string course_name, char section, string type, get_data_vec* vector_address);
    void add_attendance(sqlite3 *db, string roll_no, string course_name, string date, char section, char status);
    void change_attendance(sqlite3 *db, string course_name, string roll_no, string date, char section, char status);
    void delete_attendance(sqlite3 *db, string course_name, string roll_no, string date, char section);
    void add_marks(sqlite3 *db, string roll_no, string course_name, char section, string type, string number, string marks, string total_marks, string weightage);
    void edit_student_marks(sqlite3 *db, string roll_no, string course_name, char section, string type, string number, string marks, string total_marks, string weightage);
    void delete_student_marks(sqlite3 *db, string roll_no, string course_name, char section, string type, string number);
    void view_all_attendance_for_a_section(sqlite3 *db, string course_name, char section, get_data_vec* vector_address);
    void view_all_attendance_for_a_student(sqlite3 *db, string course_name, char section, string roll_no, get_data_vec* vector_address);
};

class Student: public User {
private:
    static int student_callback(void* data, int argc, char** argv, char** azColName);
public:
    void view_info(sqlite3 *db, string roll_no, get_data_vec* vector_address);
    void view_all_courses(sqlite3 *db, get_data_vec* vector_address);
    void reg_course(sqlite3 *db, string roll_no, string course_id, string course_name, string name, char section, string status);
    void view_reg_course(sqlite3 *db, string roll_no, get_data_vec* vector_address);
    void view_attendance(sqlite3 *db, string roll_no, string course_name, get_data_vec* vector_address);
    void view_marks(sqlite3 *db, string roll_no, string course_name, get_data_vec* vector_address);
};

class Admin: public User {
public:
    void add_user(sqlite3 *db, string user, string pass);
    void delete_user(sqlite3 *db, string user);
    void forgot_password(sqlite3 *db, string user, string new_pass);
    void add_info(sqlite3 *db, string roll_no, string first_name, string last_name, string father_name, string cnic, string phone, string email);
    void edit_student_info(sqlite3 *db, string column_name, string roll_no, string update_text);
    void add_course(sqlite3 *db, string course_name, string course_id, char section, string assigned_teacher);
    void edit_course_details(sqlite3 *db, string course_name, string course_id, char section, string column_name, string update_text);
    void delete_reg_course(sqlite3 *db, string roll_no, string course_name,char section);
    void change_registered_section(sqlite3 *db, string roll_no, string course_id, string course_name, char section);
    void delete_course(sqlite3 *db, string course_name, char section);
};

#endif //SDM_HEADER_TEST_SDM_H
