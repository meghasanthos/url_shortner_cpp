// *********************** URL SHORTNER *****************************

#include <bits/stdc++.h>
using namespace std;

class URLShortner
{
    private:
        const string baseUrl = "http://tinuUrl/";
        unordered_map<string, string> storage;

        string generateKey(){
            string key = "";
            const string charset = "bacdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

            for(int i = 0; i < 6; i++){
                int index = rand() % charset.length();
                key += charset[index];
            }

            return key;

        }

    public:
        URLShortner(){
            srand(time(0));
        }

        string shortenURL(string originalUrl){
            for(auto &KeyValuePair : storage){
                if(KeyValuePair.second == originalUrl){
                    return KeyValuePair.first;
            }
        }

        string shortUrl;
        do {
            shortUrl = baseUrl + generateKey();
        }while(storage.count(shortUrl));

        storage[shortUrl] = originalUrl;
        return shortUrl;
    }

    string getOriginalUrl(string shortUrl){
        return storage[shortUrl];
    }

    void displayStorage(){
        for(auto &KeyValuePair : storage){
            cout<<KeyValuePair.first<<" -> "<<KeyValuePair.second<<endl;
    }
}

};

int main(){
    URLShortner urlShortner;

    string longUrl1 = "https://example.com/very/long/url1";
    string longUrl2 = "https://example.com/some/other/url2";


    string shortUrl1 = urlShortner.shortenURL(longUrl1);
    string shortUrl2 = urlShortner.shortenURL(longUrl2);
    
    cout<<"SHORT_URLS"<<endl;
    cout<<shortUrl1<<endl;
    cout<<shortUrl2<<endl;

    cout<<"ORIGINAL_URLS"<<endl;

    cout<<urlShortner.getOriginalUrl(shortUrl1)<<endl;
    cout<<urlShortner.getOriginalUrl(shortUrl2)<<endl;

    cout<<"\n\n"<<endl;
    urlShortner.displayStorage();

    return 0;
}