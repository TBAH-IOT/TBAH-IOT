#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <conio.h>

#define MAX 100

typedef struct {
    char ten[1000];
    char dia_chi[1000];
    char id[1000];
    char sdt[12];
    char date[20];
    float payment_advance;
    int booking_id;
} User;

typedef struct {
    int time;
    char stype;
    char ven[1000];
    int gs;
    int EventNumber;
    int cost;
    int info;
    User usr;
} Event;

Event Events[MAX];
int cnt = 0;

Event addEvent(int ev) {
    Event event;
    event.EventNumber = ev;
    printf("\n  So_Khach_Moi : ");
    scanf("%d", &event.gs);
    printf("\n  Tong_Thoi_Gian   : ");
    scanf("%d", &event.time);
    printf("\n  Dia_Diem : ");
    scanf("%s", event.ven);
    event.info = 0;
    printf("\n  Tao Su Kien Thanh Cong ");
    getch();
    return event;
}

void displayEvent(Event tempEvent) {
    printf("\n\n   Thong tin   \n");
    printf("\n   Thu_tu_su_kien  : %d", tempEvent.EventNumber);
    printf("\n   tong_khach_hang : %d", tempEvent.gs);
    printf("\n   Tong_thoi_gian  : %d", tempEvent.time);
    printf("\n   Dia_diem_to_chuc: %s", tempEvent.ven);
}

void searchEvent(int ev) {
    int i, found = 0;
    for (i = 0; i < cnt; i++) {
        if (Events[i].EventNumber == ev) {
            found = 1;
            break;
        }
    }
    if (found == 1) {
        printf("\n\t\t\t\t\t--------Chi tiet Su Kien --------\n\n");
        if (Events[i].info == 1) {
            printf("\n   Su Kien da duoc dat . ");
        } else {
            printf("\n\n   Su kien chua duoc ai dat ");
        }
        displayEvent(Events[i]);
        getch();
    } else {
        printf("\n  Khong tim thay. ");
        getch();
    }
}

void GuestSummary(char *uname) {
    system("cls");
    int z;
    printf("\n\n   Nhan phim 1 de biet ve thong tin khach hang / An phim 2 de biet them ve chung toi : ");
    scanf("%d", &z);
    if (z == 1) {
        if (cnt == 0) {
            printf("\n\n  No Event Booked !!");
        }
        for (int i = 0; i < cnt; i++) {
            if (Events[i].info == 1) {
                printf("\n\t\t\t\t___________ Thong ke khach hang ___________\n\n");
                printf("\n\n   Ten : %s", Events[i].usr.ten);
                printf("\n\n   Thu thu su kien : %d", Events[i].EventNumber);
                printf("\n\n   Dia chi : %s", Events[i].usr.dia_chi);
                printf("\n\n   So dien thoai : %s", Events[i].usr.sdt);
            }
        }
    } else if (z == 2) {
        printf("\n\t\t\t\t          Ve chung toi          \n\n");
        printf("\n Chung toi la nhom 14  \n");
        printf(" Contact NOW Email : tranbaanhhao@gmail.com\n");
        printf(" Phone: 01234567890\n");
        printf(" Address: HUST\n");
        printf(" Thank You :) ! \n\n");
    }
    getch();
}

void checkIn() {
    int i, found = 0, ev;
    printf("\n   Nhap so thu tu su kien : ");
    scanf("%d", &ev);
    for (i = 0; i < cnt; i++) {
        if (Events[i].EventNumber == ev) {
            found = 1;
            break;
        }
    }
    if (found == 1) {
        if (Events[i].info == 1) {
            printf("\n   Xin loi, su kien da ton tai");
            getch();
            return;
        }
        system("cls");
        printf("\n\t\t\t\t___________ Booking Su Kien ___________\n\n");
        printf("\n\n   Nhap ID su kien: ");
        scanf("%d", &Events[i].usr.booking_id);
        printf("\n\n   Nhap ten: ");
        scanf("%s", Events[i].usr.ten);
        printf("\n\n   Nhap dia chi: ");
        scanf("%s", Events[i].usr.dia_chi);
        printf("\n\n   Nhap dien thoai: ");
        scanf("%s", Events[i].usr.sdt);
        printf("\n\n   Nhap ngay ban muon to chuc: ");
        scanf("%s", Events[i].usr.date);
        printf("\n\n   Nhap Thang ban muon to chuc: ");
        scanf("%f", &Events[i].usr.payment_advance);
        Events[i].info = 1;
        printf("\n\n   Nhap thong tin thanh cong !!! ( Nhan phim 3 de tro ve)");
        getch();
    }
}

