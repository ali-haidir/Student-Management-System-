//
// Created by hashim on 5/1/19.
//

#include "sdm.h"

void Database::open_database() {
    sqlite3_open("Student_Database.db", &db);
}

sqlite3** Database::get_db_pointer() {
    return &db;
}

int* Database::get_status() {
    return &exit;
}

void Database::close_database() {
    sqlite3_close(db);
}

int User::login_callback(void *data, int argc, char **argv, char **azColName) {
    log_in_details *check;
    check = (log_in_details *)data;
    if ((check->password) == argv[1]) {
        check->access = true;
    }
    return 0;
}

bool User::login(sqlite3 *db, string user, string pass) {
    string sql = "SELECT * FROM Login where USERNAME='" + user + "'; ";
    log_in_details *logincheck = new log_in_details;
    logincheck->password = sha256(pass);
    logincheck->access = false;
    sqlite3_exec(db, sql.c_str(), login_callback, logincheck, NULL);
    if (logincheck->access) {
        return true;
    } else {
        return false;
    }
    delete logincheck;
}

int Teacher::teacher_callback(void *data, int argc, char **argv, char **azColName) {
    get_data_vec* sec_atten_vec = static_cast<get_data_vec*>(data);
    vector<vector<string>> row;
    vector<string> row1;
    for(int i = 0; i < argc; i++) {
        row1.push_back(argv[i]);
        row.push_back(row1);
        row1.clear();
    }
    sec_atten_vec->push_back(row);

    return 0;
}

void Teacher::view_marks_for_a_section(sqlite3 *db, string course_name, char section, string type, get_data_vec* vector_address) {
    get_data_vec* marks_vec = vector_address;
    string sql = "SELECT ROLL_NO,COURSE_NAME,SECTION,TYPE,NUMBER,MARKS_OBTAINED,TOTAL_MARKS,WEIGHTAGE FROM Marks WHERE COURSE_NAME='" + course_name + "' AND SECTION='" + string(1,section) + "' AND TYPE='" + type + "'; " ;
    sqlite3_exec(db, sql.c_str(), teacher_callback, marks_vec, NULL);
}

void Teacher::view_attendance_section(sqlite3 *db, string course_name, char section, get_data_vec* vector_address) {
    get_data_vec* sec_atten_vec = vector_address;
    string sql="SELECT ROLL_NO,NAME FROM Registered WHERE COURSE_NAME='" + course_name + "' AND SECTION='" + string(1,section) + "'; ";
    sqlite3_exec(db, sql.c_str(), teacher_callback, sec_atten_vec, NULL);
}

void Teacher::add_attendance(sqlite3 *db, string roll_no, string course_name, string date, char section, char status) {
    string sql = "INSERT INTO Attendance (ROLL_NO,COURSE_NAME,DATE,SECTION,STATUS) VALUES('" + roll_no + "','" + course_name + "','" + date + "','" + section + \
		"','" + status + "');";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
}

void Teacher::change_attendance(sqlite3 *db, string course_name, string roll_no, string date, char section, char status) {
    string sql= "UPDATE Attendance set STATUS = '" +  string(1,status) + "' where SECTION='" + string(1,section) + "' AND DATE='" + date +"' AND ROLL_NO='" + roll_no + "'; " \
                "SELECT * from Attendance";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
}

void Teacher::delete_attendance(sqlite3 *db, string course_name, string roll_no, string date, char section) {
    string sql = "DELETE from Attendance where ROLL_NO='" + roll_no + "' AND COURSE_NAME='" + course_name + "' AND DATE='" + date + "' AND SECTION='" + string(1,section) + "'; ";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
}

void Teacher::add_marks(sqlite3 *db, string roll_no, string course_name, char section, string type, string number,
                        string marks, string total_marks, string weightage) {
    string sql="INSERT INTO Marks (ROLL_NO,COURSE_NAME,SECTION,TYPE,NUMBER,MARKS_OBTAINED,TOTAL_MARKS,WEIGHTAGE) VALUES" \
                "('" + roll_no + "','" + course_name + "','" + string(1,section) + "','" + type + "','" + number + "','" + marks + "','" + total_marks + \
                "','" + weightage + "');";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
}

void Teacher::edit_student_marks(sqlite3 *db, string roll_no, string course_name, char section, string type,
                                 string number, string marks, string total_marks, string weightage) {
    string sql = "UPDATE Marks set MARKS_OBTAINED='" + marks + "',TOTAL_MARKS='" + total_marks + "',WEIGHTAGE='" + weightage + "' where ROLL_NO='" + roll_no + "' AND COURSE_NAME='"  + \
    course_name + "' AND SECTION='" + string(1,section) + "' AND TYPE='" + type + "' AND NUMBER='" + number + "'; " \
    "SELECT * from Marks";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
}

