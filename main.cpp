#include "class_Event.cpp"
#include "labs123.cpp"
#include "labs123.hpp"

int main() {
 /*   DateTime d(34, 13, 2022, 78, 70, 60);
    d.CheckingDay(d.GetDay());
    d.CheckingMonth(d.GetMonth());
    d.CheckingHours(d.GetHours());
    d.CheckingMinutes(d.GetMinutes());
    d.CheckingSeconds(d.GetSeconds());
	DateTime d1(29, 2, 2021, 13, 14, 15);
	d1.CheckingYear(d1.GetYear());
    DateTime d2(0, 0, -1, -1, -1, -1);
    d2.CheckingDay(d2.GetDay());
    d2.CheckingMonth(d2.GetMonth());
    d2.CheckingHours(d2.GetHours());
    d2.CheckingMinutes(d2.GetMinutes());
    d2.CheckingSeconds(d2.GetSeconds());
    d2.CheckingYear(d2.GetYear()); */

    DateTime d(1,12,2022,12,12,12);
    DateTime d2;
    ofstream out("../txt_and_dat_files/text.txt");
    ifstream in("../txt_and_dat_files/text.txt");
    out << d;
    char mas[20];
    char* mas1;
    bool check = true;
    out.close();
    while (!in.eof()) {
        in.getline(mas, 20);
    }
   // in >> mas1;
    check = !memcmp(mas, mas1, 19);
    cout << check;
    in.close();

  //  ifstream is("../txt_and_dat_files/text1.txt");
  //  is >> d;
  //  cout << d.GetDateTime();

  //ofstream binary("../txt_and_dat_files/binary.dat");
  //writeBinary(binary, d);
 // binary.close();

//ifstream frombinary("../txt_and_dat_files/binary.dat");
//readBinary(frombinary, d2);
//cout << d2.GetDateTime();
//frombinary.close();

//Event Event("rave", "ebny room nsk", 25, 6, 2021, 22, 0, 0);
//cout << Event.GetEvent();

}