void getAvailEvent() {
    int i, found = 0;
    for (i = 0; i < cnt; i++) {
        if (Events[i].info == 0) {
            displayEvent(Events[i]);
            printf("\n\n   Nhan Enter cho su kient tiep theo!\n");
            found = 1;
            getch();
        }
    }
    if (found == 0) {
        printf("\n  Tat ca su kien da duoc dat");
        getch();
    }
}

void searchUser(char *uname) {
    int i, found = 0;
    for (i = 0; i < cnt; i++) {
        if (Events[i].info == 1 && strcasecmp(Events[i].usr.ten, uname) == 0) {
            system("cls");
            printf("\n\n\t\t\t\t        _________ Thong tin nguoi dung  _________ ");
            printf("\n\n   Ten: %s", Events[i].usr.ten);
            printf("\n\n   Thu tu su kien: %d", Events[i].EventNumber);
            printf("\n\n   Nhan Enter de tiep tuc!!");
            found = 1;
            getch();
        }
    }
    if (found == 0) {
        printf("\n\n   Khong tim thay su kien nao ");
        getch();
    }
}

typedef struct {
    int acc_no;
    int amount;
} Account;

void deposit(Account *acc, int num) {
    if (num == acc->acc_no) {
        char date[50];
        printf("\n   Nhap so luong: ");
        scanf("%d", &acc->amount);
        printf("\n   Transferred To Account No 14. \n");
        printf("\n   Branch Name : Nhom 14 Bank\n");
        printf("\n   Transaction Date : ");
        scanf("%s", date);
        printf("\n   Event Confirmed, Thank You :)! \n");
    } else {
        printf("\n   Incorrect account number. Try Again. \n");
    }
}

void checkOut(int EventNum)
{
    int i, found = 0, TotalGuests = 0, TotalTime = 0, j;
    double billAmount = 0;
    char p[100];

    for (i = 0; i < cnt; i++)
    {
        if (Events[i].info == 1 && Events[i].EventNumber == EventNum)
        {
            found = 1;
            break;
        }
    }
    if (found == 1)
    {
        system("cls");
        printf("\n\n\t\t\t\t        _________ Chi tiet su kien  _________ ");
        printf("\n\n\n   Nhap so luong khach:  ");
        scanf("%d", &TotalGuests);
        printf("\n\n   Tong thoi gian :  ");
        scanf("%d", &TotalTime);
        printf("\n\n   Tong so ban da duoc dat "); //one table = minimum 6 person
        j = ceil(TotalGuests / 6.0);
        printf("%d\n", j);

        double TotalStaff, CostH, CostM, OneStaffCost, X, TotalFoodCost, AverageCost, DepositAmount, TotalCost;
        double PerHourCost = 30.00;
        double PerMinCost = 0.50;
        double CostOfMeal = 100.00;
        double CarParking = 1000.00;
        double Lighting = 1500.00;

        // Total Staff Number
        X = TotalGuests / 10.0;
        TotalStaff = ceil(X);

        // One Staffs Cost
        CostM = (TotalTime % 60) * PerMinCost;
        CostH = (TotalTime / 60) * PerHourCost;
        OneStaffCost = CostM + CostH;

        // Cost of Food
        TotalFoodCost = (TotalGuests * CostOfMeal);

        // Average Cost Per Person
        AverageCost = (TotalFoodCost / TotalGuests);

        // Total Cost
        TotalCost = TotalFoodCost + (OneStaffCost * TotalStaff) + Lighting + CarParking;

        // Advance (30%) Amount
        DepositAmount = TotalCost * (.30);

        printf("\n\n\t\t\t\t __________Chi tiet ve chi phi cua su kien__________\n\n");
        printf("\n\n  Ten : %s", Events[i].usr.ten);
        printf("\n\n  So thu tu su kien : %d", Events[i].EventNumber);
        printf("\n\n  Dia chi : %s", Events[i].usr.dia_chi);
        printf("\n\n  Dien thoai : %s", Events[i].usr.sdt);
        printf("\n\n  So luong nhan vien : %.0f\n", TotalStaff);
        printf("  Chi phi cho 1 nhan vien : %.2f\n", OneStaffCost);
        printf("  Chi phi do an : %.2f\n", TotalFoodCost);
        printf("  Chi phi trung binh 1 nguoi : %.2f\n", AverageCost);
        printf("  tong chi phi: %.2f\n", TotalCost);
        printf("  To reserve the event , Please Deposit 30%% of Total Amount including VAT\n");
        printf("  Chi phi triet khau: %.2f\n", DepositAmount);
        printf("  Phi ban dau: %.2f /-\n", Events[i].usr.payment_advance);
        printf("\n Phi can tra: %.2f/- duy nhat\n", TotalCost - Events[i].usr.payment_advance);
        Events[i].info = 0;

        Account acc;
        int num;
        printf("\n  NHap lai so tai khoan: ");
        scanf("%d", &num);
        acc.acc_no = num;
        deposit(&acc, num);
        printf("\n");
    }
    else
    {
        printf("\n\n   Khong tim thay su kien nao ");
        getch();
    }
    getch();
}

