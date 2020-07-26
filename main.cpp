#include<bits/stdc++.h>
#define ll long long
using namespace std;


/*
 we have represented the numbers as strings
 and made various mathematical functions which work on
 numbers represented as strings. we have made a total of
 10 operator.
 1-IsSmallOrEqual(<=) checks if a number is smaller or equal to the other.
 2-IsSmall(<) checks if a number is smaller than the other.
 3-IsEqual(==) checks if a number is equal to another.
 4-add(+) adds two numbers.
 5-prod(*) multiplies two numbers.
 6-diff(-) subtracts two numbers.
 7-divide(/) divides two numbers.
 8-Mod(%) finds the remainder when a is divided by b.
 9-gcd finds the gcd of a and b.
 10-power(pow(a,b)) finds pow(a,b)
*/


//1 (<=)
bool IsSmallOrEqual(string str1, string str2)
{
    ll n1 = str1.length(), n2 = str2.length();
    bool z1 = true, z2 = true;
    for (int i = 0; i < n1; i++)
        if (str1[i] != '0')
            z1 = false;
    for (int i = 0; i < n2; i++)
        if (str2[i] != '0')
            z2 = false;
    if (z1 && z2)
        return true;
    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;
    for (ll i = 0; i < n1; i++)
        if (str1[i] < str2[i]) return true;
        else if (str1[i] > str2[i]) return false;
    return true;
}

//2 (<)
bool IsSmall(string str1, string str2)
{
    ll n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (ll i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
    return false;
}

//3-(==)
bool IsEqual(string str1, string str2)
{

    ll n1 = str1.length(), n2 = str2.length();
    bool z1 = true, z2 = true;
    for (int i = 0; i < n1; i++)
        if (str1[i] != '0')
            z1 = false;
    for (int i = 0; i < n2; i++)
        if (str2[i] != '0')
            z2 = false;
    if (z1 && z2)
        return true;
    if (n1 != n2)
        return false;
    for (ll i = 0; i < n1; i++)
        if (str1[i] != str2[i])
            return false;
    return true;
}

// 4- add two numbers.
string add(string str1, string str2)
{
    ll n1 = str1.length(), n2 = str2.length();
    if (n1 > n2)
        swap(str1, str2);
    string str = "";
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    ll carry = 0;
    for (int i = 0; i < n1; i++)
    {
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    for (int i = n1; i < n2; i++)
    {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry)
        str.push_back(carry + '0');
    reverse(str.begin(), str.end());
    return str;
}

//5-prod two numbers
string prod(string x, string y)
{
    string ans = "";
    int k = 0;
    for (int i = y.size() - 1; i >= 0; i--)
    {
        int temp = 0, carry = 0;
        string stemp = "";
        for (int j = x.size() - 1; j >= 0; j--)
        {
            temp = (y[i] - '0') * (x[j] - '0') + carry;
            stemp += temp % 10 + '0';
            carry = temp / 10;
        }
        if (carry != 0)
            stemp += carry + '0';

        reverse(ans.begin(), ans.end());
        temp = 0;
        carry = 0;
        for (int j = 0; j < k + stemp.size(); j++)
        {
            if (j >= k && j < ans.size())
            {
                temp = ans[j] + stemp[j - k] - 2 * '0' + carry;
                ans[j] = temp % 10 + '0';
                carry = temp / 10;
            }
            else if (j >= ans.size())
            {
                temp = stemp[j - k] - '0' + carry;
                ans += temp % 10 + '0';
                carry = temp / 10;
            }
        }
        if (carry != 0)
            ans += carry + '0';
        reverse(ans.begin(), ans.end());
        k++;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] != '0')
            return ans;
    }
    return "0";
}

//function 6 difference
string diff(string str1, string str2)
{
    if (IsSmall(str1, str2))
        swap(str1, str2);
    string str = "";
    //find the lengths of strings
    ll n1 = str1.length(), n2 = str2.length();
    //reverse the strings to iterate
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    //iteration procedure similar to addition
    ll carry = 0;
    for (ll i = 0; i < n2; i++)
    {
        ll sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else carry = 0;
        str.push_back(sub + '0');
    }
    for (ll i = n2; i < n1; i++)
    {
        ll sub = ((str1[i] - '0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else carry = 0;
        str.push_back(sub + '0');
    }
    reverse(str.begin(), str.end());
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '0') return str.substr(i);
    }
    return "0";
}

//7- function divide
string divide(string num, string div)
{
    string ans = "";
    int pos = 0;
    string temp = "";
    while (pos < num.size())
    {
        if (temp[0] == '0')
            temp[0] = num[pos];
        else
            temp += num[pos];
        if (IsSmall(temp, div))
        {
            if (ans.size() != 0)
                ans += '0';
        }
        else
        {
            for (int i = 9; i >= 0; i--)
            {
                string t = "";
                t += i + '0';
                if (IsSmallOrEqual(prod(t, div), temp))
                {
                    ans += t;
                    if (IsEqual(prod(t, div), temp))
                        temp = "";
                    else
                        temp = diff(prod(t, div), temp);
                    break;
                }
            }
        }
        pos++;

    }
    if (ans.size() == 0)
        return "0";
    return ans;
}

//8-remainder function simply returns b-(floor(a/b))*b
string mod(string n, string d)
{
    return diff(n, prod(divide(n, d), d));
}

