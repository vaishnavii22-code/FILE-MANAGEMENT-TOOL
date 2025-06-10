#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class file
{
    public:
    void read()
    {
        //reading from file

        //ifstream is input class
        ifstream in;

        in.open("data.txt",ios::in);
        //ios::in is used to open file in input mode

        if(!in.is_open())
        {
            //error in opening file
            cout<<"File not opened correctly...try again";
        }
        else
        {
            string str;
            while(!in.eof())
            {
                //this part of code will run till end of file is reached
                getline(in,str);
                cout<<str<<endl;
                cout<<endl<<"Data read from file successfully"<<endl;
            }
        }
        in.close();
    }
    void write()
    {
        //writing to file

        //ofstream is output class 
        ofstream out;

        out.open("data.txt",ios::out);
        //ios::out rewrites the file from the starting point

        if(!out.is_open())
        {
            cout<<"File not opened correctly...try again";
        }
        else
        {
            string inp;
            cout<<"Enter the line you want in file: ";
            cin.ignore();
            getline(cin,inp);
            out<<inp;
            cout<<endl<<"Written to file successfully...."<<endl;
        }
        out.close();
    }
    void append()
    {
        //appending to file i.e writing at the end 

        ofstream out;
        //ofstream is output class
    
        out.open("data.txt",ios::app);
        if(!out.is_open())
        {
            //error in opening file
            cout<<"File not opened correctly....try again";
        }
        else
        {
            string inp;
            cout<<"Enter the line you want to append: ";
            cin.ignore();
            getline(cin,inp);
            out<<" "<<inp<<" ";
            cout<<endl<<"Appended to the file successfully"<<endl;
        }
        out.close();
    }

};


int main()
{
    cout<<endl<<"File handling Application...."<<endl;
    cout<<"Welcome.........";

    //choice is switch case variable
    int choice=0;

    //object of class file
    file f;

    do
    {
        cout<<endl<<"1.Write"<<endl;
        cout<<"2.Append"<<endl;
        cout<<"3.Read"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                f.write();
                break;
            case 2:
                f.append();
                break;
            case 3:
                f.read();
                break;
            case 4:
                cout<<"Exiting.......";
                break;
            default:
                cout<<"Enter a valid choice";
                break;
        }

   } while (choice!=4);
    return 0;
}