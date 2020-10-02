#include <bits/stdc++.h>
using namespace std;

int main() {
     string str="";
    string x="";
    cout<<"Sender side "<<endl;
    ifstream MyReadFile("input.txt");
    while (getline (MyReadFile, x))
        {str+=x;}
    MyReadFile.close();
    cout<<"Original message:"<<str<<endl;
    string del="01111110";
    int check=del.length()-1;
    int cnt_1 = 0;
    vector<string>ar;
     srand(time(0));
    for(int j=0;j<str.length();)
    {

        int fr_size=(rand() % (str.length()-j)) + 1;
        cnt_1=0;
        string to_be_send=del;
        for(int i=j;i<str.length() && i<(j+fr_size);i++)
        {
                if(cnt_1==check){
                    to_be_send+="1";
                    if(str[i]==del[0]) cnt_1=1;
                    else cnt_1=0;
                }
                else if(str[i]==del[cnt_1]){cnt_1++; }
                else cnt_1=0;
                to_be_send+=str[i];
        }
        j=j+fr_size;
        to_be_send+=del;
        ar.push_back(to_be_send);
    }
    cout<<"Starting & Ending delimeter is "<<del<<" "<<del<<endl<<endl;
   for(int i=0;i<ar.size();i++) cout<<"In frame no."<<i+1<<" string to be send: "<<ar[i]<<endl;
   ofstream Myfile("sender.txt");
   if(Myfile.is_open())
    {
        for(int i=0;i<ar.size();i++)
            {
            Myfile<<ar[i]<<endl;
            }
            cout<<endl<<"Written successfully in sender.txt"<<endl;
    }
    Myfile.close();

    cout<<endl<<"Receiver's side "<<endl<<endl;
    vector<string> rec;
    ifstream MyReadFile2("sender.txt");
    while (getline (MyReadFile2, x))
        {rec.push_back(x);}
    MyReadFile2.close();

  del="01111110";
    check=del.length()-1;
    string ans="";

    for(int j=0;j<rec.size();j++)
    {
        string from_s=rec[j];
        cnt_1=0;
        for(int i=del.length();i<from_s.length()-del.length();i++)
        {
            if(cnt_1==check && from_s[i]==del[cnt_1]) {cnt_1=0; continue;}
            else if(from_s[i]==del[cnt_1]) cnt_1++;
            else cnt_1=0;
            ans+=from_s[i];
        }
    }
    cout << "\n";
    cout<<"Interpreted message at receiver: "<<ans<<endl;
    ofstream MyFile2("receiver.txt");
    MyFile2 << ans;
    MyFile2.close();
}
