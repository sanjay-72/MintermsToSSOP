#include<iostream>
using namespace std;
vector<string> bin;
int n;
string ans;
void generateBinaries(string s)
{
    if(s.length() == n)
    {
        bin.push_back(s);
        return;
    }
    generateBinaries(s+'0');
    generateBinaries(s+'1');
}

int main()
{
    n = 10;
    generateBinaries("");
    while (true)
    {
        int un,i,digitsRequired;
        ans = "";
        cout<<endl<<endl<<"Enter number of terms : ";
        cin>>un;
        int arr[un];
        cout<<"Enter Minterms : ";
        for(i = 0;i < un; i++)
            cin>>arr[i];
        sort(arr,arr+un);
        digitsRequired = floor(log2(arr[un-1])+1);
//      cout<<digitsRequired;
        for(i = 0;i < un;i++)
        {
            string myString = bin[arr[i]].substr(n-digitsRequired,digitsRequired);
            int rep = 65;
            for(int j = 0;j < myString.length();j++)
            {
                if(myString[j] == '0')
                {
                    string s(1,(char)rep);
                    ans += " (~"+s+") ";
                }
                else
                {
                    string s(1,(char)rep);
                    ans += " "+s+" ";
                }
                rep++;
            }
            ans += "  +  ";
        }
        cout<<"Standard SOP expression"<<endl<<endl;
        ans = ans.substr(0,ans.length()-5);
        cout<<ans<<endl;

        char tk;
        cout<<endl<<"To exit enter ~, to enter c : ";
        cin>>tk;
        if(tk == '~')
            break;
    }
}
