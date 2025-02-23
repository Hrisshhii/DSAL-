#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Student{
    typedef struct stud{
        int roll;
        char name[30];
        char add[30];
        char div;
    };
    stud rec;
    public:
        void create();
        void display();
        int search();
        void deletion();
};

void Student::create(){
    char con;
    ofstream fout;
    fout.open("STUDENT.dat",ios::out | ios::binary);
    do{
        cout<<"\nENTER ROLL NUMBER OF STUDENT: ";
        cin>>rec.roll;
        cout<<"\nENTER NAME OF STUDENT: ";
        cin>>rec.name;
        cout<<"\nENTER ADDRESS OF STUDENT: ";
        cin>>rec.add;
        cout<<"\nENTER DIVISION OF STUDENT: ";
        cin>>rec.div;

        fout.write((char*)&rec,sizeof(stud))<<flush;
        cout<<"\n DO YOU WANT TO ADD MORE RECORDS?(Y/N): ";
        cin>>con;
    }while(con=='y' || con=='Y');
    fout.close();
}

void Student::display(){
    ifstream fin;
    fin.open("STUDENT.dat",ios::in | ios::binary);
    fin.seekg(0,ios::beg);
    cout<<"CONTENTS OF FILE: "<<endl;
    cout<<"\n\tROLL\tNAME\tDIV\tADDRESS"<<endl;
    while(fin.read((char*)&rec,sizeof(stud))){
        if(rec.roll!=-1){
            cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
        }
    }
    fin.close();
}

int Student::search(){
    int r;
    ifstream fin;
    fin.open("STUDENT.dat",ios::in | ios::binary);
    fin.seekg(0,ios::beg);
    cout<<"\nENTER THE ROLL NUMBER TO BE SEARCHED: "<<endl;
    cin>>r;

    int i=0;
    while(fin.read((char*)&rec,sizeof(stud))){
        if(rec.roll==r){
            cout<<"\n\tRecord found!!"<<endl;
            cout<<"\n\tROLL\tNAME\tDIV\tADDRESS";
            cout<<"\n\t"<<rec.roll<<"\t"<<rec.name<<"\t"<<rec.div<<"\t"<<rec.add;
            return i;
        }
        i++;
    }
    fin.close();
    return -1;
}

void Student::deletion(){
    int pos;
    pos=search();
    fstream f;
    f.open("STUDENT.dat",ios::in | ios::out | ios::binary);
    f.seekg(0,ios::beg);
    if(pos==-1){
        cout<<"\n\tRecord NOT found!!";
        return;
    }

    int offset=pos*sizeof(stud);
    f.seekp(offset);
    rec.roll=-1;
    strcpy(rec.name,"NULL");
    rec.div='N';
    strcpy(rec.add,"NULL");
    f.write((char*)&rec,sizeof(stud));
    f.seekg(0);
    f.close();
    cout<<"\n\n\tRECORD DELETED!!"<<endl;
}

int main(){
    Student s;
    int ch,k;

    do{
        cout<<"\n\n\n\t****** STUDENT INFORMATION MENU ******"<<endl;
        cout<<"\n\t1.Create\n\t2.Display\n\t3.Delete\n\t4.Search\n\t5.Exit"<<endl;
        cin>>ch;

        switch(ch){
            case 1:
            s.create();
            break;
            case 2:
            s.display();
            break;
            case 3:
            s.deletion();
            break;
            case 4:
            k=s.search();
            if(k==-1)
                cout<<"\n\tRecord not Found!!"<<endl;
            break;
            case 5:
            cout<<"EXITING.............:)";
            break;
            default:
            cout<<"INVALID CHOICE!!!"<<endl;
            break;
        }
    }while(ch!=5);
    return 0;
}