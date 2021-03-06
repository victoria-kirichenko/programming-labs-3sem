#define CATCH_CONFIG_MAIN
#include "labs123.cpp"
#include "methods_for_2_lab.cpp"
#include "methods_for_3_lab.cpp"
#include "lab4/class_Event.cpp"
#include "lab4/class_TimeString.cpp"
#include "lab5/stack.cpp"
#include "lab7/template.cpp"
#include "catch.hpp"

TEST_CASE("combo and weird date (+Seconds/+Day)") {
	DateTime date(31, 12, 2021, 13, 40, 59);
	date.PlusSeconds();
	date.PlusDay();
    bool check = false;
    if (date.GetDay() == 1 && date.GetSeconds() == 0 && date.GetMonth() == 1 && date.GetYear() == 2022 && date.GetMinutes() == 41) {
        check = true;
    }
    REQUIRE(check);
}

TEST_CASE("1th march minus day") {
    DateTime date(1, 3, 2021, 10, 50, 30);
    date.MinusDay();
    bool check = false;
    if (date.GetDay() == 28 && date.GetMonth() == 2) {
        check = true;
    }
    REQUIRE(check);
}

TEST_CASE("Print() with parametres") {
    DateTime date(15, 10, 1345, 16, 32, 12);
    char* mas1 = { date.GetDateTime() };
    char mas2[20] = "15.10.1345 16:32:12";
    REQUIRE(!memcmp(mas1, mas2, 19));
}

TEST_CASE("Print() without parametres") {
    DateTime date;
    char* mas1 = { date.GetDateTime() };
    char mas2[20] = "01.01.1000 00:00:00";
    REQUIRE(!memcmp(mas1, mas2, 19));
}

TEST_CASE("24 hours + 1 hour") {
    DateTime date(4, 5, 2020, 23, 30, 40);
    bool check = false;
    date.PlusHours();
    if (date.GetHours() == 0 && date.GetDay() == 5) {
        check = true;
    }
    REQUIRE(check);
}

TEST_CASE("valid date: 31.07 - 1 month") {
    DateTime date(31, 7, 2020, 20, 30, 40);
    bool check = false;
    date.MinusMonth();
    if (date.GetMonth() == 6 && date.GetDay() == 30) {
        check = true;
    }
    REQUIRE(check);
}

TEST_CASE("Plus Year") {
    DateTime date(31, 7, 2020, 20, 30, 40);
    bool check = false;
    date.PlusYear();
    if (date.GetYear() == 2021) {
        check = true;
    }
    REQUIRE(check);
}

TEST_CASE("Plus Minute") {
    DateTime date(31, 7, 2020, 20, 32, 40);
    bool check = false;
    date.PlusMinutes();
    if (date.GetMinutes() == 33) {
        check = true;
    }
    REQUIRE(check);
}

