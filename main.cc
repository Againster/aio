#include "config.h"
#include "core.h"

static const char* addr = "0.0.0.0";
static const char* port = "1080";

void signal_handler() {
    signal(SIGPIPE, SIG_IGN);
};

void epoll_cycle() {
    /** mem pool **/
    MemPool* mp = new SimpleMemPool();
    mp->create(4096);
    /** init socket **/
    uint16_t port = htons((uint16_t)1080);
    uint32_t addr = inet_addr(::addr);

    Listening* ls = (Listening*) mp->alloc(sizeof(Listening));
    ls->sockaddr = (struct sockaddr*) mp->alloc(sizeof(struct sockaddr));
    ls->sockaddr->sa_family = AF_INET;
    memmove(ls->sockaddr->sa_data, &port, sizeof(uint16_t));
    memmove(&ls->sockaddr->sa_data[2], &addr, sizeof(uint32_t));

    ls->backlog = LISTEN_BACKLOG;
    ls->type = SOCK_STREAM;
    ls->socklen = sizeof(struct sockaddr);

    /** init cycle **/
    Cycle* cycle = (Cycle*) mp->alloc(sizeof(Cycle));
    cycle->mem = mp;
    cycle->log = new SimpleLogger();
    void* p = mp->alloc(sizeof(vector<Listening*>));
    void* a = mp->alloc(sizeof(vector<Listening*>));
    std::allocator<Listening*>* alloc = new (a) std::allocator<Listening*>();
    cycle->listening = new (p) vector<Listening*>(*alloc);
    cycle->listening->push_back(ls);

    open_listening_socket(cycle);


};

namespace my {

    double sqrt_newton(unsigned long c) {
        double x = 17.3;
        double x_new = 0.5 * x + 0.5 * c / x;
        double p = 0.00000000000000001;

        double delta = 0;

        while (((delta = x_new - x) >= 0 ? delta : -delta) >= p) {
            x = x_new;
            x_new = 0.5 * x + 0.5 * c / x;
            //printf("x_new: %.32g, x: %.32g\n", x_new, x);
        }
        return x_new;
    }

    double sqrt_bin(unsigned long c) {
        double left = 0.0f;
        double right = 1.0f * c;
        double middle =  0.0f;
        double middle_new = left / 2 + right / 2;
        double p = 0.000000000000000000001f;


        double f_middle;
        double f_left;
        double f_right;
        double delta;
        while (((delta = middle - middle_new) > 0 ? delta : -delta) - p > 0) {
            middle = middle_new;
            f_middle = middle * middle - c;
            f_left = left * left - c;
            f_right = right * right - c;

            if (f_middle * f_left > 0) {
                left = middle;
                middle_new = left / 2 + right / 2;
            } else if (f_middle * f_right > 0) {
                right = middle;
                middle_new = left / 2 + right / 2;
            } else {
                printf("error");
            }
        }

        return middle_new;
    }
}

#include <memory>
#include <cmath>
#include <iostream>
using namespace std;
int main() {
    vector<int> v;
    vector<int>::allocator_type alloc = v.get_allocator();
    int* i = alloc.allocate(1);
    *i = 90;
    printf("%d\n", *i);

    vector<int>::allocator_type::rebind<char>::other k;
    char* c = k.allocate(4);
    c[0] = 'h';
    c[1] = 'e';
    c[2] = 'k';
    printf("%s\n", c);

    double x = 4964561563454258;
    printf("result: %.32g\n", std::sqrt(x));
    printf("result: %.32g\n", my::sqrt_bin(x));
    printf("result: %.32g\n", my::sqrt_newton(x));

    //String c = a;
    /*
    char* p = "sdfksdfkj";
    char* x[3][4];
    char* (*c)[3][4];
    c = &x;
    *c[0][0] = p;
    cout << sizeof(c) << endl;
    */

    /*
    typedef char* (*funca)(int);
    funca k = testa;
    *k(5);
     */

    /*
    const a = 5;
    const auto b = a;
    const auto& c = a;
    const auto d = &c;
    auto e = a;
    e = 10;
    e++;
    const type_info& ti = typeid(b);
    cout << ti.name() << e << endl;
    */

    /*-------------------------------
    int k[] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v(k, k + sizeof(k) / sizeof(int));
    vector<int>::iterator it;
    for (it = v.begin() ; it != v.end(); it++) {
        if (*it == 5) {
            break;
        }
    }

    //v.insert(it + 1, 34);
    vector<int>::iterator it2 = it + 1;
    cout << strlen("hello world") << endl;
    string s("hello world");
    cout << s.size() << endl;
    return 0;
    */
}



/*
#include "ipc/fifo_ipc.h"
#define TEST 0
int main() {

#if TEST
    FifoIpc k("test", true);
#else
    FifoIpc k("test", false);
#endif
    if (k.init()) {
        printf("open fifo error");
    };
    Ipc *ipc = &k;
    char test_w[64];
    char test_r[64];
    int r_n, w_n;
    int pid = fork();
    if (pid == 0) {
        printf("child ready\n");
        while (fgets(test_w, 63, stdin)) {
            ipc->push(test_w, strlen(test_w));
            printf("child push: %s", test_w);
        };
    } else {
        printf("parent ready\n");
        while (r_n = ipc->pull(test_r, sizeof(test_r))) {
            test_r[r_n] = 0;
            printf("parent pull: %s", test_r);
        }
    }
}
*/
