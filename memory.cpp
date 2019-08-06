#include <iostream>
#include <cstddef>
#include <cstring>
using namespace std;
void mymemcpy (void *dst, const void *src, size_t n) {
    char *tmp_dst = (char *)dst;
    const char *tmp_src = (char *)src;
    
    while (n--) {
        *tmp_dst = *tmp_src;
       // cout<<"dst: "<<tmp_dst<< " src:"<< tmp_src<<endl;
        tmp_dst++;
        tmp_src++;
    }
    
}

void mymemmove (void *dst, const void *src, size_t n) {
    char *tmp_dst = (char *) dst;
    const char *tmp_src = (char *) src;
    
    if (src < dst) {
         tmp_src += n;
         tmp_dst += n;
         while (n--) {
            *--tmp_dst = *--tmp_src;
           // cout<<"dst: "<<tmp_dst<< " src:"<< tmp_src<<endl;
         } 
        
    } else {
        while (n--) {
            *tmp_dst++ = *tmp_src++;
            // cout<<"dst: "<<tmp_dst<< " src:"<< tmp_src<<endl;
        }
    }
}

int main()
{
    char s1[]= "hello world";
    char *s2;
    s2 = s1 + 10;
    mymemcpy(s2, s1, strlen(s1)+1);
    // memcpy(s2,s1, strlen(s1)+1);
    //mymemmove(s2, s1, strlen(s1)+1);
    //memmove(s2, s1, strlen(s1)+1);
    cout<<"s1: size "<<strlen(s1)<< " content "<<s1<<endl;
    cout<<"s2: size "<<strlen(s2)<< " content "<<s2<<endl;
    return 0;
}

