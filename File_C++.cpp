#include<bits/stdc++.h>
#include<string.h>
#include<conio.h>
#include <fstream>
#include <filesystem>
#include <cstdlib> 
#include <ctime> 
#include <chrono>
#define max 100
using namespace std;
using namespace std::chrono; // Namespace cho các hàm thời gian
ofstream feedbackFile("feedback.csv", ios::app);

class User
{
public:
    char ten[1000];
    char dia_chi[1000];
    char id[1000];
    char sdt[12];
    char date[20];
    float payment_advance;
    int booking_id;
};

class Event
{
public:
    int time;
    char stype;
    string ven;
    int gs;
    int EventNumber;
    int cost;
    int info;
    class User usr;
    class Event addEvent(int);
    void searchEvent(int);
    void deleteEvent(int);
    void displayEvent(Event);
	void xemPhongThuy();

};
class Event Events[max];
int cnt=0;
Event Event::addEvent(int ev)
{
    class Event Event;
    Event.EventNumber=ev;
    cout<<"\n  So_Khach_Moi : ";
    cin>>Event.gs;
    cout<<"\n  Tong_Thoi_Gian   : ";
    cin>>Event.time;
    cout<<"\n  Dia_Diem : ";
    cin>>Event.ven;
    Event.info=0;
    cout<<"\n  Tao Su Kien Thanh Cong ";
    getch();
    return Event;
}
void Event::searchEvent(int ev)
{
    int i,found=0;
    for(i=0; i<cnt; i++)
    {
        if(Events[i].EventNumber==ev)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        cout<<"\n\t\t\t\t\t--------Chi tiet Su Kien --------\n\n";
        if(Events[i].info==1)
        {
            cout<<"\n   Su Kien da duoc dat . ";
        }
        else
        {
            cout<<"\n\n  	Su kien chua duoc ai dat ";
        }
        displayEvent(Events[i]);
        getch();
    }
    else
    {
        cout<<"\n  Khong tim thay. ";
        getch();
    }
}
void Event::displayEvent(Event tempEvent)
{
    cout<<"\n\n   Thong tin   \n";
    cout<<"\n   Thu_tu_su_kien  : "<<tempEvent.EventNumber;
    cout<<"\n   tong_khach_hang : "<<tempEvent.gs;
    cout<<"\n   Tong_thoi_gian  : "<<tempEvent.time;
    cout<<"\n   Dia_diem_to_chuc: " <<tempEvent.ven; //Your Preferred Venue For Booking
}
class EventMen:protected Event
{
public:
    void checkIn();
    void getAvailEvent();
    void searchUser(char *);
    void checkOut(int);
    void GuestSummary(char *);
    void collectFeedback();
    void xemPhongThuy();
};
void EventMen::GuestSummary(char *uname)
{
    system("cls");
    int z;
    cout<<"\n\n   Nhan phim 1 de biet ve thong tin khach hang / An phim 2 de biet them ve chung toi : ";
    cin>>z;
    if(z==1)
    {
    if(cnt==0)
    {
        cout<<"\n\n  No Event Booked !!"; // sua
    }
    for(int i=0; i<cnt; i++)
    {
        if(Events[i].info==1)
        {
            cout<<"\n\t\t\t\t___________ Thong ke khach hang ___________\n\n";
            cout<<"\n\n   Ten : "<<Events[i].usr.ten;
            cout<<"\n\n   Thu thu su kien : "<<Events[i].EventNumber;
            cout<<"\n\n   Dia chi : "<<Events[i].usr.dia_chi;
            cout<<"\n\n   So dien thoai : "<<Events[i].usr.sdt;
        }
    }
    }
    else if(z==2)
    {
    cout<<"\n\t\t\t\t          Ve chung toi          \n\n";
    cout<<"\n Chung toi la nhom 14  "<<endl;
    cout<<" Contact NOW Email : tranbaanhhao@gmail.com"<<endl;
    cout<<" Phone: 01234567890" <<endl;
    cout<<" Address: HUST";
    cout<<" Thank You :) ! "<<endl<<endl;
    }
    getch();
}
void EventMen::checkIn()
{
    int i,found=0,ev;
    class Event Event;
    cout<<"\n   Nhap so thu tu su kien : ";
    cin>>ev;
    for(i=0; i<cnt; i++)
    {
        if(Events[i].EventNumber==ev)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        if(Events[i].info==1)
        {
            cout<<"\n   Xin loi, su kien da ton tai";
            getch();
            return;
        }	 
        system("cls");
        cout<<"\n\t\t\t\t___________ Booking Su Kien ___________\n\n";
        cout<<"\n\n   Nhap ID su kien: ";
        cin>>Events[i].usr.booking_id;
        cout<<"\n\n   Nhap ten: ";
        cin>>Events[i].usr.ten;
        cout<<"\n\n   Nhap dia chi: ";
        cin>>Events[i].usr.dia_chi;
        cout<<"\n\n   Nhap dien thoai: ";
        cin>>Events[i].usr.sdt;
        cout<<"\n\n   Nhap ngay ban muon to chuc: ";
        cin>>Events[i].usr.date;
        cout<<"\n\n   Nhap Thang ban muon to chuc: ";
        cin>>Events[i].usr.payment_advance;
        Events[i].info=1;
        cout<<"\n\n   Nhap thong tin thanh cong !!! ( Nhan phim 3 de tro ve)";
        getch();
    }
}
void EventMen::getAvailEvent()
{
    int i,found=0;
    for(i=0; i<cnt; i++)
    {
        if(Events[i].info==0)
        {
            displayEvent(Events[i]);
            cout<<"\n\n   Nhan Enter cho su kient tiep theo!\n";
            found=1;
            getch();
        }
    }
    if(found==0)
    {
        cout<<"\n  Tat ca su kien da duoc dat";
        getch();
    }
}
void EventMen::searchUser(char *uname)
{
    int i,found=0;
    for(i=0; i<cnt; i++)
    {
        if(Events[i].info==1 && stricmp(Events[i].usr.ten,uname)==0)
        {
            system("cls");
            cout<<"\n\n\t\t\t\t        _________ Thong tin nguoi dung  _________ ";
            cout<<"\n\n   Ten: "<<Events[i].usr.ten;
            cout<<"\n\n   Thu tu su kien: "<<Events[i].EventNumber;
            cout<<"\n\n   Nhan Enter de tiep tuc!!";
            found=1;
            getch();
        }
    }
    if(found==0)
    {
        cout<<"\n\n   Khong tim thay su kien nao ";
        getch();
    }
}
class Account
{
    int acc_no;
    int amount;
public:
    Account()
    {
        cout<<"\n\n Nhap so tai khoan dung de thanh toan : ";
        cin>>acc_no;
        amount = 0;
    }
    void deposit(int num)
    {
        if(num == acc_no)
        {
            string date;
            cout<<"\n   Nhap so luong: ";
            cin>>amount;
            cout<<"\n   Transferred To Account No 14. "<< endl;
            cout<<"\n   Branch Name : Nhom 14 Bank"<< endl;
            cout<<"\n   Transaction Date : ";
            cin>>date;
            cout<<endl;
            cout<<"   Event Confirmed, Thank You :)! "<< endl;
        }
        else
            cout<<"\n   Incorrect account number. Try Again. "<<endl;
    }
};
void EventMen::checkOut(int EventNum)
{
    int i,found=0,TotalGuests,TotalTime,j;
    double billAmount=0;
    string p;
    for(i=0; i<cnt; i++)
    {
        if(Events[i].info==1 && Events[i].EventNumber==EventNum)
        {
            found=1;
            break;
        }
    }
    if(found==1)
    {
        system("cls");
        cout<<"\n\n\t\t\t\t        _________ Chi tiet su kien  _________ ";
        cout<<"\n\n\n   Nhap so luong khach:  ";
        cin>>TotalGuests;
        cout<<"\n\n   Tong thoi gian :  ";
        cin>>TotalTime;
        cout <<"\n\n   Tong so ban da duoc dat "; //one table = minimum 6 person
        j = ceil(TotalGuests/6);
        cout << j <<endl;
        double cp;
        double TotalStaff, CostH, CostM, OneStaffCost,X, TotalFoodCost, AverageCost, DepositAmount,TotalCost;
        double PerHourCost = 30.00;
        double PerMinCost  = 0.50;
        double CostOfMeal  = 100.00;
        double CarParking  = 1000.00;
        double Lighting    = 1500.00;
// Total Staff Number
        X = TotalGuests / 10;
        TotalStaff = ceil(X);
// One Staffs Cost
        CostM = (TotalTime % 60) * PerMinCost;
        CostH = (TotalTime / 60) * PerHourCost;
        OneStaffCost = CostM+CostH;
// Cost of Food
        TotalFoodCost = (TotalGuests * CostOfMeal) ;

// Average Cost Per Person
        AverageCost = (TotalFoodCost / TotalGuests);

// Total Cost
        TotalCost = TotalFoodCost + (OneStaffCost * TotalStaff)+ Lighting + CarParking;
// Advance (30%) Amount
        DepositAmount = TotalCost * (.30);
        cout<<"\n\n\t\t\t\t __________Chi tiet ve chi phi cua su kien__________\n\n";
        cout<<"\n\n  Ten : "<<Events[i].usr.ten;
        cout<<"\n\n  So thu tu su kien : "<<Events[i].EventNumber;
        cout<<"\n\n  Dia chi : "<<Events[i].usr.dia_chi;
        cout<<"\n\n  Dien thoai8 : "<<Events[i].usr.sdt;
        cout<<"\n\n  So luong nhan vien : " << TotalStaff << fixed << setprecision(3) << endl<< endl;
        cout<<"  Chi phi cho 1 nhan vien : "  << OneStaffCost <<endl<< endl;
        cout<<"  Chi phi do an : "<< TotalFoodCost << endl <<endl;
        cout<<"  Chi phi trung binh 1 nguoi : "  << AverageCost<<endl<<endl;
        cout<<"  tong chi phi: "  << TotalCost << endl<< endl;
        cout<<"  To reserve the event , Please Deposit 30% of Total Amount including VAT" << endl<< endl;
        cout<<"  Chi phi triet khau: "  << DepositAmount << endl<< endl;
        cout<<"  Phi ban dau: "<<Events[i].usr.payment_advance<<" /-"<<endl;
        cout<<"\n Phi can tra: "<<TotalCost - Events[i].usr.payment_advance<<"/- duy nhat";
        Events[i].info=0;
        Account acc;
        int num;
        cout<<"\n  NHap lai so tai khoan: ";
        cin>>num;
        acc.deposit(num);
        cout<< endl<<endl;
    }
    getch();
}
void manageEvents()
{
    class Event Event;
    int opt,ev,i,flag=0;
    char ch;
    do
    {
        system("cls");
        cout<<"\n\t\t\t\t        _________ Quan li su kien _________";
        cout<<"\n\n 1. Them su kien";
        cout<<"\n\n 2. Tim kiem su kien";
        cout<<"\n\n 3. Tro ve MENU";
        cout<<"\n\n    Option: ";
        cin>>opt;
        switch(opt)
        {
        case 1:
            cout<<"\n    Nhap so thu tu cua su kien : ";
            cin>>ev;
            i=0;
            for(i=0; i<cnt; i++)
            {
                if(Events[i].EventNumber==ev)
                {
                    flag=1;
                }
            }
            if(flag==1)
            {
                cout<<"\n  so thu tu da ton tai. \n\n Nhap so thu tu khac: ";
                flag=0;
                getch();
            }
            else
            {
                Events[cnt]=Event.addEvent(ev);
                cnt++;
            }
            break;
        case 2:
            cout<<"\n   Nhap so thu tu su kien: ";
            cin>>ev;
            Event.searchEvent(ev);
            break;
        case 3:
            break;
        default:
            cout<<"\n\n  sai, hay nhap lai ";
            break;
        }
    }
    while(opt!=3);
}
void EventMen::collectFeedback()
{
     auto now = system_clock::now();
    time_t now_time = system_clock::to_time_t(now);

    string feedback, customerName;
    cout << "\n\n\t\t\t\t _________ PHAN HOI _________ \n";
    cout << "\n Nhap ten cua ban: ";
    cin.ignore();
    getline(cin, customerName);
    cout << "\n Phan hoi cua ban la: ";
    getline(cin, feedback);
	
    // Chuyển đổi thời gian thành chuỗi và loại bỏ ký tự xuống dòng
    string timeStr = ctime(&now_time); 
    if (!timeStr.empty() && timeStr.back() == '\n') {
        timeStr.pop_back(); // Loại bỏ ký tự '\n' ở cuối chuỗi
    }

    // Mở file CSV và ghi dữ liệu
    ofstream feedbackFile("feedback.csv", ios::app);
    if (feedbackFile.is_open()) {
        feedbackFile << customerName << "," << timeStr << "," << feedback << endl;
        feedbackFile.close();
        cout << "\n Phan hoi thanh cong!!.";		
    }
	else {
        cout << "\n Khong thanh cong!!.";
    }

}
void EventMen::xemPhongThuy() {
    system("cls");
    cout << "\n\t\t\t\t        _________ Xem Phong Thuy _________ ";
    string ngay, buoi;
    cout << "\n\n   Nhap ngay muon to chuc (VD: 13/01/2025): ";
    cin >> ngay;
    cout << "\n\n   Chon buoi (sang/trua/toi): ";
    cin >> buoi;

    // Danh sach cac goi y ngau nhien
    string goiYThoiTiet[] = {
        "Thoi tiet se rat dep thich hop to chuc ngoai troi",
        "Co kha nang mua nen chuan bi cac phuong an du phong",
        "Troi se lanh phu hop voi cac su kien trong nha",
        "Nhiet do cao can chu y cac thiet bi lam mat",
    };

    string goiYPhongThuy[] = {
        "Day la ngay tot de bat dau mot su kien quan trong",
        "Buoi nay se mang lai may man va thinh vuong",
        "Han che to chuc su kien lon tap trung vao cac hoat dong nho",
        "Nang luong tich cuc moi thu se dien ra suon se",
    };

    // Random hoa goi y
    
    int indexThoiTiet = rand() % 4;
    int indexPhongThuy = rand() % 4;

    cout << "\n\n\t\t\t\t __________ Goi y phong thuy __________";
    cout << "\n\n   Ngay ban chon: " << ngay;
    cout << "\n   Buoi ban chon: " << buoi;
    cout << "\n\n   Thoi tiet du doan: " << goiYThoiTiet[indexThoiTiet];
    cout << "\n   Goi y phong thuy: " << goiYPhongThuy[indexPhongThuy];

    cout << "\n\n   Chuc ban co mot su kien thanh cong";
    getch();
}