void Teacher::delete_student_marks(sqlite3 *db, string roll_no, string course_name, char section, string type,
                                   string number) {
    string sql = "DELETE from Marks where ROLL_NO='" + roll_no + "' AND COURSE_NAME='" + course_name + "' AND SECTION='" + string(1,section) + "' AND TYPE='" + type + "' AND NUMBER='" + number + "'; ";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
}

void Teacher::view_all_attendance_for_a_section(sqlite3 *db, string course_name, char section,
                                                get_data_vec *vector_address) {
    get_data_vec* view_atten_sec = vector_address;
    string sql = "SELECT * from Attendance WHERE COURSE_NAME='" + course_name + "' AND SECTION='" + section + "'; ";
    sqlite3_exec(db, sql.c_str(), teacher_callback, view_atten_sec, NULL);
}

void Teacher::view_all_attendance_for_a_student(sqlite3 *db, string course_name, char section, string roll_no,
                                                get_data_vec *vector_address) {
    get_data_vec* view_atten_student = vector_address;
    string sql = "SELECT ROLL_NO,COURSE_NAME,DATE,SECTION,STATUS from Attendance WHERE COURSE_NAME='" + course_name + "' AND SECTION='" + section + "' AND ROLL_NO='" + roll_no + "'; ";
    sqlite3_exec(db, sql.c_str(), teacher_callback, view_atten_student, NULL);
}

int Student::student_callback(void *data, int argc, char **argv, char **azColName) {
    get_data_vec* view_marks_vec = static_cast<get_data_vec*>(data);
    vector<vector<string>> row;
    vector<string> row1;
    for (int i = 0; i < argc; i++) {
        row1.push_back(argv[i]);
        row.push_back(row1);
        row1.clear();
    }
    view_marks_vec->push_back(row);

    return 0;
}

void Student::view_marks(sqlite3 *db, string roll_no, string course_name, get_data_vec* vector_address) {

    get_data_vec* view_marks_vec = vector_address;

    string sql = "SELECT ROLL_NO,COURSE_NAME,SECTION,TYPE,NUMBER,MARKS_OBTAINED,TOTAL_MARKS,WEIGHTAGE FROM Marks WHERE ROLL_NO='" + roll_no + "' AND COURSE_NAME='" + course_name + "' AND TYPE='Quiz'; " ;
    sqlite3_exec(db, sql.c_str(), student_callback, view_marks_vec, NULL);

    sql = "SELECT ROLL_NO,COURSE_NAME,SECTION,TYPE,NUMBER,MARKS_OBTAINED,TOTAL_MARKS,WEIGHTAGE FROM Marks WHERE ROLL_NO='" + roll_no + "' AND COURSE_NAME='" + course_name + "' AND TYPE='Assignment'; " ;
    sqlite3_exec(db, sql.c_str(), student_callback, view_marks_vec, NULL);

    sql = "SELECT ROLL_NO,COURSE_NAME,SECTION,TYPE,NUMBER,MARKS_OBTAINED,TOTAL_MARKS,WEIGHTAGE FROM Marks WHERE ROLL_NO='" + roll_no + "' AND COURSE_NAME='" + course_name + "' AND TYPE='Project'; " ;
    sqlite3_exec(db, sql.c_str(), student_callback, view_marks_vec, NULL);

    sql = "SELECT ROLL_NO,COURSE_NAME,SECTION,TYPE,NUMBER,MARKS_OBTAINED,TOTAL_MARKS,WEIGHTAGE FROM Marks WHERE ROLL_NO='" + roll_no + "' AND COURSE_NAME='" + course_name + "' AND TYPE='Sessional I'; " ;
    sqlite3_exec(db, sql.c_str(), student_callback, view_marks_vec, NULL);

    sql = "SELECT ROLL_NO,COURSE_NAME,SECTION,TYPE,NUMBER,MARKS_OBTAINED,TOTAL_MARKS,WEIGHTAGE FROM Marks WHERE ROLL_NO='" + roll_no + "' AND COURSE_NAME='" + course_name + "' AND TYPE='Sessional II'; " ;
    sqlite3_exec(db, sql.c_str(), student_callback, view_marks_vec, NULL);

    sql = "SELECT ROLL_NO,COURSE_NAME,SECTION,TYPE,NUMBER,MARKS_OBTAINED,TOTAL_MARKS,WEIGHTAGE FROM Marks WHERE ROLL_NO='" + roll_no + "'AND COURSE_NAME='" + course_name + "' AND TYPE='Mid Term'; " ;
    sqlite3_exec(db, sql.c_str(), student_callback, view_marks_vec, NULL);

    sql = "SELECT ROLL_NO,COURSE_NAME,SECTION,TYPE,NUMBER,MARKS_OBTAINED,TOTAL_MARKS,WEIGHTAGE FROM Marks WHERE ROLL_NO='" + roll_no + "' AND COURSE_NAME='" + course_name + "' AND TYPE='Final'; " ;
    sqlite3_exec(db, sql.c_str(), student_callback, view_marks_vec, NULL);

}

