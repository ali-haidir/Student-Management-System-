//
// Created by Ali on 5/1/19.
//

#include "sdm.h"

int main(){

    Database d1;
    d1.open_database();
    sqlite3** db = d1.get_db_pointer();

    Student s1;
    get_data_vec s_info_vec;
    s1.view_info(*db, "18P-0012", &s_info_vec));
    for(int i=0; i<s_info_vec.size(); i++){
        for(int j=0; j<s_info_vec[i].size(); j++){
            cout<<s_info_vec[i][j][0];
        }
    }

    d1.close_database();

}
