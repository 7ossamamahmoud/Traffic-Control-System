#include <iostream>
#include <cstring>


using namespace std;
const int max_speed = 120;
 int Fines_Number=0;

void check_Speed_Limit(int speed, struct person p[], int size, char plate_number[20], char name[50], struct car car_info[]);
void pay_Bill(struct person p[], int size_struct, char name[50], struct car car_ifo[]);
void search_byName(char search_obj[50], struct person p[], struct car car_info[], int size);
void search_byLicense(long search_obj, struct person p[], struct car car_info[], int size);


struct car {
    char product_Year[20];
    char model_Car[20];
    char plate_Num[20];
};

struct person {
    char name[50];
    long int licence_Num;
    char birthdate[10];
    int num_car;
    int valueOf_Fine;
    char street[20];
    char date_fine[10];
    bool check_fine;
    int record_Fines[sizeof(Fines_Number)] = { 0 };
    car car_info;



};
int number_of_fine = 0;

int main() {


    int drivers;
    cout << "Enter Drivers' Number: " << endl;
    cin >> drivers;
    person p[sizeof(drivers)];
    car car_info[3];
    for (int i = 0; i < drivers; i++) {

        cout << "Enter Driver's Name: " << i + 1 << endl;
        cin >> p[i].name;
        cout << "Enter Driver's License Number: " << i + 1 << endl;
        cin >> p[i].licence_Num;
        cout << "Enter Driver's Date_Of_Birth: " << i + 1 << endl;
        cin >> p[i].birthdate;
        cout << "Enter No. Of Car that The driver has ""Max. 3 Cars"":" << endl;
        cin >> p[i].num_car;
        if (p[i].num_car <= 3) {

            for (int j = 0; j < 3; j++) {

                cout << "Enter Plate Number Of Car No.: " << j + 1 << " For The Driver No.: " << i + 1 << endl;
                cin >> car_info[j].plate_Num;
                cout << "Enter Car Model Of Car No.: " << j + 1 << " For The Driver No.: " << i + 1 << endl;
                cin >> car_info[j].model_Car;
                cout << "Enter the Production Year Of Car No.: " << j + 1 << " For The Driver No.: " << i + 1 << endl;
                cin >> car_info[j].product_Year;
                if (j + 1 == p[i].num_car) 
                    break;
            }
        }


    }
       system("cls");


    cout << "Checking Cars' Speed !: " << endl;
    cout << "If the Car speed exceeded 120 Km/h ,Press 1" << endl;
    cout << "If the Car speed did NOT exceed 120 Km/h ,Press 0" << endl;
    cout << "--------------------------------------" << endl;
    int check_speed;
    cin >> check_speed;
    if (check_speed == 1) {
        cout << "Enter Plate Number Of the Car that exceeded the Legal speed:" << endl;
        char plat_number_speed[20];
        cin >> plat_number_speed;
        cout << "Enter Driver's Name of the Car that exceeded the Legal speed:" << endl;
        char driver_name[50];
        cin >> driver_name;
        cout << "--------------------------------------" << endl;
        cout << "Enter the Car speed that exceeded the Legal speed""* MUST Be Over 120 *"" :" << endl;
        int car_speed;
        cin >> car_speed;
        check_Speed_Limit(car_speed, p, drivers, plat_number_speed, driver_name, car_info);
        cout << "If U Want to Pay the Fine, Press 1 or 0 For NOT " << endl;
        int pay_bill;
        cin >> pay_bill;
        if (pay_bill == 1) {
            cout << "Enter the name that will pay the fine : " << endl;
            char name_fine[50];
            cin >> name_fine;
            pay_Bill(p, drivers, name_fine, car_info);
        }
        

      
    }
    system("cls");
    cout << "____________________________________________________" << endl;
    cout << "Choose What do you want to Search about driver using his name or one of his car's plate" << endl;
    cout << "For Searching by name Press 1 " << endl;
    cout << "For Searching by plate car Number Press 2 " << endl;
    cout << "____________________________________________________" << endl;
    int search_press;
    cin >> search_press;
    cout << "____________________________________________________" << endl;

    if (search_press == 1) {

        char search_obj[20];
        cout << "Enter the name of the driver  " << endl;
        cin >> search_obj;
        search_byName(search_obj, p, car_info, drivers);
    }
    else if (search_press == 2)
    {
        long search_obj;
        cout << "Enter the Plate Car Number: " << endl;
        cin >> search_obj;
        search_byLicense(search_obj, p, car_info, drivers);
    }




}
void check_Speed_Limit(int speed, person p[], int size, char plate_number[20], char name[50], car car_info[]) {

    int fine_value;
    fine_value = (speed - max_speed) * 2;
    if (fine_value > 0)
        Fines_Number++;
    int temp = 0;
    int press;
    for (int i = 0; i < size; i++) {
        if (strcmp(p[i].name, name) == 0) {
            for (int x = 0; x <p[i].num_car; x++) {
                if (strcmp(car_info[x].plate_Num, plate_number) == 0) {
                    for (int j = 0; j < Fines_Number; j++) {
                        temp = p[i].record_Fines[j];
                        if (temp == 0) {
                            cout << "There is NO Old Fine to Pay For Driver : " << p[j].name << "Press 1 to add a new Fine for it : " << endl;
                            cin >> press;
                            if (press == 1) {
                                cout << "Enter Fine's Date " << endl;
                                cin >> p[i].date_fine;
                                cout << "Enter the Street name where it exceeded the Speed at:" << endl;
                                cin >> p[i].street;
                                p[i].record_Fines[j] = fine_value;
                                p[i].valueOf_Fine = fine_value;
                                break;
                                
                            }
                            else if(press==0)
                            {
                                break;
                            }
                            

                        }
                        else {
                            cout << "There are some Old Fines: " << endl;
                            cout << p[i].record_Fines[j] << endl;
                            Fines_Number--;
                        }


                    }


                }

            }


        }



    }

}