void Student::view_info(sqlite3 *db, string roll_no, get_data_vec* vector_address) {
    get_data_vec* s_info_vec = vector_address;
    string sql="SELECT * from Student_info where ROLL_NO='" + roll_no + "'; ";
    sqlite3_exec(db, sql.c_str(), student_callback, s_info_vec, NULL);
}

void Student::view_all_courses(sqlite3 *db, get_data_vec* vector_address) {
    get_data_vec* course_vec = vector_address;
    string sql = "SELECT * from Courses";
    sqlite3_exec(db, sql.c_str(), student_callback, course_vec, NULL);
}

void Student::view_reg_course(sqlite3 *db, string roll_no, get_data_vec* vector_address) {
    get_data_vec* view_reg_c_vec = vector_address;
    string sql="SELECT * from Registered where ROLL_NO='" + roll_no + "'; ";
    sqlite3_exec(db, sql.c_str(), student_callback, view_reg_c_vec, NULL);
}

void Student::reg_course(sqlite3 *db, string roll_no, string course_id, string course_name, string name, char section,
                         string status) {
    string sql = "INSERT INTO Registered (ROLL_NO,COURSE_ID,COURSE_NAME,NAME,SECTION,STATUS) VALUES('" + roll_no + "','" + course_id + "','" + course_name + "','" + name + "','" + string(1,section) + "','" + status + "');";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
}

void Student::view_attendance(sqlite3 *db, string roll_no, string course_name, get_data_vec* vector_address) {
    get_data_vec* atten_vec = vector_address;
    string sql = "SELECT * from Attendance where ROLL_NO='" + roll_no + "' AND COURSE_NAME='" + course_name + "'; ";
    sqlite3_exec(db, sql.c_str(), student_callback, atten_vec, NULL);
}

void Admin::add_user(sqlite3 *db, string user, string pass) {
    pass = sha256(pass);
    string create = "INSERT INTO Login VALUES ('" + user + "','" + pass + "');";
    sqlite3_exec(db, create.c_str(), NULL, NULL, NULL);
}

void Admin::delete_user(sqlite3 *db, string id) {
    string sql="DELETE from Login where USERNAME='" + id +  "';";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
}

void Admin::forgot_password(sqlite3 *db, string user, string new_pass) {
    string sql=" UPDATE Login set PASSWORD = '" + sha256(new_pass) + "' where USERNAME='" + user + "';";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
}

void Admin::add_info(sqlite3 *db, string roll_no, string first_name, string last_name, string father_name, string cnic,
                     string phone, string email) {
    string sql = "INSERT INTO Student_info VALUES('" + roll_no + "','" + first_name + "','" + last_name + "','" + father_name + \
		"','" + cnic + "','" + phone + "','" + email + "');";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
}

void Admin::edit_student_info(sqlite3 *db, string column_name, string roll_no, string update_text) {
    string sql = "UPDATE Student_info set " + column_name + " = '" + update_text + "' where ROLL_NO='" + roll_no + "';";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
}

void Admin::add_course(sqlite3 *db, string course_name, string course_id, char section, string assigned_teacher) {
    string sql = "INSERT INTO Courses VALUES('" + course_name + "','" + course_id + "','" + section + "','" + assigned_teacher + "');";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
}

void Admin::edit_course_details(sqlite3 *db, string course_name, string course_id, char section, string column_name,
                                string update_text) {
    string sql=" UPDATE Courses set " + column_name + " = '" + update_text + "' where COURSE_NAME='" + course_name + \
            "' AND COURSE_ID='" + course_id + "' AND SECTION='" + string(1,section) + "';";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
}

void Admin::delete_reg_course(sqlite3 *db, string roll_no, string course_name, char section) {
    string sql="DELETE from Registered where COURSE_NAME='" + course_name + "'AND ROLL_NO='" + roll_no + "' AND SECTION='" + string(1,section) + "';";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
}

void Admin::change_registered_section(sqlite3 *db, string roll_no, string course_id, string course_name,
                                      char section) {
    string sql="UPDATE Registered set SECTION='" + string(1,section) + "' where ROLL_NO='" + roll_no + "' AND COURSE_ID='" + course_id + "' AND COURSE_NAME='" + course_name + "'; ";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
}

void Admin::delete_course(sqlite3 *db, string course_name, char section) {
    string sql="DELETE from Courses where COURSE_NAME='" + course_name + "' AND SECTION='" + string(1,section) + "';";
    sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
    sql ="DELETE from Registered where COURSE_NAME='" + course_name + "' AND SECTION='" + string(1,section) + "';";
    sqlite3_exec(db, sql.c_str(),NULL,NULL,NULL);
}