//9-power function returns pow(a,b)
string power(string x, ll n)
{
    if (n == 0)
        return "1";
    if (n == 1)
        return x;
    string temp = power(x, n / 2);
    if (n % 2 == 0)
        return prod(temp, temp);
    else
        return prod(x, prod(temp, temp));
}

ll g = 0;
string power(string x, string n, string N)
{
    if (IsEqual(n, "0"))
        return "1";
    if (IsEqual(n, "1"))
        return mod(x, N);
    string temp = mod(power(x, divide(n, "2"), N), N);

    if (IsEqual(mod(n, "2"), "0"))
        return mod(prod(temp, temp), N);
    else
        return mod(prod(x, mod(prod(temp, temp), N)), N);

}


//GCD function finds the greatest common divisor
//of a and b
string gcd(string a, string b)
{
    if (IsEqual(b, "0"))
        return a;
    return gcd(b, mod(a, b));
}



string getPrime()
{
    string primes[] = {
        "1772629573679152589335751",
        "9996834795542799325379081",
        "8076737514959871909661591",
        "9184713383182455436877249",
        "5248856571818397095667017",
        "3316361718074381133015827",
        "6612394226173762040335063",
        "4246452375127824091160929",
        "8418082864875619721401463",
        "2875808158322221473148513",
        "61920572513383563943782839",
        "65320483338614522331739967",
        "94473552408568888084488047",
    };

    //rand() function is an in built stl function
    //which generates a random number
    return primes[rand() % 13];
}
ll mod(string num, ll a)
{
    // Initialize result
    ll res = 0;

    // One by one process all digits of 'num'
    for (ll i = 0; i < num.length(); i++)
        res = (res * 10 + (ll)num[i] - '0') % a;

    return res;
}
string strToNum(string s)
{
    string ans = "";
    for (ll i = s.size() - 1, k = 0; i >= 0; i--, k++)
    {
        ll t = s[i] + 0;
        string temp;
        while (t != 0)
        {
            temp += t % 10 + '0';
            t /= 10;
        }
        reverse(temp.begin(), temp.end());
        ans = add(ans, prod(power("128", k), temp));
    }
    return ans;
}
string numToStr(string n)
{
    string ans = "";
    while (!IsSmall(n, "128"))
    {
        ans += mod(n, 128);
        n = divide(n, "128");
    }
    ans += mod(n, 128);
    reverse(ans.begin(), ans.end());
    return ans;
}


class company
{
private:
    string p;
    string q;
    string phiN;
    string d;
public:
    string N;
    string e;
    void getPandQ();
    void getN();
    void getPHIn();
    void getE();
    void getD();
    string ENCRYPT(string m , company n);
    string DECRYPT(string m);
    void signup();
};

void company::getPandQ()
{
    p = getPrime();
    q = getPrime();
}

void company::getN()
{
    N = prod(p, q);
}

void company::getPHIn()
{
    phiN = prod(diff(p, "1"), diff(q, "1"));
}

void company::getE()
{
    e = "3";
    while (1)
    {
        if (IsEqual(gcd(e, phiN), "1") == 1)
            break;
        e = add(e, "2");
    }
}

void company::getD()
{
    string k = "1";
    while (1)
    {
        if (IsEqual(mod(add("1", prod(k, phiN)), e), "0"))
        {
            d = divide(add("1", prod(k, phiN)), e);
            break;
        }
        k = add(k, "1");
    }
}

string company::ENCRYPT(string message, company recipient)
{
    cout << "Encrypting.......    ";
    string mnum, c, r_e, r_N;
    mnum = strToNum(message);
    r_e = recipient.e;
    r_N = recipient.N;
    c = mod(power(mnum, r_e, r_N), r_N);
    cout << "Encrypted." << endl;
    return c;
}

string company::DECRYPT(string EncryptedMessage)
{
    cout << "Decrypting.......     ";
    string DecryptedMessage, DecryptNum;
    DecryptNum = mod(power(EncryptedMessage, d, N), N);
    DecryptedMessage = numToStr(DecryptNum);
    cout << "Decrypted." << endl;
    return DecryptedMessage;
}

char x = 'A';

void company::signup()
{

    cout << "Establishing company " << x << endl;
    getPandQ();
    getN();
    getPHIn();
    getE();
    getD();
    cout << x << " established." << endl;
    x++;
    if (x == 'C')
    {
        cout << "Message from company A to B is : " << endl;
    }
}

int main()
{
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string message;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//                         WELCOME      TO      RSA       CRYPTO       SYSTEM                                 //" << endl;
    cout << "//                         BY-     SANYAM SHARMA     SARTHAK PAL      PRANJUL                                 //" << endl;
    cout << "//                         Roll no. (SE)-  115                                                                //" << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    company A;
    company B;
    A.signup();
    B.signup();
    cout << "Enter the message to be sent by A : ";
    getline(cin, message);
    cout << "Message from company A to B is : " << message << endl;
    string EncryptedMessage = A.ENCRYPT(message, B);
    cout << "the encrypted message sent is : " << EncryptedMessage << endl;
    string DecryptedMsg = B.DECRYPT(EncryptedMessage);
    cout << "the Deccrypted message recieved by B from A is : " << DecryptedMsg;
    return 0;
}