void manageEvents() {
    int opt, ev, i, flag = 0;
    do {
        system("cls");
        printf("\n\t\t\t\t        _________ Quan li su kien _________");
        printf("\n\n 1. Them su kien");
        printf("\n\n 2. Tim kiem su kien");
        printf("\n\n 3. Tro ve MENU");
        printf("\n\n    Option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("\n    Nhap so thu tu cua su kien : ");
                scanf("%d", &ev);
                for (i = 0; i < cnt; i++) {
                    if (Events[i].EventNumber == ev) {
                        flag = 1;
                    }
                }
                if (flag == 1) {
                    printf("\n  so thu tu da ton tai. \n\n Nhap so thu tu khac: ");
                    flag = 0;
                    getch();
                } else {
                    Events[cnt] = addEvent(ev);
                    cnt++;
                }
                break;
            case 2:
                printf("\n   Nhap so thu tu su kien: ");
                scanf("%d", &ev);
                searchEvent(ev);
                break;
            case 3:
                break;
            default:
                printf("\n\n  sai, hay nhap lai ");
                break;
        }
    } while (opt != 3);
}

void collectFeedback() {
    time_t now = time(NULL);
    struct tm *now_tm = localtime(&now);

    char feedback[1000], customerName[1000];
    printf("\n\n\t\t\t\t _________ PHAN HOI _________ \n");
    printf("\n Nhap ten cua ban: ");
    getchar(); // clear newline character from buffer
    fgets(customerName, sizeof(customerName), stdin);
    customerName[strcspn(customerName, "\n")] = 0; // remove newline character

    printf("\n Phan hoi cua ban la: ");
    fgets(feedback, sizeof(feedback), stdin);
    feedback[strcspn(feedback, "\n")] = 0; // remove newline character

    FILE *feedbackFile = fopen("feedback.csv", "a");
    if (feedbackFile != NULL) {
        fprintf(feedbackFile, "%s,%04d-%02d-%02d %02d:%02d:%02d,%s\n",
                customerName,
                now_tm->tm_year + 1900, now_tm->tm_mon + 1, now_tm->tm_mday,
                now_tm->tm_hour, now_tm->tm_min, now_tm->tm_sec,
                feedback);
        fclose(feedbackFile);
        printf("\n Phan hoi thanh cong!!.");
    } else {
        printf("\n Khong thanh cong!!.");
    }
}

