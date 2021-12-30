#include <iostream>
#include <cpr/cpr.h>

std::string request(const std::string &req){
    if(req == "get"){
        return cpr::Get(cpr::Url{"http://httpbin.org/get"}).text;
    }else if(req == "post"){
        return cpr::Post(cpr::Url{"http://httpbin.org/post"}).text;
    }else if(req == "put"){
        return cpr::Put(cpr::Url{"http://httpbin.org/put"}).text;
    }else if(req == "delete"){
        return cpr::Delete(cpr::Url{"http://httpbin.org/delete"}).text;
    }else if(req == "patch"){
        return cpr::Patch(cpr::Url{"http://httpbin.org/patch"}).text;
    }else{
        return "WARNING: this request is not supported!";
    }
}

int main(){
    std::cout << "########-USER REQUEST-########\n\n";
    std::string req;
    std::cout << "Your request(get, post, put, delete, patch): ";
    std::getline(std::cin, req);

    while(req != "ext"){
    std::cout << request(req) << "\n";
    std::cout << "Your request(get, post, put, delete, patch): ";
    std::getline(std::cin, req);
    }

    return 0;
}
