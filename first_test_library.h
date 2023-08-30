#include <iostream>
#include "string.h"
#include <locale>
#include <vector>
#include <sstream>
#include <curl/curl.h>
#include "json.h"
using namespace std;
const string REST_API = "https://rdb.altlinux.org/api/";
struct binary_package
{
    string name;
    int epoch;
    string version;
    string release;
    string arch;
    string disttag;
    int buildtime;
    string source;
};
struct list_json
{
    string branch;
    binary_package pack;
};

auto onDataReceived(char* ptr, size_t size, size_t nmemb, void* userdata) -> size_t;

constexpr auto k_max_buffer_size = 4096;

void readList(string url,string branch, string arch,string method){
        //Json :: Value message;
        CURL* req = curl_easy_init();
        CURLcode res;
        string full_url = url+"/export/branch_binary_packages/"+branch+"?arch="+arch;
        
        curl_easy_setopt(req, CURLOPT_URL, url);
        curl_easy_setopt(req, CURLOPT_FOLLOWLOCATION, 1L);
        //message =  curl_easy_perform(req);
        cout <<  curl_easy_perform(req);
};
void writeListJSON(){
    
};

bool IsElemInList(list<binary_package> str_list, binary_package pack){
    return find (str_list.begin(), str_list.end(), pack) != str_list.end ();
};
void say_hello(){
    std::cout << "Hello, from test_rest_project!\n";
};
