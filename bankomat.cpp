#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;
map<float, int> ile_jakich;
void monety(float &kwota, vector<float>&nominaly);
void drukuj();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<float> nominaly = {0.01, 0.02, 0.05, 0.10, 0.20, 0.50, 1.00, 2.00, 5.00, 10.00, 20.00, 50.00, 100.00, 200.00, 500.00}; 
    float k;
    cin >> k;
    for(int i = nominaly.size()-1; i>=0; i--)
        if(k < nominaly[i])
            nominaly.erase(nominaly.begin()+i);
    monety(k, nominaly);
    drukuj();
    
}

void monety(float &kwota, vector<float>&nominaly)
{
    for(int i = nominaly.size()-1; i>=0; i--)
    {
        if(kwota >= nominaly[i])
        {
            kwota = kwota - nominaly[i];
            ile_jakich[nominaly[i]]++;
            if(kwota == 0)
                return;
            else if(kwota >= nominaly[i])
                monety(kwota, nominaly);
        }
    }
}

void drukuj()
{
    for (auto it = ile_jakich.rbegin(); it != ile_jakich.rend(); it++) 
        cout << fixed << setprecision(2) << it->first << " " << it->second << endl;
}