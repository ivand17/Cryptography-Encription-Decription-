#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
typedef int long long ll;
typedef unsigned int long long ul;
typedef long double ld;
#define mod 1000000007
#define mod1 998244353
#define pb push_back
#define mk make_pair
#define pi 3.14159265358979323846
#define vi vector<ll>
#define pii pair<ll, ll>
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define alla(arr,i,n) arr+i, arr+n
#define sz(a) a.size()
#define mp map<ll,ll>
#define ump unordered_map<ll,ll>
#define mmp multimap<ll,ll>
#define ub(a,x) upper_bound(all(a),x) - a.begin()
#define lb(a,x) lower_bound(all(a),x) - a.begin()
//#define o_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//#define o_setpll tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
bool compare(const pair<ll,ll> &a, const pair<ll,ll> &b){
    return a.ss<=b.ss;
}

ll inline power(ll a, ll b, ll p){
    a %= p;
    ll ans = 1;
    while(b>0){
        if(b & 1)
            ans = (ans*a)%p;
        a = (a*a)%p;
        b >>= 1;
    }
    return ans;
}

ll inv(ll n, ll p){
    return power(n,p-2, p);
}

bool inline isPrime(ll n) {
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    for (ll i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;
    return true;
}

ll gcd(ll a, ll b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b);
}


class EncryptionDecryption {
	private:
		string outputstringenc;
        string outputstringdec;
		string inputstring;
		string encpass;
		string decpass;
		ll enckey;
		ll deckey;
		ll temp;
		char tempc;
		void doEncryption(); //function to do Encryption
		void doDecryption(); //function to do Decryption
	public:
		EncryptionDecryption(); //initializer Default Constructor
		EncryptionDecryption(string); //parameterized constructor	
		void setInputString(string); //
		~EncryptionDecryption();
		ll checkEncPass(string);
		ll checkDecPass(string);
		void getOutputStringenc(); //get the encrypted string
        void getOutputStringdec();

};

//array for encripted values
vi a;
// function of encripted values
void fun()
{
    for(ll i=32;i<=126;i++)
    {
        a.pb(i);
    }
}
//Use this function to do Encryption
void EncryptionDecryption::doEncryption() {

	for(ll i=0;i<inputstring.size();i++) {
		temp = (ll)inputstring[i];
		temp = (temp + enckey-32)%sz(a);
		tempc = (char)a[temp];
		outputstringenc += tempc; 
		}

}
//End of encryption function

//Use this function to do Decryption
void EncryptionDecryption::doDecryption() {
	for(ll i=0;i<inputstring.size();i++) {
		temp = (ll)inputstring[i];
		temp = (sz(a)+temp + deckey-32)%sz(a);
        //cout<<temp<<" ";
		tempc = (char)a[temp];
		outputstringdec += tempc;
		}
	

}
//End of decryption function

void EncryptionDecryption::getOutputStringenc() {
	outputstringenc += '\0';
	cout << "The Encrypted string is"  <<" : "<<outputstringenc;	
	outputstringenc="";
}

void EncryptionDecryption::getOutputStringdec() {
	outputstringdec += '\0';
	cout << "The Decrypted string is"  <<" : "<<outputstringdec;	
	outputstringdec="";
}

//first check the password
ll EncryptionDecryption::checkEncPass(string pass) {
	//check password before encrypting
	if(pass!=encpass)
	{	
		cout << endl << "The password you entered is Incorrect the, Encryption will not proceed.\nTry Again \n";
		return 0;
	}	
	else {
		doEncryption();
		return 1;
	}	
}

//first check the password
ll EncryptionDecryption::checkDecPass(string pass) {
	//check password before encrypting
	if(pass!=decpass)
	{	
		cout << endl << "The password you entered is Incorrect the, Decryption will not proceed.\nTry Again \n";
		return 0;
	}	
	else {
		doDecryption();
		return 1;
	}	
}

//Initializer
EncryptionDecryption::EncryptionDecryption() {
	inputstring = "";
	outputstringenc = "";
    outputstringdec="";
	encpass= "111"; //this is the password
	decpass= "000";
	enckey= 4; //this is the key
	deckey= -1 * enckey;
	temp= 0;
	tempc='\0';
}


EncryptionDecryption::EncryptionDecryption(string e) { 
	inputstring = e;
}

void EncryptionDecryption::setInputString(string f) {
	inputstring=f;
}

EncryptionDecryption::~EncryptionDecryption() {
}

//The program begins here
int main() 

{
    
	string inputstring;
	string pass;
	char ch;
	bool quit=false;
    fun();
	EncryptionDecryption O1; //creating object

	//Which operation you want to perform
		cout << "\n******************************************";
		cout << "\nMenu\n";
		cout << "1. Encryption\n";
		cout << "2. Decryption\n";
		cout << "3. Quit\n";
		cout << "******************************************";
		

	while(!quit)
	{
		quit = false;
		cout << "\nEnter the choice to perform the task";
		cout << "\nEnter 1 or 2 or 3: ";	
		cin >> ch;
		

		switch(ch)
		{

				case '1':
					cout << "Enter word to Encrypt: ";
					cin.ignore();
					getline(cin, inputstring);
						
					O1.setInputString(inputstring); //set the encryption text
					
					cout << "Enter the password to proceed Encryption: ";
					getline(cin, pass);
					
					if(O1.checkEncPass(pass)==1) { //check encryption password and then do encryption if the password is correct
						O1.getOutputStringenc();
					}
					else {
						break;
					}
		
					break;

				case '2':
					cout << "Enter word to Decrypt: ";
					cin.ignore();
					getline(cin, inputstring);

					O1.setInputString(inputstring); //set the decryption string

					cout << "Enter the password to proceed Decryption: ";
					getline(cin, pass);
					
					if(O1.checkDecPass(pass)==1) { //check decryption password and then do decryption if the password is correct
						O1.getOutputStringdec();
					}
					else {
						break;
					} 		
					break;

				case '3':
						cout<< "Exiting the program";
						quit=true;
						break;
				case '\n':
        		case '\t':
        		case ' ':
            			break;			   
				default:
						cout<<"Wrong Choice";
						quit=false;
						break;	
			}
		cout << "\n\n";
	}

	return 0;
}