void xemPhongThuy() {
    system("cls");
    printf("\n\t\t\t\t        _________ Xem Phong Thuy _________ ");
    char ngay[20], buoi[20];
    printf("\n\n   Nhap ngay muon to chuc (VD: 13/01/2025): ");
    scanf("%s", ngay);
    printf("\n\n   Chon buoi (sang/trua/toi): ");
    scanf("%s", buoi);

    // Danh sach cac goi y ngau nhien
    const char *goiYThoiTiet[] = {
        "Thoi tiet se rat dep thich hop to chuc ngoai troi",
        "Co kha nang mua nen chuan bi cac phuong an du phong",
        "Troi se lanh phu hop voi cac su kien trong nha",
        "Nhiet do cao can chu y cac thiet bi lam mat",
    };

    const char *goiYPhongThuy[] = {
        "Day la ngay tot de bat dau mot su kien quan trong",
        "Buoi nay se mang lai may man va thinh vuong",
        "Han che to chuc su kien lon tap trung vao cac hoat dong nho",
        "Nang luong tich cuc moi thu se dien ra suon se",
    };

    // Random hoa goi y
    srand(time(NULL));
    int indexThoiTiet = rand() % 4;
    int indexPhongThuy = rand() % 4;

    printf("\n\n\t\t\t\t __________ Goi y phong thuy __________");
    printf("\n\n   Ngay ban chon: %s", ngay);
    printf("\n   Buoi ban chon: %s", buoi);
    printf("\n\n   Thoi tiet du doan: %s", goiYThoiTiet[indexThoiTiet]);
    printf("\n   Goi y phong thuy: %s", goiYPhongThuy[indexPhongThuy]);

    printf("\n\n   Chuc ban co mot su kien thanh cong");
    getch();
}

int main() {
    int i, j, opt, ev, f;
    char ch;
    char uname[1000];
    do {
        system("cls");
        printf("\t\t\t\t    ------------------------------------\n");
        printf("\t\t\t\t    |HE THONG QUAN LY SU KIEN (NHOM 14)|\n");
        printf("\t\t\t\t    ------------------------------------\n");
        printf("\n------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n-------------------------------------------- Chi Tiet Su Kien ----------------------------------------------------------\n");
        printf("\n------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\t\t\t\t         1. Quan li su kien ");
        printf("\n\t\t\t\t         2. Book Su kien ");
        printf("\n\t\t\t\t         3. Thong tin su kien");
        printf("\n\t\t\t\t         4. Tim kiem nguoi dung ");
        printf("\n\t\t\t\t         5. Chi phi Su kien ");
        printf("\n\t\t\t\t         6. Ve chung toi");
        printf("\n\t\t\t\t         7. Xem Phong Thuy . ");
        printf("\n\t\t\t\t         8. Nhap y kien phan hoi. ");
        printf("\n\t\t\t\t         9. Thoat. ");
        printf("\n\n   Nhap lua chon:  ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                manageEvents();
                break;
            case 2:
                if (cnt == 0) {
                    printf("\n   Chua co su kien nao .\n\n   Hay dien 1 su kien truoc.");
                    getch();
                } else {
                    checkIn();
                }
                break;
            case 3:
                if (cnt == 0) {
                    printf("\n   Chua co su kien nao .\n\n   Hay dien 1 su kien truoc.");
                    getch();
                } else {
                    getAvailEvent();
                }
                break;
            case 4:
                if (cnt == 0) {
                    printf("\n Chua co su kien nao .\n\n   Hay dien 1 su kien truoc.");
                    getch();
                } else {
                    printf("\n\n   Ten nguoi dung : ");
                    scanf("%s", uname);
                    searchUser(uname);
                }
                break;
            case 5:
                if (cnt == 0) {
                    printf("\n   Chua co su kien nao .\n\n   Hay dien 1 su kien truoc.");
                    getch();
                } else {
                    printf("\n\n   Nhap so thu tu su kien: ");
                    scanf("%d", &ev);
                    checkOut(ev);
                }
                break;
            case 6:
                GuestSummary(uname);
                break;
            case 7:
                xemPhongThuy();
                break;
            case 8:
                collectFeedback();
                break;
            case 9:
                printf("\n   Nhom 14 XIN CAM ON! ");
                break;
            default:
                printf("\n\n   Hay thu lua chon lai ");
                break;
        }
    } while (opt != 9);
    getch();
    return 0;
}