void pay_Bill(person p[], int size_struct, char name[50], car car_info[]) {

    int temp = 0;
    int sum = 0;
    for (int i = 0; i < size_struct; i++) {
        if (strcmp(p[i].name, name) == 0) {
            for (int j = 0; j < Fines_Number; j++) {
                temp = p[i].record_Fines[j];
                if (temp == 0) {
                    cout << "There is NO Late Fines" << endl;
                    break;
                }
                else {

                    cout << "There are some late Fines: " << endl;
                    cout << p[i].record_Fines[j] << endl;
                    cout << "Total Amount Of Money For the all Fines is: " << endl;
                    sum = sum + p[i].record_Fines[j];
                    cout << sum << endl;
                    int p;
                    cout << "To Pay it Press 1 For NOT Press 0" << endl;
                    cin >> p;
                    if (p == 1)
                    {
                        Fines_Number--;
                        break;
                    }
                    else
                        break;
                }
            }
        }
    }


    system("cls");
}

void search_byName(char search_obj[50], person p[], car car_info[], int size) {

    for (int i = 0; i < size; i++) {
        if (strcmp(p[i].name, search_obj) == 0) {
            for (int j = 0; j < p[j].num_car; j++) {
                cout << "Driver's Name is:" << endl;
                cout << p[i].name << endl;
                cout << "Driver's DateOfBirth is: " << endl;
                cout << p[i].birthdate << endl;
                cout << "license Number is: " << endl;
                cout << p[i].licence_Num << endl;
                if (p[i].valueOf_Fine > 0) {
                    cout << "Fine is equal to: " << endl;
                    cout << p[i].valueOf_Fine << endl;
                }
                else {
                    cout << "Fine is equal to: " << endl << "Zero" << endl;
                }
                if (Fines_Number > 0)
                {
                    cout << "Date Of the Fine is: " << endl;
                    cout << p[i].date_fine << endl;
                    cout << "Street Name is: " << endl;
                    cout << p[i].street << endl;
                }
                cout << "No. Of Car(s), He has: " << endl;
                cout << p[i].num_car << endl;
                if (p[i].num_car == 1)
                {
                    cout << "Car Model Of Car is: " <<endl;  //Cars Overlap 
                    cout << car_info[j].model_Car << endl;
                    cout << "Production Year Of Car is: " << endl;
                    cout << car_info[j].product_Year << endl;
                }
                else
                {
                    for (int h = 0; h < p[i].num_car; h++) {
                        cout << "Car Model Of Car No. " << h + 1 << " is : " << endl;  //Cars Overlap 
                        cout << car_info[h].model_Car << endl;
                        cout << "Production Year Of Car No. " << h + 1 << " is : " << endl;
                        cout << car_info[h].product_Year << endl;
                    }
                }
                if (j + 1 == p[i].num_car) break;
            }

            for (int b = 0; b < Fines_Number; b++) {

                cout << "Recorded Fines Or Late Ones are: " << endl;
                cout << p[i].record_Fines[b] << endl;

            }


        }



    }

}


void search_byLicense(long search_obj, person p[], car car_info[], int size) {
    system("cls");
    for (int i = 0; i < size; i++) {
        if ((p[i].licence_Num)== search_obj) {
            for (int j = 0; j < p[j].num_car; j++) {
                cout << "Driver's Name is:" << endl;
                cout << p[i].name << endl;
                cout << "Driver's DateOfBirth is: " << endl;
                cout << p[i].birthdate << endl;
                cout << "license Number is: " << endl;
                cout << p[i].licence_Num << endl;
               
                if (p[i].valueOf_Fine > 0) {
                    cout << "Fine is equal to: " << endl;
                    cout << p[i].valueOf_Fine << endl;
                }
                else {
                    cout << "Fine is equal to: " <<endl<< "Zero" << endl;
                }
                if (Fines_Number > 0)
                {
                    cout << "Date Of the Fine is: " << endl;
                    cout << p[i].date_fine << endl;
                    cout << "Street Fine is: " << endl;
                    cout << p[i].street << endl;
                }
                cout << "No. Of Car(s), He has: " << endl;
                cout << p[i].num_car << endl;
                if (p[i].num_car == 1)
                {
                    cout << "Car Model Of Car is: " << endl;  //Cars Overlap 
                    cout << car_info[j].model_Car << endl;
                    cout << "Production Year Of Car is: " << endl;
                    cout << car_info[j].product_Year << endl;
                }
                else
                {
                    for (int h = 0; h < p[i].num_car; h++) {
                        cout << "Car Model Of Car No. " << h + 1 << " is : " << endl;  //Cars Overlap 
                        cout << car_info[h].model_Car << endl;
                        cout << "Production Year Of Car No. " << h + 1 << " is : " << endl;
                        cout << car_info[h].product_Year << endl;
                    }
                }
                if (j + 1 == p[i].num_car)
                    break;
            }

            for (int b = 0; b < Fines_Number; b++) {
                if (Fines_Number > 0) {
                    cout << "Recorded Fines Or Late Ones are: " << endl;
                    cout << p[i].record_Fines[b] << endl;
                }
                else
                {
                    cout << " There are NO Fines Found" << endl;
                }
            }


        }



    }


}