int main()
{


    class EventMen hm;
    int i,j,opt,ev,f;
    char ch;
    char uname[1000];
    system("cls");
    do
    {
        system("cls");
        cout<<"\t\t\t\t    ------------------------------------"<<endl;
        cout<<"\t\t\t\t    |HE THONG QUAN LY SU KIEN (NHOM 14)|"<<endl;
        cout<<"\t\t\t\t    ------------------------------------"<<endl;
        cout<<"\n------------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\n-------------------------------------------- Chi Tiet Su Kien ----------------------------------------------------------"<<endl;
        cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"\n\t\t\t\t         1. Quan li su kien ";
        cout<<"\n\t\t\t\t         2. Book Su kien ";
        cout<<"\n\t\t\t\t         3. Thong tin su kien";
        cout<<"\n\t\t\t\t         4. Tim kiem nguoi dung ";
        cout<<"\n\t\t\t\t         5. Chi phi Su kien ";
        cout<<"\n\t\t\t\t         6. Ve chung toi";
        cout<<"\n\t\t\t\t         7. Xem Phong Thuy . ";
    	cout<<"\n\t\t\t\t         8. Nhap y kien phan hoi. ";
    	cout<<"\n\t\t\t\t         9. Thoat. ";
        cout<<"\n\n   Nhap lua chon:  " ;
        cin>>opt;
        switch(opt)
        {
        case 1:
            manageEvents();
            break;
        case 2:
            if(cnt==0)
            {
                cout<<"\n   Chua co su kien nao .\n\n   Hay dien 1 su kien truoc.";
                getch();
            }
            else
                hm.checkIn();
            break;
        case 3:
            if(cnt==0)
            {
                cout<<"\n   Chua co su kien nao .\n\n   Hay dien 1 su kien truoc.";
                getch();
            }
            else
                hm.getAvailEvent();
            break;
        case 4:
            if(cnt==0)
            {
                cout<<"\n Chua co su kien nao .\n\n   Hay dien 1 su kien truoc.";
                getch();
            }
            else
            {	
                cout<<"\n\n   Ten nguoi dung : ";
                cin>>uname;
                hm.searchUser(uname);
            }
            break;
        case 5:
            if(cnt==0)
            {
                cout<<"\n   Chua co su kien nao .\n\n   Hay dien 1 su kien truoc.";
                getch();
            }
            else
            {
                cout<<"\n\n   Nhap so thu tu su kien: ";
                cin>>ev;
                hm.checkOut(ev);
            }
            break;
        case 6:
            hm.GuestSummary(uname);
            break;
        case 7:
        	hm.xemPhongThuy();
        	break;
        case 8:
        	hm.collectFeedback();
            break;
        case 9:
        cout<<"\n   Nhom 14 XIN CAM ON! ";
    	break;

        default:
            cout<<"\n\n   Hay thu lua chon lai ";
            break;
        }
    }
    while(opt!=9);
    getch();
}