TEST_CASE("copy") {
    DateTime date(31, 7, 2020, 20, 32, 40);
    DateTime date1(date);
    char* mas = { date.GetDateTime() };
    char* mas1 = { date1.GetDateTime() };
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("Minus hour + auto minus year") {
    DateTime date(1, 1, 2022, 0, 20, 40);
    date.MinusHours();
    char *mas = { date.GetDateTime() };
    char mas1[20] = "31.12.2021 23:20:40";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("Minus year + leap year") {
    DateTime date(29, 2, 2024, 22, 34, 12);
    date.MinusYear();
    char *mas = { date.GetDateTime() };
    char mas1[20] = "28.02.2023 22:34:12";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("Plus Month") {
    DateTime date(29, 2, 2024, 22, 34, 12);
    date.PlusMonth();
    char *mas = { date.GetDateTime() };
    char mas1[20] = "29.03.2024 22:34:12";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("Minus second + auto minus minute") {
    DateTime date(29, 2, 2024, 22, 34, 0);
    date.MinusSeconds();
    char *mas = { date.GetDateTime() };
    char mas1[20] = "29.02.2024 22:33:59";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("Minus minute + auto minus hour") {
    DateTime date(29, 2, 2024, 22, 0, 1);
    date.MinusMinutes();
    char *mas = { date.GetDateTime() };
    char mas1[20] = "29.02.2024 21:59:01";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("combo: copy + weird date + plus hour") {
    DateTime date(29, 2, 2024, 23, 7, 7);
    DateTime date1(date);
    bool check = false;
    char* mas = { date.GetDateTime() };
    char* mas1 = { date1.GetDateTime() };
    check = !memcmp(mas, mas1, 19);
    date1.PlusHours();
    char* mas2 = { date1.GetDateTime() };
    char mas3[20] = "01.03.2024 00:07:07";
    REQUIRE(!memcmp(mas2, mas3, 19));
}

TEST_CASE("operator =") {
    DateTime date1(29, 2, 2024, 23, 7, 7);
    DateTime date2(23, 1, 2021, 13, 12, 45);
    date1 = date2;
    char* mas = { date1.GetDateTime() };
    char mas1[20] = "23.01.2021 13:12:45";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("operator adding dates") {
    DateTime date1(3, 3, 2021, 13, 14, 15);
    DateTime date2(3, 3, 2021, 14, 12, 35);
    DateTime p = date1 + date2;
    char* mas = { p.GetDateTime() };
    char mas1[20] = "07.06.4042 04:26:50";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("operator subtracting dates") {
    DateTime date1(3, 3, 2021, 13, 14, 15);
    DateTime date2(2, 2, 2020, 12, 12, 10);
    DateTime p = date1 - date2;
    char* mas = { p.GetDateTime() };
    char mas1[20] = "01.01.0001 01:02:05";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("operator char*") {
    DateTime date1(3, 3, 2021, 13, 14, 15);
    char* r = date1;
    char mas1[20] = "03.03.2021 13:14:15";
    REQUIRE(!memcmp(r, mas1, 19));
}

TEST_CASE("operator adding number in hours") {
    DateTime date1(3, 3, 2021, 23, 14, 15);
    date1 = date1 + 4;
    char mas1[20] = "04.03.2021 03:14:15";
    REQUIRE(!memcmp(date1, mas1, 19));
}

TEST_CASE("operator subtragting number in hours") {
    DateTime date1(3, 3, 2021, 1, 14, 15);
    date1 = date1 - 4;
    char mas1[20] = "02.03.2021 21:14:15";
    REQUIRE(!memcmp(date1, mas1, 19));
}

TEST_CASE("adding wierd dates") {
    DateTime date1(30, 11, 2021, 23, 59, 59);
    DateTime date2(1, 1, 1, 0, 0, 1);
    DateTime p = date1 + date2;
    char* mas = { p.GetDateTime() };
    char mas1[20] = "01.01.2023 00:00:00";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("subtragting weird dates") {
    DateTime date1(1, 1, 2021, 0, 0, 0);
    DateTime date2(1, 1, 1, 1, 1, 1);
    DateTime p = date1 - date2;
    char* mas = { p.GetDateTime() };
    char mas1[20] = "29.11.2019 22:58:59";
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("checking operators << and >>") {
    DateTime d(1,12,2022,12,12,12);
    ofstream out("txt_and_dat_files/text.txt");
    ifstream in("txt_and_dat_files/text.txt");
    out << d;
    char mas[20];
    char* mas1;
    bool check = true;
    out.close();
    while (!in.eof()) {
        in.getline(mas, 20);
    }
    mas1 = d.GetDateTime();
    REQUIRE(!memcmp(mas, mas1, 19));
}

TEST_CASE("checking operators writeBinary and readBinary") {
    DateTime d(1,12,2022,12,12,12);
    DateTime d1;
    ofstream to_binary("txt_and_dat_files/binary.dat");
    writeBinary(to_binary, d);
    to_binary.close();
    ifstream from_binary("txt_and_dat_files/binary.dat");
    readBinary(from_binary, d1);
    REQUIRE(!memcmp(d.GetDateTime(), d1.GetDateTime(), 19));
}

TEST_CASE("class Event + construct with parametres") {
    Event event("rave", "ebny room nsk", 25, 6, 2021, 22, 0, 0);
    char* mas = { event.GetEvent() };
    char mas1[50] = "rave ebny room nsk 25.06.2021 22:00:00";
    REQUIRE(!memcmp(mas, mas1, 38));
}

TEST_CASE("class Event + construct with no parametres") {
    Event event;
    char* mas = { event.GetEvent() };
    char mas1[50] = "Rave Moscow 01.01.1000 00:00:00";
    REQUIRE(!memcmp(mas, mas1, 31));
}

TEST_CASE("SetName() + SetCity()") {
    Event event;
    event.SetName("Club");
    event.SetCity("New York");
    char* mas = { event.GetEvent() };
    char mas1[50] = "Club New York 01.01.1000 00:00:00";
    REQUIRE(!memcmp(mas, mas1, 33));
}

TEST_CASE("class TimeString + construct with parametres + operator adding") {
    TimeString time("18:24:45", 26, 10, 2021);
    time = time+10;
    time.SetTimeIntAfterOperators(time.GetHours(), time.GetMinutes(), time.GetSeconds());
    const char* mas = { time.GetTime() };
    char mas1[10] = "04:24:45";
    REQUIRE(!memcmp(mas, mas1, 8));
}

TEST_CASE("class TimeString + construct with parametres + operator substragting") {
    TimeString time("00:00:00", 13, 10, 2021);
    time = time-10;
    time.SetTimeIntAfterOperators(time.GetHours(), time.GetMinutes(), time.GetSeconds());
    const char* mas = { time.GetTime() };
    char mas1[10] = "14:00:00";
    REQUIRE(!memcmp(mas, mas1, 8));
}

TEST_CASE("Push 3 elem in diff classes") {
    DateTime date(12, 12, 2021, 10, 11, 12);
    TimeString time("10:10:10", 3, 11, 2021);
    Event event("Angina", "NSK", 6, 11, 2021, 9, 0, 0);
    List list;
    list.Push(date);
    list.Push(time);
    list.Push(event);
    char *mas = { list.Show() };
    int s = event.SizeOfDate();
    char *mas1 = new char[s];
    strcpy(mas1, event.GetEvent());
    strcat(mas1, "\n");
    strcat(mas1, time.GetDateTime());
    strcat(mas1, "\n");
    strcat(mas1, date.GetDateTime());
    strcat(mas1, "\n");
    REQUIRE(!memcmp(mas, mas1, strlen(mas1)));
}

TEST_CASE("Push, Pop ans search") {
    DateTime date(12, 12, 2021, 10, 11, 12);
    TimeString time("10:10:10", 3, 11, 2021);
    Event event("Angina", "NSK", 6, 11, 2021, 9, 0, 0);
    List list;
    list.Push(date);
    list.Push(time);
    list.Push(event);
    list.Pop();
    int idx = list.Search(time);
    REQUIRE(idx == 0);
    char *mas = { list.Show() };
    int s = event.SizeOfDate();
    char *mas1 = new char[s];
    strcpy(mas1, time.GetDateTime());
    strcat(mas1, "\n");
    strcat(mas1, date.GetDateTime());
    strcat(mas1, "\n");
    REQUIRE(!memcmp(mas, mas1, strlen(mas1)));
}

TEST_CASE("Template DateTime") {
    DateTime date(12, 12, 2021, 10, 11, 12);
    DateTime date1;
    DateTime date2(13, 3, 2020, 1, 1, 1);
    ListT<DateTime> list;
    list.Push(date);
    list.Push(date1);
    list.Push(date2);
    char *mas = { list.Show() };
    int s = date2.SizeOfDate();
    char *mas1 = new char[s];
    strcpy(mas1, date2.GetDateTime());
    strcat(mas1, "\n");
    strcat(mas1, date1.GetDateTime());
    strcat(mas1, "\n");
    strcat(mas1, date.GetDateTime());
    strcat(mas1, "\n");
    REQUIRE(!memcmp(mas, mas1, strlen(mas1)));
}

TEST_CASE("Template TimeString") {
    TimeString date("10:11:12", 12, 12, 2021, 10, 11, 12);
    TimeString date1;
    ListT<TimeString> list;
    list.Push(date);
    list.Push(date1);
    char *mas = { list.Show() };
    int s = date1.SizeOfDate();
    char *mas1 = new char[s];
    strcpy(mas1, date1.GetDateTime());
    strcat(mas1, "\n");
    strcat(mas1, date.GetDateTime());
    strcat(mas1, "\n");
    REQUIRE(!memcmp(mas, mas1, strlen(mas1)));
}

TEST_CASE("Template Event") {
    Event date("zhhhh", "RRR", 12, 12, 2021, 10, 11, 12);
    Event date1;
    ListT<Event> list;
    list.Push(date);
    list.Push(date1);
    list.Pop();
    char *mas = { list.Show() };
    int s = date.SizeOfDate();
    char *mas1 = new char[s];
    strcpy(mas1, date.GetEvent());
    strcat(mas1, "\n");
    REQUIRE(!memcmp(mas, mas1, strlen(mas1)));
}

TEST_CASE("Template int") {
    int x = 3;
    int y = 456;
    ListT<int> list;
    list.Push(x);
    list.Push(y);
    char *mas = { list.Show() };
    char *mas1 = new char[3];
    sprintf(mas1, "");
    strcat(mas1, "456\n");
    strcat(mas1, "3");
    strcat(mas1, "\n");
    REQUIRE(!memcmp(mas, mas1, strlen(mas1)));
}